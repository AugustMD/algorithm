#include <iostream>
#include <cmath>

using namespace std;

long long count(long long a, long long i) {
    int c = 1;
    if(a < i) {
        return 0;
    }
    while(1) {
        long long temp = a/pow(i,c);
        if(temp == 0) {
            return c-1;
        }
        c++;
    }
    return 0;
}

long long factorial(long long c, long long a, long long i) {
    if(c == 0) {
        return 0;
    } else {
        long long temp = a/pow(i,c);
        return temp + factorial(c-1,a,i);
    }
}

int main() {
    long long n, m, output, two, five;
    scanf("%lld %lld",&n,&m);
    // printf("%lld %lld %lld\n",factorial(count(n),n),factorial(count(m),m),factorial(count(n-m),n-m));
    two = factorial(count(n,2),n,2) - factorial(count(m,2),m,2) - factorial(count(n-m,2),n-m,2);
    five = factorial(count(n,5),n,5) - factorial(count(m,5),m,5) - factorial(count(n-m,5),n-m,5);
    output = min(two,five);
    printf("%lld\n",output);
    return 0;
}

//  n/5 + n/5^2 + n/5^3 + n/5^4 ...