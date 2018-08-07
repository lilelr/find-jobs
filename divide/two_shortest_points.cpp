//
// Created by YuXiao on 8/1/18.
//

#include "two_shortest_points.h"
//  main.cpp
//  test
//
//  Created by 吴有堃 on 2017/9/11.
//  Copyright © 2017年 吴有堃. All rights reserved.
//
//https://blog.csdn.net/u013554860/article/details/78568614
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define LL long long
#define inf 0x3f3f3f3f
#define mod 1e9+7
using namespace std;
const int maxn=2e3+5;
struct Point{
    double x,y;
    int flag;
}p[maxn];
int arr[maxn];
double dis(Point a, Point b)
{
    return  sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp_x(Point a, Point b)
{
    return a.x<b.x;
}
bool cmp_y(int a, int b)
{
    return p[a].y<p[b].y;
}
double solve(int l, int r)
{
    if(r==l+1){
        if(p[l].flag!=p[r].flag){
            return dis(p[l],p[r]);
        }
        else return inf;
    }
    else if(r==l+2){
        if(p[l].flag==p[l+1].flag&&p[l+1].flag==p[l+2].flag&&p[l].flag==p[l+2].flag){//三个都相等
            return inf;
        }
        else if(p[l].flag==p[l+1].flag){//两两相等
            return  min(dis(p[l],p[l+2]),dis(p[l+1],p[l+2]));
        }
        else if(p[l].flag==p[l+2].flag){
            return min(dis(p[l],p[l+1]),dis(p[l+2],p[l+1]));
        }
        else if(p[l+1].flag==p[l+2].flag){
            return min(dis(p[l+1],p[l]),dis(p[l+2],p[l]));
        }
        else return min(dis(p[l],p[l+1]), min(dis(p[l],p[l+2]),dis(p[l+1],p[l+2])));//互不相等
    }
    int mid=(l+r)/2;
    double ans=min(solve(l,mid),solve(mid+1,r));
    int i=0,j=0,cnt=0;
    for(i=l;i<=r;i++){
        if( p[i].x>=p[mid].x-ans && p[i].x<=p[mid].x+ans ){
            arr[cnt++]=i;
        }
    }
    sort(arr,arr+cnt,cmp_y);
    for(i=0;i<cnt;i++){
        for(j=i+1;j<cnt;j++){
            if(p[arr[j]].flag!=p[arr[i]].flag){
                if(p[arr[j]].y-p[arr[i]].y>ans) break;//点开始不满足了
                ans=min(ans,dis(p[arr[j]],p[arr[i]]));
            }
        }
    }
    return ans;
}
int main()
{
    int i=0,T=0,N=0;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
            p[i].flag=1;
        }
        for(i=N;i<N+N;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
            p[i].flag=2;
        }
        sort(p,p+N+N,cmp_x);
        printf("%.3f\n",solve(0,N+N-1));
    }
    return 0;
}
