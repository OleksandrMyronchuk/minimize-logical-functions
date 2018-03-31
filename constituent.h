#ifndef CONSTITUENT_H
#define CONSTITUENT_H

#include "defines.h"
#include "expression.h"
#include "abstractobject.h"
#include <vector>
#include <cstddef>

class Constituent : public AbstractObject
{
private:
    std::vector<bool> _cons;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    Constituent( const std::vector<bool> &cons );
    ~Constituent();

    /**** OVERRIDE FUNCTIONS ****/
    std::string print() const override;

    /**** UNIQUE FUNCTIONS ****/
    std::size_t allVarSize();
    std::size_t getSize();
    std::vector<bool> getAllCons() const;
    void setCons( const std::vector<bool> &cons );
    std::vector<Expression> getAllTrueExpr();
};
#endif // CONSTITUENT_H
