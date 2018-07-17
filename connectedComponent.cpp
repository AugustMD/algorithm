#include <cstdio>
#include <vector>

using namespace std;

vector<int> a[1001];
vector<bool> check(1001);

void dfs(int x) {
    check[x] = true;
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if(!check[y]) {
            dfs(y);
        }
    }
}

int main() {
    int n_num, v_num, u, v, ans = 0;
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n_num, &v_num);

    for(int i = 1; i <= v_num; i++) {
        scanf("%d %d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    for(int i = 1; i <= n_num; i++) {
        if(!check[i]) {
            dfs(i);
            ans += 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}