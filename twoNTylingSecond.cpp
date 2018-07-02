#include <iostream>

using namespace std;

int dp[1001];

int calc(int n) {
    if(n <= 1) {
        return 1;
    }
    else {
        if(dp[n] > 0) {
            return dp[n];
        }
        dp[n] = (calc(n - 1) + calc(n - 2) * 2) % 10007;
        return dp[n];
    }
}

int main() {
    int input, output;
    cin >> input;
    output = calc(input);
    cout << output << "\n";
    return 0;
}
