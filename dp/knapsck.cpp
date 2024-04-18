#include<iostream>
#include<vector>

using namespace std;

int knap(vector<int>&wt, vector<int> &val, int i,int W){
    if(i>=wt.size()){
        return 0;
    }
    if(W<=0){
        return 0;
    }
    if(W-wt[i]>=0){
        return max(knap(wt,val,i+1,W-wt[i])+val[i],knap(wt,val,i+1,W));
    }
    return knap(wt,val,i+1,W);
}

int mini(vector<int> &arr,int i,int ts){
    if(i>=arr.size()){
        return 0;
    }

}

int main(){
    vector<int> wt;
    vector<int> val;
    int i = 0,W = 10;
    cout<<knap(wt,val,i,W);
}