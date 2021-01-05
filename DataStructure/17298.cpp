//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n, temp, arr[1000001], result[1000001];
stack<int> s;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        while(s.size() && arr[s.top()] < arr[i]){
            result[s.top()] = arr[i]; s.pop();
        }
        s.push(i);
    }
    while(s.size()){
        result[s.top()] = -1; s.pop();
    }
    for(int i = 0; i < n; i++) cout << result[i] << ' ';
    return 0;
}

