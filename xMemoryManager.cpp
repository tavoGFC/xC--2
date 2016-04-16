//
// Created by kevin on 15/04/16.
//

#include "xMemoryManager.h"
/**
 * Class constructor this one does the an initial malloc of 32MB
 */
xMemoryManager::xMemoryManager() {
    Firstptr=(xObject*) malloc(32000000);
    Currentptr=Firstptr;
    Lastptr = Firstptr+32000000;
    cout<<"Este es el inicio de la porcion de memoria en heap: " << Firstptr<<endl;
    cout<<"Este es el final de la porcion de memoria en heap: " <<Lastptr<<endl;
    list.addNode(list.initNode(Firstptr,0));

}
/**
 * This reserves an memory space and initialize it in 0's
 */
void xMemoryManager::xCalloc(int size) {
    list.addNode(list.initNode(Currentptr+size, 0));
    cout<<"se inicializa el nodo para ser agregado a la lista"<<endl;
    Currentptr=Currentptr+size;
}


