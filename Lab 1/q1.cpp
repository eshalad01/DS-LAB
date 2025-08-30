#include <iostream>
using namespace std;

class BankAccount{  //bank account class
private:
    int balance; // making balance a private data member
public:
    BankAccount(){ // default constructor
    	balance=100; // initializing bal to 100 in def constructor
	}
    BankAccount(int bal){ //parameterized constructor 
	 balance=bal; // intialized balance with the value passed in parametrized constructor
	}
	BankAccount(const BankAccount &obj){ //copy constructor
	balance=obj.balance; // copying the bal from the passed object
	}
	void deduct(int amount){ //function to deduct amount from balance
		balance-=amount; //updating balance after every deduction
	}
	void printBalance(string acc){ // function to print balance
        cout<<acc << " current balance"<<": $"<<balance<<endl;
    }
};

int main() {
    BankAccount account1; // obj of default constructor
    account1.printBalance("account1"); //printing balance of acc1 through function
    BankAccount account2(1000); // obj of parametrized constructor(passed with bal amount)
    account2.printBalance("account2");//printing balance of acc2 through function
    BankAccount account3(account2);  //  making obj of copy constructor by passing an obj
     account3.printBalance("account3");//printing balance of acc3 through function
    account3.deduct(200); // deducting 200 from acc3 to check if it effects acc 2
     account3.printBalance("account3"); //reprinting acc3 bal
    account2.printBalance("account2"); // reprinting acc 2 bal to show it is uneffected
    return 0;//end
}

