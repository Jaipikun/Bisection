#include <iostream>
#include <cmath>

#define LAMBDA 0.0000001

using namespace std;

float function(float x,unsigned int type){//function selection

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

float bisection(float minimum_x,float maximum_x,unsigned int type){//function for splitting function in range(min_x,max_x) untill x-intercept's found

    float x_intercept = (minimum_x + maximum_x) / 2.0;

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
    cout<<bisection(1,4,1);
    return 0;
}