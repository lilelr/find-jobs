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

vector<int> get_factors(int n) {
    vector<int> res;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res.push_back(i);
            int quo = n / i;
            if (quo != i) {
                res.push_back(quo);
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    int len = m - n + 1;
    vector<int> steps(len, INT_MAX);
    steps[0] = 0;
    for (int pos = n; pos < m; pos++) {
        if (steps[pos - n] != INT_MAX) {
            vector<int> factors = get_factors(pos);
            for (int i = 0; i < factors.size(); i++) {
                int item = factors[i];
                int next_pos = pos + item;
                if(next_pos>m){
                    continue;
                }
                if (steps[pos - n] + 1 < steps[next_pos - n]) {
                    steps[next_pos - n] = steps[pos - n] + 1;
                }
            }
        }
    }
    if (steps[len - 1] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << steps[len - 1] << endl;
    }
    return 0;

}