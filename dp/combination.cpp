// nCr = n-1Cr + n-1Cr-1; and nC0 = 1; nCn = 1;
#include <vector>
#include<iostream>
using namespace std;

int bottom_up(int n,int r){
    vector<vector<int> > dp(n+1,vector<int>(r+1,0));

    dp[0][0] = 1;
    for(int i = 0;i<=n;i++){
        dp[i][0]=1;
    }

    for(int i = 0;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(j==i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[n][r];
}

int main(){

    int n = 5;
    int r = 2;
    cout<<bottom_up(n,r);
}