
#include <string>
#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// 完全背包问题
// https://www.nowcoder.com/question/next?pid=2811407&qid=46577&tid=14854246

int main() {
    int n;
    while (cin >> n) {
        if (n < 6 || n == 7) {
            cout << -1 << endl;
            continue;
        }
        if (n == 6 || n == 8) {
            cout << 1 << endl;
            continue;
        }

        vector<int> dp(n + 1, 1000);

        dp[6] = 1;
        dp[8] = 1;
        for (int j = 6; j <= n; j++) {
            if (dp[j] > dp[j - 6] + 1) {
                dp[j] = dp[j - 6] + 1;
            }
        }
        for (int j = 8; j <= n; j++) {
            if (dp[j] > dp[j - 8] + 1) {
                dp[j] = dp[j - 8] + 1;
            }
        }

        if(dp[n] == 1000){
            cout<<-1<<endl;
        }else{
            cout<<dp[n]<<endl;

        }
    }
    return 0;
}