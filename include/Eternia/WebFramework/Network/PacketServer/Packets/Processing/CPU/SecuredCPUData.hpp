//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SECURED_CPU_DATA_H_
#define SECURED_CPU_DATA_H_

#include "../../Packet.hpp"

// This is a packet that is encrypted.
// Header: 56 94 01 01
// Contents: List of instructions for incoming encrypted data

// Structure of decrypted form:
//      - Type of data (Stream / List, ect)
//      - byte length of data
//      - Listlength (if list type)
//      - pure data

#endif
