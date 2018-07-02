#include <iostream>

using namespace std;

long dp[91];

long calc(long n) {
    if(n <= 2) {
        return 1;
    } else {
        if(dp[n] > 0) {
            return dp[n];
        } else {
            dp[n] = calc(n - 1) + calc(n - 2);
            return dp[n];
        }
    }
}

int main() {
    long input, output;
    cin >> input;
    output = calc(input);
    cout << output << '\n';
    return 0;
}