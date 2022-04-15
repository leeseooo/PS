#include <string>
#include <vector>

using namespace std;
bool checkString(string u){
    int cnt=0;
    for(int i=0;i<u.length();i++){
        if(u[i] == '(')cnt++;
        else cnt--;
        if(cnt < 0)return false;
    }
    return true;
}

string recur(string p, string u, string v){
    if(p.length() == 0)return "";
    
    int l=0; int r=0;
    for(int i=0;i<p.length();i++){
        if(p[i] =='(')l++;
        else r++;
        if(l == r){
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(checkString(u)){
        u += recur(v,"","");
        return u;
    }   
    else{
        string tmp = "(";
        tmp += recur(v,"","");
        tmp += ')';
        u = u.substr(1,u.length()-2);
        for(int i=0;i<u.length();i++){
            if(u[i] == '(')u[i] = ')';
            else u[i] = '(';
        }
        return tmp + u;
    }
}
string solution(string p) {
    string answer = "";
    answer = recur(p, "","");
    return answer;
}
