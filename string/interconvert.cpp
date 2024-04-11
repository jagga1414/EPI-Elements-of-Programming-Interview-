#include <string>
#include <iostream>

using namespace std;

string reverse(string st){
    int a =0;
    int b = st.length()-1;
    while(a<b){
        char c = st[a];
        st[a] = st[b];
        st[b] = c;
        a++;
        b--;
    }
    return st;
}

string convert(int a){
    string ans="";
    while(a!=0){
        char c = '0'+a%10;
        ans+=c;
        a = a/10;
    }
    return reverse(ans);
}

int main(){
    int n = 134;
    cout<<convert(n);

}