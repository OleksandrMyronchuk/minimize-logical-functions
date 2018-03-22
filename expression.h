#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <abstractobject.h>
#include <defines.h>
#include <utility>

class Expression : public AbstractObject
{
private:
    __uint64 _variables;
    __uint64 _shortenedVars;// 1 - shortened, 0 - not
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    Expression();    
    ~Expression();

    /**** OVERRIDE FUNCTIONS ****/
    std::string print() const override;

    /**** UNIQUE FUNCTIONS ****/
    Expression static *gluing(const Expression &var1, const Expression &var2);
    bool static compareBits(__uint64 value1, __uint64 value2, __uint8 ind);
    void setAllVars(__uint64 vars);
    void setVar(bool var, __uint8 varInd);
    std::pair<__uint64, __uint64> getAllVars() const;
    bool getVar(__uint8 varSize) const;
    static std::size_t getVarSize(std::size_t setVarSize = 0);//кількість змінних у Exptrtion
    inline bool operator==(const Expression &other) const
    {
        return  ( this->_shortenedVars == other._shortenedVars ) &&
                ( this->_variables == other._variables );
    }
};

#endif // EXPRESSION_H
