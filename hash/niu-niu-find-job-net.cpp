
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// https://www.nowcoder.com/test/question/46e837a4ea9144f5ad2021658cb54c4d?pid=9763997&tid=14638605

// 作者：NotDeep
//链接：https://www.nowcoder.com/discuss/70736
//        来源：牛客网
//
//        分析
//实际上对于每个难度的工作，只有报酬最高的那一种是可能成为答案的，剩下的都可以无视。
//由于只有N项工作和M个小伙伴，最多只会出现N+M种难度(能力值)，所以可以把难度和能力值映射到不超过N+M个数上(std通过排序+map来完成)。
//对这些难度(能力值)分别求出最高的报酬，再按i从小到大的顺序维护难度(能力值)不超过i的最大报酬。最后输出每个小伙伴对应的能力值以下的最高报酬即可。
//
//时间复杂度
//        O((N+M)*log(N+M))
int R = 2000005;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> pi(n);
    vector<int> di(n);
    vector<int> ab(m);
    vector<int> val(n + m);
    vector<int> ans(n + m);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> di[i] >> pi[i];
        val[i] = di[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ab[i];
        val[i + n] = ab[i];
    }
    sort(val.begin(), val.end());
    int cnt = 0;
    mp[val[0]] = cnt;

    for (int i = 1; i < n + m; i++) {
        if (val[i] != val[i - 1]) {
            mp[val[i]] = ++cnt;
        }
    }

    for (int i = 0; i < n; i++) {
        ans[mp[di[i]]] = max(ans[mp[di[i]]],pi[i]);
    }
//    cout << "ans.size" << ans.size() << endl;
//    for (int a:ans) {
//        cout << a << endl;
//    }

    for (int i = 1; i <= cnt; i++) {
        ans[i] = max(ans[i - 1], ans[i]);
//        cout << endl;
//        cout << ans[i] << endl;
//        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[mp[ab[i]]] << endl;
    }

}