#ifndef SECURED_CPU_DATA_H_
#define SECURED_CPU_DATA_H_

// This is a packet that is encrypted.
// Header: 56 94 01 01
// Contents: List of instructions for incoming encrypted data

// Structure of decrypted form:
//      - Type of data (Stream / List, ect)
//      - byte length of data
//      - Listlength (if list type)
//      - pure data

#endif 
