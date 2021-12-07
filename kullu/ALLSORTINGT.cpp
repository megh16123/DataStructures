#include<iostream>

using namespace std;
template <typename T>
int BubbleSort(T arr[] , int size){
	
	cout<<"\t\t       *********************\n";
    cout<<"\t\t\t   BUBBLE SORT     \n";
	T x[size];	
	for(int i=0; i<size; i++){
		x[i] = arr[i];
	}
	
		int minpos, pass_IS=0, pass_BS=0, pass_SS=0;
		
		cout<<endl<<endl;
	for(int j=0;j<size-1;j++){
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
	return pass_BS;
	}
	template <typename T>
	int SelectionSort(T arr[] , int size){
	cout<<endl;
	cout<<"\t\t       *********************\n";
	cout<<"\t\t\t   SELECTION SORT     \n";
	T x[size];
	for(int i=0; i<size; i++){
		x[i] = arr[i];
	}
	
	int minpos, pass_IS=0, pass_BS=0, pass_SS=0;
		for(int i=0;i<size-1;i++){
		minpos=i;
		for(int j=i+1;j<size;j++){
			if(arr[minpos]>arr[j]){
				minpos=j;
			}
		}
		T swap=arr[minpos];
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
	return pass_SS;
}

template <typename T>
int InsertionSort(T arr[], int size){
	cout<<endl;
	cout<<"\t\t       *********************\n";
	cout<<"\t\t\t   INSERTION SORT     \n";
    
    	int minpos, pass_IS=0, pass_BS=0, pass_SS=0;
    
    T x[size];
	for(int i=0; i<size; i++){
		x[i] = arr[i];
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
	return pass_IS;
}




int main(){
	int size;
cout<<"Enter the size of the array -: \n";
cin>>size;
int arr[size];
cout<<"Enter the elements -: \n";
for(int i=0; i<size ; i++){
	cin>>arr[i];
}
cout<<endl<<"Your array is -: \n";
for(int i=0; i<size ; i++){
	cout<<arr[i]<<"   ";
}
cout<<endl;

	
	int pass_BS = BubbleSort(arr,size);
	int pass_IS = InsertionSort(arr,size);
	int pass_SS = SelectionSort(arr,size);
	
	cout<<endl;
    if(pass_BS<pass_IS && pass_BS<pass_SS){
		cout<<"BUBBLE SORT has minimum passes!";
	}
	else if(pass_IS<pass_BS && pass_IS<pass_SS){
		cout<<"INSERTION SORT has minimum passes!";	
	} 
	else if(pass_IS == pass_SS){
		cout<<"SELECTION AND INSERTION HAS SAME NO OF PASSES !";
	}
	else{
		cout<<"SELECTION SORT has minimum passes!";
}

	
}
