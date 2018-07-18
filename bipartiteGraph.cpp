#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
vector<int> a[20001];
vector<int> check(20001);
string ans;

void dfs(int x, int type) {
    check[x] = type;
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if(check[y] == 0) {
            dfs(y, 3-check[x]);
        }
        if(check[x] == check[y]) {
            ans = "NO";
        }
    }
}

int main() {
    int k, v_num, e_num, v, e;
    // freopen("input.txt", "r", stdin);
    scanf("%d\n", &k);
    while(k--) {
        scanf("%d %d",&v_num,&e_num);
        ans = "YES";
        for(int i = 1; i <= e_num; i++) {
            scanf("%d %d",&v,&e);
            a[v].push_back(e); a[e].push_back(v);
        }
        for(int i = 1; i <= v_num; i++) {
            if(check[i] == 0) {
                dfs(i,1);
            }
        }
        cout << ans << '\n';
        for(auto& i: a) i.clear();
        fill(check.begin(), check.end(), 0);
    }
    return 0;
}