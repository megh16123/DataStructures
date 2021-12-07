#include <iostream>
using namespace std;

int front=-1,rear=-1;

bool isempty()
{
 if(front == -1 && rear == -1)
 return true;
 else
 return false;
}

template <typename T>
void enqueue ( T value,T A[], int SIZE)
{

 if ((rear + 1)%SIZE == front)
    cout<<"Queue is full \n";
 else
 {
  
  if( front == -1)
     front = 0;
 
 rear = (rear+1)%SIZE;
   A[rear] = value;
 }
}

template <typename T>
void dequeue (T A[], int SIZE )
{
 if( isempty() )
  cout<<"Queue is empty\n";
 else
 
 if( front == rear )
  front = rear = -1;
 else
  front = (front + 1)%SIZE;
}

template <typename T>
void showfront( T A[],int size)
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at front is:"<<A[front];
}

template <typename T>
void displayQueue(T A, int SIZE)
{
 if(isempty())
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   cout<<A[i]<<" ";
  }
  else
  {
   i=front;
   while( i < SIZE)
   {
   cout<<A[i]<<" ";
   i++;
   }
   i=0;
   while( i <= rear)
   {
   cout<<A[i]<<" ";
   i++;
   }
  }
 }
}

int main()
{
 int choice, flag=1;
 double value;
 int size;
 cout<<"Enter the size of array"<<endl;
 cin>>size;
 double A[size];
 while( flag == 1)
 {
  cout<<"\n1.enqueue 2.dequeue 3.showfront 4.displayQueue 5.exit\n";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Enter Value:\n";
          cin>>value;
          enqueue(value,A,size);
          break;
  case 2: dequeue(A,size);
          break;
  case 3: showfront(A,size);
          break;
  case 4: displayQueue(A,size);
          break;
  case 5: flag = 0;
          break;
  }
 }

 return 0;
}
