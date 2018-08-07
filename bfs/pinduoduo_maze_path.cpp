
// https://blog.csdn.net/u012102841/article/details/76862262
//2017.8.1拼多多内推内推笔试题（4）—迷宫寻路（状态压缩+BFS）
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;
int n, m, sx, sy, ex, ey;
char g[1024][1024];
int use[120][120][1400];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct node {
    int x, y, k;
};

int bfs() {
    memset(use, 0xff, sizeof(use));
    queue<node> q;
    node t;
    t.x = sx;
    t.y = sy;
    t.k = 0;
    use[t.x][t.y][t.k] = 0;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        //printf("%d %d %d %d\n",t.x,t.y,t.k,use[t.x][t.y][t.k]);
        if (t.x == ex && t.y == ey) return use[t.x][t.y][t.k];
        for (int i = 0; i < 4; i++)//上下左右
        {
            node k;//分别往上下左右走
            k.x = t.x + dx[i];
            k.y = t.y + dy[i];
            k.k = t.k;
            if (k.x < 0 || k.x >= n || k.y < 0 || k.y >= m || g[k.x][k.y] == '0') continue;//直接进入下次循环
            if (g[k.x][k.y] >= 'a' && g[k.x][k.y] <= 'z') {
                k.k = k.k | (1 << (g[k.x][k.y] - 'a'));//走到钥匙点捡起钥匙
            }
            if (g[k.x][k.y] >= 'A' && g[k.x][k.y] <= 'Z') {
                int p = k.k & (1 << (g[k.x][k.y] - 'A'));//走到门处匹配钥匙
                if (p == 0) continue;//没有钥匙直接进入下次循环
            }
            if (use[k.x][k.y][k.k] == -1 || use[k.x][k.y][k.k] > use[t.x][t.y][t.k] + 1)//第一个条    件保证BFS，第二个条件保证不走墙
            {
                use[k.x][k.y][k.k] = use[t.x][t.y][t.k] + 1;
                q.push(k);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '2') {
                sx = i;
                sy = j;
            }//储存起点
            if (g[i][j] == '3') {
                ex = i;
                ey = j;
            }//储存终点
        }
    }
    printf("%d\n", bfs());
    return 0;
}