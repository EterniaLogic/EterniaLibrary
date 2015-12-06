#include "../EventHandler.h"

#include <iostream>

void testObjectTOP(){
        cout << "TOP" << endl;
}

void testObjectMID(){
        cout << "MID" << endl;
}

void testObjectBOT(){
        cout << "BOT" << endl;
}

void testObjectSingle(void* dat){
        cout << (char*)dat << endl;
        //cout << "cc" << endl;
}

void testObjectDouble(void* dat, void* dat2){
        cout << (char*)dat << " " << (char*)dat2 << endl;
        //cout << "cc2" << endl;
}


void testEventHandler(){
        EventHandler *handler = new EventHandler();

        //handler->createEvent(&testObjectTOP, 0);
        EventHandle *handle1 = handler->createEvent(&testObjectMID, 2);
        handle1->setRecurrences(6);
        handle1->setPeriod(100);
        EventHandle *handle = handler->createEvent(&testObjectBOT, 1);
        handle->setRecurrences(3);
        handle->setPeriod(100);
        /*cout << "Adding 10000 events...";
        cout.flush();
        for(int i=0;i<10000;i++){
                if(i % 100 == 0) {cout << "add " << i << endl; cout.flush(); }
                EventHandle *handley = handler->createEvent(&testObjectSingle, 0);
                handley->setRecurrences(200);
                //handlex->setPeriod(1); // 1 ms
                handley->arg1 = (void*)"XXXX GTFO!";
        }*/

        EventHandle *handlex = handler->createEvent(&testObjectSingle, 0);
        handlex->setRecurrences(200);
        handlex->setPeriod(10);
        handlex->arg1 = (void*)"aaa";

        EventHandle *handlex2 = handler->createEvent(&testObjectSingle, 0);
        handlex2->setRecurrences(5);
        handlex2->setPeriod(1000);
        handlex2->arg1 = (void*)"bbb";

        while(!handler->isEmpty()){
                handler->handleEvents();
        }
}
