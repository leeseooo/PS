#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown+yellow;
    for(int i=1;i<=total;i++){
        int width = i;
        int height = 0;
        
        if(total % width == 0)height = total / width;
        else continue;
        
        int brown_cnt=0,yellow_cnt=0;
        brown_cnt += width * 2 + height * 2 - 4;
        yellow_cnt = width > 2 && height > 2 ? (width-2)*(height-2) : 0;
        if(brown_cnt == brown && yellow_cnt == yellow){
            if(width >= height){
            answer.push_back(width);
            answer.push_back(height);
            }
        }
    }
    return answer;
}
