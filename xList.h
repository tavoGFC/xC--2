//
// Created by kevin on 15/04/16.
//

#ifndef KEVIN_C_2_XLIST_H
#define KEVIN_C_2_XLIST_H

#include <iostream>
#include <string>

using namespace std;

class xList {
public:
    struct node {
        int id;
        string name;
        struct node *next;
    } *head, *tail, *ptr;
    xList():head(NULL),tail(NULL){}	// constructor
    ~xList();			// destructor

    struct xList::node* searchName(struct xList::node*, string);
    struct xList::node* searchId(struct xList::node*, int);
    struct xList::node* initNode(string, int);

    void addNode( struct xList::node*);
    void insertNode( struct xList::node*);
    void deleteNode( struct xList::node*);
    void displayList( struct xList::node*)const ;
    void displayNode( struct xList::node*) const;
};


#endif //KEVIN_C_2_XLIST_H
