#include<iostream>

using namespace std;

class PQnode{
    public:
    int data,priority;
    PQnode *link;
    PQnode(){
        data = int(NULL);
        priority = int(NULL);
        link = NULL;
    }
};
void insertionAtEnd(PQnode *&front,int data,PQnode *&rear,int priority){
PQnode *node = new PQnode();
    node->data = data;
    node->priority = priority;
     PQnode *p = front;
if(front ==NULL){
    front = node;
    node->link = NULL;
    
 }else if(p->priority > node->priority){
   node->link = p;
   front = node;
 } else{
     while (p != NULL && p->link->priority < node->priority)
     {
        p = p->link;
     }
    node->link = p->link;
    p->link = node;

     

}
}
bool deleteBeg(PQnode *&front){
if(front==NULL){
  return false;
}
PQnode *q = front;
front = front->link;
delete(q);
return true;
}
void traverse(PQnode *front){
    PQnode *p = front;
if(front == NULL){
    cout<<"Queue is empty ";

}else{
    while(p != NULL){
cout<<"data - > "<<p->data<<"\tpriority-> "<<p->priority<<endl;
p = p->link;
    }
}
}
int sizeoQ(PQnode *front){
    PQnode *p = front;
    int size = 0 ;
if(front == NULL){
return 0;
}else{
    while(p != NULL){
size++;
p = p->link;
    }
}
return size;
}

int main(int argc, char const *argv[])
{   
    PQnode *front=NULL,*rear = front;
   int choice,data,priority;
   char ch = 'y';
   while(ch=='y'){
    cout<<"Enter the operation to perform \n 1. Enqueue \t 2. Dequeue \t 3. Display \t4. Size of Queue";
    cin>>choice;
    switch (choice)
    {
    case 1: cout<<"Enter the value to be added : ";
            cin>>data;
            cout<<"Enter the priority : ";
            cin>>priority;
insertionAtEnd(front,data,rear,priority);
        break;
    case 2: if(deleteBeg(front)){
        cout<<"Operation Done ";
    }else{
        cout<<"Queue is empty ";
    }
        break;
    case 3: traverse(front);
        break;
    
    case 4: cout<<"The size of queue is - "<<sizeoQ(front);
        break;
    
    default: cout<<"Enter a correct choice ";
        break;
    }
    cout<<"\nDo you want to continue ? ";
    cin>>ch;
   }
    return 0;
}
