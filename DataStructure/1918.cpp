//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
string c, result;
int i;

string re(){
    string s, s2, s3; bool check = false;
    for(; i < c.size(); i++){
        if(c[i] == '*' || c[i] == '/'){
            if(check){
                s.append(s2); s2.clear();
                check = false;
            }
            check = true; s2.push_back(c[i]);
        }
        else if(c[i] == '+' || c[i] == '-') {
            if(s2.size() || s3.size()){
                s.append(s2); s.append(s3);
                s2.clear(); s3.clear();
            }
            s3.push_back(c[i]);
        }
        else if(c[i] == '('){
            i += 1; string add = re();
            s.append(add);
        }
        else if(c[i] == ')'){
            s.append(s2); s.append(s3);
            return s;
        }
        else{
            s.push_back(c[i]);
        }
    }
    s.append(s2); s.append(s3);
    return s;
}

int main()
{
    cin >> c;
    result.append(re());
    
    cout << result << endl;
    return 0;
}

