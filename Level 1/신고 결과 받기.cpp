#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0); //정답벡터 초기화
    map<string,int>members;//멤버,인덱스
    map<string,set<string>>reports;//멤버,해당 멤버를 신고한 유저들 리스트
    stringstream ss;
    
    for(int i=0;i<id_list.size();i++){
        members[id_list[i]] = i;//멤버 별 인덱스
    }
    
    for(int i=0;i<report.size();i++){
        ss.str(report[i]);
        string a,b;
        ss >> a >> b; //공백으로 분리
        reports[b].insert(a); //b를 신고한 유저들 정리 -> 메일을 보내줘야 하므로
        ss.clear();//초기화
    }
    for(auto &it : reports){
        if(it.second.size() >= k){
            for(auto &i : it.second){
                int idx = members[i]; //set의 string값으로 members에 접근해서 인덱스를 알아낸다.
                answer[idx]++;
            }
        }
    }
    return answer;
}
