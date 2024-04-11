#include <iostream>
#include <string>

using namespace std;

int decoder(string st){

    int ans = 0;
    int mul = 1;
    for(int i =st.length()-1;i>=0;i--){
        ans+= (st[i]-'A'+1)*mul;
        mul *= 26;
    }
    return ans;
}

int main(){
    string st = "ZZ";
    cout<<decoder(st);

}