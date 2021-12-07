#include<iostream>
using namespace std;

template <class T>
class Dnode{
public:
	T data;
	Dnode* link;
	Dnode* prev;
	Dnode(){
		link = NULL;
	}	
};

// TO DISPLAY THE LIST
void display(Dnode<int>*&head)
{
	Dnode<int>*n = head;
	while(n != NULL){
		cout<<n->data<<" ";
		n=n->link;
	}
	cout<<"\n";
} 

// TO INSERT AT THE END OF LIST
template <typename T>
void insert_Last(Dnode<int>*&head, T x, Dnode<int>*&last){
   	Dnode<int>*n = new Dnode<int>();
   	n->data = x;
	n->prev=NULL;
	n->link=NULL;
	if(head == NULL){
		head=n;
	}
	if(last == NULL){
	last = n;
	}
	else{
		n->prev=last;
		last->link=n;
		last=n;
    }
	display(head);		
}

 
// TO INSERT AFTER A VALUE IN THE LIST
template <typename T>
void insert_After(Dnode<int>*&head,  T x , T y ,Dnode<int>*&last){
	Dnode<int>*n = new Dnode<int>();
	Dnode<int>*p = head;
	n->data = x;
	n->link = NULL;
	n->prev = NULL;
	if(head == NULL){
		head = n;
		last = n;
	}
	else{
		while(p->data !=y && p != NULL){
			p = p->link;
		}
		
		n->data = x;
		n->link = p->link;
		n->prev = p;
		p->link->prev = n;
		p->link = n;
	
	}
	display(head);
}

// TO INSERT BEFORE A VALUE IN THE LIST
template <typename T>
void insert_Before(Dnode<int>*&head,  T x , T y ,Dnode<int>*&last){
	Dnode<int>*n = new Dnode<int>();
	Dnode<int>*p = head;
	n->data = x;
	n->link = NULL;
	n->prev = NULL;
	if(head == NULL){
		head = n;
		last = n;
	}
	else if (head->data == y){
		n->link = head;
		n->prev = NULL;
		head->prev = n;
		head =n;
	}
	else{
		while(p != NULL && p->data !=y){
			p = p->link;
		}
	
		n->data = x;
		n->link = p;
		n->prev = p->prev;
		p->prev->link = n;
		p->prev = n;

	}
	display(head);
}

// TO DELETE THE BEGGINING ELEMENT
void delete_Beg(Dnode<int>*&head , Dnode<int>*&last){
	Dnode<int>*n = head;
	if(head == NULL){
		exit;
	}
	else{
		n = head;
		head = head->link;
		head->prev = NULL;
		delete n;
	}
	display(head);
}

// TO DELETE THE LAST ELEMENT
void delete_Last(Dnode<int>*&head, Dnode<int>*&last){
	Dnode<int>*n = head;
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
		Dnode<int>*q = n->link;
		n->link = NULL;
		delete q;
	}
	display(head);
}


// TO DELETE A SPECIFIC LOCATION
template <typename T>
void delete_Location(Dnode<int>*&head, T x ,Dnode<int>*&last){
	Dnode<int>*n = head;
	if(head == NULL){
		exit;
	}
	if(head->link == NULL){
		head == NULL;
	}
	else if(head->data == x){
		n = head;
		head = head->link;
		head->prev = NULL;
		delete n;
	}
	else {
		while(n->data != x && n->link != NULL){
			n = n->link;
		}
		n->prev->link = n->link;
		n->link->prev = n->prev;
		delete n;
	}
	cout<<"Linked list after deleting "<<x<<" is \n";
	display(head);
}


// TO PERFORM LINEAR SEARCH
template <typename T>
void linear_Search(Dnode<int>*&head, T x){
	Dnode<int>*n = head;
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




int main(){
	int beg,end, val_aft, aft, bef, val_bef;
	Dnode<int>*head = NULL;
	Dnode<int>*last = NULL;
	
		char choice = 'y';
	
	while(choice=='y'){
		int elem;
		cout<<"Enter the elements -: ";
		cin>>elem;
	insert_Last(head,elem,last);
		
		cout<<"Do you want to add more elements to the list (y/n) -> ";
		cin>>choice;
	}
	
	
	
	char choi;
	cout<<endl<<endl;
	cout<<"Do you want to perform operations (y/n) \n";
	cin>>choi;
    while(choi == 'y'){
	cout<<"\t  \n1. display ";
	
	cout<<"\t  \n3. Insert at last ";
	cout<<"\t  \n4. Insert before a value ";
	cout<<"\t  \n5. Insert after a value ";
	cout<<"\t  \n6  Delete at last";
	cout<<"\t  \n7  Delete at beginning ";
	cout<<"\t  \n8. Delete a location ";
	cout<<"\t  \n9. Linear search ";
	int input;
	cout<<"\nEnter your choice  -: \n";
	cin>>input;
	
	
	
	
	if(input == 1){
	// DISPLAY	
	cout<<"The Linked list is -: \n";
    display(head);
	}
 
    
	
	else if(input == 3){
    // LAST INSERT
    cout<<"Enter the element to be added at last -> ";
	cin>>end;
	insert_Last(head,end,last);
	
	cout<<endl<<endl;
	}
	
	else if(input == 5){
	// AFTER INSERT
    cout<<"Enter after which element you want to add -: ";
	cin>>val_aft;
	cout<<"Enter the value -> ";
	cin>>aft;
	insert_After(head,aft,val_aft, last);
	
	cout<<endl<<endl;
	}
	
	else if (input == 4){
	// BEFORE INSERT	
    cout<<"Enter before which element you want to add -: ";
	cin>>val_bef;
	cout<<"Enter the value -> ";
	cin>>bef;
	insert_Before(head,bef,val_bef, last);
	
	cout<<endl<<endl;
	}
	
	else if (input == 7){
	// DELETE BEGINNING	
	cout<<"\nLinked list after deleting the beginning value is -: \n";
	delete_Beg(head,last);
	
	cout<<endl<<endl;
	}
	
	else if (input == 6){
	// LAST DELETE
	cout<<"\nLinked list after deleting the last value is -: \n";
	delete_Last(head,last);

	cout<<endl<<endl;
	}
    
    else if (input == 8){
    // DELETE LOCATION	
    	cout<<"Enter the location you want to delete -:\n";
    	int loc;
    	cin>>loc;
    	delete_Location(head, loc ,last);
	}
    
    else if(input == 9){
    // LINEAR SEARCH	
    	cout<<"Enter the element you want to search -: \n";
    	int elem;
    	cin>>elem;
    	linear_Search(head, elem);
	}
    
    cout<<"\nDo you want to perform more -: \n";
	cin>>choi;
}
	return 0;
}
