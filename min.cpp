#include<iostream>

using namespace std;

int main(){
 int array[9] = {10,0,2,4,5,6,8,9,7},min=array[0];

 for(int i = 1;i<9;i++){
  for(int j =0;j<9;j++){
      if(array[j]<min){
          min = array[j];
      }
  }
 }
 cout<<min;
 }