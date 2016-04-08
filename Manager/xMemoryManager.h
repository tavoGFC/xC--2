/*
 * xMemoryManager.h
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#ifndef XMEMORYMANAGER_H_
#define XMEMORYMANAGER_H_

#include "xPointer.h"
#include "xList.h"

using namespace std;

class xMemoryManager {
public:
	xMemoryManager();
	void xCalloc(int size);
	void xFree(xPointer ptr);
	void xSet(bool num, xPointer ptr);
	xList xL;
};

#endif /* XMEMORYMANAGER_H_ */
