#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    int data;
    Node* link;
    Node(){
        int data;
        link=NULL;
    }
};

 
// TO DISPLAY THE LINKED LIST 
void display(Node<int>*&head)
{
		Node<int>*n = head;
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->link;
	}
	cout<<"\n";
} 
 
 // TO DELETE THE BEGGINING VALUE OF LINKED LIST
void delete_Beg(Node<int>*&head){
	Node<int>*n = head;
	if (head == NULL){
		exit;
	}
	else{
		n = head;
		head = head->link;
		delete n;
	}
	display(head);
}


// TO DELETE THE LAST VALUE OF THE LINKED LIST
void delete_Last(Node<int>*& head){
	Node<int>*n = head;
	if(head == NULL){
		exit;
	}
	if(head->link == NULL){
		head == NULL;
	}
	else{
		while(n->link->link != NULL){
			n=n->link;
		}
		Node<int>*q = n->link;
		n->link = NULL;
		delete q;
	}
	display(head);
}


// TO DELETE A VALUE BEFORE A GIVEN VALUE
void delete_Before(Node<int>*&head, int x){
	Node<int>*n= head;
	if(head== NULL){
		exit;
	}
	else{
		if(n->link->data==x){
			n = head;
			head = head->link;
		}
		else{
			while(n->link->link->data != x && n->link!=NULL){
				n=n->link;
				if(n->link->link==NULL){
					break;
				}
			}
			if(n->link->link!=NULL){
				Node<int>*q = n->link;
				n->link = q->link;
				delete q;
			}
			else{
				cout<<"Element not found";
			}
		}
	}
	cout<<"\nYour linked list after de leting is -: \n";
	display(head);
}


// TO DELETE A VALUE AFTER A GIVEN VALUE
void delete_After(Node<int>*&head , int x){
		Node<int>*n= head;
	if(head== NULL){
		exit;
	}
	else{
		while(n->data != x && n->link != NULL){
			n=n->link;
			if(n->link==NULL){
				break;
			}
		}
		if(n->link==NULL){
			cout<<"Element not found";
		}
		else{
			Node<int>*q = n->link;
			n->link = q->link;
			delete q;
		}
	}
	cout<<"\nYour linked list after deleting is -: \n";
	display(head);
}
 
 
// TO INSERT A VALUE AT THE BEGINNING OF THE LIST
void insert_Beg(Node<int>*&head, int x){
	Node<int>*ins_val = new Node<int>();
	ins_val->data = x;
	ins_val->link = head;
	head = ins_val;
	display(head);
	
}
 
 
 
// TO INSERT A VALUE AT THE END OF LIST
void insert_Last(Node<int>*&head, int x){
	Node<int>*ins_val = new Node<int>();
	ins_val->data = x;
	ins_val->link = NULL;
	Node<int>*n = head;
	if(n==NULL){
		head = ins_val;
	}
	else{
	   while(n->link!=NULL){
	      n=n->link;
	   }
	   n->link=ins_val;
    }
	display(head);
} 
 
// TO INSERT A VALUE BEFORE A VALUE
void insert_Before(Node<int>*&head, int x, int y){
	Node<int>*ins_val = new Node<int>();
	Node<int>*n = head;
	ins_val->data = y;
	ins_val->link = NULL;
	if(head == NULL){
		head->data = x;
	}
	else if(head->data == x){
		insert_Beg(head, y);
	}
	else{
		while(n->link->data!=x && n->link!=NULL){
			n = n->link;
		}
		ins_val->link = n->link;
		n->link = ins_val;
		display(head);
	}
}


// TO INSERT A VALUE AFTER A GIVEN VALUE
void insert_After(Node<int>*&head, int x , int y){
	Node<int>*ins_val = new Node<int>();
	ins_val->data = y;
	ins_val->link = NULL;
	
	Node<int>*n = head;
	while(n->data!=x && n->link!=NULL){
		n = n->link;
	}
	ins_val->link = n->link;
	n->link = ins_val;
	cout<<"Linked list -> ";
	display(head);
}




// TO PERFORM LINEAR SEARCH
int Linear_Search(Node<int>*&head , int x){
	Node<int>*n = head;
	int found,count=1;
	
	while(n->link != NULL){
		count++;
		if(n->data==x){
				found=1;
				count=1;
				break;
			}
		n= n->link;
		if(n->data==x){
				found=1;
				break;
			}
	}
	if(found == 1){
		cout<<"Element found at "<<count<<" number in Linked List";
	}
	else{
		cout<<"Element not found!";
	}
	found=0;
	count=1;
		
}


int main()
{
   	Node<int>*head = NULL;
	int val_bef, bef, beg, aft, val_aft, last , val_Bef , val_Aft , elem;
	char choice = 'y';
	
	while(choice=='y'){
		int element;
		cout<<"Enter the element -: ";
		cin>>element;
	insert_Last(head,element);
		
		cout<<"If you want to add more elements press y -: ";
		cin>>choice;
		
	}
	
	char choi;
	cout<<endl<<endl;
	cout<<"Do you want to perform operations (y/n) \n";
	cin>>choi;
    while(choi == 'y'){
	cout<<"\t  \n1. display ";
	cout<<"\t  \n2. Insert at beginning ";
	cout<<"\t  \n3. Insert at last ";
	cout<<"\t  \n4. Insert before a value ";
	cout<<"\t  \n5. Insert after a value ";
	cout<<"\t  \n6  Delete at last";
	cout<<"\t  \n7  Delete at beginning.  ";
	cout<<"\t  \n8. Delete after a value ";
	cout<<"\t  \n9. Delete before a value ";
	cout<<"\t  \n10. Linear search ";
	int input;
	cout<<"\nEnter your choice  -: \n";
	cin>>input;
	
	
	if(input == 1){
	// DISPLAY	
	cout<<"The Linked list is -: \n";
    display(head);
    }
    
    else if(input == 4){
    // BEFORE INSERT
   	cout<<"Enter before which element you want to add -: ";
	cin>>val_bef;
	cout<<"Enter the value -> ";
	cin>>bef;
	insert_Before(head,val_bef,bef);
	
	cout<<endl<<endl;
	}
	
	else if (input == 2){
	// BEGGINING INSERT
    cout<<"Enter element to be added at beginning -: ";
	cin>>beg;
	insert_Beg(head,beg);
    
    cout<<endl<<endl;
	}
    
    else if(input  == 5){
    // AFTER INSERT
    cout<<"Enter after which element you want to add -: ";
	cin>>val_aft;
	cout<<"Enter the value -> ";
	cin>>aft;
	insert_After(head,val_aft,aft);
	
	cout<<endl<<endl;
	}
	
	else if(input == 3){
	// LAST INSERT
    cout<<"Enter the element to be added at last -: ";
	cin>>last;
	insert_Last(head,last);
	
	cout<<endl<<endl;
	}
	
	else if(input == 7){
	// BEGINNING DELETE
	cout<<"\nLinked list after deleting the beggining element is -: \n";
	delete_Beg(head);
	
	cout<<endl<<endl;
	}
	
	else if(input == 6){
	// LAST DELETE
	cout<<"\nLinked list after deleting the last value is -: \n";
	delete_Last(head);
	
	cout<<endl<<endl;	
	}
	
	else if (input == 9){
	// BEFORE DELETE
	cout<<"\nEnter the value before which you want to delete -: \n";
	cin>>val_Bef;
	delete_Before(head , val_Bef);
	
	cout<<endl<<endl;
	}
	
	else if(input == 8){
	// AFTER DELETE
	cout<<"\nEnter the value after which you want to delete -: \n";
	cin>>val_Aft;
	delete_After(head , val_Aft);
	
	cout<<endl<<endl;
	}
	
	else if(input == 10){
	// LINEAR SEARCH
	cout<<"\nEnter the element you want to search -: \n";
	cin>>elem;
	Linear_Search(head, elem);
	}
	cout<<"\nDo you want to perform more -: \n";
	cin>>choi;
}
	
    return 0;
}
