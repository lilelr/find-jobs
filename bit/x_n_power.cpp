//
// Created by YuXiao on 4/15/18.
//

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

typedef long long LL;

LL power_n(int x, int n){
    LL ans =1;
    LL temp = x;
    while (n>0){
        if(n&1 == 1){
            ans = ans * temp;
        }
        n = n>>1;
        temp = temp * temp;
    }
    return ans;
}

int main(){
    LL ans = power_n(5,1);
    cout<<ans<<endl;
}