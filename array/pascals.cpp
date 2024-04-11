#include <vector>

using namespace std;
class Solution{
public:
    int mod = 1e9 + 7;
    vector<long long> pascal(vector<long long>prev, int i){
        vector<long long> ans(prev.size()+1,0);
        for(int i = 0;i<ans.size();i++){
            if(i==0){
                ans[i] = prev[i];
            }
            else if(i == ans.size()-1){
                ans[i] = 1;
            }
            else{
                ans[i] = (prev[i-1] + prev[i])%mod;
            }
        }
        return ans;
    }
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long> prev;
        vector<long long> cur;
        prev.push_back(1);
        for (int i =2;i<=n;i++){
            cur = pascal(prev,i);
            prev = cur;
        }
        return prev;
    }
};