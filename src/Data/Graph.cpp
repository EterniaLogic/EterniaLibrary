

#include "Graph.h"

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif


//////////////////////////////////////////////////
//////////////////// GRAPH! //////////////////////
//////////////////////////////////////////////////

/*
Graph::Graph(){
    // lookup verticies to store GVertexes in a fast map.
    //lookupVerticies = new HashMap<GVertex>(20000);
    //lookupEdges = new HashMap<GEdge>(20000);

    // LinkedListT to store verticies in linear order.
    //verticiesList = new LinkedListT();
    //edgesList = new LinkedListT();

    // leave undeclared null so we can use it later
    //  on.
    AdjacencyMatrix = 0x0;
}

// aaand take them all down! >:D
Graph::~Graph(){
  / *lookupEdges->~HashMap();
  lookupVerticies->~HashMap();
  verticiesList->~LinkedListT();
  edgesList->~LinkedListT();
}

// creates an GEdge if it doesn't exist.
GEdge* Graph::makeEdge(GVertex* v1, GVertex* v2, int len){
    // combine names together.
    CharString* cnames = v1->name->clone();
    char* c = new char();
    strcpy(c, "||");

    cnames->concata(c,2);
    cnames->concata(v2->name);

    // lookup GEdge to see if it exists in the HashMap.
    GEdge* newEdge = lookupEdges->get(cnames);
    if(newEdge == 0x0){
        newEdge = new GEdge(v1,v2,len); // if not, create one!
    }
    return newEdge;
}

// creates the adjacency matrix.
void Graph::createAdjMatrix(){
    // initialize matrix
    const int L = verticiesList->size();
    // make void** matrix using int* as base.
    //  note: int* has a length of 1
    // This allows us to use very small amounts
    //    of memory.

    // also note that we are using triple *.
    //    this means that we can point to ANYTHING.
    // write matrix base
    AdjacencyMatrix = new GEdge**[L+1];
    for(int i=0;i<=L;i++){
        // write matrix sub-base
        AdjacencyMatrix[i] = new GEdge*[L+1];
        for(int j=0;j<=L;j++){
            // NULLify sub-base's data values.
            AdjacencyMatrix[i][j] = 0x0;
        }
    }

    // form adjacency matrix
    // loop through every GVertex and use their lists of connected items to form a matrix.
    // Note: each item in the list has it's own number.

    // freezes the GVertex list for very fast traversal.
    // frozen list gets converted to an array list.
    verticiesList->freeze();
    // loop through all of the verticies.
    for(int i=0;i<verticiesList->size();i++){
        GVertex* v = (GVertex*)verticiesList->frozen[i];

        if(v != 0x0){
            //v->incidentEdges->freeze();
            // loop through the incident GEdge list.
            for(int j=0;j<v->incidentEdges->size();j++){
                //GEdge* e = (GEdge*)v->incidentEdges->frozen[j];
                GEdge* e = (GEdge*)v->incidentEdges->get(j);
                if(e != 0x0){
                    GVertex* end = e->b;
                    // determine the index position of the endpoint.
                    int endpoint = -1;
                    for(int z=0;z<verticiesList->size();z++){
                         GVertex* v = (GVertex*)verticiesList->frozen[z];
                         if(v == end){
                            endpoint = z;
                            z = 999999;
                         }
                    }

                    // assign incidence points on adjacency matrix.
                    int x = i+1;
                    int y = endpoint+1;
                    AdjacencyMatrix[x][y] = e;
                    AdjacencyMatrix[y][x] = e;
                }
            }
        }
    }


#ifdef DEBUGx
    // print-out of this adjacency graph.
    // DEBUG!
    cout << "    ";
    for(int i=0;i<L;i++){
          GVertex* v = (GVertex*)verticiesList->frozen[i];
          if(v != 0x0){
            cout << v->name->get() << "   ";
          }else{
            cout << "    ";
          }
    }
    cout << endl;

     for(int i=0;i<=L;i++){
         for(int j=0;j<=L;j++){
            GEdge* e = AdjacencyMatrix[j][i];
            if(e != 0x0){
                cout << e->a->name->get();
                cout << e->b->name->get();
                cout << (e->data) << " ";
            }else{
                cout << "--- ";
            }
         }
         cout << endl;
     }
#endif
}

// insert GVertex
void Graph::insertVertex(GVertex* o){
    // insert GVertex (if it doesn't exist)
    if(lookupVerticies->get(o->name) == 0x0){
        // it doesn't exist!
        // add to verticies HashMap.
        lookupVerticies->add(o->name, o);
        // add to verticies LinkedList.
        verticiesList->add(o);
    }
}

// insert the GEdge
/ *void Graph::insertEdge(GEdge* e){
    // connect the names together.
    CharString* cnames = e->a->name->clone();
    char c[3];
    strcpy(c, "||");
    cnames->concata(c,2);
    cnames->concata(e->b->name);
    // insert GEdge
    if(lookupEdges->get(cnames) == 0x0){
        // it doesn't exist!
        // add to GEdges HashMap.
        lookupEdges->add(cnames,e);
        // add to GEdges LinkedList.
        edgesList->add(e);
    }
}

// remove all related GEdges
void Graph::eraseVertex(GVertex* v){

}

// erase all related verticies
void Graph::eraseEdge(GEdge* e){

}

// return the verticies list.
LinkedListT* Graph::verticies(){
    return verticiesList;
}

// return the GEdges list.
LinkedListT* Graph::GEdges(){
    return edgesList;
}



//////////////////////////////////////////////////
//////////////// GEdgeS & Verticies ///////////////
//////////////////////////////////////////////////

// initialize GVertex.
GVertex::GVertex(){ incidentEdges = new LinkedListT(); label=0; name=0x0; data=0x0; graph=0x0; location = new GVertex(); }
// initialize GVertex with a name.
GVertex::GVertex(CharString* _name){ incidentEdges = new LinkedListT(); graph=0x0; label=0; name=_name; data=0x0;distance=0;}

GVertex::~GVertex(){
  incidentEdges->~LinkedListT();
  vertexList->~LinkedListT();
  //delete data;
  //delete name;
}

GVertex* GEdge::opposite(GVertex* v){
    if(a == v){
        return b;
    }else if(b == v){
        return a;
    }else{
        return 0x0;
    }
}


// initialize GEdge.
GEdge::GEdge(){a=b=0X0; data=0;}


// initialize GEdge with two verticies and a depth length.
GEdge::GEdge(GVertex* A, GVertex* B, int LEN){
    // set GEdge structure.
    a=A;
    b=B;

    data=LEN;

    // add this GEdge.
    a->incidentEdges->add(this);
    b->incidentEdges->add(this);
}

GEdge::~GEdge(){
    a->~GVertex();
    b->~GVertex();
    edgeList->~LinkedListT();
}*/
