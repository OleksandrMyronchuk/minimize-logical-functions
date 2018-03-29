#include "kuainrule.h"
#include <expression.h>

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <custompair.h>
#include <expression.h>
#include "normalform.h"

/******** PRIVATE ********/

template<typename tNF>
ShortNormalForm *KuainRule::gluing(tNF *typeNormalForm)
{

    ShortNormalForm *shortNormalForm = new ShortNormalForm; /*Create the new SNF that will be used as a result*/
    std::size_t exprSize = typeNormalForm->exprSize(); /*Get size of the current NF*/
    std::vector<bool> wasShortened(exprSize, {false});
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

            lastData += '[' + std::to_string( i + 1 ) + ',' + std::to_string( j + 1 ) + ',';
            lastData += currentExpression->print();
            lastData += "],";

            wasShortened[i] = true;
            wasShortened[j] = true;
            shortNormalForm->setExpr( currentExpression );
        }
    }

    eraseLastComma(lastData);

    lastData += "]},{\"ng\":[";

    bool changeIndicator(false);
    for(std::size_t i(0); i < exprSize; i++)
    {
        if( !wasShortened[i] )
        {
            lastData += typeNormalForm->getExprById( i ).print() + ',';
            shortNormalForm->setExpr( typeNormalForm->getExprById( i ) );
        }
        else
        {
            changeIndicator = true;
        }
    }

    eraseLastComma(lastData);

    lastData += "]}";
    return changeIndicator ? shortNormalForm : nullptr;
}

/******** PUBLIC ********/

/**** CONSTRUCTOR & DESTRUCTOR ****/
KuainRule::KuainRule(){}
KuainRule::~KuainRule(){}

/**** OVERRIDE FUNCTIONS ****/
std::string KuainRule::print()
{
    return this->_data;
}

/**** UNIQUE FUNCTIONS ****/
#define eraseLastComma( str ) do { \
    if(',' == str.at(str.length() - 1)) \
        str.erase( str.length() - 1 ); \
    } while( false )

ShortNormalForm *KuainRule::gluingLoop(PerfectNormalForm *perfectNormalForm)
{   
    this->_data += "{\"glu\":[[";

    ShortNormalForm *shortNormalForm = KuainRule::gluing(perfectNormalForm); /*Result*/
    ShortNormalForm *nextForm = shortNormalForm;

    this->_data += lastData;
    this->_lastData.clear();
    this->_data += "]";

    do
    {
        shortNormalForm = nextForm;
        nextForm = KuainRule::gluing(nextForm); /*Gluing*/
        if(nextForm != nullptr) /*Check if it was gluing*/
        {
            this->_data += ",[";
            this->_data += lastData;
            this->_lastData.clear();
            this->_data += "]";
        }
        else
        {
            this->_data += "]}\n";
            break;
        }
    }
    while ( true );
    /*Begin of delete duplicate numbers*/
    std::vector<__uint64> duplicates = shortNormalForm->deleteDuplicates();
    std::size_t duplicatesSize = duplicates.size();
    data += "{\"snf_dplc\":[";
    for(std::size_t i(0); i < duplicatesSize; i++)
    {
        data += std::to_string( duplicates.at(i) ) + ',';
    }    
    eraseLastComma(data);
    data += "]}\n";
    /*End of delete duplicate numbers*/
    return shortNormalForm;
}

NormalForm *KuainRule::absorption(PerfectNormalForm *perfectNormalForm, ShortNormalForm *shortNormalForm)
{
#define checkOverlap(id1, id2, SNFshrtndExpr) \
(SNFshortenedExpr = ~shortNormalForm->getExprById( id1 ).getAllVars().second), \
((shortNormalForm->getExprById( id1 ).getAllVars().first & SNFshortenedExpr) == \
(perfectNormalForm->getExprById( id2 ).getAllVars().first & SNFshortenedExpr))

    std::size_t PNFSize = perfectNormalForm->exprSize(); /*Get size of the PNF vector*/
    std::size_t SNFSize = shortNormalForm->exprSize(); /*Get size of the SNF vector*/
    std::vector<bool> rows(PNFSize, {false}); /*Contains information about overlap rows*/
    __uint64 maxAbsorptionInd(0); /*The index of the element with maximum absorption*/
    __uint64 currentCounter(0); /*Counter enclosed loop*/
    __uint64 lastCounter(0); /*Total loop counter*/
    __uint64 SNFshortenedExpr; /*Inversion of variables that have been reduced*/
    bool wasOverlap(false);
    NormalForm *normalForm = new NormalForm; /*Result*/

    this->_data += "{\"absr\":[";
    do
    {
        lastCounter = 0; /*Reset counter*/
        for (std::size_t i(0); i < SNFSize; i++) /*SNF*/
        {
            currentCounter = 0; /*Reset counter*/
            for (std::size_t j(0); j < PNFSize; j++) /*PNF*/
            {                                                
                if( checkOverlap(i, j, SNFshortenedExpr) && !rows[j] ) /*Check if the SNF and PNF are overlap and did not shorten*/
                {
                    currentCounter++; /*Increase the local counter*/
                    if(currentCounter > lastCounter) /*Check if the currentCounter is greater than lastCounter*/
                    {
                        lastCounter = currentCounter;
                        maxAbsorptionInd = i; /*Set into the maxAbsorptionInd index that overlaps the most cases*/
                    }
                }
            }
        }               
        normalForm->setExpr( shortNormalForm->getExprById( maxAbsorptionInd ) ); /*Set into the NF expression that overlaps the most cases*/

        this->_data += "[";
        this->_data += std::to_string( maxAbsorptionInd + 1 );
        this->_data += ",[";

        wasOverlap = false; /*Reset*/
        for (std::size_t i(0); i < PNFSize; i++) /*PNF*/
        {             
            if( checkOverlap(maxAbsorptionInd, i, SNFshortenedExpr) ) /*Check if the SNF and PNF at maxAbsorptionInd are overlap*/
            {                
                this->_data += std::to_string( i + 1 ) + ',';
                rows[i] = true; /*Mark up all of overlapped cases*/
                wasOverlap = true;
            }
        }
        if(wasOverlap)
            eraseLastComma(data);

        this->_data += "]],";

    }while( !std::all_of(rows.begin(), rows.end(), [](bool elem){return elem;}) ); /*Until all of rows will be overlap*/
    eraseLastComma( this->_data );
    this->_data += "]}";
    return normalForm;
#undef checkOverlap
}
