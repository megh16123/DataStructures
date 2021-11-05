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
		
		static void show(node* &parent){
			cout<<" "<<parent->value;
			if(parent->lnode!=NULL){
				show(parent->lnode);
			}
			if(parent->rnode!=NULL){
				show(parent->rnode);
			}
		}
};

int main(){
	node *root;
	node::inputnode(root);
	node::show(root);
	return 0;
}
