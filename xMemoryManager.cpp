//
// Created by kevin on 15/04/16.
//

#include "xMemoryManager.h"

xMemoryManager::xMemoryManager() {
    Firstptr=(xObject*) malloc(32000000);
    Lastptr = Firstptr+32000000;
    cout<<Firstptr<<endl;
    cout<<Lastptr<<endl;

}

void xMemoryManager::xCalloc(int size) {

}


