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
template <typename T>
void arraySum(T *array,T *array1,int rows,int columns){
int sum[rows][columns];
for(int i = 0;i<rows;i++){
    for (int j = 0; j < columns; j++)
    {
       sum[i][j] = *(array+i*columns+j) + *(array1+i*columns+j);
    }
}
valueDisplay((T *)sum,rows,columns);
}
template <typename T>
void arraySub(T *array,T *array1,int rows,int columns){
T sub[rows][columns];
for(int i = 0;i<rows;i++){
    for (int j = 0; j < columns; j++)
    {
       sub[i][j] = *(array+i*columns+j) - *(array1+i*columns+j);
    }
}
valueDisplay((T *)sub,rows,columns);
}
template <typename T>
void arrayMul(T *array,T *array1,int rows,int columns){
T mul[rows][columns];
for(int i = 0;i<rows;i++){
    for(int j=0;j<columns;j++){
        mul[i][j] = 0;
    }
}
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j)
            for(int k = 0; k < columns; ++k)
            {   
                // mul[i][j] = 0;
                mul[i][j] += (*(array+i*columns+k)) * (*(array1+k*columns+j));
            }
valueDisplay((T *)mul,rows,columns);

}
template <typename T>
void arrayScaler(T *array,int rows,int columns,T num,char ch){
switch(ch){
    case '+': for(int i = 0;i<rows;i++){
                for (int j = 0; j < columns; j++)
                    {
                        *(array+i*columns+j) += num; 
                    }
    
                }
              valueDisplay(array,rows,columns);
              break;

    case '-':for(int i = 0;i<rows;i++){
                for (int j = 0; j < columns; j++)
                    {
                        *(array+i*columns+j) -= num; 
                    }
    
    }
              valueDisplay(array,rows,columns);
              break;


    case '*':for(int i = 0;i<rows;i++){
                for (int j = 0; j < columns; j++)
                    {
                        *(array+i*columns+j) *= num; 
                    }}
            valueDisplay(array,rows,columns);
              break;
    case '/':for(int i = 0;i<rows;i++){
                for (int j = 0; j < columns; j++)
                    {
                        *(array+i*columns+j) /= num; 
                    }}
              valueDisplay(array,rows,columns);
              break;
    default: cout<<"Please enter a valid operation";          }}
int main()
{  int rows,columns;
    cout<<"Enter the number of rows = ";
    cin>>rows;
    cout<<"\nEnter the number of colimns = ";
    cin>>columns;
    int array[rows][columns];
    valueInput((int *)array,rows,columns);
    cout<<"Your array is - \n";
    valueDisplay((int *)array,rows,columns);
    cout<<"Enter your choice - \n1.Transpose\t2.addition\t3.subtraction\t4.multiplication\t5.Scale";
    int choice;
    int array1[rows][columns];
    cin>>choice;
    switch(choice){
         case 1:  cout<<"Transpose of the matrix is - \n" ;
                for(int i = 0;i<columns;i++){
                    for (int  j = 0; j <rows; j++){
                        cout<<array[j][i]<<" ";
                    }
                    cout<<endl;
                    } 
                    break;
        case 2:cout<<"Enter the another matrix - \n";
               valueInput((int *)array1,rows,columns); 
               arraySum((int *)array,(int *)array1,rows,columns);
               break;
        case 3:cout<<"Enter the another matrix - \n";
               valueInput((int *)array1,rows,columns); 
               arraySub((int *)array,(int *)array1,rows,columns);
               break;
        case 4:cout<<"Enter the another matrix - \n";
               valueInput((int *)array1,rows,columns); 
               arrayMul((int *)array,(int *)array1,rows,columns);
               break;
        case 5: cout<<"Enter the number you want to scale ";
                int num;
                cin>>num;
                cout<<"Enter the operation to perform \t '+' '-' '*' '/'  ";
                char ch;
                cin>>ch;
                arrayScaler((int *)array,rows,columns,num,ch);
                break;
        default: cout<<"Enter a correct choice";                           
    } return 0;}
