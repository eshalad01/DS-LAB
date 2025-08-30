#include <iostream>
using namespace std;

class Box {
private:
    int* integer; //dma integer

public: 
	Box(){ //default constructor
		integer=new int(0); // by default initializes with 0
	}
    Box(int num) {  //parametrized constructor
        integer=new int(num); // allocating memory and assigning passed value
    }
    ~Box() { //destructor
        delete integer; //deleting allocated memory
    } 
    Box(const Box& other) {// copy constructor
        integer=new int(*other.integer);// copying data of the passed obj in new obj dma
    }
    Box& operator= (const Box& obj) { //copy assignemnt operator
    if (this!=&obj) {
        int* temp=new int(*obj.integer);  // allocates  memory ans copies
        delete integer;  //delete memory(if any)
        integer=temp; // new memory assigned
    }
    return *this; //ptr returned
}
    void display(){ //display func
        cout<<"Integer: "<<*integer<<endl;
    }
    void setter(int val) { //setter func
        *integer=val;
    }
};

int main() {
    Box b1(99); // box 1 with parametrized constructor
    Box b2; // box 2 using default constructor
	b2=b1; //copy assignment operator box1 assigned to box 2
	Box b3=b1;// copy constructor

    cout<<"Before:"<<endl; //displaying details
    cout<<"Box 1: ";
    b1.display();
    
    cout<<"Box 2: ";
    b2.display();
    
    cout<<"Box 3: ";
    b3.display();
    cout<<endl<<endl;
    //updating box 2 and box 3 values for test cases
    b3.setter(50);
    b2.setter(22);
    // re displaying details
    cout<<"After:"<<endl;
    cout<<"Box 1: ";
    b1.display();
    
    cout<<"Box 2: ";
    b2.display();
    
    cout<<"Box 3: ";
    b3.display();
    
    return 0; //end
}

