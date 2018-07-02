#include <iostream>
#include <string>

using namespace std;

int dp[1001];

int calc(int n) {
    if(n == 0) {
        return 1;
    }
    if(n <= 2) {
        return n;
    } else {
        if(dp[n] > 0) {
            return dp[n];
        } else {
            dp[n] = calc(n - 1) + calc(n - 2) + calc(n - 3);
            return dp[n];
        }
    }
}

int main() {
    int input;
    string input_num, output;
    getline(cin, input_num);
    int num = stoi(input_num);
    while(num--) {
        cin >> input;
        output = output + to_string(calc(input)) + '\n';
    }
    cout << output;
    return 0;
}