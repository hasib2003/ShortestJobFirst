//
// Created by hasib on 7/23/23.
//

#include "shortJob.h"
#include <iostream>
shortJob ::shortJob() {

    totalProcess = 0;
    timer = 1;
    averageWaiting = 0;
}

void shortJob ::simulate() {

    takeInput();
    executeJobs();
}



void shortJob :: takeInput(){
    // first we shall take input from user
// inreal cases we can traverse queue for this purpose

    printf("Enter total number of processes ");
    scanf("%d",&totalProcess);

    int temp  = 1;
    int i = 0;

    for (;i<totalProcess;i++){
        node * iterator = new node();

        iterator->pId  = i;
        std::cout << "Enter the information about process with id " << i << "\n";
        std::cout << "Burst time in milliseconds (can only be an integer): ";
        std::cin>>iterator->brustTime;
        int temp;
        std::cout << "Arrival time in milliseconds (can only be an integer): ";
        std::cin >> temp;
        while(arivalTimeConflictResolver(i,temp) == 1){
            std::cout << "Enter again Arrival time in milliseconds (can only be an integer): ";
            std::cin >> temp;
        }
        iterator->arivalTime = temp;
        readyQueue.InsertAtLast(iterator);


    }
}

void shortJob ::executeJobs() {
    printf("Follwing shall be scheduling scheme under Shortest Job First with no preemption\nprocessId\tarivalTime\t\tbrustTime\twaitTime\tcompletionTime\t\n");

    // we shall keep executing the processes untill no process is avaiable
    while(readyQueue.start || executionQueue.start){
        // fetching the process into execution queue by calling update function
        if(readyQueue.start) {
            updateQueue();
        }

        // fetching the process with shortes job
        node * shortestJobProcess = executionQueue.start;
        shortestJobProcess->assignedTime = timer;

        if(timer - shortestJobProcess->arivalTime < 0){
            // that means that given process did not have to wait
            shortestJobProcess->waitTime = 0;
        }
        else{
            shortestJobProcess->waitTime = timer - shortestJobProcess->arivalTime;
        }


        // call to system call to execute process
        // .......
        // when finished deleted the front job

        timer += shortestJobProcess->brustTime;
        shortestJobProcess->compTime = timer - shortestJobProcess->arivalTime;

        averageWaiting += shortestJobProcess->waitTime;

        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\n",shortestJobProcess->pId,shortestJobProcess->arivalTime, shortestJobProcess->brustTime,shortestJobProcess->waitTime,shortestJobProcess->compTime);

        executionQueue.removeFront();




    }

}

void shortJob ::updateQueue() {
    // in real os, it has to put jobs into the execution queue based on how they come,
    // but in order to make this compatible with real life scenerios we shall use the
    // timer.


    node * temp = readyQueue.start;
    while (true){
        if (temp && temp->arivalTime <= timer ){
            // inserting it into sorted position in execution queue.
            readyQueue.start = readyQueue.start->next;
            executionQueue.InsertSorted(temp);
            // removing the job from the ready queue
            temp = readyQueue.start;

        }
        else{
            // this is from future so ignore it
            break;
        }

    }
}





int shortJob:: arivalTimeConflictResolver(int idx,int time){
    // takes index of the process in array whose value is to be set and the poposed arival time
    // called before the assigning the arival time to process
    // useful if two process are given arival same time by user
    // or the arival time is lesser than that of the previous one

    int conflict = 0;
    node * temp = readyQueue.start;
    int i = 0;
    for (;i<idx;i++){
        if (temp->arivalTime > time){
            printf("The arival time must be greater that all previous arival times");
            conflict = 1;
        }
        temp = temp->next;
    }
    return conflict;



}
shortJob :: ~shortJob() {
    std::cout<<"Average Waiting was "<<averageWaiting/totalProcess<<std::endl;
}
