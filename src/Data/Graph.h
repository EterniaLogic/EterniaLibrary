#ifndef Graph_H_
#define Graph_H_

#include "LinkedList.hpp"
#include "HashMap.hpp"
#include "../Data/CharString.h"
#include "../Math/struct/vertex.h"
using namespace Math;

// pre-load library types:
class GVertex;
class GEdge;


class Graph {
        // maintained automatically, may be slow.
        GEdge*** AdjacencyMatrix;

        // hashmap to store verticies for looking up new verticies
        //   Used to quickly find certain verticies by a name.
        HashMap<GVertex>* lookupVerticies;
        HashMap<GEdge>* lookupEdges;

        // LinkedListT to store verticies in linear order.
        LinkedList<GVertex*> verticiesList;
        LinkedList<GEdge*> edgesList;

    public:
        Graph();
        virtual ~Graph();

        GEdge* makeEdge(GVertex* v1, GVertex* v2, int len); // creates an edge if it doesn't exist.

        void createAdjMatrix(); // Computes the adjacency Matrix for each vertex.

        void insertVertex(GVertex* o); // inserts a vertex if it doesn't exist.
        void insertEdge(GEdge* e); // inserts an edge if it doesn't exist.
        void eraseVertex(GVertex* v); // remove all related edges
        void eraseEdge(GEdge* e); // erase an edge
        LinkedList<GVertex*> verticies(); // returns the full list of verticies
        LinkedList<GEdge*> edges(); // returns the full list of edges
};


class GVertex {
    public:
        GVertex();
        virtual ~GVertex();

        // involved edge types, static list of len Elen.
        // note: on a directed graph, only E edges that are beginning with this node will be available.
        LinkedList<GEdge*> incidentEdges;

        int label;

        LinkedList<GVertex*> vertexList; // structure that stores this.

        vertex location;
};

class GEdge {
    public:
        GEdge();
        GEdge(GVertex *a_, GVertex *b_, int c);
        virtual ~GEdge();

        // pair
        GVertex *a, *b;

        // data, such as distance between pair.
        // applications are casted with (type*)
        int data;


        bool isAdjacentTo(GVertex* v);
        GVertex* opposite(GVertex* v);


        LinkedList<GEdge*> edgeList; // structure that stores this.
};


#endif
