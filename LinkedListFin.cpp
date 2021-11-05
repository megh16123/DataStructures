#include<iostream>

using namespace std;
// Creating Class node 
class Node{
public:
int data ; // data part 
Node *link; // link class pointer 

};
// Inserting at the end 
void insertionAtEnd(Node *&start,int data,Node *&current){
Node *node = new Node();  
    node->data = data;  
if(start ==NULL){ 
    start = node; 
    node->link = NULL;
    current = node;
 }
 else{
    current->link = node;
    node->link = NULL;
    current = node;
    
}
}
//  Display the traversed values
void traverse(Node *start){
      Node *p = start;
    do{
      cout<<p->data<<" ";
      p = p->link;
    }while (p!=NULL);
       
}  
// Deleting the duplicate values 
void dupe(Node *head){

  
    Node *p = head,*q = NULL;
    while(p->link != NULL){
   if(p->data == p->link->data){
       q = p->link->link;
       delete(p->link);
       p->link = q;
   }  
  p = p->link;
    }
   
}
// merging the two lists 
void merge(Node *head1,Node *head2,Node *&newHead,Node *&newCurrent){
    if(head1 == NULL || head2 == NULL){
        cout<<"\nOne of the lists is empty";
      return;
    }
    newHead = head1; // setting the head equal to the head of first list 
    Node *p = head1;
    while (p->link!=NULL){
        p = p->link; // iterating the loop 
    }
    p->link = head2;
    p = head2;   // setting the pointer to the head of the second list 
    while (p->link!= NULL)
    {
        p = p->link;  // iterating the loop to the end 
    }
    newCurrent = p; // setting the new current to p 
    newCurrent->link =  NULL;
    
    
}
void swap(int &a,int &b){    // swapping the two numbers by refrence 
   int temp = a;
   a = b;
   b = temp;
}
bool sort(Node *head){ // sorting the list 
    if(head ==NULL){
        return false;
    }
    Node *p = head,*q = NULL;
while(p->link != NULL){   
    q = p->link;
    while (q != NULL)
       {
        if(p->data > q->data){
         swap(p->data,q->data);
        

     }
     q= q->link;
    }
  
  p = p->link;
    }
    return true;
}
bool rev(Node *head){  // reversing the sorted merged list 
    if(head ==NULL){
        return false;
    }
    Node *p = head,*q = NULL;
while(p->link != NULL){
    q = p->link;
    while (q != NULL)
       {
        if(p->data < q->data){
         swap(p->data,q->data);
        

     }
     q= q->link;
    }
  
  p = p->link;
    }
    return true;
}

int main(){
    Node *head1 = NULL,*head2 = NULL,*current1 = head1,*current2 = head2,*newHead = NULL,*newCurrent;
    int choice,data;
    char ch = 'y';
   while(ch=='y'){
    cout<<"Enter the choice\n 1. Append 1st list \t2. Append 2nd list \t3. Display 1st \t4. Display 2nd \t \nChoice :- ";
    cin>>choice;
    switch (choice)
    {
    case 1: cout<<"Enter data to insert ";
            cin>>data;
            insertionAtEnd(head1,data,current1);
        break;
    case 2: cout<<"Enter data to insert ";
            cin>>data;
            insertionAtEnd(head2,data,current2);
        break;
    case 3: traverse(head1);
        break;
    case 4: traverse(head2);
        break;
    
   
    
    default: cout<<"Enter a correct choice !! ";
    
        break;
    }
    cout<<"\nDo you want to continue ? ";
    cin>>ch;

 }
 cout<<"Success ";
if(sort(head1)){
cout<<"\nFirst Sorted list is : \n";
traverse(head1);
}else{
    cout<<"\nFirst List is empty ";
}
if(sort(head2)){
    cout<<"\nSecond Sorted list is : \n";
traverse(head2);
}else{
    cout<<"\nSecond List is empty ";
}
 
    merge(head1,head2,newHead,newCurrent);
    
    cout<<"\nMerged list is \n";
    traverse(newHead);
    cout<<"\nSorted merged list is : \n";
   if(sort(newHead)){
        
    traverse(newHead);
   }else{
       cout<<"\nList is empty ";
   }
   cout<<"\nAfter removing duplicates : \n";
    dupe(newHead);
    traverse(newHead);
    cout<<"\nReversed List is : \n";
    rev(newHead);
    traverse(newHead);
    return 0;
}