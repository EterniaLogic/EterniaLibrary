#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

// The Serializable class allows a class to specify the information coming from the output.

class Serializable{
public:
    Serializable(){}
    ~Serializable(){}
    
    virtual char* Serialize(); // convert value to char*
};

#endif
