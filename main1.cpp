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

int rev(int a){
     int res=0;
    int b;
    while (a!=0){
        b = a%10;
        a = a/10;
        res+=b;
        if(a==0){
            break;
        }
        res*=10;
    }
    return res;
}

int main() {
    int x, y;
    cin >> x >> y;
    int rev_x = rev(x);
    int rev_y = rev(y);
    int sum = rev_x + rev_y;
    int res = rev(sum);
    cout<<res<<endl;

    return 0;

}