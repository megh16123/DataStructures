#include<iostream>

using namespace std;

class Dnode{
public:
 int data;
 Dnode *prev,*next;
 Dnode(){
     data= 0;
     prev = NULL;
     next = NULL;
 }
};
void insertionAtEnd(Dnode *&start,Dnode *&current,int data){
Dnode *node = new Dnode();
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
void insertAtBegin(Dnode *&start,Dnode *&current,int data){
Dnode *node = new Dnode();
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

bool insertBeforeVal(Dnode *start,int key,int data){
Dnode *p = start,*node = new Dnode();
node->data = data;
while(p != NULL){
  if(p->data == key){
node->next = p;
node->prev = p->prev;
p->prev->next = node;
p->prev = node;
return true;
  }
  p = p->next;
}
return false;
}
bool insertAfterVal(Dnode *start,int key,int data){
Dnode *p = start,*node = new Dnode();
node->data = data;
while(p != NULL){
 if(p->data == key){
node->next = p->next;
node->prev = p;
p->next->prev = node;
p->next = node;
return true;
 }
  p = p->next;
}
return false;

}
void traverse(Dnode *start){
Dnode *p = start;
while (p != NULL){
  cout<<p->data<<" ";
  p = p->next;
}

}
bool deleteVal(Dnode *start,int data){
Dnode *p = start;
while (p->next != NULL){
 if(p->data == data){
Dnode *q = p;
p->prev->next = p->next;
p->next->prev = p->prev;
delete(q); 
return true;
 }
  p = p->next;
}
return false;
}
bool deleteEnd(Dnode *start,Dnode *current){
if(start == NULL){
  return false;
}
Dnode *p = start;
while(p !=NULL){
  p = p->next;
}
p->prev->next = NULL;
current = p->prev;
Dnode *q = p;
delete(q);
return true;
}
bool deleteBeg(Dnode *&start){
if(start == NULL){
  return false;
}
Dnode *q = start;
start = start->next;
start->next->prev = NULL;
delete(q);
return true;
}
bool SearchNode(Dnode *start,int data){
Dnode *p = start;
while (p!= NULL)
{
  if(p->data == data){
    return true;
  }else{
    p = p->next;
  }
}
return false;
}
int main(){
Dnode *start = NULL,*current = start;
 int data,chce;
  char choice = 'y';
  while(choice=='y'){
  cout<<"Enter the operation to perform : \n1.Append\t2.Insert At begin\t3.Insert Before a value \t 4.Insert After a value \t 5.Display \t 6.Delete\t  7.search \t8.Delete from begin \t 9.Delete from end\nChoice : - ";
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
  case 3: int key;
          cout<<"Enter the value to insert : ";
          cin>>data;
          cout<<"Enter the value to insert "<<data<<" before : ";
          cin>>key;
          if(insertBeforeVal(start,key,data)){
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
          if(insertAfterVal(start,key,data)){
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
  case 9: 
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