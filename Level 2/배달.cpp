#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>dist;
vector<pair<int,int>>v[51];

void solve(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({1,0});
    dist[1] = 0;
    while(!pq.empty()){
        int cur = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nD = v[cur][i].second;
            
            if(dist[next] > dist[cur] + nD){
                dist[next] = dist[cur] + nD;
                pq.push({next, nD});
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.resize(N+1,1e9);
    for(int i=0;i<road.size();i++){
        int a = road[i][0]; int b = road[i][1]; int dis = road[i][2];
        v[a].push_back({b,dis});
        v[b].push_back({a,dis});
    }
    solve();
    for(int i=1;i<dist.size();i++){
        cout << dist[i] << ' ';
        if(dist[i] <= K){
            answer++;
        }
    }
    return answer;
}
