//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Matrix.h"

#include <iostream>

using namespace std;

Matrix::Matrix(){ values=0x0; columns=0;rows=0; }
Matrix::Matrix(double **values_, int _m, int _n) { set(values_,_m,_n); }

Matrix::~Matrix(){
    for(int i=0;i<rows;i++){
        delete values[i];
    }
    delete values;
}

// clone the matrix so we can use it again without modifying this matrix.
Matrix* Matrix::clone(){
    Matrix* two = new Matrix();
    
    
    // re-create vertex set.
    const int x = columns;
    const int y = rows;
    double** vset = new double*[y];
    for(int i=0;i<y;i++){
        double* vset2 = new double[x];
        vset[i] = vset2;
        
        // fill in.
        for(int k=0;k<x;k++){
            vset2[k] = values[k][i];
        }
    }
    
    two->set(vset,columns,rows);
	return two;
}

double** Matrix::createMatrixContainer(const int x, const int y){
    // initialize x-wide container.
    double** newset =  (double**)calloc(x+1,sizeof(double**));
    // initialize all of the arrays.
    for(int i=0; i<x; i++) {
        newset[i] = (double*)calloc(y+1,sizeof(double*));
    }
    
    return newset;
}

// set a double matrix with m columns and n rows.
void Matrix::set(double **values_, int _m, int _n){
    values = values_;
    columns = _m;
    rows = _n;
}

/////////////////////////////////////////
////////// BASIC OPERATIONS /////////////
/////////////////////////////////////////


// multiplies with another matrix
void Matrix::multiply(Matrix* matrix){
    // values and matrix->values
    // do initial length and height tests:
    if(columns == matrix->rows){ // n m x n m => mxn w/ size nxm
        double** newMatrix = createMatrixContainer(rows, matrix->columns);
        Matrix* mm = new Matrix(newMatrix,rows, matrix->columns);
        // multiply 
        // select row i and dot-product it with column j @ matrix->m
        for(int i=0;i<rows;i++){
            for(int j=0;j<matrix->columns;j++){
                int result = 0;
                // cross-product this row with this column.
                // loop through this row. (value should be the same with the column on matrix)
                for(int k=0;k<columns;k++){
                    result += values[i][k] * matrix->values[j][k];
                }
                
                // store result into new matrix at row i, column j
                newMatrix[i][j] = result;
            }
        }
        
        values = newMatrix;
        columns = rows;
        rows = matrix->columns;
        mm->~Matrix();
    }
}

// adds with another matrix. Changes values* size.
void Matrix::add(Matrix* matrix){
    // get maximum sizes between the two.
    int sizex = (matrix->columns > columns ? matrix->columns : columns);
    int sizey = (matrix->rows > rows ? matrix->rows : rows);
    
    double** newMatrix = createMatrixContainer(sizex, sizey);
    double** MatrixA = matrix->values;
    double** MatrixB = values;
    
    // not done....
}

// multiply all values in matrix by value.
void Matrix::scale(double scalar){
    // loop through all parts and scale each.
    for(int i=0;i<columns;i++){
        for(int j=0;j<rows;j++){
            values[j][i] *= scalar;
        }
    }
}


/////////////////////////////////////////
////////// ADVANCED OPERATIONS //////////
/////////////////////////////////////////



// solves a square matrix determinant. Where the matrix = [[a,b],[c,d]]
double Matrix::solveSquareDeterminant(double a, double b, double c, double d){
    return a*d - b*c;
};

// transpose the matrix A T (swap on sides of diagonal)
void Matrix::transpose(){
    // transpose
    // 1 1 0    1 0 0
    // 0 1 1 => 1 1 0
    // 0 0 1    0 1 1
    // flips diagonal
    //cout << "transposed-1" << endl;
    Matrix* copy = clone(); // use to reference to.
    double** m2 = createMatrixContainer(rows, columns);
    
    // all we have to do is flip x and y during express copy.
    for(int i=0;i<columns;i++){
        for(int j=0;j<rows;j++){
            //?
            m2[j][i] = copy->values[j][i];
        }
    }
    
    for(int i=0;i<rows;i++){
        delete values[i];
    }
    values = m2;
    //cout << "transposed-2" << endl;
};




// find the minor (find inner keys)
double Matrix::adjMinor(int n, int m){
    // block the row and column of the current, but do the others. If 2x2, solve for Square determinant.
    //  if greater, then separate that region as a matrix and find it's determinate.
    // Minor: (@ 0, 0)
    //  ! * * 
    //  * a b
    //  * c d
    
    // Minor: @ (1,1)
    // a * b
    // * ! *
    // c * d
    
    double** cValues = createMatrixContainer(columns-1, rows-1);
    
    // used as positional controllers, note that xinc takes precedence over yinc.
    int xinc = 0;
    int yinc = 0;
    
    // solve for before this column.
    int i;
    for(i=0;i<columns;i++){
        // skip this column.
        if(i == m) continue;
        
        int j;
        // loop through rows.
        for(j=0;j<rows;j++){
            // skip this row.
            if(j == n) continue;
            
            // determine row and column in cMatrix.
            cValues[yinc][xinc] = values[j][i];
            yinc++;
        }
        // increment x, reset y
        xinc++;
        yinc=0;
    }
    
    // solve if needed.
    Matrix* c = new Matrix(cValues, columns-1, rows-1);
    double det = c->determinant();
    
    // clean up memory and return
    delete c->values;
    delete c;
    
    return det;
}

// - + - +
// + - + -

// find the adjutant (obtained from minor of all values)
Matrix* Matrix::adjutant(){
    //cout << "adj-0" << endl;
    Matrix* ret = clone();
    //cout << "adj-1" << endl;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            ret->values[i][j] = ((i%2 != 0 && j%2 == 0 
                                    || i%2 == 0 && j%2 != 0) 
                                    ? -1 : 1);
            ret->values[i][j] *= adjMinor(i,j);
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout << ret->values[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    ret->transpose();
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout << ret->values[i][j] << " ";
        }
        cout << endl;
    }
    
    return ret;
}

// finds the determinant by using minor(n,0) on top row.
// returns -9999 as non-square or inconclusive.
double Matrix::determinant(){
    double result = 0;
    
    if(rows == 2 && columns == 2){
        return solveSquareDeterminant(values[0][0],
                            values[1][0],
                            values[0][1],
                            values[1][1]);
    }else if(columns%2 == rows%2){
    
        // This is a square matrix. Find and add the top-row Minors.
        // coefficient matrix:
        //   + - + -
        //   - + - +
        //   + - + -
        for(int j=0;j<columns;j++){
            // get minor at location.
            double mi = adjMinor(j,0);
            // coefficnent of i
            double ci = ((j%2 == 0) ? 1 : -1);
            // value at location
            double val = values[0][j];
            result += mi* ci *val;
        }
        return result;
    }
    
    return -9999;
}

void Matrix::inverse(){
    // wow, this one is difficult.
    // adj*determinant = inverse.
    Matrix* A = adjutant();
    A->scale( 1/determinant() );
    
    values = A->values;
}






// Forming the echeolon form.
// solves a single row using a scaled row.
void Matrix::rowSolve(double scalar, int row, int toRow){
    for(int j=0;j<columns;j++){
        values[toRow][j] += scalar * values[row][j];
    }
}

// solves a single column using a scaled column.
void Matrix::colSolve(double scalar, int col, int toCool){

} 

// linearly solves the lower quadrant
void Matrix::lower(){
    // Use row operations to solve. 
    // Also use scalar multiplication to scale rows if necessary.
    
    // method:
    // * * *    * * *    * * *    * * *
    // ! * * => 0 * * => 0 * * => 0 * *
    // * * *    ! * *    0 ! *    0 0 *
    // (R2/R1) * R1 + R2 -> R2
    // (R3/R2) * R2 + R3 -> R3
    // * * * * *
    // 0 * * * * 
    // 0 0 * * *
    // 0 0 0 * * 1 2 3 4
    // 0 0 0 0 * 1 3 6 10
    
    // First, calculate the second row's first column position.
    // Second, find a row that cancels out ONLY that number.
    // Third, apply the calculation using rowSolve.
    cout << "lower" << endl;
    for(int j=0;j<columns;j++){
        for(int i=j+1;i<rows;i++){
            // i,j => position of first spot to solve.
            
            // now we need to find the row that can help resolve our problems.
            //      We should be able to start from row 1
            int essrow = -1;
            for(int k=0;k<rows;k++){
                // determine if this location has a zero at it.
                if(values[k][j] != 0){
                    
                    // done testing. this row is good.
                    essrow = k;
                    break;
                }
            }
            
            if(essrow != -1){
                // apply row change.
                double scale = -values[essrow][j]/values[i][j];
                rowSolve(scale, essrow, i);
            }
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout << values[i][j] << " ";
        }
        cout << endl;
    }
    
}

// linearly solves the upper quadrant
void Matrix::upper(){
    // same as lower, but on the upper right quadrant.
}

void Matrix::echeolonForm(){
    // solve for each Row. If not found, solve for each column.
    // since this is not done by a human, any mid-term result may be found, 
    //  so using (?) R1 to solve will occur most often.
    //  * 0 0
    //  0 * 0
    //  0 0 *
    lower();
    upper();
}

// returns the rank, or number of rows that are non-zero.
// returns -1 if impossible to find.
int Matrix::rank(){
	// solve for echeolon form
	Matrix* m = this->clone();
	m->echeolonForm();

	// Scan through the rows. Make sure that each row is 0. If not, do not count that row.
	int ret = 0;
	for(int y = 0; y<this->rows;y++){
		bool isZero = true;
		// loop through columns for this row.
		for(int x=0;x<this->columns;x++){
			if(this->values[y][x] != 0){
				isZero = false;
			}
		}
		if(isZero) ret++;
	}

	return ret;
}

/////////////////////////////////////////
///////////////// MISC //////////////////
/////////////////////////////////////////

// determines if it is a square matrix. (# columns = # rows)
bool Matrix::isSquare(){
    return columns == rows;
}

// output literally places the entire matrix into a charstring so that you can see what is happening.
CharString* Matrix::toOutput(){
    CharString* ccc = new CharString();
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
        double a1 = values[i][j];
            ccc->concata(CharString::ConvertFromInt(a1));
            
            ccc->concata_(" ",1);
        }
        
        ccc->concata_("\n",1);
    }
    
    return ccc;
}



