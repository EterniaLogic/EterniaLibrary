#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <stdio.h>
using namespace std;





#ifdef _WIN64 || _WIN32

#else
#include <unistd.h>
#include <signal.h>
#include <execinfo.h>
#endif


#ifdef _WIN64
   #define WINDOWSXX
#elif _WIN32
   #define WINDOWSXX
#else
   #define LINUXX

#endif




template<class T>
class LinkedListIterator;
#include "LinkedListIterator.hpp"
#include "ArrayList.hpp"
//#include "DynamicType.h"

//#include "../Math/Functions/Basic.h"
#include "../Math/struct/Matrix.h"


//class CharString;
//#include "CharString.h"

template<class T>
class LinkedList;
template<class T>
void QuickSortT(LinkedList<T> *listx, int (*valuefunc)(T item), int left, int right);
#include "../Algorithm/Sorting/QuickSort.h"


//#define dbgLog(STRX) cout << "[LinkedList] " << STRX << endl; cout.flush();
#define dbgLog(STRX) //

#define SIZEOFA(x) (sizeof(x) / sizeof(x[0]))


#define LLOPERATOR(OP) \
LinkedList<double> operator OP(LinkedList<double> v){ \
    LinkedList<double> out; \
    const char* cs = #OP; \
    cout << "[LinkedList] operator " << cs << "   sizes: " << size() << " " << v.size() << endl; \
    /*int msize = Math::max(size(), v.size());*/\
    double a=0, b=0; \
    for(int i=0;i<size();i++){ \
        if(i <= size()-1) a=get(i); \
        if(i <= v.size()-1) b=v.get(i); \
        out.add(a OP b); \
    } \
    return out; \
} \
\
LinkedList<double> operator OP(double v){ \
    LinkedList<double> out; \
    for(int i=0;i<size();i++){ \
        out.add(get(i) OP v); \
    } \
    return out; \
} 

template<class T>
class LinkedNode {
public:
    LinkedNode<T> * next;
    T data;
    LinkedNode() {
        next = 0x0;
    }
    ~LinkedNode() {}
};





template<class T>
class LinkedList {
    //Written January 25th, 2013
    
    int _size;
    bool changed; // used with freezing to help keep better performance
public:
    LinkedNode<T>* baseNode;
    LinkedNode<T>* currentNode;
    T *frozen;
    int frozenlen;
    


    // Initialize!
    LinkedList() {
        dbgLog("init");
        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    }
    
    // initializer for LinkedList<int> = {1,2,354,9};
    LinkedList(std::initializer_list<T> vallist){
        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    
        std::vector<T> v;
        v.insert(v.end(), vallist.begin(), vallist.end());
        for(int i=0;i<vallist.size();i++){
            add(v[i]);
        }
    }
    
    LinkedList(T* vallist, int len){
        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    
        for(int i=0;i<len;i++){
            add(vallist[i]);
        }
    }

    // Clean up!
    ~LinkedList() {
        dbgLog("finalize");
        
        // do not use due to clearing Real datasets between functions
        //  when using non-pointer referencing. (kind of annoying)
        //clear();
        
        // This also means that memory leaks are a big thing here.
    }
    
    
    
    

    // add item
    T add(T cc) {
        //adds a Void* Object. This can be declared when using the list.
        //cout << "add item " << cc << endl;
        dbgLog("add item");
        LinkedNode<T>* item = new LinkedNode<T>();
        item->data = cc;
        if(baseNode == 0x0 || currentNode == 0x0) {
            baseNode = item;
            currentNode = item;
        } else {
            currentNode->next = item;
            currentNode = item;
        }
        _size++;
        changed=true;
        
        return cc;
    }
    
    T addFirst(T cc){
        //adds a Void* Object. This can be declared when using the list.
        
        LinkedNode<T>* item = new LinkedNode<T>();

        dbgLog("add item first '" << cc << "' @ (" << item << ")");

        item->data = cc;
        
        if(baseNode == 0x0 || currentNode == 0x0) {
            this->baseNode = item;
            this->currentNode = item;
        } else {
            item->next = this->baseNode;
            this->baseNode = item;
        }
        _size++;
        changed=true;
        
        dbgLog("base = " << baseNode << " cur = " << currentNode);
        dbgLog("value item " << item->data << " " << baseNode->data);
        
        return cc;
    }
    
    // add items from another list
    void addFrom(LinkedList<T> cc) {
        addAll(cc);
    }
    
    // add items from another list
    void addAll(LinkedList<T> cc) {
        LinkedListIterator<T> it = cc.getIterator();
        while(it.hasNext())
            add(it.next());
    }


    // return item
    T get(long index) {
        freeze();
        //if(index > _size-1) return 0x0;
        return frozen[index];
    }

    // insert at the specified location
    void insert(T data, long location){
        dbgLog("insert");
        if(location >= _size || baseNode == 0x0){
            add(data);
            return;
        }
        
        

        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* cnt = 0x0;
        int i=0;
        LinkedNode<T>* item = new LinkedNode<T>();
        item->data = data;

        while(current != 0x0){
            if(i == location){
                if(location == 0){
                    cnt = baseNode;
                    baseNode = item;
                    item->next = cnt;
                }else{
                    cnt->next = item;
                    item->next = current;
                }
                _size++;
                break;
            }

            cnt = current;
            current = current->next;
            i++;
        }

        changed=true;
    }

    // return the size
    int size() {
        return _size;
    }
    
    int getSize() {
        return _size;
    }
    
    int length() {
        return _size;
    }



    LinkedNode<T>* top() {
        return baseNode;
    }

    T remove(long index) {
        T r;
        dbgLog("remove");
        
        if(index< _size) {
            // erase element at i

            LinkedNode<T>* current = baseNode;
            LinkedNode<T>* prev = 0x0;
            for(long i=0; i<=index; i++) {
                if(current != 0x0) {
                    if (i == index) {
                        if(prev != 0x0) prev->next = current->next;
                        else baseNode = current->next;
                        
                        current->next = 0x0;
                        //current->prev = 0x0;
                        r = current->data;
                        current->data = 0x0;
                        _size--;

                        //delete current;
                        break;
                    }
                } else {
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
        changed=true;
        return r;
    }
    
    T remove(T vd) {
        T r = 0x0;
        dbgLog("remove");

        // erase element with data of v

        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* prev = 0x0;
        for(long i=0; i<_size; i++) {
            if(current != 0x0) {
                if (vd == current->data) {

                    if(prev != 0x0) prev->next = current->next;
                    else baseNode = current->next;
                    current->next = 0x0;
                    
                    r = current->data;
                    current->data = 0x0;
                    _size--;

                    changed = true;
                    break;
                }
            } else {
                break;
            }
            prev = current;
            current = current->next;
        }
        return r;
    }
    
    
    
    // Queue-like functions
    T pop(){
        if(baseNode != 0x0) {
            T dat = baseNode->data;
            baseNode = baseNode->next;
            delete baseNode;
            return dat;
        }else{
            return T();
        }
    }
    
    void pop(T data){
        add(data); // same thing
    }
    
    T front(){
        if(baseNode != 0x0) {
            return baseNode->data;
        }else{
            return T();
        }
    }
    
    bool empty(){
        return baseNode != 0x0;
    }
    
    
    
    
    
    

    // Clears up the list
    void clear() {
        dbgLog("list clear");
        //while(remove(0L) != 0x0);
        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* cnt;
        while(current != 0x0){
            cnt = current->next;
            current->next = 0x0;
            current = cnt;
        }

        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    }

    // slice this list up into parts, output new one
    // start to count, skipping every N
    LinkedList<T> slice(int start, int count, int skip){
        LinkedList<T> newList;
        dbgLog("slice");
        
        freeze();
        for(int i=0; i<count && i<frozenlen; i++){
            newList.add(frozen[start+i*skip]);
        }

        return newList;
    }
    
    int indexOf(T val){
        int i = -1;
        dbgLog("indexof");
        LinkedNode<T> *current = baseNode;
        while(current != 0x0){
            if(current->data == val) return i+1;
            else i++;
            current = current->next;
        }
        
        return -1;
    }
    
    bool contains(T val){
        dbgLog("contains");
        LinkedNode<T> *current = baseNode;
        while(current != 0x0){
            if(current->data == val) return true;
            current = current->next;
        }
        
        return false;
    }

    // retrieve item value?
    T operator [](long i) const {
    	LinkedNode<T>* current = baseNode;
    	int i1=0;
    	while(current != 0x0){
			if(i1 == i){
				return current->data;
			}
			current = current->next;
		}
    }

    T& operator [](long index){
        dbgLog(" list["<<index<<"] = ?");
        LinkedNode<T>* current = baseNode;
        for(long i=0; i<=index; i++) {
            if(current != 0x0) {
                //dbgLog(current << " " << i);
                if (i == index) {
                    return current->data;
                }else{
                    current = current->next;
                }
            }else{
                dbgLog(" list["<<i<<"] doesn't exist.");
            }
        }
        //return frozen[i];
    }

    // Returns the type-size of the data
    int typeSize() {
        return sizeof(T);
    }

    // convert from linkedList to a static list.
    void freeze() {
        LinkedNode<T>* current;
        const int len = _size;
        int i;

        if(changed || _size != frozenlen) {
            dbgLog("freeze-1 " << _size);
            if(frozen != 0x0){
                for(i = 0;i<frozenlen;i++)
                    frozen[i] = T();
                delete [] frozen;
                frozen = 0x0;
            }

            if(_size == 0) {
                changed=false;
                return;
            }

            // copy values in!
            if(baseNode != 0x0) {

                this->frozenlen = _size;
                this->frozen = new T[len];

                current = baseNode;
                for(i=0; i<len; i++) {
                    if(current != 0x0) {
                        //dbgLog("FREEZE: item " << current->data << " @ " << current);
                        frozen[i] = current->data;
                        current = current->next;
                    } else {
                        break;
                    }
                }
                //cout << endl; cout.flush();
            }
            changed=false;
        }else if(_size <= 0){
            this->frozenlen = _size;
        }
    }
    
    // returns an array list with data
    ArrayList<T> getArrayList(){
        const int len = _size;
        ArrayList<T> alist = ArrayList<T>(len);
        
        for(int i = 0;i<len;i++){
            alist[i] = get(i);
        }
        
        return alist;
    }
    
    // list = char{'a','b'};
    LinkedList<T> operator =(T vallist){
        int size_ = SIZEOFA(vallist);
        clear();
        for(int i=0;i<size_;i++){
            add(vallist[i]);
        }
        
        return this;
    }
    
    
    // math operations between two lists of same length
    LLOPERATOR(-);
    LLOPERATOR(+);
    LLOPERATOR(/); // might divide by zero if second list is shorter
    LLOPERATOR(*);
    
    
    
    // assuming that this list is a double!
    // template<double D, LinkedList<D> v);
    /*double dot(LinkedList<double> v){
        double out=0;
        cout << "[LinkedList] dot  sizes: " << size() <<" " << v.size() << endl;
        int msize = Math::max(size(), v.size());
        for(int i=0;i<msize;i++){
            double a = 0, b=0;
            if(i <= size()-1) a=get(i);
            if(i <= v.size()-1) b=v.get(i);
            out += a*b;
        }
        return out;
    }
    
    LinkedList<double> dot(LinkedList<LinkedList<double>> v){
        LinkedList<double> out;
        cout << "[LinkedList] dot<<double>>  sizes: " << size() <<" " << v.size() << " " <<
            v[0].size() << endl;
        
        
        for(int i=0;i<v.size();i++){
            LinkedList<double> v1 = v[i];
            int msize = Math::max(size(), v1.size());
            double x=0;
            for(int j=0;j<msize;j++){
                double a=0, b=0;
                if(i <= size()-1) a=get(i);
                if(i <= v1.size()-1) b=v1[i];
                x += a*b;
            }
            out.add(x);
        }
        
        
        return out;
    }
    
    // dot product, actually just a scalar
    // this list or the other only has 1
    LinkedList<LinkedList<double>> dotT(LinkedList<LinkedList<double>> v){
        LinkedList<LinkedList<double>> out;
        int s = size(), s_ = v.size();
        int s1 = get(0).size(), s2 = v[0].size();
        
        int nsize = s*s_;
        int nsize1 = s1*s2;
        
        int nsizex = Math::max(nsize, nsize1); // 17 by 17 output size
        
        cout << "[LinkedList] <<>>dot<<>>  sizes: " << s <<"x"<< s1 << " " << s_ << "x" << s2 << " => " << nsize << "x" << nsize1 << endl;
        cout.flush();
        // comments assume two-dim lists, 1x17 and 17x1 OR 17x17
        
        if(size() == 1 || v.size() == 1){ // scalar
            // dimsize 1 dot 17 or 17 dot 1
            
            if(size() == 1){
                for(int i=0;i<nsizex;i++){
                    out.add(v[i]*get(0));
                }
            }else{ // v.size() is 1
                for(int i=0;i<nsizex;i++){
                    out.add(get(i)*v[0]); // LinkedList<double> * double
                }
            }
        }else if(size() == v.size()){ // dot each, 1x17 out
            // dimsize 17 dot 17 (just do dot for each)
            LinkedList<double> out1;
            for(int i=0;i<size();i++)
                for(int j=0;j<v.size();j++)
                    out1.add(get(i).dot(v[j]));
            out.add(out1); 
        }else{
            // error, not same size
            cout << "dotT<<>> error not 1xN or NxN" << endl;
        }
        return out;
    }*/
    

    void refreeze(){
        changed=true;
        frozenlen=0;
        freeze();
    }


    // unfreeze will determine if there are any new addresses added
    // First, clears the list, then goes through a brand new list
    void unfreeze(ArrayList<T> listx) {
        clear();
        _size = listx.size();

        for(int i=0; i<_size; i++) {
            add(listx[i]);
        }

        changed=true;
    }
    
    void unfreeze(T* dat, int len) {
        clear();
        _size = len;

        for(int i=0; i<len; i++) {
            add(dat[i]);
        }

        changed=true;
    }
    
    
    // Special iterator
    LinkedListIterator<T> getIterator(){
        return LinkedListIterator<T>(this);
    }
    
    
    // Sorting algorithm, uses QuickSort for efficiency
    //  Valuefunc is a function used to sort list items from low to high
    void sort(int (*valuefunc)(T item)){
        // sorting valuefunction is passed here
        LinkedList<T>* listx = this;
        QuickSortT<T>(listx, valuefunc, 0, size()-1);
    }
    
    
    //template<class T>
    static Math::Matrix* toMatrix(LinkedList<LinkedList<double>> dlist){
        // convert a doubley-list to a matrix
        if(dlist.size() == 0 || dlist[0].size() == 0) return 0x0;
        int s = dlist.size(), s1 = dlist[0].size();
        
        Math::Matrix* m = new Math::Matrix(s, s1);
        
        for(int i=0;i<s;i++){
            for(int j=0;j<s1;j++){
                m->values[j][i] = dlist[i][j];
            }
        }
        
        return m;
    }
    
    
    static LinkedList<LinkedList<double>> fromMatrix(Math::Matrix* matrix){
        // convert a doubley-list to a matrix
        LinkedList<LinkedList<double>> l;
        if(matrix == 0x0 || matrix->values == 0x0) return l;
        
        for(int i=0;i<matrix->columns;i++){
            LinkedList<double> l2;
            for(int j=0;j<matrix->rows;j++){
                l2.add(matrix->values[j][i]);
            }
            l.add(l2);
        }
        
        return l;
    }
    
    void printlist(){
        cout << "linkedlist["<<this<<", "<< sizeof(T) <<"]: ";
        for(long i=0;i<size();i++){
            cout << (T)get(i);
            if(i<size()-1)
                cout << ",";
        }
        cout << endl;
    }
    
    // returns a list based off of this list's type
    // currently supports numeric values and strings
    // NOTE: definitely slower than normal list operations with integers/floats
    /*LinkedList<DynamicType> getDynamicList(){
        LinkedList<DynamicType> listx;
        
        LinkedListIterator<T> it = getIterator();
        
        while(it.hasNext()){
            T val = it.next();
            DynamicType dyn = DynamicType(val); // supports   
            listx.add(dyn); 
        }
        
        return listx;
    }*/
    
    // returns a comma-denoted list ()
    // TODO FIX dependency problems
    /*LinkedList<CharString> stringList(){
        LinkedList<CharString> listvals;
        LinkedListIterator<T> it = getIterator();
        
        while(it.hasNext()){
            T val = it.next();
            
            
            //listvals.add(CharString::getQuotedString(val));
            
        }
        
        return listvals;
    }*/
    
};



#else
template<class T>
class LinkedList;// : public List<T>;

template<class T>
class LinkedListIterator;
#include "LinkedListIterator.hpp"
#endif
