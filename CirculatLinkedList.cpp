#include<iostream>
using namespace std;

template <class T>
class node{
    public:
    T item;
    node*link;
    node(T x){
        item=x;
        link=NULL;
    }
};
template <class T>
void traverse(node<T> *start){
    node<T> *p= start;
    cout<<"The linkedlist formed is:-"<<endl;
    while(p!=NULL){
        cout<<p->item<<" ";
        p=p->link;
    }
    cout<<endl;
    
}
template <class T>
void insertEnd(node<T>* &start,T item,node<T>*&end){
    node<T> *n= new node<T>(item);
    node<T> *p=start;
    if(start==NULL){
    	start=n;
        end=start;
    }
    
    else{
    	
        n->link=end->link;
        end->link=n;
        end=n;
    
    }
}
template <class T>
void insertBeg(node<T>* &start,T item){
	node<T> *n= new node<T>(item);
    n->link=start;
    start=n;
    traverse(start);
}

template <class T>
void deleteBeg(node<T>* &start){
    node<T> *a=start;
    if(start->link==NULL){
        cout<<"underflow";
    }
    else{
    start=a->link;
    delete(a);

    }
}


template <class T>
void deleteAfterVal(node<T>* &start,T val){
    node<T> *p=start;
     if(start->link==NULL){
        cout<<"underflow";
    }
    else{
        while(p->link->item!=val){
            p=p->link;
        }
        node<T> *temp=p->link->link;
        p->link->link=p->link->link->link;
        delete(temp);
    }
}

int main(){
   float item;
   node<float> *start=NULL;
   node<float>*end=NULL;   
   char choice='y';
   while(choice=='y'){
       cout<<"Enter the value you want to add "<<endl;
       cin>>item;
       insertEnd(start,item,end);
       cout<<"Do you want to add more(y/n):-"<<endl;
       cin>>choice;
   }
   traverse(start);
   float no;
   cout<<"Enter the item you want to enter at beggining"<<endl;
   cin>>no;
   insertBeg(start,no);
   
   float no2,val;

        deleteBeg(start);
        traverse(start);
        

   return 0;
}