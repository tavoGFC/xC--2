/*
 * xObject.h
 *
 *  Created on: Mar 23, 2016
 *      Author: kevin
 */

#ifndef XOBJECT_H_
#define XOBJECT_H_

class xObject {
public:
	//xObject();
	void* operator new  (int size);
	long getPtr();
	void setPtr();
	char* getClassName();
	long getId();
	char* setId();
private:
	char* className;
};

#endif /* XOBJECT_H_ */
