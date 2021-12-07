#include<iostream>
using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node *link;
		Node(){
			data=NULL;
			link = NULL;
		}
};


bool list_Check(Node<int> *&head, Node<int> *&rear){
	if(head->link == NULL && rear->link == NULL){
		return true;
	}
	else{
		return false;
	}
}

// template <typename T>
void display(Node <int>*&head,Node <int>*&rear){
	Node <int>*n = head;
	if(list_Check(head,rear)){
		cout<<"\nQueue is Empty\n";
	}
	else{
		do{
			n = n->link;
			cout<<n->data<<"  ";
		}while(n->link != head->link&&head->link!=rear->link);
	}
	
}

template <typename T>
void EnQueue (Node <int>*&head, T x, Node <int>*&rear){
	Node <int>*n = new Node<int>;
	n->data = x;
	n->link = head->link;
	
	if(list_Check(head,rear)){
		head->link = n;
		rear->link = n;
	}
	else{
		rear->link->link = n;
		rear->link = n;
	}
}
// template <typename T>
void DeQueue (Node<int>*&head,Node<int>*&rear){
	if(list_Check(head,rear)){
		cout<<"Underflow";
	}
	else if(head->link==rear->link){
		head->link=NULL;
		rear->link=NULL;
		cout<<"\nNOW";
	}
	else{
		Node<int>*n = head->link;
		head->link = head->link->link;
		rear->link->link=head->link;
		delete n;
	}
}

int main(){
	Node<int>*head = new Node<int>;
	Node<int>*rear = new Node<int>;
	
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
