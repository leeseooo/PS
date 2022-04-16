#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(st.empty() || s[i] != st.top()){
            st.push(s[i]);
        }
        else{
            st.pop();
        }
    }
    if(st.empty())answer = 1;
    else answer = 0;
    return answer;
}
