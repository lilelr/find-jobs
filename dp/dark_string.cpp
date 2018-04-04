
#include <string>
#include <iostream>

#include <cmath>
using namespace std;

typedef long long LL;

//https://www.nowcoder.com/question/next?pid=2811407&qid=46576&tid=14854246
// [编程题] 暗黑的字符串 dp
// https://www.cnblogs.com/JSONBEAN/p/6433755.html
int main() {
//    cout<<(3^2)<<endl;
    int n;
    cin>>n;
    if(n==1){
        cout<<3;
        return 0;
    }
    if(n==2){
        cout<<9;
        return 0;
    }



    LL res=0;

    LL a = 3;
    LL b = 9;

    for(int i=0;i<n-2;i++){
        res = 2*b+a;
        a = b;
        b = res;
    }

    cout<<res;
    return 0;
}