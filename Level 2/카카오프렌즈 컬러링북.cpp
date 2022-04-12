#include <vector>
#include <queue>

using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visit[101][101];
int bfs(int a,int b, vector<vector<int>> picture,int m, int n){
    queue<pair<int,int>>q;
    q.push({a,b});
    visit[a][b] = true;
    int color = picture[a][b];
    int cnt = 1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 && ny >=0 && nx<m && ny<n && !visit[nx][ny]){
                if(color == picture[nx][ny]){
                    q.push({nx,ny});
                    cnt+=1; //같은 color area 증가
                    visit[nx][ny] = true;
                }
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = false;
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j] != 0 && !visit[i][j]){
                int cnt = bfs(i,j,picture,m,n);
                number_of_area++;
                if(max_size_of_one_area < cnt){
                    max_size_of_one_area = cnt;
                }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
