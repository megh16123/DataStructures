#include<iostream>

using namespace std;
template <typename T>
void InsertionSort(T dummy){
	int size, minpos, pass_IS=0;
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
	
    for(int i=1; i<size; i++){
    	T item = arr[i];
		int j= i-1;
		while(j>=0 && arr[j] > item){
			arr[j+1] = arr[j];
			j--;
		} 
		pass_IS++;
		arr[j+1] = item;
			cout<<endl<<"ARRAY AFTER PASS "<<i<<" IS \n";
			for(int i=0; i<size ; i++){
	        	cout<<arr[i]<<"   ";
            }
		
	}
	
	cout<<endl<<"Your SORTED array is -: \n";
for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}
		cout<<endl<<"No of passes are -: "<<pass_IS;
}
int main(){
	InsertionSort(1);
	
}
