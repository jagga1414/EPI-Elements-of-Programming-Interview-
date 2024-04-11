#include <string>
#include<iostream>
using namespace std;

string remove(string st){
    int s=0;

    for(int i =0;i<st.length();i++){
        if(st[i]!='b'){
            st[s] = st[i];
            s++;
        }
    }
    s=0;
    for(int i=0;i<st.length();i++){
        if(st[i]=='a'){
            s+=2;
        }
        else if(st[i]!='b'){
            s++;
        }
    }
    s = s-1;

    for(int i =st.length()-1;i>=0;i--){
        if(st[i]=='a'){
            st[s]='d';
            s--;
            st[s]='d';
            s--; 
        }
        else if(st[i]!='b'){
            st[s] = st[i];
            s--;
        }
    }
    return st;
}

int main(){
    string st = "acdbbca  ";
    cout<<remove(st);
}