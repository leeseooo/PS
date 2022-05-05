#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s = "";
    while(n != 0){
        s += to_string(n%3);
        n /= 3;
    }
    while(s[0] == '0'){
        s.erase(0,1);
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        answer += (s[i]-'0')*pow(3,i);
    }
    return answer;
}
