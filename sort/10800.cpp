//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring>
#define MAX 200001
using namespace std;
int n, c, s, before, num, sum, color;

struct ICS{
    int size, color, index, sum;
}ics[MAX];

struct CMS{
    int sum, before, num;
}cms[MAX];

bool compare(const ICS& p1, const ICS& p2){
    if (p1.size == p2.size) return p1.color < p2.color;
    return p1.size < p2.size;
}
bool compare2(const ICS& p1, const ICS& p2){
    return p1.index < p2.index;
}
int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c >> s;
        ics[i].color = c; ics[i].size = s; ics[i].index = i;
    }
    sort(ics, ics + n, compare);
    
     //- (cms[ics[i].color].before * cms[ics[i].color].num)
    
    for(int i = 0; i < n; i++){
        if(before == ics[i].size){
            if(color == ics[i].color){
                ics[i].sum = sum - cms[ics[i].color].sum - (before * (num - cms[ics[i].color].num));
                cms[ics[i].color].num++;
            }
            else{
                ics[i].sum = sum - cms[ics[i].color].sum - (before * num);
                cms[ics[i].color].num = 1;
            }
            num++;
        }
        else{
            ics[i].sum = (sum - cms[ics[i].color].sum);
            num = 1; cms[ics[i].color].num = 1;
        }
        
        sum += ics[i].size; before = ics[i].size; color = ics[i].color;
        cms[ics[i].color].sum += ics[i].size; cms[ics[i].color].before = ics[i].size;
    }
    
    sort(ics, ics + n, compare2);
    for(int i = 0; i < n; i++) cout << ics[i].sum << '\n';
    return 0;
}
