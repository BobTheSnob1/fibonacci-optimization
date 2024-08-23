#include <stdio.h>
#include <time.h>
#include <malloc.h>

unsigned long long *fibs;

unsigned long long mean(unsigned long long* nums, int nums_amount) {
    unsigned long long out = 0;
    for(int i=0;i<nums_amount;i++){
        out += nums[i];
    }
    return out/nums_amount;
}

unsigned long long fib(int n) {
    if(fibs[n] != 0) {
        return fibs[n];
    }else{
        unsigned long long out  = fib(n-1) + fib(n-2);
        fibs[n] = out;
        return out;
    }
}

int fib_timeboxed() {
    unsigned long long n = 0;
    clock_t end_time;
    double time_spent;

    clock_t start_time = clock();

    fibs = (unsigned long long *)calloc(10000000, sizeof(unsigned long long));
    fibs[0] = 1;
    fibs[1] = 1;

    do {
        unsigned long long x = fib(n);
        n++;
        end_time = clock();
        time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    } while (time_spent < 0.1);
    printf("%llu\n", fibs[10]);
    return n;
    free(fibs);
}

int main() {

    unsigned long long fib_reached[10];

    for(int i=0;i<10;i++){
        fib_reached[i] = fib_timeboxed();
    }

    printf("Fibonacci sequence calculated 10 times for 0.1s each. Highest ns reached:\n");
    for(int i=0;i<10;i++){
        printf("%llu \n", fib_reached[i]);
    }
    printf("Mean highest n reached: %llu", mean(fib_reached, 10));

    return 0;
}
