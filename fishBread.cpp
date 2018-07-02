#include <iostream>
#include <string>

using namespace std;

// n x O(n) = O(n^2)
// max(P(i) + D(n-i)), 1 <= i <= n)
// n개 팔아서 얻을 수 있는 최대 수익
int dp[1000001];
int p[10001];

int calc(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j] + p[j]);
        }
    }
    return dp[n];
}

int main() {
    int output, num, count = 1;
    string input_num;
    getline(cin, input_num);
    num = stoi(input_num);
    while(num--) {
        cin >> p[count];
        count++;
    }
    output = calc(count-1);
    cout << output << '\n';

    return 0; 
}