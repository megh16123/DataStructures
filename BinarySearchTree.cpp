#include<iostream>
using namespace std;

template <class T>
class node{
    public:
    T item;
    node*left;
    node*right;
    node(T val){
        item=val;
        left=NULL;
        right=NULL;
    }
};
template <class T>
void creation(node<T>* &root,T val){
    if(root==NULL){
        root= new node<T>(val);
    }
    else if(val>root->item){
        creation(root->right,val);
    }
    else{
        creation(root->left,val);
    }
}
template <class T>
void preorder(node<T>* root){
    
    if(root){
        cout<<root->item<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}
template <class T>
void inorder(node<T>* root){
    
    if(root){
        inorder(root->left);
        cout<<root->item<<"  ";
        inorder(root->right);
    }
}
template <class T>
void postorder(node<T>* root){
    
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->item<<"  ";
    }
}
template <class T>
void Search(node<T>* root, T item){
    if(item==root->item){
        cout<<"Found!!";
    }
    else if(item<root->item){
        Search(root->left,item);
    }
    else if(item>root->item){
        Search(root->right,item);
    }
    else{
        cout<<"Not found";
    }
}
template <class T>
void minimum(node<T>*root){
    if(root==NULL){
        cout<<"tree is empty"<<endl;
    }
    if(root->left==NULL){
        cout<<"Minimum element is "<<root->item<<endl;
    }
    else{
        while(root->left!=NULL){
            root=root->left;
        }
        cout<<"Minimum element is "<<root->item<<endl;
    }
}
template <class T>
void maximum(node<T>*root){
    if(root==NULL){
        cout<<"tree is empty"<<endl;
    }
    if(root->right==NULL){
        cout<<"Maximum element is "<<root->item<<endl;
    }
    else{
        while(root->right!=NULL){
            root=root->right;
        }
        cout<<"Maximum element is "<<root->item<<endl;
    }
}
template <class T>
node<T>* inorderSuccessor(node<T>* root){
    node<T>* successor= root;
    while(successor!=NULL && successor->left!=NULL){
        successor=successor->left;
    }
    return successor;
}
template <class T>
node<T>* deletion(node<T>* &root,T key){
    if(root==NULL){
        return NULL;
    }
    else if(key<root->item){
        root->left=deletion(root->left,key);
    }
    else if(key> root->item){
        root->right=deletion(root->right,key);
    }
    else if(key==root->item){
        if(root->left==NULL){
            node<T>* newval=root->right;
            delete(root);
            return newval;
        }
        else if(root->right==NULL){
            node<T>* newval=root->left;
            delete(root);
            return newval;
        }
        else{
            node<T>* temp=inorderSuccessor(root->right);
            root->item=temp->item;
            root->right=deletion(root->right,temp->item);
        }
    }
            return root;
}
int main(){
node<double>*root=NULL;
char choice='y';
while(choice=='y'){
    double val;
    cout<<"Enter value to be stored"<<endl;
    cin>>val;
    creation(root,val);
    cout<<"Do you want to enter more(y/n)\n";
    cin>>choice;
}
cout<<"Preorder Traversal"<<endl;
preorder(root);
cout<<"\nInorder Traversal"<<endl;
inorder(root);
cout<<"\nPostorder Traversal"<<endl;
postorder(root);
double x;
cout<<"\nEnter value to be searched"<<endl;
cin>>x;
Search(root,x);
minimum(root);
maximum(root);
double y;
cout<<"\nEnter value which you want to delete"<<endl;
cin>>y;
deletion(root,y);
cout<<"Preorder Traversal"<<endl;
preorder(root);
}
