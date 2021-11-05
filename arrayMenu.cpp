 #include<iostream>
using namespace std;
// insertion
void insert(int array[],int LB,int &UB,int n,int value,int index){
if(UB==n){
 cout<<"Array is full";
}else if(index>n){
 cout<<"Index not in array";
}else if(index == UB){
array[UB] = value;
UB++; 
}else{
 
 //shifting the elements 
 for(int i = UB;i>index;i--){
 array[i]=array[i-1];
 }
 cout<<"shifting complete";
 // inserting the value
 array[index] = value;
 UB++;
}
}
// display
void display(int array[],int LB,int UB){
 if(LB==UB){
 cout<<"The array is empty";
 }else{
cout<<"The array is \n";
for(int i = LB;i<UB;i++){
 (array[i]==NULL)?cout<<"NULL":cout<<array[i];
 cout<<" ";
}
}}
// deletion
void deleteItem(int array[],int LB,int &UB,int index){
if(index == UB){
 UB--;
}else{
 for(int i=index+1;i<UB;i++){
 array[i-1] = array[i];
 }
UB--;
}
}
// min max with location
void min_max(int array[],int UB){
 int min = array[0],max= array[0],minIND,maxIND;
for(int i = 1;i<UB;i++){
 for(int j =0;j<UB;j++){
 if(array[j]<min){
 min = array[j];
 minIND = j;
 }else if(array[i]>max){
 max = array[j];
 maxIND = j;
 }
 }
}
cout<<"Minimum Value in the array is "<<min<<" @ "<<minIND<<endl;
cout<<"Maximum Value in the array is "<<max<<" @ "<<maxIND;
}
// searching for an element
bool search(int array[],int LB,int UB,int n,int item_to_search ){
for(int i = LB;i<UB;i++){
 if(item_to_search = array[i]){
 cout<<"Item found ";
 
 return true;
 }else{
 cout<<"Element not found";
 return false;
 }
}
}
// Runner code 
int main()
{ int UB,LB,n,index,choice,value;
 cout<<"Enter the array Size ";
 cin>>n;
 LB = 0;
 UB = 0;
 int array[n] ={0};
 char ch = 'y';
 do{
 cout<<"\nEnter your Choice : - \n"
 <<"1.insert"<<endl
 <<"2.delete"<<endl
 <<"3.Display"<<endl
 <<"4.Display min and max"<<endl
 <<"5.Search "<<endl
 <<"\n";
 cin>>choice;
 switch(choice){
 case 1:
 cout<<"Enter the value to be added\n";
 cin>>value;
 cout<<"Enter the index \n";
 cin>>index;
 insert(array,LB,UB,n,value,index);
 cout<<"Do you want to continue ?";
 cin>>ch;
 break;
 case 2: 
 cout<<"Enter the index of value to be deleted";
 cin>>index;
 deleteItem(array,LB,UB,index);
 break;
 case 3: 
 display(array,LB,UB);
 break;
 case 4: 
 min_max(array,UB);
 break;
 case 5: cout<<"Enter the element to search ";
 int item;
 cin>>item;
 search(array,LB,UB,n,item);
 
 break;
 default: cout<<"Enter a correct choice";
 cout<<"\nDo you want to continue ? ";
 cin>>ch; 
 break; 
 }
 }while(ch=='y');
 return 0;
}
