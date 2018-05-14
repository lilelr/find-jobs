//
// Created by YuXiao on 5/14/18.
//
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
// test
// 4 3
//1 -4 10
//3 -2 -1
//2 -1 0
//0 5 -2

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> T(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> T[i][j];
        }
    }

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));
    for (int i = m - 1; i >= 0; i--) {// 先观察第一个for循环与 下面dp[j][i] 的关系， 即先对列遍历，从最后一列往前到第一列
        for(int j=0;j<n;j++){// 然后观察 j的变化范围 0——n, 从第一行到最后一行
            if(i==m-1){ //第 m-1 列，即最后一列,初始化
                dp[j][i].first = T[j][i];  // first 记录 没有一个负数变为正数
                dp[j][i].second = abs(T[j][i]); // second 记录当前路径上有且仅有一个数变正数
            }else{
                if(j==0) { // 第 0 行
                    //  往后走 只有 第0行，第1 行可选择
                    int tmp = max(dp[j][i+1].first, dp[j+1][i+1].first);
                    if(tmp<0){
                        dp[j][i].first = T[j][i];
                    }else{
                        dp[j][i].first = T[j][i]+tmp;
                    }
                    int tmp2 = max(dp[j][i+1].second,dp[j+1][i+1].second);
                    if(tmp<0){
                        dp[j][i].second = max(tmp2+T[j][i],abs(T[j][i]));
                    }else{
                        dp[j][i].second = max(tmp2+T[j][i], tmp+abs(T[j][i]));
                    }
                }else if(j==n-1){ // 最后一行
                    int tmp= max(dp[j-1][i+1].first, dp[j][i+1].first);
                    if(tmp<0){
                        dp[j][i].first = T[j][i];
                    }else{
                        dp[j][i].first = tmp+T[j][i];
                    }
                    int tmp2 = max(dp[j-1][i+1].second, dp[j][i+1].second);
                    if(tmp<0){
                        dp[j][i].second = max(tmp2+T[j][i], abs(T[j][i]));
                    }else{
                        dp[j][i].second = max(tmp2+T[j][i], tmp+abs(T[j][i]));
                    }
                }else{
                     //中间行数
                    // 没有一个负数变为正数
                    int tmp = max(max(dp[j-1][i+1].first, dp[j][i+1].first), dp[j+1][i+1].first);
                    if(tmp<0){
                        dp[j][i].first = T[j][i];
                    }else{
                        dp[j][i].first = tmp+T[j][i];
                    }
                    // 从第0列到到当前i列都没有把负数变正数， 从第i+1 列到第m-1 列有可能有一列的值变为正数
                    int tmp2 = max(max(dp[j-1][i+1].second, dp[j][i+1].second), dp[j+1][i+1].second);
                    if(tmp<0){
                        // tmp2+T[j][i] 因为tmp2 刻画了已经改变的数，所以 当前数T[j][i]不能从负数变为正数
                        dp[j][i].second = max(tmp2+T[j][i],abs(T[j][i]));
                    }else{
                        // tmp+abs(T[j][i]) 当前数变为正数，其余的数不能变了，即为first 的结果，所以加上tmp
                        dp[j][i].second = max(tmp2+T[j][i],tmp+abs(T[j][i]));
                    }
                }
            }
        }
    }
    int res =0;
    for(int i=0;i<n;i++){
        res = max(res, dp[i][0].second);
    }
    cout<<res<<endl;
}