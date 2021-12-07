#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* link;
		Node(){
			data=NULL;
			link = NULL;
		}
};


bool list_Check(Node* &head, Node* &rear){
	if(head->link == NULL && rear->link == NULL){
		return true;
	}
	else{
		return false;
	}
}


void display(Node* &head,Node* &rear){
	Node* n = head;
	if(list_Check(head,rear)){
		cout<<"\nQueue is Empty\n";
	}
	else{
		while(n->link != NULL){
			n = n->link;
			cout<<n->data<<"  ";
		}
	}
	
}


void EnQueue (Node* &head, int x, Node* &rear){
	Node* n = new Node();
	n->data = x;
	n->link = NULL;
	
	if(list_Check(head,rear)){
		head->link = n;
		rear->link = n;
	}
	else{
		rear->link->link = n;
		rear->link = n;
	}
}

void DeQueue (Node* &head,Node* &rear){
	if(list_Check(head,rear)){
		cout<<"Underflow";
	}
	else if(head->link==rear->link){
		head->link=NULL;
		rear->link=NULL;
		cout<<"\nNOW";
	}
	else{
		Node* n = head->link;
		head->link = head->link->link;
		delete n;
	}
}

int main(){
	Node* head = new Node();
	Node* rear = new Node();
	
	int choice;
	char input;
	cout<<"Press y to begin \n";
	cin>>input;
	while (input == 'y'){
		cout<<"\n\nChoices are below:- \n";
		cout<<"1. To enqueue a element \n";
		cout<<"2. To dequeue a element \n";
		cout<<"3. Display \n";
		cout<<"\nWhat do you want to perform \n";
		cin>>choice;
		if(choice == 1){
			int elem;
			cout<<"\nEnter the element\n";
			cin>>elem;
			EnQueue(head,elem,rear);
			display(head,rear);
		}
		
		else if(choice == 2){
			DeQueue(head,rear);
			display(head,rear);
		}
		
		else if(choice == 3){
			display(head,rear);
		}
		cout<<"\nWant to perform more opoerations (y) \n";
		cin>>input;
	}
	cout<<"\n!!Program exitted!!";
	return 0;
}
