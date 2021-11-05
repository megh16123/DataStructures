#include<iostream>

using namespace std;

class TreeNode{
public:
int data ;
TreeNode *Lbranch,*Rbranch;
TreeNode(int value){
    data = value;
    Lbranch = NULL;
    Rbranch = NULL;
}
};
void addNode(TreeNode *&parent,int key){
if(parent == NULL){
    parent = new TreeNode(key);
}
else if(parent->data>key){
    return addNode(parent->Lbranch,key);
}else if(parent->data<key){
   return addNode(parent->Rbranch,key);
}
}
void  Display(TreeNode *&parent){
			cout<<" "<<parent->data;
			if(parent->Lbranch!=NULL){
				Display(parent->Lbranch);
			}
			if(parent->Rbranch!=NULL){
				Display(parent->Rbranch);
			}
		}
int main (){
int size,value;
TreeNode *root= NULL;
cout<<"Enter the number of values you want to enter : ";
cin>>size;

for(int i= 0;i<size;i++){
    cout<<"Value "<<i+1<<" : ";
    cin>>value;
    addNode(root,value);
}
Display(root);

    return 0;
}