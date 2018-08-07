
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <sstream>

using namespace std;
typedef long long LL;

int convertFromString(const string &s) {
    istringstream i(s);
    int x;
    i >> x;
    return x;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

vector<string> split(const string &str, const string &delim) {
    vector<string> res;
    if ("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}

const int maxn=102;
#define M(a, b) memset(a,b,sizeof(a))

int vis[maxn];
int main() {
    int n, ju;
    cin >> n >> ju;
    vector<vector<int>> grid(n, vector<int>());
    string str;
    getline(cin,str);

    for (int i = 0; i < n; i++) {
        getline(cin,str);
        vector<string> split_res = split(str, " ");
        for (int j = 0; j < split_res.size(); j++) {
            int temp = convertFromString(split_res[j]);
            grid[i].push_back(temp);
//            cout << temp << " ";
        }
//        cout << endl;
    }
    int ans=-1;
    int mmax = -1;
    for(int i=0;i<n;i++){
        int cnt=0;
        if(i!=ju && find(grid[i].begin(), grid[i].end(),ju)==grid[i].end()){
            M(vis,0);
            for(int j=0;j<grid[i].size();j++){
               vis[grid[i][j]]++;
            }

            for(int k=0;k<grid[ju].size();k++){
                if(vis[grid[ju][k]] ==1){
                    cnt++;
                }
            }
            if(cnt > mmax){
                mmax = cnt;
                ans  = i;
            }


        }

    }
    cout<<ans<<endl;

    return 0;


}

