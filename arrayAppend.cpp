//Meghansh Tyagi 3923
#include<iostream>

using namespace std;
// void insert(int ar[],int Ub,int Lb,int n ,int i,int item){

// if(n==0){
//     cout<<"array is empty";
// }else if(uB==n){
//     cout<<"Overflow";

// }else if(i>n){
//     cout<<"index not in array";
// }else{
//     ar[i] = item;
// }}
int main(){
    int uB=0,size;
    cout<<"Enter the size of array";
    cin>>size;
    int array[size];
    char choice = 'y';
    while(choice =='y'){
    if(uB<size){
    cout<<"Enter the value ";
    cin>>array[uB];
    uB++;
    cout<<"Do you want to continue?(y/n)";
    cin>>choice;
    }else{
        cout<<"Overflow";
        break;
    }
    }

    return 0;
}