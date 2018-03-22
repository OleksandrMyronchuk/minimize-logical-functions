#include "kuainrule.h"
#include <expression.h>

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <custompair.h>
#include <expression.h>
#include <normalform.h>

/******** PRIVATE ********/

std::string KuainRule::data;
std::string KuainRule::lastData;

/******** PUBLIC ********/

/**** CONSTRUCTOR & DESTRUCTOR ****/
KuainRule::KuainRule(){}
KuainRule::~KuainRule(){}

/**** OVERRIDE FUNCTIONS ****/
std::string KuainRule::print()
{
    return data;
}

/**** UNIQUE FUNCTIONS ****/
/*
{ "glu" : [ 0, [ 1, 3, <expr> ], [ 1, 5, <expr> ],... ] ,
[ 1, [ 2, 3, <expr> ], [ 2, 4, <expr> ],... ] }
*/
template<typename tNF>
ShortNormalForm *KuainRule::gluing(tNF *typeNormalForm)
{
    ShortNormalForm *shortNormalForm = new ShortNormalForm;
    std::size_t exprSize = typeNormalForm->exprSize();
    std::vector<bool> wasShortened(exprSize, {false});
    bool entry(false);
    lastData += "{\"g\":[";
    for(std::size_t i(0); i < exprSize; i++)
    {        
        for(std::size_t j(i + 1); j < exprSize; j++)
        {
            Expression *currentExpression = Expression::gluing(
                            typeNormalForm->getExprById( i ),
                            typeNormalForm->getExprById( j )
                        );
            if( currentExpression == nullptr )
                continue;

            if(entry)
                lastData += ',';
            else
                entry = true;
            lastData += '[' + std::to_string( i + 1 ) + ',' + std::to_string( j + 1 ) + ',';
            lastData += currentExpression->print();
            lastData += ']';

            wasShortened[i] = true;
            wasShortened[j] = true;
            shortNormalForm->setExpr( currentExpression );
        }        
    }
    lastData += "]},{\"ng\":[";
    entry = false;
    bool changeIndicator(false);
    for(std::size_t i(0); i < exprSize; i++)
    {
        if( !wasShortened[i] )
        {
            if(entry)
                lastData += ',';
            else
                entry = true;
            lastData += typeNormalForm->getExprById( i ).print();

            shortNormalForm->setExpr( typeNormalForm->getExprById( i ) );
        }
        else
        {
            changeIndicator = true;
        }
    }
    lastData += "]}";
    return changeIndicator ? shortNormalForm : nullptr;
}

ShortNormalForm *KuainRule::gluingLoop(PerfectNormalForm *perfectNormalForm)
{   
    data += "{\"glu\":[[";

    ShortNormalForm *shortNormalForm = KuainRule::gluing(perfectNormalForm);
    ShortNormalForm *nextForm = shortNormalForm;

    data += lastData;lastData.clear();/*getlastDataAndClear*/
    data += "]";

    do
    {
        shortNormalForm = nextForm;
        nextForm = KuainRule::gluing(nextForm);
        if(nextForm != nullptr)
        {
            data += ",[";
            data += lastData;lastData.clear();/*getlastDataAndClear*/
            data += "]";
        }
        else
        {
            data += "]}\n";
            break;
        }
    }
    while ( true );
//перенести
    bool entry(false);
    std::vector<__uint64> duplicates = shortNormalForm->deleteDuplicates();
    std::size_t duplicatesSize = duplicates.size();
    data += "{\"snf_dplc\":[";
    for(std::size_t i(0); i < duplicatesSize; i++)
    {
        if(entry)
            data += ',';
        else
            entry = true;
        data += std::to_string( duplicates.at(i) );
    }
    data += "]}\n";
//
    return shortNormalForm;
}

NormalForm *KuainRule::absorption(PerfectNormalForm *perfectNormalForm, ShortNormalForm *shortNormalForm)
{
    std::size_t PNFSize = perfectNormalForm->exprSize();
    std::size_t SNFSize = shortNormalForm->exprSize();
    std::vector<bool> row(PNFSize, {false});
    __uint64 maxAbsorptionInd(0);//dangerously
    __uint64 currentCounter(0);
    __uint64 lastCounter(0);
    __uint64 SNFshortenedVars;
    bool isWorkCompleted(false);
    NormalForm *normalForm = new NormalForm;
    bool entry(false);
    bool entry1(false);
    data += "{\"absr\":[";
    do
    {
        for (std::size_t i(0); i < SNFSize; i++)
        {
            currentCounter = 0;
            for (std::size_t j(0); j < PNFSize; j++)
            {                                
                SNFshortenedVars = ~shortNormalForm->getExprById( i ).getAllVars().second;
                if(
                        ((shortNormalForm->getExprById( i ).getAllVars().first & SNFshortenedVars) ==
                        (perfectNormalForm->getExprById( j ).getAllVars().first & SNFshortenedVars)) &&
                        !row[j]
                        )
                {
                    currentCounter++;
                    if(currentCounter > lastCounter)
                    {
                        lastCounter = currentCounter;
                        maxAbsorptionInd = i;
                    }
                }
            }
        }
        lastCounter = 0;
        currentCounter = 0;
        normalForm->setExpr( shortNormalForm->getExprById( maxAbsorptionInd ) );
        if(entry1)
            data += ',';
        else
            entry1 = true;
        data += "[";
        data += std::to_string( maxAbsorptionInd + 1 );
        data += ",[";
        entry = false;
        for (std::size_t i(0); i < PNFSize; i++)
        {
            SNFshortenedVars = ~shortNormalForm->getExprById( maxAbsorptionInd ).getAllVars().second;
            if(
                (shortNormalForm->getExprById( maxAbsorptionInd ).getAllVars().first & SNFshortenedVars) ==
                (perfectNormalForm->getExprById( i ).getAllVars().first & SNFshortenedVars)
                )
            {                
                if(entry)
                    data += ',';
                else
                    entry = true;
                data += std::to_string( i + 1 );
                row[i] = true;
            }
        }
        data += "]]";
        isWorkCompleted = true;
        for (std::size_t i(0); i < PNFSize; i++)
        {
            isWorkCompleted = isWorkCompleted && row[i];
        }
    }while(!isWorkCompleted);
    data += "]}";
    return normalForm;
}
