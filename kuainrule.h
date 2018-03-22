#ifndef CRAMERRULE_H
#define CRAMERRULE_H

#include <shortnormalform.h>
#include <normalform.h>
#include <perfectnormalform.h>
#include <string>

class KuainRule/*ЗРОБИТИ ВСПАДКУВАННЯ від initKuainRule*/
{
private:
    /**** UNIQUE FUNCTIONS ****/
    template <typename tNF>    
    ShortNormalForm static *gluing(tNF *typeNormalForm);
    static std::string data;
    static std::string lastData;
public:
    /**** CONSTRUCTOR & DESTRUCTOR ****/
    KuainRule();
    ~KuainRule();

    /**** OVERRIDE FUNCTIONS ****/
    static std::string print();

    /**** UNIQUE FUNCTIONS ****/
    ShortNormalForm static *gluingLoop(PerfectNormalForm *perfectNormalForm);
    NormalForm static *absorption(PerfectNormalForm *perfectNormalForm, ShortNormalForm *shortNormalForm);    
};

#endif // CRAMERRULE_H
