#include<iostream>
using namespace std;

class Node{
public: 
	char data;
	Node* l_sidenode;
	Node* r_sidenode;	
	
	Node(){
		l_sidenode = NULL;
		r_sidenode = NULL;
		cout<<"Enter the value - ";
		cin>>data;
	}
};

void insert(Node* &root){
	root = new Node;
	cout<<"\nPress y to begin - \n";
	char choice;
	cin>>choice;
	while (choice == 'y'){
	cout<<"\t\t 1. To enter left node "<<root->data<<"\n";
	cout<<"\t\t 2. To enter right node "<<root->data<<"\n";
	cout<<"\t\t 3. To enter both the nodes "<<root->data<<"\n";
	int input;
	cin>>input;
	if (input == 1){
		cout<<"\nEnter the left node value - \n";
		insert(root->l_sidenode);
		
	}
	else if (input == 2){
		cout<<"\nEnter the right node value - \n";
		insert(root->r_sidenode);
	}
	else if (input == 3){
		cout<<"Enter the left node value - \n";
		insert(root->l_sidenode);
		cout<<"\nEnter the right node value - \n";
		insert(root->r_sidenode);
	}
    else {
    	exit;
	}
	cout<<"\nPress y for more tree values - \n";
	cin>>choice;
}
}

void inorder (Node* &root){
	if(root->l_sidenode != NULL){
		inorder(root->l_sidenode);
	}
	cout<<"\t";
	cout<<root->data;
	if(root->r_sidenode != NULL){
		inorder(root->r_sidenode);
	}	
}

void pre_order (Node* &root){
	cout<<"\t";
	cout<<root->data;
	if(root->l_sidenode != NULL){
		pre_order(root->l_sidenode);
	}
	if(root->r_sidenode != NULL){
		pre_order(root->r_sidenode);
	}	
}

void post_order (Node* &root){
	if(root->l_sidenode != NULL){
		post_order(root->l_sidenode);
	}
	if(root->r_sidenode != NULL){
		post_order(root->r_sidenode);
	}
	cout<<"\t";
	cout<<root->data;	
}



int main(){
	Node *head;
	insert(head);
	cout<<"\nBinary Tree in pre order - ";
	pre_order(head);
	cout<<"\nBinary Tree in post order - ";
	post_order(head);
	cout<<"\nBinary Tree in in order - ";
	inorder(head);
	return 0;
}

