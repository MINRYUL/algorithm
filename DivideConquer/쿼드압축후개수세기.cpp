#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int m;
int r[3] = {0, };

int divide(int I, int Sx, int Sy, int Ex, int Ey, const vector<vector<int>>& arr){
    
    int num = arr[Sx][Sy];
    if(I == 1){ return num; }
    int a = divide(I/2, Sx, Sy, Ex - I/2, Ey - I/2, arr);
    int b = divide(I/2, Sx + I/2, Sy, Ex, Ey - I/2, arr);
    int c = divide(I/2, Sx, Sy + I/2, Ex - I/2, Ey, arr);
    int d = divide(I/2, Sx + I/2, Sy + I/2, Ex, Ey, arr);
    if(a == b && b == c && c == d) {
        if(I == m) r[a] += 1;
        return a;
    }
    else{
        if(a != 2) r[a] += 1;
        if(b != 2) r[b] += 1;
        if(c != 2) r[c] += 1;
        if(d != 2) r[d] += 1;
    }
    return 2;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int num = arr.size();
    m = num;
    divide(num, 0, 0, num, num, arr);
    answer.push_back(r[0]);
    answer.push_back(r[1]);
    return answer;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    solution({{0, 0}, {0, 0}});
    return 0;
}


