// Binary Search
#include<iostream>

using namespace std;
template <typename T>
bool BinarySearch(T array[],int size,T item){
int left = 0,right = size;
  int  mid = (left+right)/2;
do{
    mid = (left+right)/2;
    if(array[mid]==item){
        return true;
    }else if(item < array[mid]){
     right = mid-1;
    }else if(item > array[mid]){
        left = mid+1;
    }

}while(mid != left  || mid == right);
return false;
}
template <typename T>
void enterValues(T array[],int size){
cout<<"Enter the values (array must be sorted)\n";
for(int i = 0;i<size;i++){
    cout<<"Index "<<i+1<<" : ";
    cin>>array[i];
}

}

int main(){

int size,item,ch;
cout<<"Enter the size of array ";
cin>>size;
int array[size];
enterValues(array,size);
cout<<"Enter the number to search ";
cin>>item;
if(BinarySearch(array,size,item)){
    cout<<"Element found";
    cin>>ch;
}else{
    cout<<"Element not found ";
    cin>>ch;

}

return 0;
}