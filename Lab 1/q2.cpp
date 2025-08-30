#include <iostream>
#include <cstring>

using namespace std;

class Exam{
private:
    char* studname; //dynamically allocated *
    char* exmdate; //dynamically allocated *
    int score; // as its of int data type size is always fixed so no dma

public:
	  Exam(){ //default const
        studname=nullptr;// pointing to nullptr
        exmdate=nullptr; // pointing to nullptr
        score=0; //initialized to 0
    }
 void setname(char* name) { //setter for name
        studname=new char[strlen(name)+1]; // calc length of name+1 for string
        strcpy(studname,name); //copying the passed name to studname
    }

    void setdate(char* date){ //setter for date
        exmdate=new char[strlen(date)+1]; // calc length of date+1 for string
        strcpy(exmdate, date);//copying the passed date to exmdate
    }
    

    void setscore(int sc){//setter for score
        score=sc;
    }
    void displaydetails(){ //printing details
        cout<<"Student Name: "<<studname<<endl;
        cout<<"Exam Date: "<<exmdate<<endl;
        cout<<"Score: "<<score<<endl;
    }

    ~Exam() { //detsructor
        delete[] studname;
        delete[] exmdate; // freeing up memory allocated in name and date
    }
};

int main() {
    Exam exam1; //obj using default constructor
    //setting values using setters
    exam1.setname("Bisma");
    exam1.setdate("August 23, 2025");
    exam1.setscore(78);
    
    cout<<"Before Modification:"<<endl;
    
    cout<<"Exam 1:"<<endl;
    exam1.displaydetails();
    
    Exam exam2=exam1; //shallow copy without copy constructor
    
    cout<<"Exam 2(copied):"<<endl;
    exam2.displaydetails();
    
    exam2.setname("Zara"); //updating exam2 name which allocates new memory and ptr
    
    cout<<"After modification:"<<endl;
    cout<<"Exam 1:"<<endl;
    exam1.displaydetails();
    cout<<"Exam 2:"<<endl;
    exam2.displaydetails();  // despite of correct output there was double deletion and memory leak 
    return 0; //end
}

