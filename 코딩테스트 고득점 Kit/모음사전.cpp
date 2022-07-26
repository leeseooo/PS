#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string>v;
string alp[5] = {"A","E","I","O","U"};

void makeWord(int maxLen, string str){
    if(maxLen == str.size()){
        v.push_back(str);
        return;
    }
    for(int i=0;i<5;i++){
        makeWord(maxLen, str + alp[i]);
    }
}
int solution(string word) {
    int answer = 0;
    for(int i=1;i<=5;i++){
        makeWord(i, "");
    }
    sort(v.begin(),v.end());
    answer = find(v.begin(), v.end(), word) - v.begin() + 1;
    return answer;
}
