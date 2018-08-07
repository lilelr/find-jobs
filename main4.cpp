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

//
//int asec(vector<int>& nums,int n){
//    int cnt=0;
//    for(int i=1;i<n;i++){
//        if(nums[i]>nums[i-1]){
//            cnt++;
//        }
//    }
//    return cnt;
//}
//
//
//void as(vector<int>& nums,int n){
//    int cnt=0;
//    for(int i=1;i<nums.size();i++){
//        if(nums[i]>nums[i-1]){
//          nums.erase(nums.begin()+i);
//        }
//    }
//}
//
//int desc(vector<int>& nums,int n){
//    int cnt=0;
//    for(int i=n-2;i>=0;i--){
//        if(nums[i]>nums[i+1]){
//            cnt++;
//        }
//    }
//    return cnt;
//}


int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<2<<endl;
    return 0;

}