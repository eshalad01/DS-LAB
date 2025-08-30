#include <iostream>
using namespace std;

int main() {
    int D; // number of departments
    cout << "Enter number of departments: ";
    cin >> D;
    int* studentsCount = new int[D]; // an array to store number of students in each department
    
    for (int i = 0; i < D; i++) {
        cout << "Enter number of students in department " << i + 1 << ": "; //taking input of numb of stud in each dept
        cin >> studentsCount[i];
    }

    int*** departments = new int**[D]; //  departments having array of pointers to students

    for (int i = 0; i < D; i++) { // For each department allocating array of students
        departments[i] = new int*[studentsCount[i]];
        for (int j = 0; j < studentsCount[i]; j++) {// each student having array of 5 subjects marks i.e. const
            departments[i][j] = new int[5];
        }
	}   

    for (int i = 0; i < D; i++) {// taking input marks for each student in each department
        cout << "Enter marks for students in department " << i + 1 << " (5 subjects each):\n";
        for (int j = 0; j < studentsCount[i]; j++) { //input marks for each student
            cout << " Student " << j + 1 << ": ";
            for (int k = 0; k < 5; k++) {
                cin >> departments[i][j][k];//memoy for each students marks ie 5
            }
        }
    }
    
   
for (int i = 0; i < D; i++) {
    int highest = -1;        // Initialize to smallest possible mark
    int lowest = 101;        // Initialize higher than max possible mark (100)
    int total_sum = 0;
    int total_marks = studentsCount[i] * 5;  // total number of individual marks

    for (int j = 0; j < studentsCount[i]; j++) {
        for (int k = 0; k < 5; k++) {   // Loop through each subject mark of the student
            int mark = departments[i][j][k];

            if (mark > highest) highest = mark;  // Track highest mark
            if (mark < lowest) lowest = mark;     // Track lowest mark

            total_sum += mark;  // Sum all marks
        }
    }

    double average = (double)total_sum / total_marks;  // Calculate average of all marks

    cout << "\nDepartment " << i + 1 << " stats:\n";
    cout << " Highest mark = " << highest << "\n";
    cout << " Lowest mark = " << lowest << "\n";
    cout << " Average mark = " << average << "\n";
}


    for (int i = 0; i < D; i++) { //deleting all allocated memory rows and col wise and for 5 marks allocation
        for (int j = 0; j < studentsCount[i]; j++) {
            delete[] departments[i][j];
        }
        delete[] departments[i];
    }
    delete[] departments;
    delete[] studentsCount;

    return 0;
}

