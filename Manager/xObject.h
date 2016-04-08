/*
 * xObject.h
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#ifndef XOBJECT_H_
#define XOBJECT_H_

#include <string>
#include <iostream>
#include <typeinfo>
#include "xMemoryManager.h"
#include "xPointer.h"
#include "xList.h"

using namespace std;

class xObject {
public:
	xObject();
	xPointer operator new(size_t size);
};

#endif /* XOBJECT_H_ */
