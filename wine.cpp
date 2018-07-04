#include <iostream>
#include <cstring>

using namespace std;

int dp[10001][3];

int maximum(int x, int y, int z) {
    return max(max(x,y),z);
}

int calc(int n, int p, int arr[]) {
    if(n == 0) {
        return 0;
    }
    int& ref = dp[n][p];
    if(ref > -1) {
        return ref;
    }
    int a = calc(n-1,0,arr);
    int b = calc(n-1,1,arr);
    int c = calc(n-1,2,arr);
    if(p == 0) {
        ref = max(calc(n-1,0,arr),calc(n-1,1,arr));
        return ref;
    }
    if(p == 1) {
        ref = max(calc(n-1,0,arr),calc(n-1,2,arr)) + arr[n];
        return ref;
    }
    else {
        ref = calc(n-1,0,arr) + arr[n];
        return ref;
    }
}

int main() {
    int num, wine, output;
    scanf("%d", &num);
    int arr[num+1];
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= num; i++) {
        scanf("%d", &wine);
        arr[i] = wine;
    }
    output = maximum(calc(num, 0, arr),calc(num, 1, arr),calc(num, 2, arr));
    printf("%d\n", output);
    return 0;
}

// D[n][0] : 선택 안함 = max(D[n-1][0],D[n-1][1])
// D[n][1] : 처음 선택 = max(D[n-1][0],D[n-1][2]) + A[n]
// D[n][2] : 두번째 선택 = max(D[n-1][0]) + A[n]

// max(D[n][0],D[n][1],D[n][2])