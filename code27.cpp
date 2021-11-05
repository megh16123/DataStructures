#include<iostream>

using namespace std;
class circle{
int radius;
static float pi;
public:
circle(int rad){
  radius = rad;
}
void caclulateArea(){
 cout<<"The area of circle is - "<<pi*radius*radius;   
}
static void unitCircleArea(int i){
   cout<<"The area of a circle with radius "<<i<<" is - "<<pi*i*i; 
}
};
float circle::pi = 3.14;
int main(){

circle::unitCircleArea(3);

}