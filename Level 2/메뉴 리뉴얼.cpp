#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
void checkMenu(map<string,int>&m, string order, int depth, string str, int idx,int course){
    if(depth == course){
        m[str] += 1; //메뉴 카운트
        return;
    }
    for(int i=idx;i<order.size();i++){
        str[depth] = order[i];
        checkMenu(m,order,depth+1, str,i+1,course);
    }
}
bool cmp(pair<string,int>a,pair<string,int>b){
    return a.second > b.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string,int>m;
    
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(),orders[i].end()); //알파벳 정렬
        for(int j=0;j<course.size();j++){
            string str = "";
            str.resize(course[j]);
            checkMenu(m,orders[i],0,str,0,course[j]); //각 코스 별로 메뉴 조합을 구해서 카운트
        }
    }
    vector<pair<string,int>>v; //map to vector
    for(auto &menu : m){
        if(menu.second >= 2){//2개 이상 나온 메뉴만
            v.push_back({menu.first,menu.second});
        }
    }
    sort(v.begin(),v.end(),cmp); //가장 많이 나온 단품메뉴 조합 순으로 내림차순 정렬
    
    for(int i=0;i<course.size();i++){
        int maxMenu = 0;
        for(int j=0;j<v.size();j++){
            if(course[i] != v[j].first.size())continue; //같은 코스에 대해서 반복
            else if(maxMenu == 0){ //가장 많은 개수 저장
                answer.push_back(v[j].first);
                maxMenu = v[j].second;
            }
            else if(v[j].second == maxMenu){//여러개일경우
                answer.push_back(v[j].first);
            }
            else break; //maxMenu보다 작은경우 탈출
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
