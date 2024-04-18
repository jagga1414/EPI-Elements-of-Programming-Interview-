#include <iostream>
#include <string>

using namespace std;

int req(vector<vector<int> >&a,int i,int j){
    if(i<0||j<0||i>=a.size()||j>=a[0].size()){
        return 0;
    }
    if(i==0 and j==0){
        return 1;
    }
    if(a[i][j]!=-1){
        return a[i][j];
    }
    return a[i][j] = req(a,i-1,j) + req(a,i,j-1);
}

int main(){
    vector<vector<int> > a(5,vector<int>(5,-1));

    cout<<req(a,4,4);
}