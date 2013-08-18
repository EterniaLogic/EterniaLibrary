//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Graph_H_
#define Graph_H_

#include "LinkedListT.h"
#include "HashMap.hpp"

// pre-load library types:
class Vertex;
class Edge;
class CharString;


class Graph
{
    // maintained automatically, may be slow.
    Edge*** AdjacencyMatrix; 
    
    // hashmap to store verticies for looking up new verticies
    // 	 Used to quickly find certain verticies by a name.
    HashMap<Vertex>* lookupVerticies;
    HashMap<Edge>* lookupEdges;
    
    // LinkedListT to store verticies in linear order.
    LinkedListT* verticiesList;
    LinkedListT* edgesList;
    
public:
    Graph();
    virtual ~Graph();
    
    Vertex* makeVertex(CharString* _name); // initialize a vertex if it doesn't exist.
    Edge* makeEdge(Vertex* v1, Vertex* v2, int len); // creates an edge if it doesn't exist.
    
    void createAdjMatrix(); // Computes the adjacency Matrix for each vertex.
    
    void insertVertex(Vertex* o); // inserts a vertex if it doesn't exist.
    void insertEdge(Edge* e); // inserts an edge if it doesn't exist.
    void eraseVertex(Vertex* v); // remove all related edges
    void eraseEdge(Edge* e); // erase an edge
    LinkedListT* verticies(); // returns the full list of verticies
    LinkedListT* edges(); // returns the full list of edges
};


class Vertex
{
public:
    Vertex();
    Vertex(CharString* _name);
    virtual ~Vertex();
    
    // involved edge types, static list of len Elen.
    // note: on a directed graph, only E edges that are beginning with this node will be available.
    LinkedListT* incidentEdges;
    
    int label;
    
    // internal storage
    CharString* name;
    void* data;
    Graph *graph;
    
    LinkedListT* vertexList; // structure that stores this.
    
    int distance;
};

class Edge
{
public:
    Edge();
    Edge(Vertex *a_, Vertex *b_, int c);
    virtual ~Edge();
    
    // pair
    Vertex *a, *b;
    
    // data, such as distance between pair.
    // applications are casted with (type*)
    int data;
    
    // refer to the graph.
    Graph *graph;
    
    
    bool isAdjacentTo(Vertex* v);
    Vertex* opposite(Vertex* v);
    
    
    LinkedListT* edgeList; // structure that stores this.
};


#endif
