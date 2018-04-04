//
// Created by YuXiao on 3/31/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
// 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？

//输入例子1:
//6
//45 12 45 32 5 6
//
//输出例子1:
//1 2

int main() {
    int n;
    while (cin>>n){
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());

        int num_max = 0;
        int num_min = 0;

        int ma = nums[n-1];
        int mi = nums[0];
        if(ma == mi){ // 最大值和最小值相等，组合数学公式
            num_max = n*(n-1)/2;
        }else{ // 求最大值和最小值的个数，计算count从0开始
            int mi_c =0, ma_c =0;
            for(int i=0;i<n;i++){
                if(mi == nums[i]){
                    mi_c++;
                }else{
                    break;
                }
            }

            for(int i=n-1;i>=0;i--){
                if(ma == nums[i]){
                    ma_c++;
                }else{
                    break;
                }
            }
            num_max = ma_c * mi_c;
        }

        // 计算差最小的对个数
        int dif_min =INT_MAX;

        for(int i=0;i<n-1;i++){
            nums[i] = nums[i+1]-nums[i];
            dif_min = min(dif_min,nums[i]);
        }
        if(dif_min == 0){ // 类1 如何差为0，说明有数相等
            int count = 0;
            bool flag = false;

            for(int i=0;i<n-1;i++){
                if(nums[i] == dif_min){
                    if(!flag){
                        flag = true;
                    }
                    count++;
                }else{
                    flag = false;
                    if(count>0){
                        int t = count*(count+1)/2; //相邻两个数不等，求前面相等的数的对数，注意一定要count > 0
                        num_min += t;
                    }
                    count =0;
                }
            }
            if(count>0){ //最后一轮中，数相等
                int t = count*(count+1)/2;
                num_min += t;
            }
        }else{ // 没有相等的差值，说明原数组中每个数都不一样。求差值最小的对数，就把 dif_min 个数累加即可
            for(int i=0;i<n-1;i++){
                if(dif_min == nums[i]){
                    num_min++;
                }
            }
        }

        cout<<num_min<<" "<<num_max<<endl;


    }

    return 0;
}