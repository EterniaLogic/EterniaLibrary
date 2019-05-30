#include "Composite.h"

namespace Chemistry{
Composite::Composite() {
}

Composite::Composite(MatterPhase::PHASE _phase, double _density, double _mass, const std::vector<Atom*> _atoms){
    phase=_phase;
    density=_density;
    totalMass=_mass;
    
    for(int i=0;i<_atoms.size();i++){
        atoms.add(_atoms[i]);
    }
}

Composite::Composite(CharString cval){
    //cout << "tt2 " << cval.get() << endl;
}

Composite::~Composite() {
}

CharString Composite::getString(){
        CharString s;
        s += "{";

        s += (long)phase;
        s += "|";
        s += density;
        s += "|";
        s += totalMass;
        s += "|";
        
        s += "{";
        atoms.freeze();
        LinkedList<AtomBond*> bondlist;
        for(long i=0;i<atoms.frozenlen;i++){
            Atom *a = atoms.frozen[i];
            s += i;
            s += "\\";
            s += a->protons;
            
            
            
            a->bonds.freeze();
            
            for(long j=0;j<a->bonds.frozenlen;j++){
                AtomBond *b = a->bonds.frozen[j];
                
                // make sure that it doesn't exist
                bool e = false;
                bondlist.freeze();
                for(long k=0;k<bondlist.frozenlen;k++){
                    if(bondlist.frozen[k] == b) // only compare addresses
                        e = true;
                }
                
                if(!e){
                    bondlist.add(b);
                }
            }
            
            if(i < atoms.frozenlen-1) 
                s += "|";
        }
        s += "},{";
        
        
        bondlist.freeze();
        for(long j=0;j<bondlist.frozenlen;j++){
            AtomBond *b = bondlist.frozen[j];
            s += atoms.indexOf(b->a);
            s += ",";
            s += b->strength;
            s += ",";
            s += b->length;
            s += ",";
            s += atoms.indexOf(b->b);
            
            if(j < bondlist.frozenlen-1) 
                s += "'";
        }
        
        s += "}";
        s += "}";
        
        return s;
}


namespace CompositeGas{
    void printCompositeGasses(){
        
        Atom *co2_c = elements::Carbon.clone();
        Atom *co2_o1 = elements::Oxygen.clone();
        Atom *co2_o2 = elements::Oxygen.clone();
        Atom *o2_o1 = elements::Oxygen.clone();
        Atom *o2_o2 = elements::Oxygen.clone();
        const std::vector<Atom*> co2_alist = {co2_c, co2_o1, co2_o2};
        const std::vector<Atom*> o2_alist = {o2_o1, o2_o2};
        AtomBond _co2bond1 = {749, 116.3, co2_c, co2_o1};
        AtomBond _co2bond2 = {749, 116.3, co2_c, co2_o2};
        AtomBond _o2bond = {498, 121, o2_o1, o2_o2};
        
        // Carbon Dioxide
        co2_c->bonds.clear();
        co2_o1->bonds.clear();
        co2_o2->bonds.clear();
        co2_c->bonds.add(&_co2bond1);
        co2_c->bonds.add(&_co2bond2);
        co2_o1->bonds.add(&_co2bond1);
        co2_o2->bonds.add(&_co2bond2);
        
        // Oxygen
        o2_o1->bonds.clear();
        o2_o2->bonds.clear();
        o2_o1->bonds.add(&_o2bond);
        o2_o2->bonds.add(&_o2bond);
        
        Composite* co2 = new Composite(MatterPhase::gas, 1.98, 44.01, co2_alist);
        Composite* o2 = new Composite(MatterPhase::gas, 1.429, 31.999, o2_alist);
        
        cout << co2->getString() << endl;
        cout << o2->getString() << endl;
        
//        _initcbonds = true;
    }
}
}
