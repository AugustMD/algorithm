#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001], arr[1001], n;

int calc(int i) {
    int& ref = dp[i];
    if(ref > -1) {
        return ref;
    }
    ref = 1;
    for(int j = i+1; j <= n; j++) {
        if(arr[i] < arr[j]) {
            ref = max(ref,calc(j)+1);
        }
    }
    return ref;
}

int main() {
    int output = 1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&arr[i]);
    }
    memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= n; i++) {
        output = max(output,calc(i));
    }
    printf("%d\n", output);
    return 0;
}

// D[n] : max(D[j]);