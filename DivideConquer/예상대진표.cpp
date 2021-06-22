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
#include <stdlib.h>
using namespace std;

int divide(int n, int a, int b){
    int num = n/2;
    if(num == 1) return 1;
    if(num >= a && num < b){
        int cut = 0;
        while(n){ cut += 1; n /= 2; }
        return cut - 1;
    } else if (num < a && num < b) {
        return divide(num, a - num, b - num);
    } else if (num >= a && num >= b) {
        return divide(num, a, b);
    }
    return 0;
}

int solution(int n, int a, int b)
{
    if(a > b) return divide(n, b, a);
    return divide(n, a, b);
}
