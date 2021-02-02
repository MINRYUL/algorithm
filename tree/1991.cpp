//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring> //memset
#include <utility> //pair
#define MAX 101
using namespace std;
vector<int> t[30];
int s1, s2, s3;

void preorder(int x){
    if(x == -1)  return;
    cout << char(x + 65);
    preorder(t[x][0]);
    preorder(t[x][1]);
    
}

void inorder(int x){
    if(x == -1)  return;
    inorder(t[x][0]);
    cout << char(x + 65);
    inorder(t[x][1]);
}

void postorder(int x){
    if(x == -1)  return;
    postorder(t[x][0]);
    postorder(t[x][1]);
    cout << char(x + 65);
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char x, y, z;
        cin >> x >> y >> z;
        if(y != 46) t[x - 65].push_back(y - 65);
        else t[x - 65].push_back(-1);
        if(z != 46) t[x - 65].push_back(z - 65);
        else t[x - 65].push_back(-1);
    }
    
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    return 0;
}
