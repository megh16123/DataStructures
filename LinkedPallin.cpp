#include<iostream>
using namespace std;

class Node{			
	public:
		int data;		
		Node* link;		
	
	Node(){		
		data=NULL;	
		link=NULL;
	}
	
};
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
void traverse(Node *start){
      Node *p = start;
    do{
      cout<<p->data<<" ";
      p = p->link;
    }while (p!=NULL);
       
} 


Node* reverseList(Node *temp){  
    Node *current = temp;  
    Node *prevNode = NULL, *nextNode = NULL;  
      
    while(current != NULL){  
        nextNode = current->link;  
        current->link = prevNode;  
        prevNode = current;  
        current = nextNode;  
    }  
    return prevNode;  
}  
   
bool isPalindrome(Node* head){  
    Node *current = head;  
    bool flag=true;
      
    Node *revHead = reverseList(current->link);  
   
    while(head != NULL && revHead != NULL){  
        if(head->data != revHead->data){  
          flag = false;
            break;  
        }  
        head = head->link;  
        revHead = revHead->link;  
    }  
    
 
   
return flag;
}
int main()  
{  
     Node *start=NULL,*n1,*current = start;
  int data,chce;
  char choice = 'y';
  while(choice=='y'){
  cout<<"Enter the operation to perform : \n1.Append\t2.Display\nChoice : - ";
  cin>>chce;
  switch (chce)
  {
  case 1: cout<<"Enter the value to be added : ";
          cin>>data;
          insertionAtEnd(start,data,current);
          break;
  case 2: traverse(start);
         break;

          
          
          


          
  default: cout<<"Enter a correct choice !!!\nDo you wish to continue ? ";
           cin>>choice;
          break;
  }
  cout<<"\nDo you want to continue ?";
  cin>>choice;
  }  
     
    if(isPalindrome(start)){
      cout<<"List is a pallindrome ";

    }else{
      cout<<"List is not a pallindrome ";
    }
      
    return 0;  
}