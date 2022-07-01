#include <string>
#include <vector>

using namespace std;
int need[8] = {0,};
int consume[8] = {0,};
int dSize = 0;
int ans = 0;
bool visit[8] = {false,};
void dfs(int idx,int hp){
    if(idx > ans){
        ans = idx;
    }
    for(int i=0;i<dSize;i++){
        if(!visit[i] && hp >= need[i]){
            visit[i] = true;
            dfs(idx+1,hp - consume[i]);
            visit[i] = false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    for(int i=0;i<dungeons.size();i++){
        need[i] = dungeons[i][0];
        consume[i] = dungeons[i][1];
    }
    dSize = dungeons.size();
    dfs(0,k);
    return ans;
}
