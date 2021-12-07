#include<iostream>
template <class T>
class Node
{
public:
    T data;
    Node* next;
    Node(T val)
    {
        data=val;
        next=NULL ;
    }
    
};
// Creating a class Queue
template <class X>
class queue
{
public:
    Node<X>* front;
    Node<X>* rear;

    queue()
    {
        front=rear=NULL;
    }
//Enqueue operation in queue 
template <typename T>
    void Enqueue(T x)
    {
        Node<T>*new_Node=new Node<T>(x);
        if(rear==NULL)
        {
            front=rear=new_Node;
            
        }
        else
        {   rear->next=new_Node;
            rear=rear->next;
        }
    }
//Dequeue operation in queue
template <typename T>
    void deQueue(T dummy)
    {
        if(front==NULL)
        {
            std::cout<<"Queue is Already empty\n";
            return;
        }
        if(front->next==NULL)
        {
            front=rear=NULL;
            return;
        }
        Node<T>*temp=front;
        front=front->next;
        delete temp;
    }
// Displaying the Value of Front And Rear Element
    void DispValue()
    {
        std::cout<<" \nFront value is "<< front->data;
        std::cout<<" \nRear value is\n "<< rear->data;
    }
//Checking is Queue is Empty or Not
    void IsEmpty()
    {
        if(front==NULL && rear ==NULL)
        {
            std::cout<<"Queue is empty\n";
        }
        else
        std::cout<<" Queue is not empty\n";
    }
//Displaying the data of Queue
template <typename T>
    void display(T dummy)
    {
        Node<T>*disp=front;
        std::cout<<" Value of linked list is :"<< std::endl;
        std::cout<<"\t"<<disp->data;
        while (disp->next!=NULL)
        {
            std::cout <<"\t"<<disp->next->data;
            disp=disp->next;
        }
    }
};

int main ()
{
    char ch;
    queue<int> Q;
    do
    {
        std::cout<<" Enter ur choice to perform operation :"<<std::endl;
        std::cout<<" Enter 1 to Enqueue The queue"<<std::endl;
        std::cout<<" Enter 2 to Dequeue The queue"<<std::endl;
        std::cout<<" Enter 3 for Displaying the front and rear value"<<std::endl;
        std::cout<<" Enter 4 for checking queue is Empty or Not "<<std::endl;
        std::cout<<" Enter 5 to Display the Value of Linked list"<<std::endl;
        int choice;
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            std::cout<< " Enter value for Enqueue"<<std::endl;
            int EndVal;
            std::cin>>EndVal;
            Q.Enqueue(EndVal);
            Q.display(1);
            break;
        case 2:
            Q.deQueue(1);
            Q.display(1);
            break;    
        case 3:
            Q.DispValue();
            Q.display(1);
            break;
        case 4:
            Q.IsEmpty();
            Q.display(1);
            break;
        case 5:
            Q.display(1);
            break;
        default:
            break;
        }
        std::cout<<"\n\nEnter Y for Performimg more opertion otherwise press any key"<<std::endl;
            std::cin>>ch;
    } while (ch=='Y'||ch=='y');
   
    return 0;
}