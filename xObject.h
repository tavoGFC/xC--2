//
// Created by kevin on 15/04/16.
//

#ifndef KEVIN_C_2_XOBJECT_H
#define KEVIN_C_2_XOBJECT_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "xMemoryManager.h"

using namespace std;

class xObject {
    /**
     * Atributes of the class xObject
     */
public:
    string getClassName();
    xObject();
    virtual ~xObject();
    xMemoryManager xM;
};


#endif //KEVIN_C_2_XOBJECT_H
