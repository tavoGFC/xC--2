/*
 * xMemoryManager.h
 *
 *  Created on: Mar 31, 2016
 *      Author: kevin
 */

#ifndef XMEMORYMANAGER_H_
#define XMEMORYMANAGER_H_

class xMemoryManager {
public:
	xMemoryManager();
	void xCalloc(int size);
	void xFree(xPointer *ptr);
	void xSet(bool, xPointer *ptr);
};

#endif /* XMEMORYMANAGER_H_ */
