#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;
unordered_set<string> myset;

string pair_left;
string pair_right;

bool legal(string str) {
    int len = str.length();
    if (len == 0) return false;
    if (str[0] == '0' && len >= 2 && str[1] != '.') return false;
    if (str[0] == '.' || str[len - 1] == '.') return false;
    if (str.find('.') != string::npos && str[len - 1] == '0') return false;
//    cout<<"legal： "<<str<<endl;
    return true;
}

vector<string> add_point(string str) {
    int len = str.length();
    string temp;
    vector<string> res;
    if (legal(str)) {
        res.push_back(str);
    }
    string backup=str;
    for (int i = 1; i < len; i++) {
        temp = str.insert(i, ".");
//        cout <<"temp: "<< temp << endl;
        if (legal(temp)) {
            res.push_back(temp);
        }
        str = backup;
//        if(a==1){
//            pair_left = temp;
//        }else{
//            pair_right = temp;
//        }
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    int len = str.length();
    string bakup = str;
    for (int i = 1; i < len; i++) {
        string left = str.substr(0, i);
        string right = str.substr(i);
//        cout<<left<<endl;
//        cout<<right<<endl;
        vector<string> left_pairV = add_point(left);
        vector<string> right_pairV = add_point(right);

        int left_len = left_pairV.size();
        int right_len = right_pairV.size();
        for (int j = 0; j < left_len; j++) {
            string cur_left = left_pairV[j];
            for (int k = 0; k < right_len; k++) {
                string cur_right = right_pairV[k];

                string cur_pair1 = cur_left+"#"+cur_right;
                string cur_pair2 = cur_right+"#"+cur_left;

                if (myset.find(cur_pair1) == myset.end() && myset.find(cur_pair2) == myset.end()) {
                    myset.insert(cur_pair1);
                }

            }
        }

    }
    int ans = myset.size();
    cout << ans << endl;

    return 0;

}