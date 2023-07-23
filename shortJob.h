//
// Created by hasib on 7/23/23.
//

#ifndef LINKED_LIST_SHORTJOB_H
#define LINKED_LIST_SHORTJOB_H
#include "linked_list.h"

class shortJob {

    double averageWaiting;
    // contains jobs arranged in the order of execution
    linked_list executionQueue;
    int totalProcess;
    // contains all processes that are willing to be executed
    linked_list readyQueue;

    // variable that help us to know where we are in time

    int timer;

public:

    shortJob();
    ~shortJob();
    // shall be called as main wrapper and driver function
    void simulate();

    // after performing one task this queue shall be updated so that
    // it has those shortest job on the front that became ready while execution of
    // previous task.

    void updateQueue();

    // takes input of all jobs, this part is unreal for the actual cases do not have prior
    // info of all jobs
    void takeInput();

    // this function shall execute jobs and shall be iterating the inputArray and calling updating queues
    void executeJobs();

    int arivalTimeConflictResolver(int,int);





};


#endif //LINKED_LIST_SHORTJOB_H
