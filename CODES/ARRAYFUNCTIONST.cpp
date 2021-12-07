#include <limits.h>
#include <iostream>
using namespace std;

template <typename T>
void array_display(int len,T arr[]){
    cout<<"Array obtained is:- ";
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


template <typename T>
T delete_element(int len,T arr[],int UpperBound,int n){
    int posn;
    if(UpperBound==-1 || n==0){
        cout<<"underflow";
        return 0;
    }
    else{
        cout<<"\n\n Enter the index where you want to delete item:- ";
        cin>>posn;
        if(posn==UpperBound){
            arr[UpperBound]=0;
            UpperBound--;
            n--;
            return arr[len];
        }
        else{
            for(int i=posn+1;i<=UpperBound;i++){
                arr[i-1]=arr[i];
                UpperBound--;
                n--;
                return arr[len];
            }
        }
    }
}


template <typename T>
T insert(int len,T arr[],int UpperBound,int n){
    int posn;
    T value;
    cout<<"\n\n Enter the index where you want to insert the number\n";
    cin>>posn;
       if(posn>=len){
        cout<<"Overflow\n";
        return 0;
    }
    else{
         if(posn==UpperBound+1){
        int i;
        cout<<"\n\n Enter the value that you want to insert at the end of array"<<endl;
        cin>>i;
        arr[UpperBound+1]=i;
        UpperBound++;
        n++;
        return arr[len];
         }
        else if(posn<=UpperBound){
         for(int i=UpperBound;i>=posn;i--){
             arr[i+1]=arr[i];
        }
        cout<<"\n\nEnter the value you want to enter at "<<posn<<" index\n";
        cin>>value;
        arr[posn]=value;
        return arr[len];
    }
    else{
        cout<<"\n\n Enter the value you want to enter at "<<posn<<" index\n";
        cin>>value;
        for(int i=UpperBound+1;i<=posn;i++){
            arr[i]=0;
        }
        arr[posn]=value;
    }
 
}

}




template <typename T>
void Find(int len,T arr[]){
    int posn,found=0;
    T item;
    cout<<"Enter the element to be searched in the array:- ";
    cin>>item;
    for(int i=0;i<len;i++){        //Linear search
        if(arr[i]==item){
            found++;
            posn = i;
        }
    }
    if(found>0){
        cout<<"Element is found at index "<<posn<<" in the array\n";
    }
    else{
        cout<<"Element  not found\n";
    }
}

template <typename T>
void Max_Max(int len,T arr[]){
    T min=INT_MAX,max=INT_MIN;
    int  max_pos, min_pos;
    for(int i=0;i<len;i++){
        if(arr[i]<min){
            min=arr[i];
            min_pos=i;
        }
        if(arr[i]>max){
            max=arr[i];
            max_pos=i;
        }
    }
    cout<<"The Minimum value of the array is "<<min<<" at index  "<<min_pos<<endl;
    cout<<"and the maximum value in the array is "<<max<<" at index "<<max_pos<<endl;
}


int main(){
    int len,UpperBound=-1,n=0;
    cout<<"Enter the length of the array -: \n";
    cin>>len;
    int arr[len];
    
    char choice='y';
    int i=0;
    while(choice=='y' && i<len){
        cout<<"Enter the value of arr["<<i<<"] th element:- ";
        cin>>arr[i];
        i++;
        n++;
        UpperBound++;
        
        cout<<"Do you want to add more items(y/n):- ";
        cin>>choice;
    }
    for(int i=UpperBound+1;i<len;i++){
        arr[i]=0;
    }

    insert(len,arr,UpperBound,n);
    array_display(len,arr);
    delete_element(len,arr,UpperBound,n);
    array_display(len,arr);
    Find(len,arr);
    Max_Max(len,arr);
    return 0;
}
