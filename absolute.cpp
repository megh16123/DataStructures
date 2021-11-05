//absolute value
#include<iostream>
#include<math.h>
using namespace std;

double absolute(double var)
{
    if (var<0.0)
         var=(-var);
    return var;
}

float absolute(float var)
{
    if (var<0.0)
        var=(-var);
    return var;
}
int absolute(int var)
{
    if(var<0)
       var=(-var);
    return var;
}

int main()
{
    cout<<"Absolute value of -3 = "<<absolute(-3)<<endl;
    cout<<"Absolute value of 3.5 (float) = "<<absolute(3.5f)<<endl;
    cout<<"Absolute value of 3.5 (double) = "<<absolute(3.5)<<endl;
    return 0;
}