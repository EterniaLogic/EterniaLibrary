//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "MergeSort.h"

IntegerList* partition(IntegerList *a, int partby){
    // copy over the values.
    //cout << "Partition-1" << endl;
    IntegerList* A = new IntegerList[2];
    //cout << "Partition-2" << endl;
    a->resetNext();
    //int klk=0;
    for(int i=0;i<partby;i++){
        int cc =  a->getNext();
        if(cc != -9999999){
            A[0].addFront(cc);
            //klk++;
        }
    }
    ///cout << "Partition-3" << endl;
    int cc;
    while((cc =  a->getNext()) != -9999999){
        A[1].addFront(cc);
        //klk++;
    }
    
    //cout << a->size() << " = " << A[0].size() << "+" << A[1].size() << " = " << klk << endl;
    //cout << "Partition-4" << endl;
    
    return A;
}


/*Algorithm merge(A, B)
InputsequencesAandBwithn/2 elements each
Outputsorted sequence of A∪B
S←empty sequence
while¬A.empty()∧¬B.empty()
    if A.front()<B.front()
        S.addBack(A.front());
        A.eraseFront();
    else
        S.addBack(B.front());
        B.eraseFront();
while¬A.empty()
    S.addBack(A.front());
    A.eraseFront();
while¬B.empty()
    S.addBack(B.front());
    B.eraseFront();
return S
*/

IntegerList* merge(IntegerList *a, IntegerList *b){
    IntegerList* S = new IntegerList();
    //cout << "Merge-1" << endl;
    while(!a->empty() && !b->empty()){
        //cout << a->front() << " < " << b->front() << endl;
        if(a->front() < b->front()){
            S->addBack(a->pop());
        }else{
            S->addBack(b->pop());
        }
    }
    //cout << "Merge-2" << endl;
    while(!a->empty()){
        S->addBack(a->pop());
    }
    //cout << "Merge-3" << endl;
    while(!b->empty()){
        S->addBack(b->pop());
    }
    return S;
}

IntegerList* MergeSort(IntegerList* list){
    if(list->size() > 1){
        IntegerList* S = partition(list,list->size()/2);
        IntegerList S1 = S[0];
        IntegerList S2 = S[1];
        IntegerList* slist1 = MergeSort(&S1);
        IntegerList* slist2 = MergeSort(&S2);
        IntegerList* retlist = merge(slist1,slist2);
        return retlist;
    }else{
        return list;
    }
}
