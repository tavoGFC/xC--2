//
// Created by kevin on 15/04/16.
//

#include "xObject.h"

string xObject::getClassName() {
    string name = typeid(*this).name();
    cout<<name<<endl;
    return name;
}

xObject::~xObject() {

}

xObject::xObject() {

}
