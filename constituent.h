#ifndef CONSTITUENT_H
#define CONSTITUENT_H

#include <defines.h>
#include <abstractobject.h>
#include <vector>

class Constituent : public AbstractObject
{
private:
    __uint64 _cons;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    Constituent();
    ~Constituent();

    /**** OVERRIDE FUNCTIONS ****/
    std::string print() const override;

    /**** UNIQUE FUNCTIONS ****/
    __uint64 getSize();
    __uint64 getCons(__uint64 consNum);
    void setCons(const __uint64 &cons);
};
#endif // CONSTITUENT_H
