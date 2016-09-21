/*This function accepts n and return n!*/

unsigned int fact(unsigned int n){
	unsigned int rc=1;
	if(n > 1){
		rc=n * fact(n-1);
	}

	return rc;
}
unsigned fib(unsigned int n){
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
double pow(double base, unsigned int n){
    double rc=1;
    for(int i=0;i<n;i++){
        rc=rc*base;
    }
    return rc;
 }

