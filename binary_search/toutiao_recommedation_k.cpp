#include <bits/stdc++.h>
// https://www.nowcoder.com/test/question/66b68750cf63406ca1db25d4ad6febbf?pid=8537209&tid=17461769
using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
const int MAXN = 305;
typedef long long LL;


struct Node {
    int prefer;
    int id;
};


bool sort_compare(const Node &a, const Node &b) {
    if (a.prefer != b.prefer) {
        return a.prefer < b.prefer;
    } else {
        return a.id < b.id;
    }
}

struct equal_compare {
    bool operator()(const Node &a, int i) {
        return a.prefer < i;
    }

    bool operator()(int i, const Node &b) {
        return i < b.prefer;
    }
};

struct find_second_cmp {
    bool operator()(const Node &a, int k) const {
        return a.id < k;
    }

    bool operator()(int k, const Node &b) const {
        return k < b.id;
    }
};


int n;
int q;
int q_l, q_r, q_k;

int main() {
    cin >> n;
    int a;
    vector<Node> records(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        Node node;
        node.prefer = a;
        node.id = i;
        records[i] = node;
    }
    sort(records.begin() + 1, records.end(), sort_compare);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> q_l >> q_r >> q_k;
        auto range = equal_range(records.begin() + 1, records.end(), q_k, equal_compare{});
        // 返回相等的区间的下标， 注意 是左闭右开， records.end() 是不包含相等的值的下标

        // upper 返回最后一个等于给定值的坐标，没有则是第一个大于给定值的坐标
        vector<Node>::iterator ans_r = upper_bound(range.first, range.second, q_r, find_second_cmp{});

        // lower 返回第一个等于给定值的坐标，没有则是第一个大于给定值的坐标

        vector<Node>::iterator ans_l = lower_bound(range.first, range.second, q_l, find_second_cmp{});
        int ans = ans_r - ans_l;
        cout << ans << endl;

    }
    return 0;

}

//
