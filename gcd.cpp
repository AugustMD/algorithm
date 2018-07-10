#include <iostream>

using namespace std;

long gcd(long a, long b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    long t, n, a[101], sum;
    scanf("%ld",&t);
    while(t--) {
        sum = 0;
        scanf("%ld",&n);
        for(int i = 0; i < n; i++) {
            scanf("%ld",&a[i]);
            if(i > 0) {
                for(int j = 0; j < i; j++) {
                    sum = sum + gcd(a[i],a[j]);
                }
            }
        }
        printf("%ld\n",sum);
    }
    return 0;
}