//
// Created by hasib on 9/23/22.
//

#include "linked_list.h"
#include "node.h"
#include <iostream>
bool linked_list::isEmpty() {
    return start == nullptr;
}
linked_list::linked_list() {
    start = nullptr;
    last = nullptr;
}
void linked_list ::InsertAtStart(node * nn) {
    if(isEmpty()){
        start = nn;
        last = nn;
        nn->next = nullptr;
    }
    else{
        nn->next = start;
        start = nn;
    }
}
void linked_list::InsertAtLast(node * nn) {

    if (isEmpty()){
        start = nn;
        last = nn;
        nn->next = nullptr;

    }
    else{
        last->next = nn;
        last = nn;
        last->next = nullptr;
    }



}
void linked_list::printList(){
    std::cout<<"List: ";
    if(isEmpty()){
        std::cout<<"The list is currently empty"<<std::endl;
    }
    else{
    node *t_loc = start;
    while(t_loc!=nullptr){
        std::cout<<t_loc->pId<<" ";
        t_loc = t_loc->next;
    }
    std::cout<<std::endl;
    }
}

void linked_list ::Search(int value) {
    if (!isEmpty()) {
        loc = start;
        ploc = nullptr;
        while (loc != nullptr && loc->brustTime < value) {
            ploc = loc;
            loc = loc->next;
        }

        if(ploc!=last){
            if (loc->brustTime != value){
            loc = nullptr;}
        }
    }
}
void linked_list ::InsertSorted(node * nn) {
    if (!isEmpty()) {
        Search(nn->brustTime);
        if (loc == nullptr) {
            if (ploc != nullptr) {
                if (ploc == last) {
                    InsertAtLast(nn);
                }
                else {
                    nn->next = ploc->next;
                    ploc->next = nn;
                }
            } else {
                InsertAtStart(nn);
            }


        }
    }
    else {
            InsertAtStart(nn);
        }

}




void linked_list ::DeleteValue(int value) {
    if (!isEmpty()){
    Search(value);
        if (loc!= nullptr){
            if(ploc!= nullptr) {
                if (loc->pId == value) {
                    std::cout << value << " is deleted from the list" << std::endl;
                    ploc->next = loc->next;
                    node * deleter = loc;
                    delete deleter;
                    loc = nullptr;
                }
                else{
                    std::cout<<"valueError: not present in the list"<<std::endl;

                }
            }
            else{
                if (loc->pId == value) {
                    std::cout << value << " is deleted from the list" << std::endl;
                    node *deleter = loc;
                    start = loc->next;
                    delete deleter;
                    loc = nullptr;
                }
                else{
                    std::cout<<"valueError: not present in the list"<<std::endl;
                }

            }
        }
        else{
            std::cout << value << " is deleted from the list" << std::endl;
            //loc is already null is this case
            node *deleter = ploc;
            last = ploc;
            delete deleter;
            ploc = nullptr;

        }
        }
}

int linked_list :: removeFront(){
    node * temp  = start;
    start = start -> next;
    delete temp;
    return  temp->pId;
}

linked_list:: ~linked_list(){
    std::cout<<"dynamically deleted: ";
    while (start!=nullptr){
        node *loc = start;
        start = start->next;
        std::cout<<loc->pId<<" ";
        delete loc;

    }
    last = nullptr;

}

