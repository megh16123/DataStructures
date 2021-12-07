#include <iostream>
using namespace std;
template <class T>
class Stack {
public:
    T data;
    Stack* link;
    Stack(){
        int data;
        link=NULL;
    }
};

 
// TO DISPLAY THE STACK

void display(Stack<int>*&head)
{
		Stack<int>*n = head;
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->link;
	}
	cout<<"\n";
} 


// TO INSERT A VALUE AT THE BEGINNING OF THE STACK
void push(Stack<int>*&head, int x){
	Stack<int> *ins_val = new Stack<int>;
	ins_val->data = x;
	ins_val->link = head;
	head = ins_val;
	display(head);	
}

void insert(Stack<int>*&head, int x){
	Stack<int>*ins_val = new Stack<int>;
	ins_val->data = x;
	ins_val->link = NULL;
	Stack<int>*n = head;
	if(n==NULL){
		head = ins_val;
	}
	else{
	   while(n->link!=NULL){
	      n=n->link;
	   }
	   n->link=ins_val;
    }
	display(head);
} 

 // TO DELETE THE BEGGINING VALUE OF STACK

void pop(Stack<int>*&head){
	Stack<int>*n = head;
	if (head == NULL){
		exit;
	}
	else{
		n = head;
		head = head->link;
		delete n;
	}
	display(head);
}

int peek (Stack<int>*&head){
	if (head == NULL){
		cout<<"Empty\n";
	}
	else {
		cout<<head->data;
	}
}



int main()
{
   	Stack<int>*head = NULL;
	char choice = 'y';
	
	while(choice=='y'){
		int element;
		cout<<"Enter the element -: ";
		cin>>element;
	insert(head,element);
		
		cout<<"If you want to add more elements press y -: ";
		cin>>choice;
		
	}

cout<<"\n Press y to perform operations -: \n";	
char input ;
cin>>input;	
while(input == 'y'){
cout<<"\n1. PUSH ";
cout<<"\n2. POP ";
cout<<"\n3. PEEK \n";
cout<<"4. DISPLAY\n";
cout<<"5. EXIT ";
int choi;
cin>>choi;

if(choi == 1){
cout<<"\nEnter the element to push -\n";
int elem;
cin>>elem;
push(head, elem);
cout<<endl;	
}	

else if (choi ==2){
pop(head);
cout<<endl;	
}
 
else if (choi == 3){
peek(head);
cout<<endl;	
} 

else if (choi == 4){
	display(head);
}

else{
	exit;
}


cout<<"To perform more (y) -:\n";
cin>>input;	
}	
	
return 0;	
}



















