/*
 * xObject.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: kevin
 */

#include <xPointer.h>
#include <xMemoryManager.h>
#include <xList.h>
#include <iostream>



using namespace std;

xMemoryManager xM;

//xObject::xObject(){
//}

xPointer operator new(int size){
	xPointer <xObject> ptr;
	xM.xCalloc(size);
	ptr = xM.xCalloc(size);
	return ptr;
}



