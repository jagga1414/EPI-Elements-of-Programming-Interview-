// Imagine you have a special keyboard with all keys in a single row. The layout of characters on a keyboard is 
// denoted by a string keyboard of length 26. Initially your finger is at index 0. To type a character, you have 
// to move your finger to the index of the desired character. The time taken to move your finger from index i to index j 
// is abs(j - i).

// Given a string keyboard that describe the keyboard layout and a string text, return an integer denoting the time taken 
// to type string text.

#include <iostream>
#include <vector>

using namespace std;

int dist(string str,string keyboard){
    vector<int> arr(26);
    for(int i=0;i<keyboard.length();i++){
        arr[keyboard[i]-'a'] = i;
    }
    int ans = 0;
    int at = 0;
    for(int i =0;i<str.length();i++){
        int d = arr[str[i]-'a'];
        ans += (at-d)<0?(d-at):(at-d);
        at = d;
    }
    return ans;
}

int main(){

    string keyboard = "abcdefghijklmnopqrstuvwxy";
    string text = "cba";
    cout<<dist(text,keyboard); 
}