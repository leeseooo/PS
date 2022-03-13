#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>q;
    for(int i=0;i<progresses.size();i++){
        int tmp = 100-progresses[i];
        /* 예외
        3% 남았을 때 스피드 3인 경우와 4% 남았을 때 스피드 3인 경우가 연속으로 등장하는 케이스
        q.push(tmp/speeds[i])로만 해버리면 위 두 경우를 동시에 배포해버리는 오류생김
        */
        if(tmp % speeds[i])q.push(tmp/speeds[i]+1);
        else q.push(tmp/speeds[i]);
    }
    int cur = q.front();
    int cnt=0;
    while(!q.empty()){
        if(cur >= q.front()){
            cnt++;
            q.pop();
        }
        else{
            answer.push_back(cnt);
            cur = q.front();
            cnt=0;
        }
    }
    answer.push_back(cnt);
    return answer;
}
