#include <iostream>

using namespace std;
template <typename T>
void BubbleSort(int size,T dummy){
	int pass_BS=0;
T arr[size];
cout<<"Enter the elements -: \n";
for(int i=0; i<size ; i++){
	cin>>arr[i];
}
cout<<endl<<"Your array is -: \n";
for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}
cout<<endl<<endl;
for(int j=0;j<size;j++){
for(int i=0;i<size-1;i++){
	if(arr[i] > arr[i+1]){
		T swap = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = swap;
		
	}
	
}
pass_BS++;
cout<<endl<<"ARRAY AFTER PASS "<<j+1<<" is -: \n";
for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}

}

cout<<endl<<"Your SORTED array is -: \n";
for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}
cout<<endl<<"No of passes are -: "<<pass_BS;
}
int main(){
int size, pass_BS=0;
cout<<"Enter the size of the array -: \n";
cin>>size;
BubbleSort(size,1);
return 0;
}
