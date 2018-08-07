#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;
#define M(a, b) memset(a,b,sizeof(a))
const int MAXN = 305;
typedef long long LL;


bool is_zhi(int n) {
    bool res = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = false;
            return res;
        }
    }
    return res;
}

int main() {

    string input;
    cin>>input;
    int n;
    int len = input.length();
    input.insert(input.begin(),'#');
    int k = len/4;
    n = k+1;
    vector<vector<char>> grid(n,vector<char>());
    int i;
    for( i=1;i<=n;i++){
        grid[0].push_back(input[i]);
    }

    int space_len = k-1;
//    for(int j=1;j<=n-2;j++){
//
//    }
    for(int j=1;j<=n-2;j++){
        for(int b=1;b<=space_len;b++){
            grid[j].push_back(' ');
        }
        grid[j].push_back(input[i]);
        i++;
    }
    for(int j=1;j<=n;j++){
        grid[n-1].insert(grid[n-1].begin(),input[i]);
        i++;
    }

    for(int a = n-2;a>=1;a--){
        grid[a].insert(grid[a].begin(),input[i]);
        i++;
    }

    for(int j=0;j<n;j++){
        for(int a=0;a<grid[j].size();a++){
            cout<<grid[j][a];
        }
        if(j!=n-1){
            cout<<endl;
        }
    }


    return 0;

}