//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
string s, c;

int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        c.push_back(s[i]);
        if(c.size() > 4){
            string k;
            for(int i = 0; i < 4; i++){
                k += c.back(); c.pop_back();
            }
            reverse(k.begin(), k.end());
            if(k == "PPAP") c.push_back('P');
            else c.append(k);
        }
    }
    if(c == "PPAP" || c == "P") cout << "PPAP" << endl;
    else cout << "NP" << endl;
    
    return 0;
}

