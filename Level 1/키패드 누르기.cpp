#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using pii = pair<int,int>;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int,pii>m; //map에 각 번호 2차원 인덱스 저장
    m.insert({0,{1,3}});
    int tmp=1;
    for(int i=0;i<=4;i++){
        for(int j=0;j<3;j++){
            m.insert({tmp++,{j,i}});
        }
    }
    pii left = {0,3};
    pii right = {2,3};
    for(int i=0;i<numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            left = m[numbers[i]];
            answer += "L";
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            right = m[numbers[i]];
            answer += "R";
        }
        else{
          //떨어진 거리 계산 및 비교
            int left_dist = abs(left.first-m[numbers[i]].first)+abs(left.second-m[numbers[i]].second);
            int right_dist = abs(right.first-m[numbers[i]].first)+abs(right.second-m[numbers[i]].second);
            if(left_dist < right_dist){
                left = m[numbers[i]];
                answer += "L";
            }
            else if(right_dist < left_dist){
                right = m[numbers[i]];
                answer += "R";
            }
            else{
                if(hand == "left"){
                    left = m[numbers[i]];
                    answer += "L";
                }
                else{
                    right = m[numbers[i]];
                    answer += "R";
                }
            }
        }
    }
    return answer;
}
