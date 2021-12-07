#include<iostream>

using namespace std;

template <typename Lallan,typename lol>
int adder(Lallan a,lol b){
return a+b;
}
int main(){
    int a =20, b = 40;
    float c = adder(a,b);

cout<<c;
return 0;
}