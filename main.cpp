
#include <string>
#include <iostream>
#include <vector>

#include <stack>

using namespace std;

typedef long long LL;

void trim_begin(string &s) {
    while (s[0] == ' ') {
        s.erase(0);
    }
}

int main() {
    string line;
    string fi = "//";
    int cnt_fi = 0;
    string se_start = "/*";
    string se_end = "*/";
    int cnt_se = 0;

    int pre = -1;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        trim_begin(line);
        int len = line.length();
        if (len >= 2 && line[0] == '/' && line[1] == '/') {
            cnt_fi++;
            continue;
        }
        int yin_begin, yin_end;
        if (line.find('"') != line.npos) {
            yin_begin = line.find('"');
            yin_end = line.find_last_of('"');
            for (int i = yin_begin + 1; i < yin_end; i++) {
                if (line[i] == '/' && line[i + 1] == '*') {
                    line[i] = ' ';
                    line[i + 1] = ' ';
                }
                if (line[i] == '*' && line[i + 1] == '/') {
                    line[i] = ' ';
                    line[i + 1] = ' ';
                }
            }
        }
        for (int i = 0; i < len - 1; i++) {
            if (line[i] == '/' && line[i + 1] == '*') {
                if (pre == -1 || pre == 1) {
                    pre = 0;
                }
            }

            if(line[i]=='*' && line[i+1]=='/'){
                if(pre==0){
                    pre=1;
                    cnt_se++;
                }
            }

        }
    }

    int res = cnt_fi + cnt_se;
    cout<<res<<endl;
    return 0;

}
