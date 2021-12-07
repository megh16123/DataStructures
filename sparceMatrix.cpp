#include<iostream>

using namespace std;
template <typename T>
void valueInput(T *array,int rows,int columns){
cout<<"Enter the values \n";
for(int i = 0;i<rows;i++){
    for (int j = 0; j < columns; j++)
    {
        cout<<"Index "<<i<<" "<<j<<" ";
        cin>>*(array+i*columns+j);
        if(*(array+i*columns+j)==0){
            *(array+i*columns+j) = NULL;
        }
    }
    
}
}
template <typename T>
void valueDisplay(T *array,int rows,int columns){
cout<<" Array \n";
for(int i = 0;i<rows;i++){
    for (int j = 0; j < columns; j++)
    {
        cout<<*(array+i*columns+j)<<" ";
    }
cout<<endl;    
}
}
int main()
{
   int rows,columns;
   cout<<"Enter the number of rows = ";
   cin>>rows;
   cout<<"Enter the number of columns = ";
   cin>>columns;
   int array[rows][columns];
   valueInput((int *)array,rows,columns);
valueDisplay((int *)array,rows,columns);
    return 0;
}
