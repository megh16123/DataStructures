#include<iostream>
using namespace std;
void show(int array[],int n){
    for(int i= 0;i<n;i++){
        cout<<array[i]<<" ";
    }}
void swap(int &a,int &b){
   int temp = a;
   a = b;
   b = temp;
}
int bubbleSort(int array[],int n){
 int passes =0 ;
 cout<<"Intermediate values \n";
for(int i =0;i<n-(n/2)+1;i++){
    passes++;
    int swaps = 0;
    for(int j=0;j<n;j++){
    if(array[j]>array[j+1]){
        swap(array[j],array[j+1]);
    swaps++;
    }}    show(array,n);
cout<<"Number of Swaps ->"<<swaps<<endl;
}
cout<<"Number of passes ->"<<passes<<endl;
return passes;
}
int  selectionSort(int array[],int n){
    int passes = 0;
     cout<<"Intermediate values \n";
    for(int i =0;i<n-1;i++){
passes++;
        int minIn=i,swaps = 0;
        for(int j=i+1;j<n;j++){
          if(array[j]<array[i]){
            minIn = j;       
          }    
        }
         swap(array[i],array[minIn]);
        swaps++;
            show(array,n);
    cout<<" Number of swaps ->"<<swaps<<endl;
    }
    cout<<"Number of Passes ->"<<passes;
return passes;
}
int insertionSort(int array[],int n){
int key,passes=0;
 cout<<"Intermediate values \n";
for(int i=1;i<n;i++){
		key=array[i];
		passes++;
        for(int j=i-1;j>=0;j--){
			if(key<array[j]){
				array[j+1]=array[j];
				array[j]=key;
			}
		}
    show(array,n);
    cout<<endl;
}
cout<<"Number of passes ->"<<passes;
return passes;
}
void copyArray(int array[],int oldArray[],int n){
    for(int i= 0;i<n;i++){
        array[i] = oldArray[i];
    }
}
void inputArray(int array[],int n){
    cout<<"Enter the values ";
    for(int i=0;i<n;i++){
        cout<<"Index "<<i<<" ";
        cin>>array[i];
    }}
int main()
{ 
   int size,BP,SP,IP;
   cout<<"Enter the size of array : -";
   cin>>size;
   int array[size],oldArray[size];
   inputArray(array,size);
   copyArray(oldArray,array,size);
   cout<<"\nBubble Sort :- \n";
  BP = bubbleSort(array,size);
   show(array,size);
   cout<<"\nSelection Sort\n";
   copyArray(array,oldArray,size);
 SP =   selectionSort(array,size);
   cout<<"\nInsertion Sort\n";
   copyArray(array,oldArray,size);
   IP = insertionSort(array,size);

   if(BP>SP && BP>IP){
       cout<<"\nBubble sort has the max passes";
   }else if(SP>BP && SP>IP){
       cout<<"\nSelection sort has the max passes";

   }else if(IP>BP && IP>SP){
       cout<<"\nInsertion sort has the max passes";

   }
   return 0;
}
