
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


vector<string> getGray(int n) {
    if(n==0) {return vector<string>(1,"0");}

    if(n==1){
        vector<string> res = {"0","1"};
        return res;
    }else{
        vector<string> pre = getGray(n-1);
        vector<string> res;
        int len = pre.size();
        for(string item:pre){
            cout<<item<<endl;
        }
        string temp;
        for(int i=0;i<len;i++){
            temp = "0"+pre[i];
            res.push_back(temp);

        }
        for(int i=len-1;i>=0;i--){
            temp = "1"+pre[i];
            res.push_back(temp);
        }
        return res;
    }

}
int main() {
    vector<string> res = getGray(3);
//    for(string item:res){
//        cout<<item<<endl;
//    }
    return 0;
}