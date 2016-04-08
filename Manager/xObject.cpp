/*
 * xObject.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#include "xObject.h"

xMemoryManager xM;


xObject :: xObject() {
	// TODO Auto-generated constructor stub

}

xPointer operator new(size_t size){
	xPointer <xObject> ptr;
	xM.xCalloc(sizeof this);
	ptr = xM.xCalloc(sizeof this);
	//xM.xL.newObject(this);
	return  ptr;
}
