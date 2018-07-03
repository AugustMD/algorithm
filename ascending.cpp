#include <iostream>

using namespace std;

#define MOD 10007

long dp[1001][10];

long calc(int n, int p) {
    if(n == 1) {
        return 1;
    }
    long& ref = dp[n][p];
    if(ref > 0) {
        return ref;
    }
    for(int i = 0; i <= p; i++) {
        ref += calc(n-1, i);
        ref %= MOD;
    }
    return ref;
}

int main() {
    int input;
    long output = 0;
    cin >> input;
    for(int i = 0; i <= 9; i++) {
        output += calc(input, i);
    }
    output %= MOD;
    cout << output << '\n';
    return 0;
}

// D[N][P] = SUM(D[N-1][K]) (0 <= K <= P)