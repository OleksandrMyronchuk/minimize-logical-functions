#ifndef CONSTITUENT_H
#define CONSTITUENT_H

#include <defines.h>
#include <abstractobject.h>
#include <vector>

class Constituent : public AbstractObject
{
private:
    std::vector<__uint64> _truCons;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    Constituent();
    ~Constituent();

    /**** OVERRIDE FUNCTIONS ****/
    std::string print() const override;

    /**** UNIQUE FUNCTIONS ****/
    __uint64 getSize();
    __uint64 getTruCons(__uint64 consNum);
    void setTruCons(const std::vector<__uint64>& truCons);
};
#endif // CONSTITUENT_H
