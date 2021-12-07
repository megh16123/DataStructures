#include<iostream>

using namespace std;
template <typename T>
void selectionSort(T dummy){
	int size, minpos, pass_SS=0;
	T  swap;
	
cout<<"Enter the size of the array -: \n";
cin>>size;
T arr[size];
cout<<"Enter the elements -: \n";

for(int i=0; i<size ; i++){
	cin>>arr[i];
}
cout<<endl<<"Your array is -: \n";

for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}
	
	for(int i=0;i<size;i++){
		minpos=i;
		for(int j=i+1;j<size;j++){
			if(arr[minpos]>arr[j]){
				minpos=j;
			}
		}
		swap=arr[minpos];
		arr[minpos]=arr[i];
		arr[i]=swap;
		pass_SS++;
		cout<<"\nArray after pass "<<pass_SS<<" : \n";
		for(int i=0;i<size;i++){
			cout<<arr[i]<<"  ";
		}
	}
	cout<<endl<<"Your SORTED array is -: \n";
	for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}
	cout<<endl<<"No of passes are -: "<<pass_SS;
}
int main(){
selectionSort(1);
	return 0;
}
