#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visit[101][101] = {false,};
int answer = 0;
struct pos{
    int x, y, cnt;
};
int bfs(vector<vector<int> > maps){
    queue<pos>q;
    q.push({0,0,1});
    visit[0][0] = true;
    int n = maps.size();
    int m = maps[0].size();
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        if(x == n-1 && y == m-1){
            answer = max(answer, cnt);
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]){
                if(maps[nx][ny] == 1){
                    q.push({nx,ny,cnt+1});
                    visit[nx][ny] = true;
                }
            }
        }
    }
    if(!visit[n-1][m-1])return -1;
    return answer;
}
int solution(vector<vector<int> > maps)
{
    int ans = bfs(maps);
    return ans;
}
