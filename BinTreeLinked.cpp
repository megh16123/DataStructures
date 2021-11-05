#include<iostream>

using namespace std;

class TreeNode{
public:
int data ;
TreeNode *Lbranch,*Rbranch;
TreeNode(){
    data = int(NULL);
    Lbranch = NULL;
    Rbranch = NULL;
}
};



void CreateNode(TreeNode *&parent){
 parent = new TreeNode();
int choice;
cout<<"Enter the data for the  node : ";
cin>>parent->data;
cout<<"Enter the choice : \n 1. Left \t 2. Right \t 3. Both \t4. Exit \n Choice :- ";
cin>>choice;
while (choice == 1 || choice == 2 || choice == 3)
{
    switch (choice)
    {
    case 1:  CreateNode(parent->Lbranch);
             choice = 4;
        break;
    case 2: CreateNode(parent->Rbranch);
            choice = 4;
        break;
    case 3: CreateNode(parent->Lbranch);
            CreateNode(parent->Rbranch);
          choice = 4;

        break;
    
    default: choice = 4;
                break;
        break;
    }
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

int main(){
    TreeNode *root = new TreeNode();
    CreateNode(root);
    Display(root);
    return 0;
}