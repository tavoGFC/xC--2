//
// Created by kevin on 15/04/16.
//

#ifndef KEVIN_C_2_XMEMORYMANAGER_H
#define KEVIN_C_2_XMEMORYMANAGER_H

#include <iostream>
#include "xObject.h"

class xMemoryManager {
public:
    xMemoryManager();
    void xCalloc(int size);
    xObject* Firstptr=NULL;
    xObject* Lastptr=NULL;
};


#endif //KEVIN_C_2_XMEMORYMANAGER_H
