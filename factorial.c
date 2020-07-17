#include<stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <assert.h>
#include <time.h>   	
#include <unistd.h> 
#include <sys/types.h>
#include <unistd.h>

int factorial(mpz_t acc,  mpz_t value){
  

    mpz_t unit;
    
    mpz_init_set_ui(unit,1);
    if(!mpz_cmp (value,unit)){
        return 0;
    }
    else {
        mpz_t next;
        mpz_init(next);
        mpz_sub_ui(next,value,1);
        mpz_mul(acc,acc,value);
        return factorial(acc,next);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) return -1;
    double duration = 0.0;
    clock_t start_time = clock();
    mpz_t n;
    mpz_t acc;
    int flag;
    pid_t pid;
    pid = getpid();
    /* 1. Initialize the number */
    mpz_init(n);
    mpz_init(acc);
    mpz_set_ui(n,0);
    /* 2. Parse the input string as a base 10 number */
    flag = mpz_set_str(n,argv[1], 10);
    mpz_init_set_ui(acc,1);
    assert (flag == 0); /* If flag is not 0 then the operation failed */


    //printf("Factorial of argv %s\n",argv[1]);
    factorial(acc,n);
    //mpz_out_str(stdout,10,acc);
    //printf("\n");
    clock_t end_time = clock();
    duration += (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf(" Process id %d duration: %.13f ms factorial of %s \n",pid,duration*1000,argv[1] );
    return 0;
}
