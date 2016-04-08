/*
 * xNode.h
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#ifndef XNODE_H_
#define XNODE_H_

#include "xObject.h"

class xNode {
public:
	xNode(xObject i);
	xObject getObject();
	xNode next;
	xNode prev;
	xObject ele;
	int key;
};

#endif /* XNODE_H_ */
