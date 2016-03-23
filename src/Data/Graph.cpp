//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Graph.h"

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif


//////////////////////////////////////////////////
//////////////////// GRAPH! //////////////////////
//////////////////////////////////////////////////


Graph::Graph(){
    // lookup verticies to store vertexes in a fast map.
    lookupVerticies = new HashMap<Vertex>(20000);
    lookupEdges = new HashMap<Edge>(20000);

    // LinkedListT to store verticies in linear order.
    verticiesList = new LinkedListT();
    edgesList = new LinkedListT();

    // leave undeclared null so we can use it later
    //  on.
    AdjacencyMatrix = 0x0;
}

// aaand take them all down! >:D
Graph::~Graph(){
  lookupEdges->~HashMap();
  lookupVerticies->~HashMap();
  verticiesList->~LinkedListT();
  edgesList->~LinkedListT();
}

// creates a vertex if it doesn't exist.
Vertex* Graph::makeVertex(CharString* _name){
    // lookup vertex to see if it exists in the HashMap.
    Vertex* newVertex = lookupVerticies->get(_name);
    if(newVertex == 0x0){
        newVertex = new Vertex(_name); // if not, create one!
    }
    return newVertex;
}

// creates an edge if it doesn't exist.
Edge* Graph::makeEdge(Vertex* v1, Vertex* v2, int len){
    // combine names together.
    CharString* cnames = v1->name->clone();
    char* c = new char();
    strcpy(c, "||");

    cnames->concata(c,2);
    cnames->concata(v2->name);

    // lookup edge to see if it exists in the HashMap.
    Edge* newEdge = lookupEdges->get(cnames);
    if(newEdge == 0x0){
        newEdge = new Edge(v1,v2,len); // if not, create one!
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
    AdjacencyMatrix = new Edge**[L+1];
    for(int i=0;i<=L;i++){
        // write matrix sub-base
        AdjacencyMatrix[i] = new Edge*[L+1];
        for(int j=0;j<=L;j++){
            // NULLify sub-base's data values.
            AdjacencyMatrix[i][j] = 0x0;
        }
    }

    // form adjacency matrix
    // loop through every vertex and use their lists of connected items to form a matrix.
    // Note: each item in the list has it's own number.

    // freezes the vertex list for very fast traversal.
    // frozen list gets converted to an array list.
    verticiesList->freeze();
    // loop through all of the verticies.
    for(int i=0;i<verticiesList->size();i++){
        Vertex* v = (Vertex*)verticiesList->frozen[i];

        if(v != 0x0){
            //v->incidentEdges->freeze();
            // loop through the incident edge list.
            for(int j=0;j<v->incidentEdges->size();j++){
                //Edge* e = (Edge*)v->incidentEdges->frozen[j];
                Edge* e = (Edge*)v->incidentEdges->get(j);
                if(e != 0x0){
                    Vertex* end = e->b;
                    // determine the index position of the endpoint.
                    int endpoint = -1;
                    for(int z=0;z<verticiesList->size();z++){
                         Vertex* v = (Vertex*)verticiesList->frozen[z];
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
          Vertex* v = (Vertex*)verticiesList->frozen[i];
          if(v != 0x0){
            cout << v->name->get() << "   ";
          }else{
            cout << "    ";
          }
    }
    cout << endl;

     for(int i=0;i<=L;i++){
         for(int j=0;j<=L;j++){
            Edge* e = AdjacencyMatrix[j][i];
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

// insert vertex
void Graph::insertVertex(Vertex* o){
    // insert vertex (if it doesn't exist)
    if(lookupVerticies->get(o->name) == 0x0){
        // it doesn't exist!
        // add to verticies HashMap.
        lookupVerticies->add(o->name, o);
        // add to verticies LinkedList.
        verticiesList->add(o);
    }
}

// insert the edge
void Graph::insertEdge(Edge* e){
    // connect the names together.
    CharString* cnames = e->a->name->clone();
    char c[3];
    strcpy(c, "||");
    cnames->concata(c,2);
    cnames->concata(e->b->name);
    // insert edge
    if(lookupEdges->get(cnames) == 0x0){
        // it doesn't exist!
        // add to edges HashMap.
        lookupEdges->add(cnames,e);
        // add to edges LinkedList.
        edgesList->add(e);
    }
}

// remove all related edges
void Graph::eraseVertex(Vertex* v){

}

// erase all related verticies
void Graph::eraseEdge(Edge* e){

}

// return the verticies list.
LinkedListT* Graph::verticies(){
    return verticiesList;
}

// return the edges list.
LinkedListT* Graph::edges(){
    return edgesList;
}



//////////////////////////////////////////////////
//////////////// EDGES & Verticies ///////////////
//////////////////////////////////////////////////

// initialize vertex.
Vertex::Vertex(){ incidentEdges = new LinkedListT(); label=0; name=0x0; data=0x0; graph=0x0; distance=0; }
// initialize vertex with a name.
Vertex::Vertex(CharString* _name){ incidentEdges = new LinkedListT(); graph=0x0; label=0; name=_name; data=0x0;distance=0;}

Vertex::~Vertex(){
  incidentEdges->~LinkedListT();
  vertexList->~LinkedListT();
  delete data;
  delete name;
}

Vertex* Edge::opposite(Vertex* v){
    if(a == v){
        return b;
    }else if(b == v){
        return a;
    }else{
        return 0x0;
    }
}


// initialize edge.
Edge::Edge(){a=b=0X0; data=0;}

// initialize edge with two verticies and a depth length.
Edge::Edge(Vertex* A, Vertex* B, int LEN){
    // set edge structure.
    a=A;
    b=B;

    data=LEN;

    // add this edge.
    a->incidentEdges->add(this);
    b->incidentEdges->add(this);
}

Edge::~Edge(){
    a->~Vertex();
    b->~Vertex();
    edgeList->~LinkedListT();
}
