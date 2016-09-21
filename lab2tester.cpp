/*Lab 2 tester
To compile:
g++ lab2.cpp lab2tester.cpp timer.cpp -std=c++11
*/
#include <iostream>
#include <cstdlib>
#include "timer.h"
using namespace std;

unsigned int factorial(unsigned int n);
unsigned fibonacci(unsigned int n);
double power(double base, unsigned int n);
unsigned int fact(unsigned int n);
unsigned fib(unsigned int n);
double powR(double base, unsigned int n);

int main(int argc, char* argv[]){
    if(argc >2 ){
        cout << "usage: a.out [<n for fib function>, used for getting timing]" << endl;
    }
    else{
        bool isGood=true;
        for(int i=0;i<13 && isGood;i++){
            if(factorial(i)!=fact(i)){
                cout << "bug in your fact() function." << endl;
                cout << "fact(" << i << ") should return " << factorial(i) << endl;
                cout << "Your function returned: " << fact(i) << endl;
                isGood = false;
            }
        }
        if(isGood){
            cout << "fact() is working properly" << endl;
            for(int i=0;i<31 && isGood;i++){
                if(power(2,i)!=pow(2,i)){
                    cout << "bug in your pow() function." << endl;
                    cout << "pow(2," << i << ") should return " << power(2,i) << endl;
                    cout << "Your function returned: " << pow(2,i) << endl;
                    isGood = false;
                }
            }
        }
        if(isGood){
            cout << "pow() is working properly" << endl;
            for(int i=0;i<30 && isGood;i++){
                if(fibonacci(i)!=fib(i)){
                    cout << "bug in your fib function." << endl;
                    cout << "fib(" << i << ") should return " << fibonacci(i) << endl;
                    cout << "Your function returned: " << fib(i) << endl;
                    isGood = false;
                }
            }

        }
        if(isGood){
            cout << "fib() is working properly" << endl;
            unsigned int n=10;
            if(argc == 2){
                n=atoi(argv[1]);
            }
            Timer t;
            t.start();
            fib(n);
            t.stop();
            cout << "fib("<< n << ") took " <<  t.currtime() << " s" << endl;
        }

    }
    return 0;
		
}

//this function returns n! (read: n factorial).  n! = n * (n-1) * (n-2) * ... * 1
//ex. 5! = 5*4*3*2*1
//by definition, 0! = 1
unsigned int factorial(unsigned int n){
    unsigned int i;
    unsigned int rc=1;
    for(i=n;i>0;i--){
        rc=rc*i;
    }
    return rc;
}

//this function returns the n'th fibonaci number.  A fibonacci number is a sum of the two
//previous fibonacci numbers.  f0 = 0, f1=1, f2=f1+f0
unsigned fibonacci(unsigned int n){
    unsigned int rc;
    unsigned int nMinus1;
    unsigned int nMinus2;
	if(n == 0){
	   rc=0;
    }
    else if(n==1){
    	rc=1;
    }
    else{
    	nMinus1=1;
    	nMinus2=0;
    	for(int i=2;i<=n;i++){
    		rc=nMinus1 + nMinus2;
    		nMinus2=nMinus1;
    		nMinus1=rc;
    	}
    }
    return rc;
}

//this function returns base^n (base raised to power of n).  base^n = base*base*...base (multiply n times)
//thus 3^5= 3*3*3*3*3
double power(double base, unsigned int n){
    double rc=1;
    for(int i=0;i<n;i++){
        rc=rc*base;
    }
    return rc;
}