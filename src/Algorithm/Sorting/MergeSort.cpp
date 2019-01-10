

#include "MergeSort.h"

LinkedList<LinkedList<int>> partition(LinkedList<int> a, int partby) {
    // copy over the values.
    //cout << "Partition-1" << endl;
    LinkedList<LinkedList<int>> A;
    A.add(LinkedList<int>());
    A.add(LinkedList<int>());
    
    for(int i=0; i<partby; i++)
        A[0].addFirst(a[i]);

    for(int i=partby;i<a.size();i++)
        A[1].addFirst(a[i]);

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



LinkedList<int> MergeSort(LinkedList<int> list){
    if(list.size() > 1) {
        LinkedList<LinkedList<int>> S = partition(list,list.size()/2);
        LinkedList<int> retlist;
        
        retlist.addFrom(MergeSort(S[0]));
        retlist.addFrom(MergeSort(S[1]));
        return retlist;
    } else {
        return list;
    }
}
