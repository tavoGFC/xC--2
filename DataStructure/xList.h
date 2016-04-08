/*
 * xList.h
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#ifndef XLIST_H_
#define XLIST_H_

#include <iostream>
#include "xNode.h"
#include "xObject.h"

class xList {
public:
	xList();
	void newObject(xObject ele);
	xObject Sub(int n);
	bool itsEmpty();
	xNode head;
	xNode tail;
};

#endif /* XLIST_H_ */
