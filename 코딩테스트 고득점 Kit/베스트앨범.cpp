#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool cmp(pair<string,int>a,pair<string,int>b){
    return a.second > b.second;
}
bool compare(pair<int,int>a,pair<int,int>b){
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,vector<pair<int,int>>>playlist; //장르별 재생횟수와 고유번호
    map<string,int>playlist_cnt; //장르별 총 재생횟수
    for(int i=0;i<plays.size();i++){
        playlist[genres[i]].push_back({plays[i],i});
        playlist_cnt[genres[i]] += plays[i];
    }
    //장르별 재생횟수 내림차순 정렬
    for(auto &i : playlist){
        sort(i.second.begin(),i.second.end(),compare);
    }
    vector<pair<string,int>>v;
    v.assign(playlist_cnt.begin(),playlist_cnt.end());
    sort(v.begin(),v.end(),cmp);//재생횟수 많은것부터 내림차순 정렬
    for(int i=0;i<v.size();i++){
        string genre = v[i].first;
        for(int j=0;(j<playlist[genre].size()) && (j < 2);j++){
            answer.push_back(playlist[genre][j].second);//해당 장르의 j번째의 고유번호
        }
    }
    return answer;
}
