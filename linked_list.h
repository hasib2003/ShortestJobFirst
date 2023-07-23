//
// Created by hasib on 9/23/22.
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H
#include "node.h"
#include "string"
class linked_list {
public:
node *start;
node *last;
node *loc;
node *ploc;
linked_list();


void DeleteOdd();
bool isEmpty();
void InsertAtLast(node * );
void InsertAtStart(node *);
void SwapNodes();
// searches process based on its brust time
void Search(int);
void DeleteValue(int);
void printList();
void InsertSorted(node *);




int removeFront();

~linked_list();
};


#endif //LINKED_LIST_LINKED_LIST_H
