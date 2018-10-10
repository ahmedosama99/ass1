// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;
int dat[1000];
// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
  friend ostream&operator<< (ostream & print , matrix mat );
};
// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);
ostream&operator<< (ostream & print , matrix mat ){

    for(int i = 0 ; i < mat.row ; i++ ){
        for(int j = 0 ; j < mat.col ; j++){
            print<<mat.data[i*mat.col+j]<<' ' ;
        }
        print<<endl;
    }
    return print;
  }
// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    assert((mat1.row == mat2.row) && (mat1.col == mat2.col));
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]+mat2.data[i];
    }
    return mat4;
}
matrix operator-  (matrix mat1, matrix mat2){ // Sub if same dimensions
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-mat2.data[i];
    }
    return mat4;
}
matrix operator*  (matrix mat3, matrix mat5) // Multi if col1 == row2
{
    matrix mat14;
    mat14.row = mat3.row;
    mat14.col = mat3.col;
    mat14.data = new int [mat3.row * mat5.col];
    assert(mat3.row == mat5.col);

    for(int i = 0 ; i< mat3.row ; i++){
        for (int j = 0 ; j < mat5.col ; j++){
            float sum =0.0;
            for(int g = 0 ; g < mat5.row ; g++){
                sum=sum+mat3.data[i * mat3.col + g] * mat5.data[g * mat5.col +j];
            }
            mat14.data[i * mat14.col + j]=sum;
        }
    }
    return mat14;
}
matrix operator+  (matrix mat1, int scalar) // Add a scalar
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]+scalar;
    }
    return mat4;
}
matrix operator-  (matrix mat1, int scalar)  // Subtract a scalar
{

    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-scalar;
    }
    return mat4;
}
matrix operator*  (matrix mat1, int scalar)  // Multiple by scalar
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]*scalar;
    }
    return mat4;
}

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix mat1, matrix mat2){

    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat1.data[i]+=mat2.data[i];
        //mat4=mat1;
    }
    return mat1;

} // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix mat1, matrix mat2){

    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    assert((mat1.row == mat2.row) && (mat1.col == mat2.col));

    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat1.data[i]=mat1.data[i]-mat2.data[i];

    }
    return mat1;


} // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix mat1, int scalar){
    matrix mat4;
    //mat4.row = mat1.row;
    //mat4.col = mat1.col;
    //mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat1.data[i]=mat1.data[i]+scalar;
    }

    return mat1;

}   // change mat & return new matrix
matrix operator-= (matrix mat1, int scalar)
{
    //matrix mat4;
    //mat4.row = mat1.row;
    //mat4.col = mat1.col;
    //mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat1.data[i]=mat1.data[i]-scalar;
    }

    return mat1;

}   // change mat & return new matrix
matrix operator++ (matrix& mat1)
{
    matrix mat4 ;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]+1;
    }
    return mat4;
}

  	// Add 1 to each element ++mat
matrix   operator-- (matrix& mat1){
{
    matrix mat4 ;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-1;
    }
    return mat4;
}


}    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2)
{
    int c=0;
    if((mat1.col==mat2.col)&&(mat1.row==mat2.row))
    {
        for(int i = 0; i < mat1.row * mat1.col; i++)
        {
            if(mat1.data[i]==mat2.data[i])
            {
                c++;
            }
        }

        if(c==mat1.row*mat1.col)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }


}
bool   operator!= (matrix mat1, matrix mat2)
{
    int c=0;
    if((mat1.col!=mat2.col)&&(mat1.row!=mat2.row))
    {
        return true;
    }
    else if((mat1.col==mat2.col)|| (mat1.row==mat2.row))
    {
        for(int i = 0; i < mat1.row * mat1.col; i++)
        {
            if(mat1.data[i]!=mat2.data[i])
            {
                c++;

            }
        }
        if(c==mat1.row*mat1.col)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    else
    {
        return false;
    }

}
bool   isSquare   (matrix mat)
{
    return (mat.col==mat.row);

}
matrix transpose(matrix mat)
{

    matrix mat2;
    createMatrix( mat.col,  mat.row, dat,  mat2);

        for(int i=0 ; i<mat.col; i++)
        {
            for(int j=0 ; j<mat.row; j++)
            {
            mat2.data[i*mat.row+j]=mat.data[i+mat.col*j];
            }

        }
      return mat2;
}
bool   isSymetric (matrix mat)
{
    if (mat.row == mat.col)
    {
      if (mat ==transpose(mat)){return true;}
      else{return false;}
    }

    else { return false; }



}
bool   isIdentity (matrix mat)
{
    int c = 0, a = 0;
	if (mat.row == mat.col) {
		for (int i = 0; i < mat.col; i++)
		{
			for (int j = 0; j < mat.row; j++)
			{
				if ((mat.data[i*mat.row + j] == 1) && (i == j)) { a++; }
				else if ((mat.data[i*mat.row + j] == 0) && (i != j)) { c++; }
			}

		}

		if (a + c == mat.row*mat.col) { return true; }
		else { return false; }
	}
	else { return false; }
}


//__________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8,9};
  int data2 [] = {1,2,3,4,5,6,7,8,9};
  int data3 [] = {1,2,3,4};

  int data5 [] = {1,2,3,4};
  //int data6 [] = {1,2,3,4,5,6,7,8,9};
  //int data7 [] = {1,2,3,4,5,6,7,8,9};
  //int data8 [] = {1,2,3,4,5,6,7,8,9};
  //int data9 [] = {1,2,3,4,5,6,7,8,9};
  //int data10 [] = {1,2,3,4,5,6,7,8,9};
  //int data11 [] = {1,2,3,4,5,6,7,8,9};
  //int data12 [] = {1,2,3,4,5,6,7,8,9};
  //int data13 [] = {1,2,3,4,5,6,7,8,9};

  matrix mat1, mat2, mat3 , mat5 , mat6 , mat7 , mat8 , mat9 , mat10 , mat11 , mat12;
  createMatrix (3, 3, data1, mat1);
  createMatrix (3, 3, data2, mat2);
  createMatrix (2, 2, data3, mat3);
  createMatrix (2, 2, data5, mat5);
  //createMatrix (3, 3, data6, mat6);
  //createMatrix (3, 3, data7, mat7);
  //createMatrix (3, 3, data8, mat8);
  //createMatrix (3, 3, data9, mat9);
  //createMatrix (3, 3, data10, mat10);
  //createMatrix (3, 3, data11, mat11);
  //createMatrix (3, 3, data12, mat12);

  cout << "mat1 = " << endl << mat1 << endl ;
  cout << "mat2 = " << endl  << mat2 << endl;
  cout << "mat + mat2 = " << endl   << mat1 + mat2 << endl;
  cout << "mat1 - mat2 = " << endl  << mat1 - mat2 << endl;
  cout << "mat1 * mat2 = " << endl  << mat3 * mat5 << endl;
  cout << "mat1 + scaler = " << endl  << mat1 + 10 << endl;
  cout << "mat1 - scaler = " << endl  << mat1 - 1 << endl;
  cout << "mat1 * scaler = " << endl  << mat1 * 5 << endl;
  mat1+=mat2 ;
  cout << "mat1 += mat2 = " << endl  << mat1 << endl ;
  mat1-=mat2;
  cout << "mat1 -= mat2 = " << endl  << mat1 << endl;
  mat1+=10;
  cout << "mat1 + scaler = " << endl  << mat1 << endl;
  mat1-=10;
  cout << "mat1 - scaler = " << endl  << mat1 << endl;


  cout << "++mat = " << endl  << ++ mat1 << endl;
  cout  << "--mat = " << endl << -- mat1 << endl;
  cout <<"is equal "<< (mat1==mat2)<<endl;
  cout <<"is notequal "<< (mat1!=mat2)<<endl;
  cout <<"is squre "<< isSquare(mat3)<<endl;
  cout <<"is identay "<< isIdentity(mat3)<<endl;
  cout <<"is Symetric "<<isSymetric (mat2)<<endl;
  cout <<"transpose = "<<endl<<mat2<<endl<<transpose(mat2)<<endl;
/* The next code will not work until you write the functions
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
}
