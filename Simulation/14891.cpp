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
using namespace std;
int n, x, y, result, arr[5][9];

void roRight(int a){
    int temp = arr[a][0];
    for(int i = 1; i < 8; i++){
        int t = arr[a][i];
        arr[a][i] = temp;
        temp = t;
    }
    arr[a][0] = temp;
}
void roLeft(int a){
    int temp = arr[a][7];
    for(int i = 6; i >= 0; i--){
        int t = arr[a][i];
        arr[a][i] = temp;
        temp = t;
    }
    arr[a][7] = temp;
}
void recu(int a, int b, int c){
    if(!a || a > 4) return;
    if(!c){
        if(arr[a + 1][6] != arr[a][2]){
            if(b == -1){
                recu(a - 1, 1, c);
                roLeft(a);
            }else{
                recu(a - 1, -1, c);
                roRight(a);
            }
        }
    }else{
        if(arr[a - 1][2] != arr[a][6]){
            if(b == -1){
                recu(a + 1, 1, c);
                roLeft(a);
            }else{
                recu(a + 1, -1, c);
                roRight(a);
            }
        }
    }
}

int main(void) {
    for(int i = 1; i < 5; i++)
        for(int j = 0; j < 8; j++) scanf("%1d", &arr[i][j]);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(y == -1){
            recu(x - 1, 1, 0);
            recu(x + 1, 1, 1);
            roLeft(x);
        }else{
            recu(x - 1, -1, 0);
            recu(x + 1, -1, 1);
            roRight(x);
        }
    }
    int sum = 1;
    for(int i = 1; i < 5; i++){
        if(arr[i][0]) result += sum;
        sum *= 2;
    }
    cout << result << endl;
    return 0;
}
