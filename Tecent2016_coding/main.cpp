
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

int getValue(vector<int> gifts, int n) {
    if(n==0) return 0;
    if(n==1) return gifts[0];
    map<int,int> record;
    int half = n/2;
    for(int i=0;i<n;i++){
        if(record.find(gifts[i])!=record.end()){
            record[gifts[i]]++;

            if(record[gifts[i]] > half){
                return gifts[i];
            }
        }else{
            record[gifts[i]] = 1;
        }
    }
//    for(auto iter = record.begin();iter!=record.end();iter++){
//        cout<<iter->first<<" "<<iter->second<<endl;
//    }
    return 0;

}

int main() {
//   vector<int> gifts = {1,2,3,2,2};
 //  vector<int> gifts = {1};
   vector<int> gifts = {1,2,3};
    int result = getValue(gifts,3);
    cout<<result<<endl;
}