#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;
bool visit[10000] = { false, };
bool dfs(string cur, vector<vector<string>> tickets, int cnt) {
	//항공권 모두 사용 시
	if (cnt == tickets.size())return true;
	for (int i = 0; i < tickets.size(); i++) {
		//현재 여행지가 티켓의 출발지여야 탐색 가능
		if (!visit[i] && cur == tickets[i][0]) {
			visit[i] = true;
			answer.push_back(tickets[i][1]);
			bool flag = dfs(tickets[i][1], tickets, cnt + 1);
			if (flag)return true; //모두 방문한 경우 아래 코드 무시
			visit[i] = false;
			answer.pop_back();
		}
	}
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	answer.push_back("ICN");
	dfs("ICN", tickets, 0);
	return answer;
}
