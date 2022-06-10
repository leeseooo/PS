#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int idx = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            idx = 0;
            continue;
        }
        idx++ % 2 == 0 ? s[i] = toupper(s[i]) : s[i] = tolower(s[i]);
    }
    return s;
}
