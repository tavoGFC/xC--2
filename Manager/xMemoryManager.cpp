/*
 * xMemoryManager.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#include "xMemoryManager.h"


xMemoryManager::xMemoryManager() {
	// TODO Auto-generated constructor stub
	xList list = new xList();
	xL = list;
}

void xMemoryManager :: xCalloc(int size){
	void malloc(size);
}

void  xFree(xPointer ptr){
	void free(ptr);
}

void  xSet(bool num, xPointer ptr){

}
