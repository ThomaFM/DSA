#include <bits/stdc++.h>
using namespace std;
//Code Assumes possible alphabet is continues sequence of ascii values
//change -'a' to first letter of alphabet.
const int ALPHASIZE = 26;
struct node {
    bool isWord = false;
    vector<node*> children;
    node() {
        children = vector<node*>(ALPHASIZE, nullptr);
    }

    void insert(string &s, int idx) {
        if(idx == s.size()) {isWord = true; return;}
        if(!children[s[idx]-'a'])
            children[s[idx]-'a'] = new node();
        children[s[idx]-'a'] -> insert(s, idx+1);
    }

    bool find(string &s, int idx) {
        if(idx == s.size()) return isWord;
        if(!children[s[idx]-'a']) return false;
        return children[s[idx]-'a'] -> find(s, idx+1);
    }
};