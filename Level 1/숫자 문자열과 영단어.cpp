#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer;
    int i=0;
    while(i<s.size()){
        if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
            answer+=s[i];
            i++;
        }
        else{
            if(s[i]=='z'){
                answer+="0";
                i+=4;
            }
            else if(s[i] == 'o'){
                answer += "1";
                i+=3;
            }
            else if(s[i] == 't'){
                if(s[i+1]=='w'){
                    answer+="2";
                    i+=3;
                }
                else if(s[i+1]=='h'){
                    answer+="3";
                    i+=5;
                }
            }
            else if(s[i] == 'f'){
                if(s[i+1] == 'o'){
                    answer+="4";
                }
                else if(s[i+1] == 'i'){
                    answer+="5";
                }
                i+=4;
            }
            else if(s[i] == 's'){
                if(s[i+1] == 'i'){
                    answer+="6";
                    i+=3;
                }
                else if(s[i+1] == 'e'){
                    answer+="7";
                    i+=5;
                }
            }
            else if(s[i] == 'e'){
                answer+="8";
                i+=5;
            }
            else{
                answer+="9";
                i+=4;
            }
        }
    }
    return stoi(answer);
}

/* 다른 사람 풀이-> regex_replace로 대상 문자열에서 문자열을 검색해 치환
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");    
    return stoi(s);
}
*/
