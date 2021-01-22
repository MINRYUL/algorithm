#include <iostream>
#include <algorithm>
using namespace std;
int result, t;

int main(int argc, const char * argv[]) {
    string s; cin >> s;
    
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '+') {
            string tmp = s.substr(i + 1); t += atoi(tmp.c_str());
        }
        else if(s[i] == '-'){
            string tmp = s.substr(i + 1); result -= t + atoi(tmp.c_str()); t = 0;
        }
    }
    
    string tmp = s.substr(0);
    result += atoi(tmp.c_str()) + t;
    
    cout << result << endl;
    return 0;
}
