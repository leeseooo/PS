#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    
    int zero_cnt = 0;
    int rank = 0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        for(int j=0;j<win_nums.size();j++){
            if(lottos[i] == win_nums[j]){
                rank++;
                win_nums.erase(win_nums.begin()+j);
                break;
            }
        }
    }
    if(rank < 2){
        answer[1] = 6;
    }
    if(rank >= 2){
        answer[1] = 6 - rank + 1;
    }
    //일치하는 것의 개수 + 0의 개수가 2 이하일때
    if(zero_cnt + rank < 2){
        answer[0] = 6;
    }
    if(zero_cnt + rank >= 2){
        answer[0] = 6 - zero_cnt - rank + 1;
    }
    return answer;
}
