//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "P2PCPUServer.h"

P2PCPUServer::P2PCPUServer()
{
}

P2PCPUServer::~P2PCPUServer()
{
}

/*
 * CPU Servers are probably one of the best features of TRO.
 * Several main features can easily be listed:
 * 
 * :: Stop relying on your main servers! CPU Servers can help relieve offline player simulation with fast management
 * :: CPU Servers contact directly with Data servers to act as a hub to relieve the main servers of having to process sim data.
 * :: CPU servers can simulate more then raw data, they can also simulate WIRE, Computers and possibly even GridCompute.
 */