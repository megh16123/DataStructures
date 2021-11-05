#include<iostream>

using namespace std;

class Qnode{
public:
int data;
Qnode *link;

Qnode(){
    data = int(NULL);
  link = NULL;
}
};
void insertionAtEnd(Qnode *&start,int data,Qnode *&current){
Qnode *node = new Qnode();
    node->data = data;
if(start ==NULL){
    start = node;
    
    current = node;
 }
 else{
    current->link = node;

    current = node;
    
}
}
bool deleteBeg(Qnode *&start){
if(start==NULL){
  return false;
}
Qnode *q = start;
start = start->link;
delete(q);
return true;
}
 void traverse(Qnode *start){
      Qnode *p = start;
    while(p != NULL){
      cout<<p->data<<" ";
      p = p->link;
      
    }
     cout<<endl;  
}  

int main(){
int choice,data;
char ch = 'y';
Qnode *front = NULL,*rear = front;
while(ch=='y'){
cout<<"Enter the choice \n 1.Enqueue \t 2.Dequeue \t 3.Display \t4.size of queue";
cin>>choice;
switch (choice)
{
case 1: cout<<"Enter the number to be added ";
        cin>>data;
        insertionAtEnd(front,data,rear);

    break;
case 2:  if(deleteBeg(front)){
                  cout<<"\nValue deleted ";
                }else{
                  cout<<"Queue is empty";
                }
   break;
case 3: cout<<endl;
        traverse(front);
       
    break;   
case 4: 
    cout<<"\n  size is - "<<rear - front;
    break;   
default: cout<<"Enter a correct choice ";
    break;
}
cout<<"\nDo you want ot continue ? ";
cin>>ch;
}
return 0;
}