#include <iostream>

using namespace std;

class complex{
    int imag,real;
    public:
    void input(){
     cout<<"\nEnter the real part - ";
     cin>>real;
     cout<<"\nEnter the imaginary part - ";
     cin>>imag;   
    }
    void output(){
        cout<<"The number is - "<<real<<" + "<<imag<<"i";

    }
    complex add(complex a1){
       complex c;
       c.real = this->real+a1.real;
       c.imag = this->imag + a1.imag;
       return c;
    }
    complex subtract(complex a1){
       complex c;
       c.real = this->real-a1.real;
       c.imag = this->imag - a1.imag;
       return c;
    }
    complex multiply(complex a1){
       complex c;
       c.real = this->real*a1.real;
       c.imag = this->imag * a1.imag;
       return c;
    }
};

int main(){
    int choice;
    complex c1,c2;
    char ch = 'y';
    while (ch =='y')
    {
        
    
    
    cout<<"Enter you choice \n1.Input\t2.Output\t3.add\t4.subtract\t5.Multiply";
    cin>>choice;
    switch (choice)
    {
    case 1: c1.input();
        break;
    case 2: c1.output();
        break;
    case 3: cout<<"\nEnter another number to add ";
            c2.input();
            c1.add(c2).output();
        break;
    case 4: cout<<"\nEnter another number to subtract ";
            c2.input();
            c1.subtract(c2).output();
        break;
      
    case 5: cout<<"\nEnter another number to subtract ";
            c2.input();
            c1.multiply(c2).output();
        break;
      
    
    
    default: cout<<"Enter a correct choice ";
        break;
    }
    cout<<"Do you want to continue ? ";
    cin>>ch;
    }
    return 0;
}