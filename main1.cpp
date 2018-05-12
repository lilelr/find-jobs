#include <iostream>
#include <vector>

using namespace std;

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

    int N;
    cin >> N;
    int n, m;
    while (N--) {
        cin >> n >> m;
        vector<int> pos;
        int tmp;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            pos.push_back(tmp);
        }
        vector<int> record;
        for (int i = 0; i < n; i++) {
            record.push_back(i);
        }

        int start = 0;
        int cur_size;
        int res;
        for (int i = 0; i <= m; i++) {
            if (i == m) {
                i = 0;
            }
            cur_size = record.size();
            if (cur_size == 1) {
                res = record[0];
                break;
            } else {
                int steps = pos[i];
                int del = steps % cur_size;
//                if (del == 0) {
//                    del = cur_size - 1;
//                } else {
//                    del--;
//                }
                start--;
                for (int j = 0; j < del; j++) {
                    start++;
                    if (start == cur_size) {
                        start = 0;
                    }
                }
                record.erase(record.begin() + start);
//                for(int item: record){
//                    cout<<"list: "<<item << " ";
//                }
//                cout<<endl;
            }

        }
        cout << res << endl;
    }


    return 0;

}