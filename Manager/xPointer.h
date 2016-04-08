/*
 * xPointer.h
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#ifndef XPOINTER_H_
#define XPOINTER_H_

#include <string>

using namespace std;

template <class T>

class xPointer {
public:
	xPointer();
	void operator =(xPointer ptr);
	void operator ->();
	void operator ++();
	void operator --();
	void operator +(xPointer ptr, int num);
	void operator -(xPointer ptr, int num);
	void operator ==(xPointer ptrA, xPointer ptrB);
};

#endif /* XPOINTER_H_ */
