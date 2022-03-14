#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 50;
bool visit[50] = {false};

bool checkWord(string a,string b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i])cnt++;
    }
    if(cnt == a.size()-1)return true;
    return false;
}
void dfs(string cur, string target,vector<string> words,int depth){
    if(depth >= answer)return;
    if(target == cur){
        answer = min(answer,depth);
        return;
    }
    
    for(int i=0;i<words.size();i++){
        if(!visit[i] && checkWord(words[i],cur)){
            visit[i] = true;
            dfs(words[i],target,words,depth+1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin,target,words,0);
    if(answer == 50)return 0;
    return answer;
}
