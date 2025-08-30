#include <iostream>
using namespace std;

class DynamicMatrix { //dynamic matrix class
private:
    int** matrix; //array for 2d matrix
    int rows;
    int cols;

public:
    DynamicMatrix(int r, int c) { //parametrized constr rows and cols user provided
        rows = r;
        cols = c;
        matrix = new int*[rows]; // allocation of rows
        int num=0; // making var to initialize values in matrix
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols]; //allocating cols in each row
            // Initialize with 0 for safety
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = num; // assigning values at each inder
                num++; // incrementing value so every value is unique
            }
        }
    }
    ~DynamicMatrix() { //destructor to free memory
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i]; // deleting memory rows and col wise
        }
        delete[] matrix;
    }

    void resize(int r, int c, int initValue) {
        int** newMat = new int*[r]; //making a 2d array to resize the old matrix to ths one
        for (int i = 0; i < r; i++) {
            newMat[i] = new int[c]; //allocating cols
            for (int j = 0; j < c; j++) {
                if (i < rows && j < cols) { 
                    // Copy old values if within bounds
                    newMat[i][j] = matrix[i][j]; //if the size isnt exceeding the old size copying
                } else {
                    // Fill new cells with initValue
                    newMat[i][j] = initValue; //if exceeds the initialize with new val provided
                }
            }
        }


        for (int i = 0; i < rows; i++) { //deleting old memory once resizing is done
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = newMat;
        rows = r; // reasigning val to row and col size
        cols = c;
    }

    void transpose() { //transpose of matriz func
       int** transposeMatrix = new int*[cols]; //allocating memory for cols
for (int i = 0; i < cols; i++) {
    transposeMatrix[i] = new int[rows]; //allocating rows to each col
}


        for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        transposeMatrix[j][i] = matrix[i][j]; 
    }
}

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i]; // freeing memoryy
        }
        delete[] matrix;

        matrix = transposeMatrix; // updating original matrix to transposed matrix
        int temp = rows;
        rows = cols;
		cols = temp; // swapping the size of rows and cols
    }

    // Print method
    void print() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = matrix[i][j]; //storing the value of each index in a var

                if (i % 2 == 1 || j % 2 == 1) { // if row and col index is odd adding 2 its value
                    value += 2;
                }

                cout << value<<" ";
            }
            cout << endl;
        }
    }
};

int main() {
    DynamicMatrix mat(3, 3);

    mat.print();
    cout << endl;

    mat.resize(2, 2, 5);
    mat.print();
    cout << endl;

    mat.transpose();
    mat.print();

    return 0;
}

