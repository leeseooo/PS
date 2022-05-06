#include <string>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct pos{
    int x,y,d;  
};
bool bfs(int a,int b,vector<string>map){
    queue<pos>q;
    bool visit[5][5] = {false,};
    q.push({a,b,0});
    visit[a][b] = true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        
        if(d == 2)continue; //0 이거나 1일 때 사람 만나지 않았으면 초기화
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<5 && ny<5 && !visit[nx][ny]){
                if(map[nx][ny] == 'O'){
                    visit[nx][ny] = true;
                    q.push({nx,ny,d+1});
                }
                else if(map[nx][ny] == 'P'){
                    return false;
                }
            }
        }
    }
    return true;
}
int solve(vector<string>v){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
             if(v[i][j] == 'P'){
                 bool res = bfs(i,j,v);
                 if(!res)return 0;
             }
         }
     }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0;i<5;i++){
        answer.push_back(solve(places[i]));
    }
    return answer;
}
