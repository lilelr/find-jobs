
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
// https://www.nowcoder.com/question/next?pid=9763997&qid=152606&tid=14638198
// hash 记录已计算过的值
using namespace std;

map<pair<long,long>,long> mp;
long func(vector<long> & v, long w, long index){
    if(w < 0) return 0;
    if(index == static_cast<long>(v.size())) return w>=0;

    pair<long,long> status(w,index);
    if(mp.find(status) != mp.end()) return mp[status];
    mp[status] = func(v,w,index+1) + func(v,w-v[index],index+1);
    return mp[status];
}


void package_dp(){
    long n;
    long weight;
    while (cin >> n >> weight) {
        vector<long> nums;
        long t;
        long m = n;
        nums.push_back(-1);
        while (m--) {
            cin >> t;
            nums.push_back(t);
        }
        vector<vector<long>> dp(n+1);
        for(long i=0;i<=n;i++){
            dp[i] = vector<long>(weight+1,1);
        }
        for(long j=0;j<=weight;j++){
            dp[0][j] = 1;
        }

        for(long i=1;i<=n;i++){
            for(long j=nums[i];j<=weight;j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i]];
            }
        }

        long result = dp[n][weight];
        cout<<result<<endl;
        nums.clear();
        dp.clear();
    }
}
int main() {

    long n,w;
    cin>>n>>w;
    vector<long> v(n);
    for(long i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<func(v,w,0)<<endl;


    return 0;

}