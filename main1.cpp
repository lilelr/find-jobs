#include <bits/stdc++.h>

using namespace std;
#define M(a, b) memset(a,b,sizeof(a))

// memset(a,0x3f,sizeof(a))
//memset(a,0xcf,sizeof(a))
typedef long long LL;

const int maxn = 0x3f3f3f3f;


struct Node {
    int x, y;
};

bool node_compare(const Node &a, const Node &b) {
    return a.x < b.x;
}

struct node_compare {
    bool operator()(const Node &a, const Node &b) {
        return a.x < b.x;
    }
};

int main() {

    int n;
    cin >> n;
    int a, b;
    vector<Node> points;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        Node node;
        node.x = a;
        node.y = b;
        points.push_back(node);
    }
    sort(points.begin(), points.end(), node_compare);

    int flag[n];
    M(flag, 0);
    flag[n - 1] = 1;
    int mmaxy = points[n - 1].y;

    for (int i = n - 2; i >= 0; i--) {
        if (points[i].y < mmaxy) continue;
        mmaxy = points[i].y;
        flag[i] = 1;
    }
    for(int i=0;i<n;i++){
        if(flag[i]){
            printf("%d %d\n", points[i].x , points[i].y);
        }
    }
    return 0;
}