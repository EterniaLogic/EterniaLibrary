#ifndef CYCLICLIST_H_
#define CYCLICLIST_H_

// Cyclic lists are normally used to do averages.
template<class T>
class CyclicList{
private:
    T* list; // list
    int location, num;
public:
    CyclicList(int num){
        list = (T*)calloc(sizeof(T),num);
        location = 0;
        this->num = num;
    }
    ~CyclicList(){}
    
    void add(T item){
        list[location] = item;
        
        // handle cyclic motion
        location = location+1>=num ? 0 : location+1;
    }
    
    // use ONLY if you are using a number...
    // if you aren't using a number for the template, this may fail during comp.
    T getAverage(){
        T avg=0;
        
        for(int i=0;i<num;i++){
            avg += list[i];
        }
        
        avg /= num;
        
        return avg;
    }
};

#endif
