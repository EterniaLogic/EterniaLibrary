//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef DijkstraPATH_H_
#define DijkstraSPATH_H_

#ifndef Graph_H_
#include "../../Data/Graph.h"
#else
class Graph;
class Vertex;
class LinkedListT;
#endif

#include "../../Data/PriorityQueue.h"
#include "../../Data/LinkedListT.h"

// DESC: Dijkstra's algorithm to find shortest distance from source to destination on a graph.
// INPUT: Graph to expand on, Vertex to represent as the source.
// OUTPUT: Linked list of the path
LinkedListT* DijkstraDistances(Graph* graph, Vertex* source) {
    // form a cloud to every point.
    // Store this cloud in the PQueue.
    LinkedListT* verticies = graph->verticies();
    PriorityQueue* pq = new PriorityQueue();

    // loop through verticies
    for(int i=0; i<verticies->size(); i++) {
        Vertex* vv = (Vertex*)verticies->get(i);
        if(vv == source) {
            vv->distance = 0; // set vertex to zero if it is the source vertex.
        } else {
            vv->distance = 999999999; // set verticies to infinity to represent an unreachable location.
        }

        // insert into queue.
        pq->insert(vv->distance,vv);
    }

    // empty out the set
    while(!pq->empty()) {
        // remove the minimum distance from the set. (usually source vertex on start)
        Vertex* v = (Vertex*)pq->removeMin();
        LinkedListT* vt = v->incidentEdges;

        // loop through incident Edges
        for(int i=0; i<vt->size(); i++) {
            Edge* e = (Edge*)vt->get(i);
            Vertex* v2 = e->opposite(v);
            int r = v->distance + e->data;

            // if the total range is less than v2's distance, then set it.
            if(r < v2->distance) {
                v2->distance = r;
                pq->replaceKey(pq->top(),(void*)v2,r);
            }
        }
    }
}



#endif

/*
Algorithm DijkstraDistances(G, s)
    Q←new heap-based priority queue
    for all v∈G.vertices()
        if v=s then v.setDistance(0)
        else v.setDistance(∞)
        l←Q.insert(v.getDistance(),v)
        v.setEntry(l)
    while¬Q.empty()
        l←Q.removeMin()
        u←l.getValue()
        for all e ∈ u.incidentEdges()
            z←e.opposite(u)
            r←u.getDistance()+e.weight()
            ifr<z.getDistance()
                z.setDistance(r)
                Q.replaceKey(z.getEntry(), r) */
