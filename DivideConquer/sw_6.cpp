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
#define MAX 100000
using namespace std;
int n, x, arr[1026], r, le, ri;

void divide(int num, int cut, int sum){
    int temp = 0, temp2 = 0;
    if(cut == 0){
        sum = max(arr[num] + sum, arr[num - 1] + sum);
        if(r < sum) r = sum;
        return;
    }
    for(int i = le; i < num; i++) temp = max(temp, arr[i]);
    for(int i = num; i < ri; i++) temp2 = max(temp2, arr[i]);
    int t = 1;
    for(int i = 0; i < cut - 1; i++) t *= 2;
    if(temp > temp2){
        le = num;
        divide(num + t, cut - 1, temp + sum);
    }else if(temp < temp2){
        ri = num;
        divide(num - t, cut - 1, temp2 + sum);
    }else{
        int ll = le;
        le = num;
        divide(num - t, cut - 1, temp + sum);
        le = ll;
        int rr = ri;
        ri = num;
        divide(num + t, cut - 1, temp2 + sum);
        ri = rr;
    }
}

int main() {
    cin >> n; int temp = 1; int cut = 0; ri = n;
    for(int i = 0; i < n; i++){
        if(n == temp) break;
        temp *= 2; cut++;
    }
    for(int i = 0; i < n; i++){
        cin >> x; arr[i] = x;
    }
    divide(n/2, cut - 1, 0);
    cout << r << endl;
    return 0;
}
