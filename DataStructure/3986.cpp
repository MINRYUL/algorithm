//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n, r;
string v[101];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    for(int i = 0; i < n; i++){
        stack<char> s;
        s.push(v[i][0]);
        for(int j = 1; j < v[i].size(); j++){
            if(!s.size()) s.push(v[i][j]);
            else if(v[i][j] == s.top()) s.pop();
            else s.push(v[i][j]);
        }
        if(!s.size())   r++;
    }
    cout << r << endl;
    return 0;
}

