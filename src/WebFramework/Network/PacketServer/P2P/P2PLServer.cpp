//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "P2PLServer.h"

P2PLServer::P2PLServer() {
}

P2PLServer::~P2PLServer() {
}

/*
 * :: L servers act in more then one way.
 * First and foremost, they act as GameServers.
 * Second, they help distribute information across multiple nodes. (over 1 million players if so required)
 * Third, they help connect players to other players. (X-L Server comms)
 * Fourth, they help redistribute server load throughout the massive galaxy. There is truly no one direct server.
 * Fifth, hell, they're awesome!
 */
