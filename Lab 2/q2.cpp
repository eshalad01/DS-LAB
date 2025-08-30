#include<iostream>
using namespace std;
int main(){
	int s,m;
	cout<<"Enter size of students: ";
	cin>>s; //taking size of each student
	cout<<"Enter number of subjects: ";
	cin>>m; //taking size of number of subjects
	int** exam= new int*[s]; //allocating space for rows i.e students
	
	for(int i=0;i<s;i++){
		exam[i]=new int[m]; //allocating space for cols by running for loop for each row
}
	cout<<"Enter marks of subjects for each students"<<endl;
	
	for(int i=0;i<s;i++){ //iterating thru ecah row
		for(int j=0;j<m;j++){ //iterating thru each col
			cout<<"Student "<<i+1<<"'s marks "<<j+1<<endl;
		cin>>exam[i][j]; //taking input for each student's marks
	}
}
    	int* totals= new int[s]; //making 1d array of s size to store total of all marks
	for(int i=0;i<s;i++){
		totals[i]=0; //setting to 0 
		for(int j=0;j<m;j++){
			totals[i]+=exam[i][j]; // adding marks of all cols in a row as student i's totals
	}
}
	cout<<"Total Marks: "<<endl;
	for(int i=0;i<s;i++){
		cout<<"Student "<<i+1<<": "<<totals[i]<<endl; //printing total marks stored in 1d array
	}
	
	float* avg=new float[m];
	float* totavg=new float[m];
	for(int j=0;j<m;j++){
		avg[j]=0; //setting to 0 
		for(int i=0;i<s;i++){
			totavg[j]+=exam[i][j];
			
	}
	avg[j]=totavg[j]/s;
}

cout<<" Average MARKS FOR EACH SUB:"<<endl;
for(int j=0;j<m;j++){
	cout<<" Subject "<<j+1<< ": "<<avg[j]<<endl;
}

int maxmarks = totals[0];  // starting from first student total
int topperIndex = 0;

for (int i = 1; i < s; i++) {
    if (totals[i] > maxmarks) {
        maxmarks = totals[i];
        topperIndex = i;  // saving the student index with max marks
    }
}
cout << "Topper student is Student " << topperIndex + 1 << " with total marks = " << maxmarks << endl;


for (int i = 0; i < s; i++) {
    delete[] exam[i];   // delete each row
}
delete[] exam;          // delete the array of pointers

delete[] totals;        // delete totals array
delete[] avg;           // delete avg array
delete[] totavg;        // delete totavg array
return 0;
}
