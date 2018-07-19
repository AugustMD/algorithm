#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
vector<int> a(100001);
vector<int> check(100001);
vector<int> o(100001);
int cnt; int ans;

int dfs(int x, int cnt, int origin) {
    if(check[x] != 0) {
        if(origin != o[x]) {
            return 0;
        }
        return cnt - check[x];
    }
    check[x] = cnt;
    o[x] = origin;
    return dfs(a[x],cnt+1,origin);
}

int main() {
    int test_case, v, n, ans;
    // freopen("input.txt", "r", stdin);
    scanf("%d\n", &test_case);
    while(test_case--) {
        ans = 0; cnt = 0;
        scanf("%d\n",&n);
        for(int u = 1; u <= n; u++) {
            scanf("%d",&a[u]);
        }
        for(int u = 1; u <= n; u++) {
            if(check[u] == 0) {
                ans += dfs(u,1,u);;
            }
        }
        printf("%d\n", n-ans);
        fill(a.begin(), a.end(), 0);
        fill(check.begin(), check.end(), 0);
        fill(o.begin(), o.end(), 0);
    }
    return 0;
}