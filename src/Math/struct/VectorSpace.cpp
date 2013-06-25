//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "VectorSpace.h"

VectorSpace::VectorSpace(){}
VectorSpace::VectorSpace(double **values_, int _m, int _n) { set(values_,_m,_n); }

VectorSpace::VectorSpace(VECSPACE_PROPERTY _property){
    property = _property;
}

// define VS_Rn's exact number of dimensions.
VectorSpace::VectorSpace(VECSPACE_PROPERTY _property, int N_Dimensions){
    property = _property;
    dim = N_Dimensions;
}

VectorSpace* VectorSpace::clone(){
    VectorSpace* two = new VectorSpace();
    
    
    // re-create vector set.
    const int x = columns;
    const int y = rows;
    double** vset = new double*[y];
    for(int i=0;i<y;i++){
        double* vset2 = new double[x];
        vset[i] = vset2;
        
        // fill in.
        for(int k=0;k<y;k++){
            vset2[k] = values[k][i];
        }
    }
    
    two->set(vset,columns,rows);
}


// adds vector to rows.
void addVector(vector* v){
    // add as another row.
    // modify main values function.
    
}



//////////////

// has infinite dimensions?
bool VectorSpace::hasInfiniteDimensions() {
    if(dim == 0 && property == VS_Rn) return true;
    return false;
}

// <A,A>
// gets the general dot product between two vector spaces.
double VectorSpace::innerProduct(VectorSpace* V){
    // dot product of all items
    //  [ Ax * Bx ]
    //  [ Ay * By ]
    //  [ Az * Bz ]
    double result = 0;
    
    if(columns != V->columns || rows != V->rows) return 0;
    
    for(int j=0;j<columns;j++){
    	for(int i=0;i<rows;i++){
            // multiply and sum
            result = values[j][i] * V->values[j][i];
        }
    }
    
    return result;
}

// ||a|| = sqrt(<A,A>)
// returns inner product space of this Vector Space
// returns 0x0 if not possible.
/*InnerProductSpace* VectorSpace::innerProductSpace(){
    // sqrt(innerProduct())
    // <<a0, a1, a2>,<b0, b1, b2>> = a0*b0 + a1*b1 + a2*b2
    if(hasInfiniteDimensions()){
        return 0x0; // cannot find null space if infinite dimensions.
    }
}*/

// returns whether the VectorSpace is a Basis of Rn
bool VectorSpace::isBasis(VectorSpace* W){
    if(hasInfiniteDimensions() && !W->hasInfiniteDimensions()){
        return false;
    }
    
    // V spans W and this is Independent?
    if(spans(W) && isIndependent()){
        return true;
    }
    
    return false;
}

// returns the N(A), or nullity space. Should return B = span(A)
// returns 0x0 if not possible.
VectorSpace* VectorSpace::nullity(){
    // cannot find null space if infinite dimensions.
    if(hasInfiniteDimensions()) return 0x0; 
    VectorSpace* ret = new VectorSpace();
    // Ax = 0
}

// returns the dimension of the vector space.
// returns -1 if impossible to find.
int VectorSpace::dimension(){
    if(hasInfiniteDimensions()) return -1;
}

// returns the rank, or number of rows that are non-zero.
// returns -1 if impossible to find.
int VectorSpace::rank(){
    if(hasInfiniteDimensions()) return -1;
}

// returns true if the vector space is dependent of equations.
bool VectorSpace::isIndependent(){
    // Rn is never dependent because no number is recurring.
    if(hasInfiniteDimensions()) return true;
}

// does this (V) spans W? {or V spans W?}
bool VectorSpace::spans(VectorSpace* W){
    // if this is in R3 and W is also in R3, then it is true.
    // else if this is an infinite expansion (All real numbers in R1->3 or n), then false.
    if(property == W->property) return true; 
    else if(property == VS_Rn || property == VS_R1 || property == VS_R2 || property == VS_R3) return false;
    
    // we cannot compare to an infinite-dimensional set.
    if(W->hasInfiniteDimensions()) return false;
    
    // determined by the relationship of: (If W is R3)
    //      1 0 0
    //      0 1 0
    //      0 0 1
    // if V is:
    //      99 0 0
    //      0 89 0
    //      0 0 45
    // then it spans W.
    
    VectorSpace* vs = clone();
    vs->echeolonForm(); // converts to echeolon form. (Simplest form of this matrix)
    
    // I believe that this means that V spans W means that there are 0s in V, where there are 0s are in W.
    if(isIndependent()){
        // matrix dimension (n) must match W's size.
        
        // is in R1 or in 0 space
        if(W->property == VS_R1 || W->property == VS_0){ // (x) or (0)
            if(columns == 1){
            
            }else return false;
        }else if(W->property == VS_R2){ // in R2? (x,y)
            if(columns == 1){
            
            }else return false;
        }else if(W->property == VS_R3){ // in R3? (x,y,z)
            if(columns == 1){
            
            }else return false;
        }else if(W->property == VS_Rn){ // in Rn? (x,y,z,w, ... n)
            // must match dim  
            if(columns == dim){
                
            }else return false;          
        }
    }else{
        
    }
}


