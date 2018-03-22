#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <fstream>
#include <vector>
#include <string>
#include <minijson_writer.hpp>

class AbstractObject
{
public:
    /**** PURE VIRTUAL FUNCTIONS ****/
    virtual std::string print() const = 0;
};

#endif // ABSTRACTOBJECT_H
