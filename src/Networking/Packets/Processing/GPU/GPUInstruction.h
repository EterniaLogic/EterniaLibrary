#ifndef GPUInstruction_h_
#define GPUInstruction_h_

enum INSTRUCTIONTYPE {I4_ADD, I4_SUB, I4_MUL, I4_DIV};
enum INSTRUCTIONPROCESSTYPE {I5_LIST, I5_RENDER}

class GPUInstruction
{
public:
  GPUInstruction(char* pureinstruct); // pure data in
private:
  
  INSTRUCTIONTYPE typecode; // what to do? (Determines variables below)
  
  //// Arithmetic (List)
    float number1;
    float number2;
  
  //// Physics (Bulk)
    // COLLISIONS
    LinkedList<vertex>* mesh1; // RAW data points
    LinkedList<vertex>* mesh2; // RAW data points
    // PARTICLE PROCESSING
    LinkedList<vertex>* vertexMap;
    LinkedList<charges>* vertexCharges;
  
  //// Hashing (List)
    // CharString* toHash;
    // int hashID;
  
  //// Computing
    // IMAGE PROCESSING
    //BitMap* Image1;
    //int operation;
    
    // RENDERING
    //LinkedList<SceneObject>* objectlist; // render a scene
    //SceneLights* lighting;
    
    // PROGRAM
    // LinkedList<CharString>* executeableCode; // run code under execution time
};

#endif