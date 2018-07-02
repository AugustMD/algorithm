#include <iostream>

using namespace std;

// n->1 만드는데 필요한 연산의 최소값
int dp[1000001];
int cnt = 0;

int devide(int n) {
    if(n <= 1) {
        return 0;
    }
    if(dp[n] > 0) {
        return dp[n];
    }
    // 처음 저장하기 위함
    dp[n] = devide(n - 1) + 1;
    // 2 비교
    if(n%2 == 0) {
        int temp = devide(n / 2) + 1;
        if(dp[n] > temp) {
            dp[n] = temp;
        }
    }
    // 3 비교
    if(n%3 == 0) {
        int temp = devide(n / 3) + 1;
        if(dp[n] > temp) {
            dp[n] = temp;
        }
    }
    return dp[n];
}

int main() {
    int input, output;
    cin >> input;
    output = devide(input);
    cout << output << '\n';
    return 0;
}