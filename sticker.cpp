#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[100001][3];

int maximum(int x, int y, int z){
    return max(max(x,y),z);
}

int calc(int n, int p, int arr[][3]) {
    if(n == 0) {
        return 0;
    }
    int& ref = dp[n][p];
    if(ref > -1) {
        return ref;
    }
    if(p == 0) {
        ref = maximum(calc(n-1,0,arr),calc(n-1,1,arr),calc(n-1,2,arr));
        return ref;
    }
    if(p == 1) {
        ref = maximum(calc(n-1,0,arr),calc(n-1,2,arr),0) + arr[n][1];
        return ref;
    }
     else {
        ref = maximum(calc(n-1,0,arr),calc(n-1,1,arr),0) + arr[n][2];
        return ref;
    }
}

int main() {
    int t, input_arr, n, output;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int arr[n+1][3];
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= 2; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 0) {
                    arr[j][i] = 0;
                } else {
                    scanf("%d", &input_arr);
                    arr[j][i] = input_arr;
                }
            }
        }
        output = maximum(calc(n,0,arr),calc(n,1,arr),calc(n,2,arr));
        printf("%d\n", output);
    }
    return 0;
}

// D[N][0] = max(D[N-1][0],D[N-1][1],D[N-1][2])
// D[N][1] = max(D[N-1][0],D[N-1][2]) + L[n][1]
// D[N][2] = max(D[N-1][0],D[N-1][1]) + L[n][2]

// max(D[N][0], D[N][1], D[N][2])