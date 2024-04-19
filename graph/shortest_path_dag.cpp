#include<vector>
#include<queue>
using namespace std;

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // code here
    vector<int>d(N,0);
    vector<int>dis(N,-1);
    vector<vector<pair<int,int>>>adj(N);
    for(auto t:edges){
        adj[t[0]].push_back(make_pair(t[1],t[2]));
        d[t[1]]++;
    }
    queue<int>q;
    for(int i=0;i<N;i++){
        if(d[i]==0){
            q.push(i);
        }
    }
    dis[0] = 0;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(auto t:adj[s]){
            if(dis[s]!=-1){
                if(dis[t.first]==-1)
                    dis[t.first] = dis[s] + t.second; 
                else{
                    dis[t.first] = min(dis[s] + t.second,dis[t.first]); 
                }
            }
            d[t.first]--;
            if(d[t.first]==0){
                q.push(t.first);
            }
        }
    }
    return dis;
}
