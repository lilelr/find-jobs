//
// Created by YuXiao on 3/31/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;



int main() {
    string s;
    while(cin>>s){
        int len = s.length();
        string str2 = s;
        int k=0;
        for(int i=len-1;i>=0;i--){
            str2[k++] = s[i];
        }
        vector<vector<int>> dp(len+1);
        for(int i=0;i<len+1;i++){
            dp[i] = vector<int>(len+1,0);
        };
        for(int i=0;i<len+1;i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for(int i=1;i<len+1;i++){
            for(int j=1;j<len+1;j++){
                if(s[i-1] == str2[j-1]){ // 注意dp 从1 开始，但字符串string 依然从0开始下标
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
//        cout<<str2<<endl;
//        int max_c_len = dp[len][len];
//        cout<<max_c_len<<endl;
//        cout<<len<<endl;
        int result = len - dp[len][len];
        cout<<result<<endl;


    }

    return 0;
}