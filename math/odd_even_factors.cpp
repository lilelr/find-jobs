
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

bool is_odd(int n){
    return (n&1)==1 ? true: false;
}

//https://www.nowcoder.com/question/next?pid=2811407&qid=46576&tid=14865067
// 最大的奇约数
int main() {

    LL n;
    while (cin>>n){


        LL res_odd=0;
        LL res_even=0;
        LL t;
        if(is_odd(n)){
            t =  n/2+1;
            res_odd = t*(1+n)/2;
        }else{
            t = n/2;
            res_odd = t*n/2;
        }

        for(int i=1;i<=n/2;i+=2){
            for(LL j=i*2;j<=n;j*=2){
                if(j<=n){
                    res_even+=i;
                }else{
                    break;
                }
            }
        }

        LL res = res_odd + res_even;
        cout<<res<<endl;
    }
}