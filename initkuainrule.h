#ifndef INITCRAMERRULE_H
#define INITCRAMERRULE_H
#include <defines.h>
#include <perfectnormalform.h>
#include <constituent.h>
#include <shortnormalform.h>
#include <normalform.h>
#include <vector>
#include <fstream>
#include <abstractobject.h>

class InitKuainRule : public AbstractObject
{
private:
    PerfectNormalForm *perfectNormalForm;    
    ShortNormalForm *shortNormalForm;
    NormalForm *normalForm;    
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    InitKuainRule(__uint8 varNum, const std::vector<__uint64>& truCons);

    /**** OVERRIDE FUNCTIONS ****/
    std::string print() const;

    /**** UNIQUE FUNCTIONS ****/
    NormalForm *run();
};

#endif // INITCRAMERRULE_H
