#include<iostream>

using namespace std;
template <class T>
class Dnode{
public:
 T data;
 Dnode *prev,*next;
 Dnode(){
     data= 0;
     prev = NULL;
     next = NULL;
 }
};
template <typename T>
void insertionAtEnd(Dnode<T> *&start,Dnode<T> *&current,T data){
Dnode<T> *node = new Dnode<T>();
node->data = data;
if(start == NULL){
start = node;
current = node;

}else{
  current->next = node;
  node->prev = current;
  current = node;
}
}
template <typename T>
void insertAtBegin(Dnode<T> *&start,Dnode<T> *&current,T data){
Dnode<T> *node = new Dnode<T>();
node->data = data;
if(start == NULL){
  
start = node;
current = node;

}else{
  start->prev = node;
  node->next = start;
  start = node;
}

}


template <typename T>
void traverse(Dnode<T> *start){
Dnode<T> *p = start;
while (p != NULL){
  cout<<p->data<<" ";
  p = p->next;
}

}
template <typename T>
int sizeQ(Dnode<T> *start){
int size = 0;
Dnode <T>*p = start;
while (p != NULL){
size++;
  p = p->next;
}
return size;
}
template <typename T>
bool deleteEnd(Dnode <T>*start,Dnode <T>*current){
if(start == NULL){
  return false;
}
Dnode <T>*p = start;
while(p->next !=NULL){
  p = p->next;
}
p->prev->next = NULL;
current = p->prev;
Dnode <T>*q = p;
delete(q);
return true;
}
template <typename T>
bool deleteBeg(Dnode <T>*&start){
if(start == NULL){
  return false;
}
Dnode <T>*q = start;
start = start->next;
start->next->prev = NULL;
delete(q);
return true;
}

int main(){
Dnode <int>*start = NULL,*current = start;
 int data,chce;
  char choice = 'y';
  while(choice=='y'){
  cout<<"Enter the operation to perform : \n1.Enqueue Rear\t2.Enqueue Front  \t 3.Display \t4.Dequeue  Front \t 5. Dequeue Rear \t 6.Size \nChoice : - ";
  cin>>chce;
  switch (chce)
  {
  case 1: cout<<"Enter the value to be added : ";
          cin>>data;
          insertionAtEnd(start,current,data);
          break;
  case 2: cout<<"Enter the value to be added : ";
          cin >> data;
          insertAtBegin(start,current,data);
         break;

  case 3: traverse(start);
         break;


  case 4:if(deleteBeg(start)){
                  cout<<"\nValue deleted ";
                }else{
                  cout<<"Queue is empty";
                }

  break;
  case 5: 
           if(deleteEnd(start,current)){
                  cout<<"\nValue deleted ";
                }else{
                  cout<<"Queue is empty";
                }
  break;           
  case 6: 
          cout<<"Size of the queue is - "<<sizeQ(start);
            break;           
  default: cout<<"Enter a correct choice !!!\nDo you wish to continue ? ";
           cin>>choice;
          break;
  }
  cout<<"\nDo you want to continue ?";
  cin>>choice;
  }  
    return 0;
}