#ifndef DETECTINJECT_H_
#define DETECTINJECT_H_

// Injection is a bit complex, but usually deals with replacing a known function
//  with one that is being placed in through a dynlib command with a .o .dll or .so file.


// in Linux, reading another program's memory can just be done through /proc/processid/maps
//   but writing requires root permission.

// Types:
//  -- DLL Injection (most common attack vector)
//  -- Process Hollowing  (virus stuffs)
//  -- Atom Bombing (Windows global atom tabal exploit)


// InjectionAttackVector::DLLInject is the normal attack vector
namespace InjectionAttackVector{
    enum Vector {None,
        DLLInject, SOInject, ReadProcMem, AtomBombing};
}

class DetectInjection{

public:
    DetectInjection(); // start
    InjectionAttackVector::Vector DetectInjection(); // Primary function
    
    void (*callback)(InjectionAttackVector::Vector) = 0x0; // dev-suppied callback


private:
    // private functions
    bool DetectDLLInject();
    bool DetectSOInject();
    bool DetectReadProcMem();
    bool DetectAtomBombing();

}


#endif
