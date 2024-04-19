#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<iostream>

using namespace std;

// int transform(int s,int t,unordered_map<int,vector<int>>mp,vector<int>&vis){

//     if(vis[s]==1){
//         return false;
//     }
//     if(s==t){
//         return true;
//     }
//     vis[s]=1;
//     for(auto k:mp[s]){
//         if(vis[k]==0){
//             if(transform(k,t,mp,vis)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool distLess(string a,string b){
    if(a.size()!=b.size()){
        return false;
    }
    int cnt =0;
    for(int i =0;i<a.length();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
        if(cnt>=2){
            return false;
        }
    }
    return true;
}

int main(){
    string st = "cot";
    string tt = "bat";
    vector<string> dc;
    dc.push_back("cat");
    dc.push_back("cut");
    dc.push_back("but");
    int sint = 0;
    int tint = dc.size()+1;
    vector<vector<int> > adj(dc.size()+2);
    for(int i=0;i<dc.size();i++){
        for(int j=i+1;j<dc.size();j++){
            if(distLess(dc[i],dc[j])){
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    for(int i =0;i<dc.size();i++){
        if(distLess(st,dc[i])){
            adj[0].push_back(i+1);
                adj[i+1].push_back(0);
        }
    }
    for(int i =0;i<dc.size();i++){
        if(distLess(tt,dc[i])){
            adj[dc.size()+1].push_back(i+1);
                adj[i+1].push_back(dc.size()+1);
        }
    }

    if(distLess(tt,st)){
            adj[dc.size()+1].push_back(0);
            adj[0].push_back(dc.size()+1);
            return 1;
    }

    int dis =0;
    queue<int> q;
    q.push(0);
    vector<int> vis(dc.size()+2,0);
    vis[0] =1;
    bool flag = false;
    while(!q.empty()){
        int sz = q.size();
        dis++;
        for(int i=0;i<sz;i++){
            int v = q.front();
            q.pop();
            for(auto t:adj[v]){
                if(vis[t]==0){
                    vis[t]=1;
                    q.push(t);
                }
                if(t==tint){
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
        
    }
    cout<<dis;
    return 0;
}