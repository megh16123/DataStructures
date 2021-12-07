#include<iostream>
#include<string>
using namespace std;

class Student{

public:
int rollNo;
string Name;
void StudentEntry(int rollNo,string Name){
    this->rollNo = rollNo;
    this->Name = Name;
}

};
class Exam : public Student{
protected:
long marks[6];
public:
void EnterMarks(){
cout<<"Enter the marks of 6 subjects:- "<<endl;
for(int i = 0;i<6;i++){
    cout<<"Subject :- "<<i+1<<" ";
    cin>>marks[i];
}
}

};
class Result : public Exam{
float total_marks;
public:
Result(int RollNo,string name){
    Student::StudentEntry(RollNo,name);
    Result::EnterMarks();
    total_marks = 0;
    
}   
void totalCalc(){
for(int i = 0;i<6;i++){
    total_marks+= marks[i];
}
} 
float Percent(){
totalCalc();
    return total_marks/6;
}
void disp(){
    cout<<"Name - "<<Name<<endl;
    cout<<"Roll No - "<<rollNo<<endl;
    cout<<"Percentage  - "<<Percent()<<"%";
}
};

int main()
{
    int rollNo;
    string name;
    cout<<"Enter the roll number : - ";
    cin>>rollNo;
    cout<<"Enter the name : - ";
    cin>>name;
    Result res(rollNo,name);
    cout<<endl;
    res.disp();
    return 0;
}
