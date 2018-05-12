//
// Created by YuXiao on 5/12/18.
//

//作者：向宇同卓
//        链接：https://www.nowcoder.com/discuss/80839?type=0&order=0&pos=27&page=1
//        来源：牛客网
//
////第五题通过的代码，有需要的参考下。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
 int n, m;
 cin >> n >> m;

 vector<vector<int>> T(n, vector<int>(m));

 for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
   cin >> T[i][j];
  }
 }

 vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));

 for (int i = m - 1; i >= 0; i--) {
  for (int j = 0; j < n; j++) {
   if (i == m - 1) { 第 m-1 列，即最后一列
    dp[j][i].first = T[j][i];
    dp[j][i].second = abs(T[j][i]);
   }
   else {

    if (j == 0) {// 第0行
//  往后走 只有 第0行，第1 行可选择
     int tmp = max(dp[j][i + 1].first, dp[j + 1][i + 1].first);
     if (tmp < 0) dp[j][i].first = T[j][i];
     else dp[j][i].first = T[j][i] + tmp;
     int tmp2 = max(dp[j][i + 1].second, dp[j + 1][i + 1].second);
     if (tmp < 0) dp[j][i].second = max(tmp2 + T[j][i], abs(T[j][i]));
     else  dp[j][i].second = max(tmp2 + T[j][i], tmp + abs(T[j][i]));
    }
    else if (j == n - 1) { // 最后一行，
     int tmp = max(dp[j - 1][i + 1].first, dp[j][i + 1].first);
     if (tmp < 0) dp[j][i].first = T[j][i];
     else dp[j][i].first = T[j][i] + tmp;
     int tmp2 = max(dp[j - 1][i + 1].second, dp[j][i + 1].second);
     if (tmp < 0) dp[j][i].second = max(tmp2 + T[j][i], abs(T[j][i]));
     else  dp[j][i].second = max(tmp2 + T[j][i], tmp + abs(T[j][i]));
    }
    else {
     int tmp = max(max(dp[j - 1][i + 1].first, dp[j][i + 1].first), dp[j + 1][i + 1].first);
     if (tmp < 0) dp[j][i].first = T[j][i];
     else dp[j][i].first = T[j][i] + tmp;
     int tmp2 = max(max(dp[j - 1][i + 1].second, dp[j][i + 1].second), dp[j + 1][i + 1].second);
     if (tmp < 0) dp[j][i].second = max(tmp2 + T[j][i], abs(T[j][i]));
     else  dp[j][i].second = max(tmp2 + T[j][i], tmp + abs(T[j][i]));
    }

   }
  }
 }

 int res = 0;

 for (int i = 0; i < n; i++) {
  res = max(res, dp[i][0].second);
 }
 cout << res << endl;

 return 0;
}