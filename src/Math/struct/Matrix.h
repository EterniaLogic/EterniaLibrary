#ifndef MATRIX_H_
#define MATRIX_H_



#include <cstdlib>

namespace Math {
    class Matrix {
    public:
        Matrix();
        Matrix(double **values, int columns, int rows);
        Matrix(int columns, int rows);
        virtual ~Matrix();

        virtual Matrix* clone();

        void set(double **values, int columns, int rows); // set a double matrix with m columns and n rows.
        void multiply(Matrix* matrix); // multiplies with another matrix
        void add(Matrix* matrix); // add another matrix to this one.
        void scale(double scalar); // multiply all values in matrix by value.

        Matrix* dot(Matrix* m); // dot product of another matrix (see https://docs.scipy.org/doc/numpy-1.15.0/reference/generated/numpy.dot.html)


        double solveSquareDeterminant(double a, double b, double c, double d); // solve a 2x2 determinant
        double getDeterminant(int n, int m); // do inter-sequential determinants at location m,n.
        int rank(); // number of non-zero rows after echeolon form.
    
    
    
    
        void transpose(); // transpose the matrix A T
        double adjMinor(int x, int y); // find the minor (find inner keys)
        Matrix* adjutant(); // find the adjutant (obtained from minor of all values)
        double determinant(); // finds the determinant by using minor(n,0) on top row.
        void inverse(); // invert this matrix. (requires determinants)


        // Forming the echeolon form using gaussian row
        void rowSolve(double scalar, int row, int toRow); // solves a single row using a scaled row.
        void colSolve(double scalar, int col, int toCool); // solves a single column using a scaled column.

        void lower(); // linearly solves the lower quadrant
        void upper(); // linearly solves the upper quadrant

        void echeolonForm(); // changes to Echeolon form, in which rows linearly increase for each column.





        bool isSquare(); // _m == _n

        // output
        char* toOutput(); // converts to a string for output into console. (or w/e)
        //VectorSpace* toVectorSpace(); // vertex spaces are based off of matricies.



        // should be private?
        double **values;
        int columns, rows; // columns, rows

        // rows, columns swapped from initializer
        static double** createMatrixContainer(const int rows, const int columns);
        static void testErrCorr(Matrix* matrix);
    };
}

#else
namespace Math{
    class Matrix;
}
#endif /*MATRIX_H_*/
