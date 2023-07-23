//
// Created by hasib on 9/23/22.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H


// the node represent the process that we need to add of remove

class node {
public:
    int pId;
    int brustTime;
    int arivalTime; // represents the total time taken by process in queues including the execution time
    int assignedTime;
    int waitTime;
    int compTime;
    node* next;
    node ();

};


#endif //LINKED_LIST_NODE_H
