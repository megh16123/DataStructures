#include<iostream>
using namespace std;

class node{
	public:
		char value;
		node *lnode;
		node *rnode;
		
		node(){
			lnode=NULL;
			rnode=NULL;
			cout<<"\nEnter the value - ";
			cin>>value;
		}
		
		static void inputnode(node* &parent){
			parent=new node();
			int choice;
			cout<<"\nTo enter lnode at "<<parent->value<<" press1";
			cout<<"\nTo enter rnode at "<<parent->value<<" press2";
			cout<<"\nTo enter both lnode and rnode at "<<parent->value<<" press3";
			cout<<"\nTo exit press any key";
			cin>>choice;
			while(choice==1||choice==2||choice==3){
				switch(choice){
					case 1:
						cout<<"\nEntering lnode at "<<parent->value;
						inputnode(parent->lnode);
						choice=4;
						break;
						
					case 2:
						cout<<"\nEntering rnode at "<<parent->value;
						inputnode(parent->rnode);
						choice=4;
						break;
					
					case 3:
						cout<<"\nEntering lnode at "<<parent->value;
						inputnode(parent->lnode);
						cout<<"\nEntering rnode at "<<parent->value;
						inputnode(parent->rnode);
						choice=4;
						break;
					
					default:
						choice=4;
						break;
				
				}	
			}
		}
		
		static void show_preorder(node* &parent){
			cout<<" "<<parent->value;
			if(parent->lnode!=NULL){
				show_preorder(parent->lnode);
			}
			if(parent->rnode!=NULL){
				show_preorder(parent->rnode);
			}
		}

		static void show_postorder(node* &parent){
			if(parent->lnode!=NULL){
				show_postorder(parent->lnode);
			}
			if(parent->rnode!=NULL){
				show_postorder(parent->rnode);
			}
			cout<<" "<<parent->value;
		} 

		static void show_inorder(node* &parent){
			if(parent->lnode!=NULL){
				show_inorder(parent->lnode);
			}
			cout<<" "<<parent->value;
			if(parent->rnode!=NULL){
				show_inorder(parent->rnode);
			}
		}
};

int main(){
	node *root;
	cout<<"\nMaking a binary tree";
	node::inputnode(root);
	cout<<"\nBinary Tree in pre order - ";
	node::show_preorder(root);
	cout<<"\nBinary Tree in post order - ";
	node::show_postorder(root);
	cout<<"\nBinary Tree in in order - ";
	node::show_inorder(root);
	return 0;
}

