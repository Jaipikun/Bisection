#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#define LAMBDA 0.000000000000001

using namespace std;

double Test_function(double x)
{
    double function = sin(x);
    return function;
}

double Test_function2(double x)
{
    double function = (x-2.34)*(x+2.521);
    return function;
}

double bisection(double minimum_x,double maximum_x,double (*function)(double))
{
    ofstream data;
    data.open("bisection.txt");
    data.precision(20);

    double x_intercept = (minimum_x + maximum_x) / 2.0;

    if(function(minimum_x)*function(x_intercept)<=0 && function(maximum_x)*function(x_intercept)<=0)
    {
        data<<bisection(x_intercept,maximum_x,function)<<endl;
    }

    while(abs(function(x_intercept))>LAMBDA)
    {
        
        if(function(minimum_x)*function(x_intercept)<=0)
        {
            maximum_x = x_intercept;
        }

        else if(function(maximum_x)*function(x_intercept)<=0)
        {
            minimum_x = x_intercept;
        }

        else
        {
            cout<<"\nNo x-intercepts in this range\n";
        }

        x_intercept = (minimum_x + maximum_x) / 2.0;
    
    }

    data<<x_intercept<<endl;
    data.close();
    return x_intercept;

}



main(){//basic test
    cout<<setprecision(20);
    
    bisection(-5,5,Test_function2);

    bisection(1,4,Test_function);
    return 0;
}