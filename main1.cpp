#include <iostream>
#include <vector>

using namespace std;

bool is_zhi(int n){
    bool res = true;
    for(int i=2;i*i<=n;i++){
        if(n%i ==0){
            res = false;
            return res;
        }
    }
    return res;
}

int main() {

    int n;
    cin>>n;
    int cnt=0;
    vector<int> visited(n+1,0);
    for(int i=2;i<=n;i++){
        if(visited[i] ==1){
            continue;
        }
        if(i!=2 && i%2==0) continue;
        bool zhi = is_zhi(i);
        if(zhi){
            cnt++;
            for(int j=i*i;j<=n;j*=i){
                cnt++;
                visited[j] = 1;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;

}