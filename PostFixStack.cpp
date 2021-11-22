#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;
stack <int> container;

int main(){
string input;
int num1,num2;
cout<<"Enter the values in you postFix Expression ')' to terminate the expression and get the results ";
while (input != ")"){
 cout<<"\nEnter the input : ";
 cin>>input;
 if(!input.compare("+")){
    num1 = container.top();
    container.pop(); 
    num2 = container.top();
    container.pop();
    container.push(num1+num2);
 }else if(!input.compare("-")){
num1 = container.top();
    container.pop(); 
    num2 = container.top();
    container.pop();
    container.push(num1-num2);
 }else if(!input.compare("*")){
num1 = container.top();
    container.pop(); 
    num2 = container.top();
    container.pop();
    container.push(num1*num2);
 }else if(!input.compare("/")){
num1 = container.top();
    container.pop(); 
    num2 = container.top();
    container.pop();
    container.push(num1/num2);
 }else if(!input.compare("^")){
num1 = container.top();
    container.pop(); 
    num2 = container.top();
    container.pop();
    container.push(pow(num2,num1));
 }else if(!input.compare(")")){
     break;
 }else{
container.push(stoi(input));

 }
}
cout<<"\nResult = "<<container.top();


return 0;
}