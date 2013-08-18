//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef GPUInstruction_h_
#define GPUInstruction_h_

enum INSTRUCTIONTYPE {I4_ADD, I4_SUB, I4_MUL, I4_DIV, I4_COLLISION, I4_PARTICLE, I4_HASH, I4_RENDER
};
enum INSTRUCTIONPROCESSTYPE {I5_LIST, I5_RENDER};

class GPUInstruction
{
public:
  GPUInstruction(char* pureinstruct); // pure data in
private:
  
  INSTRUCTIONTYPE typecode; // what to do? (Determines variables below)
  
  //// Arithmetic (List) <<<<<<<<< GPU (or cpu if no gpu)
    float number1;
    float number2;
  
  //// Physics (Bulk) <<<<<<<<<< GPU
    // COLLISIONS
    LinkedList<vertex>* mesh1; // RAW data points
    LinkedList<vertex>* mesh2; // RAW data points
    // PARTICLE PROCESSING
    LinkedList<vertex>* vertexMap;
    //LinkedList<charges>* vertexCharges;
  
  //// Hashing (List)
    // CharString* toHash;
    // int hashID;
  
  //// Computing
    // IMAGE PROCESSING
    //BitMap* Image1;
    //int operation;
    
    // RENDERING <<<<<<<<< GPU
    //LinkedList<SceneObject>* objectlist; // render a scene
    //SceneLights* lighting;
    
    // PROGRAM <<<<<<<<< CPU
    // LinkedList<CharString>* executeableCode; // run code under execution time
};

#endif