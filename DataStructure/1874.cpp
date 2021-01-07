//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n, criteria, check;
vector<char> r;
stack<int> a;

int main()
{
    cin >> n; a.push(criteria++);
    for(int i = 0; i < n; i++){
        cin >> check;
        while(true){
            if(check > a.top()){
                a.push(criteria++);
                r.push_back('+'); continue;
            }else if(check == a.top()){
                a.pop(); r.push_back('-');
                break;
            }else{
                cout << "NO";
                return 0;
            }
        }
    }
    
    for(char i : r) printf("%c \n", i);
    return 0;
}

