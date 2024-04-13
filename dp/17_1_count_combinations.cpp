#include <iostream>
#include <vector>

using namespace std;

int req(int a[],int j,int n,int score){
    if(score==0){
        return 1;
    }

    if(score<0 or j>=n){
        return 0;
    }

    return req(a,j,n,score - a[j]) + req(a,j+1,n,score);

}

// variant 1
int bottom_up(int a[],int n,int score){
    vector<int> dp(score+1,0);
    vector<int> p(score+1,0);
    dp[0] =1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=score;j++){
            if(i==0){
                if(j==0)
                    continue;
                dp[j] = j-a[i]<0?0:dp[j-a[i]];
                // cout<<dp[j]<<endl;
            }
            else{
                dp[j] = j-a[i]<0?p[j]:p[j]+dp[j-a[i]];
            }
        }
        p = dp;   
    }
    return dp[score];
}
// permutation variant 2 
int req2(int a[],int n,int score){
    if(score<0){
        return 0;
    }
    if(score == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = ans + req2(a,n,score-a[i]);
    }
    return ans;
}

int main(){
    
    int a[] = {2,3,7};
    int score = 20;
    // int dp[score] = {0};
    cout<<req2(a,3,12);

}