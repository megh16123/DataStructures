#include<iostream>
using namespace std;


class Dnode{
public:
	int data;
	Dnode* link;
	Dnode* prev;
	Dnode* head;
	Dnode* rear;
	Dnode(){
		head = rear = NULL;
		link = NULL;
	}	
};


// TO DISPLAY
void display(Dnode* &head)
{
	Dnode *n = head;
	while(n != NULL){
		cout<<n->data<<" ";
		n=n->link;
	}
	cout<<"\n";
} 


// TO INSERT AT THE END OF LIST
void Enqueue_rear(Dnode* &head, int x, Dnode* &rear){
   	Dnode *n = new Dnode();
   	n->data = x;
	n->prev=NULL;
	n->link=NULL;
	if(head == NULL){
		head=n;
	}
	if(rear == NULL){
	rear = n;
	}
	else{
		n->prev=rear;
		rear->link=n;
		rear=n;
    }
	display(head);		
}


// TO INSERT AT THE BEGINNING OF THE LIST
void  Enqueue_beg(Dnode* &head , int x , Dnode* & rear){
	Dnode *n = new Dnode();
	n->data = x;
	n->link = NULL;
	n->prev = NULL;
	if(head == NULL){
		head = n;
		rear = n;
	}
	else{
		n->link = head;
		n->prev = NULL;
		head->prev = n;
		head =n;
	}
	display(head);
	
}


// TO DELETE THE BEGGINING ELEMENT
void Dequeue_beg(Dnode* &head , Dnode* &rear){
	Dnode* n = head;
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


void Dequeue_rear(Dnode* &head, Dnode* &rear){
	Dnode* n = rear;
	rear = rear->prev;
	
	if(head == NULL){
		exit;
	}
	if(rear == NULL){
		head == NULL;
	}
	else{
		rear->link = NULL;
		delete n;
	}
	display(head);
}

int get_front(Dnode* &head , Dnode* &rear){
	if(head == NULL){
		return -1;
	}
	else{
	return head->data;	
	}
}

int get_last(Dnode* &head , Dnode* &rear){
	if(head == NULL){
		return -1;
	}
	else{
		return rear->data;
	}
}
	




int main(){
	int beg,end;
	Dnode* head = NULL;
	Dnode* rear = NULL;
		
		char choice = 'y';
	
	while(choice=='y'){
		int elem;
		cout<<"Enter the elements -: ";
		cin>>elem;
	Enqueue_rear(head,elem,rear);
		
		cout<<"Do you want to add more elements to the Queue(y/n) -> ";
		cin>>choice;
	}

	char choi;
	cout<<endl<<endl;
	cout<<"Do you want to perform operations (y/n) \n";
	cin>>choi;
    while(choi == 'y'){
	cout<<"\t  \n1. display ";
	cout<<"\t  \n2. Insert at beginning ";
	cout<<"\t  \n3. Insert at rear ";
	cout<<"\t  \n4  Delete at rear";
	cout<<"\t  \n5  Delete at beginning ";
	cout<<"\t  \n6  To get the front element";
	cout<<"\t  \n7  To get the last element";
	int input;
	cout<<"\nEnter your choice  -: \n";
	cin>>input;
	
	
	if(input == 1){
	// DISPLAY	
	cout<<"The Queue is -: \n";
    display(head);
	}
 
    else if(input == 2){
    // BEGGINING INSERT
    cout<<"Enter element to be added at beginning -> ";
	cin>>beg;
	Enqueue_beg(head,beg,rear);
    
    cout<<endl<<endl;
	}
	
	else if(input == 3){
    // rear INSERT
    cout<<"Enter the element to be added at rear -> ";
	cin>>end;
	Enqueue_rear(head,end,rear);
	
	cout<<endl<<endl;
	}
	
		else if (input == 5){
	// DELETE BEGINNING	
	cout<<"\nQueue after deleting the beginning value is -: \n";
	Dequeue_beg(head,rear);
	
	cout<<endl<<endl;
	}
	
	else if (input == 4){
	// rear DELETE
	cout<<"\nQueue after deleting the rear value is -: \n";
	Dequeue_rear(head,rear);

	cout<<endl<<endl;
	}
	
	else if (input == 6){
		cout<<"The first element is -: \n";
		cout<<get_front(head,rear);
		cout<<endl<<endl;
	}
	
	else if (input == 7){
		cout<<"The last element is -: \n";
		cout<<get_last(head,rear);
		cout<<endl<<endl;
	}
	
	
	
	cout<<"\nDo you want to perform more -: \n";
	cin>>choi;
}
	return 0;

}
