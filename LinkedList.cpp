#include<iostream>

using namespace std;
template <class T>
class Node{
public:
T data;
Node *link;
Node(){
  data = 0;
  link = NULL;
}
};
template <typename T>
void insertionAtEnd(Node<T> *&start,T data,Node<T> *&current){
Node <T>*node = new Node<T>();
    node->data = data;
if(start ==NULL){
    start = node;
    node->link = NULL;
    current = node;
}else{
    current->link = node;
    node->link = NULL;
    current = node;
    
}
}
template <typename T>
void insertAtBegin(Node<T> *&start,T data,Node<T> *&current){
Node<T> *node = new  Node<T>();
   node->data = data;
if(start == NULL){
    start = node;
    node->link = NULL;
    current = node;+
}else{
node->link = start;
start = node;
}
}
template <typename T>
bool insertBeforeVal(Node<T> *start,T data,T key){
Node <T>*p = start;
Node <T>*node = new Node<T>();
node->data = data;
do{
  if(p->link->data == key){
    node->link = p->link;
    p->link = node;
    return true;
  }
  p = p->link;
}while(p!=NULL);
return false;
}
template <typename T>
bool insertAfterVal(Node<T> *start,T data,T key){
  Node<T> *p = start;
  Node<T> *node = new Node<T>();
  node->data = data;
  do{
 if(p->data == key){
   node->link = p->link;
   p->link = node;
   return true;
 }
  p = p->link;
}while(p!=NULL);
return false;
}
template <typename T>
bool deleteVal(Node<T> *start,T data){
 if(start == NULL){
   cout<<"\nThe list is empty\n";
   return false;
 }
  Node <T>*p = start;
  Node <T>*temp;
  
  do{
 if(p->link->data == data){ 
   temp = p->link;
   p->link = p->link->link;
   delete(temp);
   
   return true;

 }
  p = p->link;
}while(p!=NULL);
return false;
}
template <typename T>
void traverse(Node<T> *start){
      Node <T>*p = start;
    do{
      cout<<p->data<<" ";
      p = p->link;
    }while (p!=NULL);
       
}  
template <typename T>
bool SearchNode(Node<T> *start ,T data){
  Node <T>*p = start;
  if(start == NULL ){
    return false;
  }
    do{
     if(p->data == data){
       return true;
     }
      p = p->link;
    }while (p!=NULL);
    return false;
}
template <typename T>
bool deleteBeg(Node<T> *&start){
if(start==NULL){
  return false;
}
Node <T>*q = start;
start = start->link;
delete(q);
return true;
}
template <typename T>
bool deleteEnd(Node<T> *start,Node<T> *&current){
if(start==NULL){
  return false;
}
Node <T>*p = start;
while(p->link->link!=NULL){
  p = p->link;
}

Node <T>*q = p->link;
current = p;
p->link = NULL;
delete(q);
}
int main() {
  Node<int> *start=NULL,*n1,*current = start;
  int data,chce;
  char choice = 'y';
  while(choice=='y'){
  cout<<"Enter the operation to perform : \n1.Append\t2.Insert At begin\t3.Insert Before a value \t 4.Insert After a value \t 5.Display \t 6.Delete\t  7.search \t8.Delete from begin \t 9.Delete from end\nChoice : - ";
  cin>>chce;
  switch (chce)
  {
  case 1: cout<<"Enter the value to be added : ";
          cin>>data;
          insertionAtEnd(start,data,current);
          break;
  case 2: cout<<"Enter the value to be added : ";
          cin >> data;
          insertAtBegin(start,data,current);
         break;
  case 3: int key;
          cout<<"Enter the value to insert : ";
          cin>>data;
          cout<<"Enter the value to insert "<<data<<" before : ";
          cin>>key;
          if(insertBeforeVal(start,data,key)){
            cout<<"\nElement inserted";
          }else{
            cout<<"\nElement not found";
          }
         break;
  case 4: 
          cout<<"Enter the value to insert : ";
          cin>>data;
          cout<<"Enter the value to insert "<<data<<" after : ";
          cin>>key;
          if(insertAfterVal(start,data,key)){
            cout<<"\nElement inserted";
          }else{
            cout<<"\nElement not found";
          }
         break;
  case 5: traverse(start);
         break;

  case 6: cout<<"Enter the value to be deleted ";
          cin>>data;
          if(deleteVal(start,data)){
            cout<<"\nElement deleted";
          }else{
            cout<<"\nElement not found ";
          }
         break;

          
          
          
  case 7:   cout<<"Enter the value to be searched";
            cin>>data;
            if(SearchNode(start,data)){
              cout<<"\nElement Found ";
            }else{
              cout<<"Element Not Found";
            }

             break;
  case 8:if(deleteBeg(start)){
                  cout<<"\nValue deleted ";
                }else{
                  cout<<"List is empty";
                }

  break;
  case 9: cout<<"bug";
           if(deleteEnd(start,current)){
                  cout<<"\nValue deleted ";
                }else{
                  cout<<"List is empty";
                }
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
   