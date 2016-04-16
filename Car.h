//
// Created by kevin on 15/04/16.
//

#ifndef KEVIN_C_2_CAR_H
#define KEVIN_C_2_CAR_H

#include "xPointer.h"
#include "xObject.h"

class Car : public xObject{
private:
    string data="BMW";
public:
    Car();
    xPointer operator new(size_t);
    virtual ~Car();
    String getClassName();
    String getData();
};


#endif //KEVIN_C_2_CAR_H
