#include <iostream>

using namespace std;

#define MOD 1000000000
long dp[101][10];

long calc(long n, long p) {
    if(n == 1) {
        return p == 0 ? 0 : 1;
    }
    long& ref = dp[n][p];

    if(ref > 0) {
        return ref;
    }
    if(p == 0) {
        ref = calc(n-1, 1)%MOD;
        return ref;
    }
    if(p == 9) {
        ref = calc(n-1, 8)%MOD;
        return ref;
    }
    else {
        ref = ((calc(n-1, p-1) + calc(n-1, p+1)))%MOD;
        return ref;
    }
}

int main() {
    long input;
    long long output = 0;
    cin >> input;
    for(int i = 0; i <= 9; i++) {
        output += calc(input, i);
    }
    output %= MOD;
    cout << output << '\n';
    return 0;
}

// D[N][L] = D[N-1][L-1] + D[N-1][L+1] (1<=L<=8)
// D[N][0] = D[N-1][1]
// D[N][9] = D[N-1][8]
// func(n, x) = func(n-1,x-1) + func(n-1,x+1)