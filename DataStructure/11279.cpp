//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
unsigned int n, x;
priority_queue<unsigned int> pq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        cin >> x;
        if(x) pq.push(x);
        else{
            if(pq.size()){
                printf("%u \n", pq.top()); pq.pop();
            }else printf("0 \n");
        }
    }
    return 0;
}
