
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef long long LL;

struct Node{
    char val;
    vector<Node> next_v;
    bool empty;
}Node;

void dfs(Node root,string& str, int cur,int len){
    if(cur==len) return;
    char cur_c = str[cur];
    if(cur_c == root.val){
        if(root.next_v.size() == 0 && cur< len-1){
            Node new_node;
            new_node.val = str[cur+1];
            root.next_v.push_back(new_node);
            dfs(new_node,str,cur+1,len);
        }else{
            if(cur<len-1){
                int cur_root_size = root.next_v.size();
                bool found=false;
                for(int i=0;i<cur_root_size;i++){
                    if(root.next_v[i].val == str[cur+1]){
                        found = true;
                        dfs(root.next_v[i],str,cur+1,len);
                        break;
                    }
                }
                if(!found){
                    Node new_node;
                    new_node.val = str[cur+1];
                    root.next_v.push_back(new_node);
                    dfs(new_node,str,cur+1,len);
                }
            }
        }
    }
}

bool dfs_find(Node root, string& str, int cur,int len){
    if(cur<len){
        if(root.val == str[cur] && root.next_v.size() == 0){
            return true;
        }

        if(root.val == str[cur]){
            for(int i=0;i<root.next_v.size();i++){
                bool found = dfs_find(root.next_v[i], str,cur+1,len);
                if(found==true){
                    return true;
                }
            }
        }
        return false;
    }

}

int main() {

    int n,m;
    cin>>n>>m;
    string tmp;
    map<char,Node> ma;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(ma.find(tmp[0])==ma.end()){
            Node newroot;
            newroot.val = tmp[0];
            newroot.empty=false;
        }else{
            Node root = ma[tmp[0]];
            dfs(root, tmp, 0,tmp.length());
        }

    }
    int res = 1;
    for(int i=0;i<m;i++){
        cin>>tmp;
    }

    return 0;
}