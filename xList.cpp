//
// Created by kevin on 15/04/16.
//

#include "xList.h"

xList::~xList() {
    node *current,*temp;
    current = head;
    temp = head;
    while(current != NULL) {
        current = current->next;
        delete temp;
        temp = current;
    }
}

struct xList::node* xList::initNode(string s, int i) {
    struct node *ptr = new node;

    // error? then just return
    if( ptr == NULL )
        return static_cast<struct node *>(NULL);
        // assign it
        // then return pointer to ne node
    else {
        ptr->name = s ;
        ptr->id = i;
        return ptr;
    }
}

// adding to the end of list
void xList::addNode( struct node *newNode )  {
    // if there is no node, put it to head
    if( head == NULL ) {
        head = newNode;
        tail = newNode;
    }

    // link in the new_node to the tail of the list
    // then mark the next field as the end of the list
    // adjust tail to point to the last node

    tail->next = newNode;
    newNode->next = NULL;
    tail = newNode;
}

void xList::insertNode( struct node *newnode ) {
    struct node *temp, *prev;

    if( head == NULL ) {                     // if an empty list,
        head = newnode;                      // set 'head' to it
        tail = newnode;
        head->next = NULL;                   // set end of list to NULL
        return;
    }

    temp = head;                             // start at beginning of list
    // while currentname < newname
    while( temp->name < newnode->name) {	    // to be inserted then
        temp = temp->next;                // goto the next node in list
        if( temp == NULL )                // don't go past end of list
            break;
    }
    // set previous node before we insert
    // first check to see if it's inserting
    if( temp == head ) {		    	    // before the first node
        newnode->next = head;                 // link next field to original list
        head = newnode;                       // head adjusted to new node
    }
    else {				    // it's not the first node
        prev = head;		    	    // start of the list,
        while( prev->next != temp ) {
            prev = prev->next;	    	    // will cycle to node before temp
        }
        prev->next = newnode;                 // insert node between prev and next
        newnode->next = temp;
        if( tail == prev )		    // if the new node is inserted at the
            tail = newnode;		    // end of the list the adjust 'end'
    }
}

struct xList::node* xList::searchName(struct node* ptr, string name) {
    while( name != ptr->name ) {
        ptr = ptr->next;
        if( ptr == NULL )
            break;
    }
    return ptr;
}

struct xList::node* xList::searchId(struct node* ptr, int id) {
    while( id != ptr->id ) {
        ptr = ptr->next;
        if( ptr == NULL )
            break;
    }
    return ptr;
}




void xList::deleteNode( struct xList::node *ptr )
{
    struct node *temp, *prev;
    temp = ptr;    // node to be deleted
    prev = head;   // start of the list, will cycle to node before temp

    if( temp == prev ) {                    // deleting first node?
        head = head->next;                  // moves head to next node
        if( tail == temp )                  // is it end, only one node?
            tail = tail->next;               // adjust end as well
        delete temp ;                       // free up space
    }
    else {                                  // if not the first node, then
        while( prev->next != temp ) {       // move prev to the node before
            prev = prev->next;              // the one to be deleted
        }
        prev->next = temp->next;            // link previous node to next
        if( tail == temp )                  // if this was the end node,
            tail = prev;                    // then reset the end pointer
        delete temp;                         // free up space
    }
}

void xList::displayNode( struct xList::node *ptr ) const
{
    cout << ptr->id << ": " << ptr->name << endl;
}

void xList::displayList( struct xList::node *ptr ) const
{
    if(!ptr) cout << "Nothing to display" << endl;
    while(ptr) {
        displayNode(ptr);
        ptr = ptr->next;
    }
}