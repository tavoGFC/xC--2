//
// Created by kevin on 15/04/16.
//

#include "Car.h"
#include "xMemoryManager.h"

//This Method returns the data of the class
string Car::getData() {
    cout<<this->data<<endl;
    return this->data;

}
/**
 * Constructor of the class Car
 */
Car::Car() {
    this->data = d;
}

/*
 * Class destructor
 */
Car::~Car() {

}
/*
 * override in the operator new so when a Car is created an xCar pointer is created an added to a available space in our heap
 */
xPointer Car::operator new(sizeof(xObject)) {
    xPointer<Car>xCar(new Car(this->getData()));
    xCar= xM.xCalloc(sizeof(xObject));
    xCar->getData();
    return ;
}











