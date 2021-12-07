#include<iostream>
using namespace std;

template <class T>
class Pri_Queue{
public:
	T data;
	int PrTy;
	Pri_Queue *link;
	Pri_Queue(int item,int pri){
    	data=item;
    	PrTy=pri;
    	link=NULL;
	}
};



void display(Pri_Queue<int> *head){
    cout<<"The Pri_Queue formed is"<<endl;
    if(head==NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
    while(head->link!=NULL){
    	
        cout<<head->data<<"("<<head->PrTy<<") ";
        head=head->link;
    }
    }
    cout<<endl;
}


void EnQueue(Pri_Queue<int>*&head,int item,int PrTy){
	
Pri_Queue<int>*n= new Pri_Queue<int>(item,PrTy);
Pri_Queue<int>*p=head;

	if(head==NULL){
    head=n;        
}

	else if(n->PrTy<p->PrTy){
        n->link=head->link;
        head=n;
    }
    
	else{
    while(n->PrTy>=p->PrTy&&p->link!=NULL){
       p=p->link;
    }
    n->link=p->link;
    p->link=n;    

    }
}

void DeQueue(Pri_Queue<int>*&head){
    if(head==NULL){
        cout<<"Underflow"<<endl;
    }
    else{
        Pri_Queue<int>*n= head;
        head=head->link;
        delete(n);
    }
}


int main(){
Pri_Queue<int>*head =NULL;
int item;
   
    char choice='y';
    
    while(choice=='y'){
    cout<<"\n\n\n1. EnQueue an item"<<endl;
    cout<<"2. DeQueue an item "<<endl;
    cout<<"3. Display  "<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter the operation you want to perform in queue"<<endl;
    int operation,PrTy;
    cin>>operation;
    if(operation==1){
        cout<<"Enter the value that you want to insert"<<endl;
        cin>>item;
        cout<<"Enter the PrTy of the item"<<endl;
        cin>>PrTy;
        EnQueue(head,item,PrTy);
    }
    else if(operation==2){
            DeQueue(head);
    }
    else if(operation==3){
            display(head);
    }
    else if(operation==4){
        choice='n';
    }
    }
	return 0;
}


















