
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef long long LL;

bool is_odd(int n) {
    return (n & 1) == 1 ? true : false;
}

int bit_num(LL n) {
    int cnt = 0;
    while (n > 0) {
        n >>= 1;
        cnt++;
    }
    return cnt;
}

int bit_huiwen(int n) {
    int a = (n - 1) / 2;
    int res = 2 << (a - 1);
    return res;
}


LL bit_LL(string str, int n) {
    LL ans = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        if (str[0] == '1') {
            ans += (2 << j);
            j--;
        }
    }
    return ans;
}

vector<char> bit_str(LL n) {
    vector<char> ans;
    while (n > 0) {
        if (n & 1 == 1) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
        n >>= 1;
    }
    return ans;
}


void bit_str2(LL n,vector<char>& ans) {

    while (n > 0) {
        if (n & 1 == 1) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
        n >>= 1;
    }
}

bool hui_wen(vector<char> &ans) {
    int len = ans.size();
    int mid = len / 2;
    for (int i = 0, j = len - 1; i < j && i <= mid && j >= mid; i++, j--) {
        if (ans[i] != ans[j]) {
            return false;
        }
    }
    return true;
}

int main() {

    LL n;
    cin >> n;
    int cnt = 0;
    if (n == 1 || n == 2) {
        cnt = 2;
    } else if (n == 3) {
        cnt = 3;
    } else {
        cnt = 3;
        int bit_nums = bit_num(n);
        int b = bit_nums - 1;

        for (int i = 3; i <= b; i++) {
            int temp = bit_huiwen(i);
            cnt += temp;
        }

        int temp_cnt = 0;
        LL cur = 2 << (b-1);
        while (n > cur) {
            vector<char> cache;
            bit_str2(n,cache);
            int t = cache.size();
            for(int i=0;i<cache.size();i++){
                cout<<cache[i]<<endl;
            }
            if (hui_wen(cache)) {
                temp_cnt += 1;
            }
            n--;
        }
        cnt += temp_cnt;

    }


    cout << cnt << endl;

    return 0;
}