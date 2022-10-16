#include <iostream>
#include <cmath>
#include <iomanip>

#define LAMBDA 0.000000000000001

using namespace std;

double function(double x,unsigned int type){//function selection

    try{
        if(type<1 && type>4){
            throw ("Wrong type");
        }

        float example_function;

        if(type == 1){
            example_function = sin(x);
        }

        else if(type == 2){
            example_function = cos(x);
        }

        else if(type == 3){
            example_function = tan(x);
        }

        else{
            example_function = x;
        }

        return example_function;
    }

    catch(char*err){
        cout<<err;
    }
    

    return 0;
}

double bisection(double minimum_x,double maximum_x,unsigned int type){//function for splitting function in range(min_x,max_x) untill x-intercept's found

    double x_intercept = (minimum_x + maximum_x) / 2.0;

    while(abs(function(x_intercept,type))>LAMBDA){
        
        if(function(minimum_x,type)*function(x_intercept,type)<=0){
            maximum_x = x_intercept;
        }

        else if(function(maximum_x,type)*function(x_intercept,type)<=0){
            minimum_x = x_intercept;
        }

        else{
            cout<<"\nNo x-intercepts in this range\n";
        }

        x_intercept = (minimum_x + maximum_x) / 2.0;
    
    }

    return(x_intercept);

}



main(){//basic test
    cout<<setprecision(20);
    cout<<bisection(1,4,1);
    return 0;
}