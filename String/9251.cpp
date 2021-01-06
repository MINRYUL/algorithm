//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n[1001][1001], i, j;
string s1, s2;
int main()
{
    cin >> s1 >> s2 ;
    
    for (i = 1; i <= s1.size(); i++){
        for (j = 1; j <= s2.size(); j++){
            if (s1[i-1] == s2[j-1]) n[i][j] = n[i-1][j-1] + 1;
            else n[i][j] = max(n[i-1][j], n[i][j-1]);
        }
    }
    
    cout << n[s1.size()][s2.size()] << endl;
    return 0;
}

