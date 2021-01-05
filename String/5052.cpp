//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#define MAX 10001
using namespace std;
int t, n;
char s[MAX][11];

struct Trie {
    bool term; Trie* next[10];
    Trie() : term(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 10; i++)
            if (next[i])
                delete next[i];
    }
    void insert(const char* key){
        if(*key=='\0') term=true;
        else{
            int curr = *key-'0';
            if(next[curr]==NULL)
                next[curr]=new Trie();
            next[curr]->insert(key+1);
        }
    }
    bool find(const char* key){
        if(*key=='\0') return 0;
        if(term) return 1;
        int curr = *key-'0';
        return next[curr]->find(key+1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        int r = 0, num = 0; Trie *root = new Trie;
        for(int i = 0; i < n; i++) cin >> s[num++];
        
        for(int i = 0; i < n; i++)
            root -> insert(s[i]);
        for(int i = 0; i < n; i++)
            if(root -> find(s[i])) r = 1;
        cout << (r ? "NO" : "YES") << endl;
    }
    return 0;
}
