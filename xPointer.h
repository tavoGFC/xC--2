//
// Created by kevin on 15/04/16.
//

#ifndef KEVIN_C_2_XPOINTER_H
#define KEVIN_C_2_XPOINTER_H
/**
 * Class template for all the xPointers
 */
template <typename T>
class xPointer {
private:
    T*    xData; // Generic pointer to be stored
public:
    xPointer(T* xValue) : xData(xValue) {
    }
    ~xPointer()
    {
        delete xData;
    }

    T& operator* ()
    {
        return *xData;
    }

    T* operator-> ()
    {
        return xData;
    }
};



#endif //KEVIN_C_2_XPOINTER_H
