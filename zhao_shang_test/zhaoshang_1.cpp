
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;

const int FIN = 100000007;

int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<int> dp(n, 0);
        dp[0] = x[0];
        dp[1] = max(x[0], x[1]);
        if (n - 1 == 1) {
            cout << dp[1] << endl;
            continue;
        }

        vector<int> cache(n);
        vector<int> buf(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cache[i] = x[0];
            } else if (i == 1) {
                cache[1] = max(x[0], x[1]);
            } else {
                cache[i] = max(x[i] + cache[i - 2], cache[i - 1]);
            }

//            cout<<"i: "<<i<<" "<<cache[i]<<endl;
        }

//        cout<<endl;

        for (int j = 1; j < n; j++) {
            if (j == 1) {
                buf[j] = x[1];
            } else if (j == 2) {
                buf[2] = max(x[1], x[2]);
            } else {
                buf[j] = max(x[j] + buf[j - 2], buf[j - 1]);
            }
//            cout<<"j: "<<j<< " "<<buf[j]<<endl;
        }


        int res = max(cache[n - 2], buf[n - 1]);
        cout << res << endl;
    }

    return 0;

}
