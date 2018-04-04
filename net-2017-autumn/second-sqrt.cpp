
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



int main() {
    int n;
    cin>>n;
    int cnt=0;
    for(int x=1;x*x<=n;x++){
        int y = (int)sqrt(n-x*x);
        if(x*x + y*y == n){
            cnt++;
        }
    }
    cout<<cnt*4<<endl;
    return 0;
}