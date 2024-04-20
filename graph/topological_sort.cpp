
#include<vector>
#include<queue>
// Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} 
// represents the Jobs U and V such that Job V can only be started only after completion 
// of Job U. The task is to determine the minimum time taken by job to be completed where 
// each Job takes unit time to get completed.
using namespace std;

vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
{
    // code here          
    vector<int>dis(n,-1);
    vector<vector<int>>adj(n);
    vector<int>ind(n,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]-1].push_back(edges[i][1]-1);
        ind[edges[i][1]-1]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
            dis[i]=1;
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto t:adj[v]){
            ind[t]--;
            // cout<<ind[t]<<endl;
            if(ind[t]==0){
                dis[t]=dis[v]+1;
                q.push(t);
            }
        }
    }
    return dis;
}