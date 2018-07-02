#include <iostream>

using namespace std;

int dp[1001];

int calc(int n) {
    if(n <= 2) {
        return n;
    }
    else {
        if(dp[n] > 0) {
            return dp[n];
        }
        dp[n] = calc(n - 1) + calc(n - 2);
        return dp[n] % 10007;
    }
}

int main() {
    int input, output;
    cin >> input;
    output = calc(input);
    cout << output << "\n";
    return 0;
}