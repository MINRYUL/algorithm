//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath> //pow, sqrt
#include <cstring> //memset
#include <utility> //pair
using namespace std;

class Tri_Node {
private:
    Tri_Node* child[10];
 
public:
    Tri_Node() {
        for (int i = 0; i < 10; i++)
            child[i] = NULL;
    }
    ~Tri_Node() {
        for (int i = 0; i < 10; i++)
            if (child[i] != NULL)
                delete child[i];
    }
    int tonum(char c){ return tolower(c) - '0'; }

    void insert(const char* words) {
        if (*words == '\0') return;
        int next = tonum(*words);
        if (child[next] == NULL) {
            child[next] = new Tri_Node();
        }
        child[next]->insert(words + 1);
    }
 
    bool find(const char* words) {
        int next = tonum(*words);
        if (*words == '\0') return true;
        if (child[next] == NULL) return false;
        return child[next]->find(words + 1);
    }
};
bool cmp(string a, string b){
    return a.size() > b.size();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), cmp);
    Tri_Node tri;
    for(int i = 0; i < phone_book.size(); i++){
        if (tri.find(phone_book[i].c_str()))
            return false;
        else
            tri.insert(phone_book[i].c_str());
    }
    return true;
}

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    solution({"12","223","3335","567","8"});
    return 0;
}
