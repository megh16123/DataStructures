//program to check if the singly linked list is a Palindrome or not.

//done by Pushpender 3912
#include<iostream>
using namespace std;

class node{				//class node is defined
	public:
		int data;		//data part(or information part) of node	
		node* link;		//link par(or address part) of node
	
	node(){			//default constructor
		data=NULL;	//data part initialized
		link=NULL;	//address part initialized to NULL
	}
	
};

void display(node* save){				//display function to display elements and address of elements in memory
	node* S=save;			//saving the start of the linked list
	cout<<"\n  List elements are below\n\t\t";
	while(S!=NULL){			//traversal loop
		cout<<"  "<<S->data<<"  ";
		S=S->link;
	}
	cout<<"\n\n\n";
}

void insertend(node* start){		//insertion function for insertion of element at end
	node* n=new node();				//new node
	n->link=NULL;
	node* S=start;			//saving the start of the linked list
	int value;
	cout<<"Enter the value You want to add in the list :- ";
	cin>>n->data;				//user input for data value of new node
	if(S==NULL){
		start=n;	
	}
	else{
		while(S->link!=NULL){		//traversal loop to reach end of list
			S=S->link;
		}
	}
	S->link=n;
}


node* reverseList(node *temp){  
    node *current = temp;  
    node *prevNode = NULL, *nextNode = NULL;  
      
   //Swap the previous and next nodes of each node to reverse the direction of the list  
    while(current != NULL){  
        nextNode = current->link;  
        current->link = prevNode;  
        prevNode = current;  
        current = nextNode;  
    }  
    return prevNode;  
}  
   
//isPalindrome() will determine whether given list is palindrome or not.  
void isPalindrome(node* head){  
    node *current = head;  
    bool flag = true;  
      
    //Reverse the list after middle node to end  
    node *revHead = reverseList(current->link);  
   
    //Compare elements of list to its reversed list
    while(head != NULL && revHead != NULL){  
        if(head->data != revHead->data){  
            flag = false;  
            break;  
        }  
        head = head->link;  
        revHead = revHead->link;  
    }  
    
    cout<<"\n\n\t\t==========================\n ";
    cout<<"\t\t     Result   \n";
    cout<<"\t\t==========================\n";
   
    if(flag)  
        cout<<"Given singly linked list is a palindrome\n";  
    else  
        cout<<"Given singly linked list is not a palindrome\n";  
}
int main()  
{  
    //Add nodes to the list  
    node* p1=new node();	//1st element of list before any function
    node* p2=new node();
    cout<<"\n\t\tPAlINDROME IN LINKED LIST CHECKER\n";
	cout<<"\n\nEnter the value of 1st element :- ";
	cin>>p1->data;			//user input for data value of 1st element
	node* Start=new node();
	Start->link=p1;			//START pointer node with data = null
	int l;
	char c='n';
	cout<<"\t\t\tDo you wanna add more elements in the list ??\n\t\t\tPress y for yes:- ";
	cin>>c;
	while(c=='y'){			//user input loop for more element he/she wants enter
		insertend(Start);		//AS always new element add in ending so insertion at end function called
		cout<<"\t\t\tDo you wanna add more elements in the list ??\n\t\t\tPress y for yes:- ";
		cin>>c;
	}
      
    display(p1);  //display of entered linked list
      
    //Checks whether given list is palindrome or not  
    isPalindrome(p1);
      
    return 0;  
}