//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

int cipher(int check){
    int count = 0;
    if(check > 1){
        do{
            check = int(check/10);
            count++;
        }while(check > 0);
    }
    return count;
}

int solution(string s) {
    int answer = 10000;
    for(int i = 1; i <= s.size()/2 + 1; i++){
        char c[1001]; int len = s.copy(c, i, 0), result = i;
        c[len] = '\0'; int check = 1;
        for(int j = i; j < s.size(); j += i){
            if(!s.compare(j, i, c)){
                check++;
            }
            else{
                int len = s.copy(c, i, j); c[len] = '\0';
                if(j + i < s.size()) result += i;
                else result += s.size() - j;
                result += cipher(check);
                check = 1;
            }
        }
        result += cipher(check);
        if(answer > result) answer = result;
    }
    return answer;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cout << solution("abc") << endl;
    return 0;
}
