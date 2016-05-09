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
        handle1->setRecurrences(6); // "Times" to happen
        handle1->setPeriod(100); // period in milliseconds
		
        EventHandle *handle = handler->createEvent(&testObjectBOT, 1);
        handle->setRecurrences(3);
        handle->setPeriod(100);

		// add a single event
        EventHandle *handlex = handler->createEvent(&testObjectSingle, 0);
        handlex->setRecurrences(200);
        handlex->setPeriod(10); 
        handlex->arg1 = (void*)"aaa";

		// slower single event
        EventHandle *handlex2 = handler->createEvent(&testObjectSingle, 0);
        handlex2->setRecurrences(5);
        handlex2->setPeriod(1000);
        handlex2->arg1 = (void*)"bbb";

        while(!handler->isEmpty()){
                handler->handleEvents();
        }
}
