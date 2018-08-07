#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
const int MAXN = 60;
typedef long long LL;

// 状态，前两个记录下一节点的x,y; 后两个记录下下节点的x,y
int status[MAXN][MAXN][MAXN][MAXN];
int n, m;
int sx, sy, bx, by, tx, ty;
char mymap[MAXN][MAXN];
int ans;
char temp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 判断方向是否合法
bool legal(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m && mymap[x][y] != '#') {
        return true;
    }
    return false;
}

int main() {

    M(status,0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            mymap[i][j] = temp;
            if (temp == 'S') {
                sx = i;
                sy = j;
            }
            if (temp == 'E') {
                tx = i;
                ty = j;
            }
            if (temp == '0') {
                bx = i;
                by = j;
            }
        }
    }

    queue<vector<int>> myqueue;
    vector<int> cur = {sx, sy, bx, by};
    myqueue.push(cur);
    status[sx][sy][bx][by] = 1;
    int curx, cury;
    int nx, ny, nnx, nny;
    while (!myqueue.empty()) {
        vector<int> front = (vector<int> &&) myqueue.front();
        myqueue.pop();
        curx = front[0];
        cury = front[1];
        bx = front[2]; //上一个节点的下下节点
        by = front[3];
//        printf(" curx: %d, cury: %d, bx: %d, by: %d\n",curx,cury,bx,by);


        for (int i = 0; i < 4; i++) {
            nx = curx + dx[i]; // 当前的点下一点
            ny = cury + dy[i];
            nnx = nx + dx[i]; // 同一方向，当前点的下下一点
            nny = ny + dy[i];

//            if(curx == 0 && cury == 0){
//                int er = 3;
//                cout<<legal(nx,ny)<<endl;
//                cout<<(nx != bx && ny != by)<<endl;
//                cout<< status[nx][ny][bx][by]<<endl;
//            }
            if (legal(nx, ny) && (nx != bx || ny != by) && status[nx][ny][bx][by] == 0) {
//                printf("%d\n",status[nx][ny][bx][by]);

                // 从任意一点（包括block, 和block 周围） 到block位置
                status[nx][ny][bx][by] = status[curx][cury][bx][by] + 1;
//                printf("%d\n",status[nx][ny][bx][by]);

                myqueue.push({nx, ny, bx, by});
                continue;
            } else if ((nx == bx && ny == by) && legal(nnx, nny) && status[nx][ny][nnx][nny] == 0) {
                // 如果上一个节点的下下节点的坐标等于当前节点的下一节点坐标，表示同时移动两个节点（block 和人）
                 // 已经来到了block 的一侧
//                printf(" block: bx: %d  by: %d\n", nx,ny);
//                printf("%d\n",status[curx][cury][bx][by]);

                status[nx][ny][nnx][nny] = status[curx][cury][bx][by] + 1;
                if (mymap[nnx][nny] == 'E') {
                    cout << status[nx][ny][nnx][nny] - 1;
                    return 0;
                }

                myqueue.push({nx, ny, nnx, nny});

            }


        }


    }

    cout << -1 << endl;
    return 0;
}