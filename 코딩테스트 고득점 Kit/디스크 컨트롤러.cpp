#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int answer = 0;
struct cmp{
    bool operator()(vector<int>a,vector<int>b){
    return a[1] > b[1]; //작업시간 짧은 것 우선순위
  }
};
int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>,vector<vector<int>>,cmp>pq;
    sort(jobs.begin(),jobs.end());
    
    int cur = 0;//jobs 참조할 인덱스
    int time = 0;//작업시간 계산할 변수
    while(cur < jobs.size() || !pq.empty()){
        //이미 작업중인 요청과 시간 겹치면 큐에 넣고 대기
        if(cur < jobs.size() && jobs[cur][0]<=time){
            pq.push(jobs[cur++]);
            continue;
        }
        //대기중인 요청이 있다면
        if(!pq.empty()){
            time += pq.top()[1]; //제일 작업이 빨리 끝나는 시간으로 갱신
            answer += time - pq.top()[0]; //대기시간과 소요시간 차이만큼 더함
            pq.pop();
        }
        else{
            time = jobs[cur][0]; //다음 요청 시작시간으로 갱신
        }
    }
    return answer / jobs.size();
}
