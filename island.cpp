#include <cstdio>
#include <cstring>

using namespace std;
int a[50][50];
int d[50][50];
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int g_x, g_y;

void dfs(int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int k=0; k<8; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < g_x && 0 <= ny && ny < g_y) {
            if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}

int main() {
    while(1) {
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        scanf("%d %d",&g_y,&g_x);
        if(g_x == 0 && g_y == 0) break;
        for(int i = 0; i < g_x; i++) {
            for(int j = 0; j < g_y; j++) {
                scanf("%1d",&a[i][j]);
            }
        }

        int cnt = 0;

        for(int i = 0; i < g_x; i++) {
            for(int j = 0; j < g_y; j++) {
                if(a[i][j] == 1 && d[i][j] == 0) {
                    dfs(i,j,++cnt);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}