//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef VECTORSPACE_H_
#define VECTORSPACE_H_

#ifndef MATRIX_H_
    #include "Matrix.h"
#else
    class Matrix;
#endif

#include "vertex.h"

// defines a special property of the vertex space, usually to help declare a "Special" Vector Space.
// usage: new VectorSpace(VS_Rn);
// NOTE: Unless you use N_Dimensions, VS_Rn will work for an infinite number.
enum VECSPACE_PROPERTY {VS_0, VS_R1, VS_R2, VS_R3, VS_Rn};




// a vertex space is basically a Matrix of the resultant of 2 vertexs.

class VectorSpace : public Matrix {
        int dim;
    public:
        VectorSpace();
        VectorSpace(double** matrix, int m, int n);
        VectorSpace(VECSPACE_PROPERTY _property);
        VectorSpace(VECSPACE_PROPERTY _property, int N_Dimensions); // define VS_Rn's exact number of dimensions.

        virtual VectorSpace* clone();

        void addVector(vertex* v); // adds vertex to rows.

        ////

        bool hasInfiniteDimensions(); // has infinite dimensions (or Rn)

        double innerProduct(VectorSpace* V); // inner dot product. <u,v> = U(1,1)*V(1,1) + U(2,1)*V(2,1) + ... U(n)*V(n)

        VectorSpace* nullity(); // returns the N(A), or nullity space. Should return B = span(A)
        int dimension(); // returns the dimension of the vertex space.
        bool isIndependent(); // returns true if the vertex space is dependent of equations.
        bool isBasis(VectorSpace* W); // returns whether the VectorSpace is a Basis of Rn
        bool isSubSpace(VectorSpace* V); // returns whether this is a subspace of V
        bool spans(VectorSpace* W); // returns whether this spans W

        VECSPACE_PROPERTY property;
};

#endif /*VECTORSPACE_H_*/
