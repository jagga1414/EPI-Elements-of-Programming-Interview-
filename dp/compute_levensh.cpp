#include <string>
#include <iostream>

using namespace std;

int req(string s1, string s2, int i , int j){
    if(i==s1.length()){
        return s2.length()-j;
    }
    if(i==s2.length()){
        return s1.length()-j;
    }

    if(s1[i]==s2[j]){
        return req(s1,s2,i+1,j+1);
    }
    return min(min(req(s1, s2, i+1,j)+1,req(s1,s2,i,j+1)+1),req(s1,s2,i+1,j+1)+1);
}

int bottom_up(string s1,string s2,int i,int j){
    
    vector<vector<int> > dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for(int i =0;i<=s1.length();i++){
        dp[i][0] = i;
    }
    for(int i =0;i<=s2.length();i++){
        dp[0][i] = i;
    }

    for(int i=1;i<=s1.length();i++){
        for(int j = 1;j<=s2.length();j++){
            if(s1[i]==s2[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else
                dp[i][j] = min(min(dp[i-1][j-1]+1,dp[i-1][j]+1),dp[i][j-1]+1);
        }

    }
    return dp[s1.length()][s2.length()];
}

// variant 2

string req2(string s1, string s2, int i , int j){
    if(i==s1.length()){
        return "";
    }
    if(i==s2.length()){
        return "";
    }

    if(s1[i]==s2[j]){
        return s1[i] + req2(s1,s2,i+1,j+1);
    }
    string a = req2(s1,s2,i+1,j);
    string b = req2(s1,s2,i,j+1);
    return a.length()<b.length()?b:a;
}


int main(){

    string s1 = "hello";
    string s2 = "hel";
    cout<<req2(s1,s2,0,0);
}