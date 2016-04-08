/*
 * xList.cpp
 *
 *  Created on: Apr 7, 2016
 *      Author: kevin
 */

#include "xList.h"

xNode head;
xNode tail;

xList::xList() {
	// TODO Auto-generated constructor stub
	head=tail=NULL;
}

bool xList :: itsEmpty(){
	return head==NULL;
}

void xList :: newObject(xObject ele){
	xNode node = xNode(ele);
	if(!itsEmpty()){
		this->tail.next=node;
		node.prev=tail;
		node.key=tail.key+1;
		tail=node;
	}
	else{
		this->head=this->tail=node;
		node.key=0;
	}
}

xObject xList:: Sub(int n){
	if (n<0){
			cout << "error" ;
			return NULL;
		}
		if (n>this->tail.key){
			cout<<"Error,indice fuera del rango de lista ";
			return NULL;
		}
		else{
			xNode temp= this->head;
			int i=0;
			while (i<n){
				temp=temp.next;
				i++;
			}
			return temp.ele;
		}
}

