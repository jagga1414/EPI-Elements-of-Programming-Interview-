#include <string>
#include <iostream>

using namespace std;

bool check(string s,string t,int pi){
    for(int i = 0;i<s.length();i++){
        if(s[i]!= t[i+pi]){
            return false;
        }
    }
    return true;
}

int rbk(string st, string t){
    if(st.length()>t.length()){
        return -1;
    }
    int kbase = 26;
    int thase = 0,shase = 0,power = 1;
    for(int i = 0;i<st.length();i++){
        power = i?power*kbase:1;
        thase = thase*kbase + t[i];
        shase = shase*kbase + st[i];
    }
    int pi = 0;
    for(int i = st.size();i<t.length();i++){
        if(thase==shase and check(st,t,pi)){
            return pi;
        }
        thase -= st[pi]*power;
        thase = thase*kbase + st[i];
        pi++; 
    }
    if(thase==shase and check(st,t,pi)){
            return pi;
    }
    return -1;
}