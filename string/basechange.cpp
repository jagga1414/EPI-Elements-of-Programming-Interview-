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
string convertb(int n,int b){
    string ans ="";
    cout<<n<<b<<endl;
    while(n!=0){
        // cout<<n%b<<endl;
        if(n%b>=10){
            ans+= 'A'+n%b -10;
        }
        else
            ans += '0'+n%b;
        n = n/b;
        // cout<<n<<endl;
    }
    return reverse(ans);
}
string convert(string st,int a,int b){
    string ans="";
    int n = 0;
    for(int i = 0;i<st.length();i++){
        n *= a;
        n += (st[i]-'0'<=9 and st[i]>=0)?st[i]-'0': st[i]-'A'+10;
    }
    // cout<<n<<endl;
    return convertb(n,b);
}

int main(){
    int a = 7,b = 3;
    string st = "134";
    cout<<convert(st,a,b);

}