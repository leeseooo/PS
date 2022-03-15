//나의 풀이
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        int start = commands[i][0]-1;
        int end = commands[i][1]-1;
        int idx = commands[i][2]-1;
        vector<int>v;
        for(int j=start;j<=end;j++){
            v.push_back(array[j]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[idx]);
    }
    return answer;
}

//천재의 깔끔한 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2] -2]); //(commands[i][0]-1) + (commands[i][2]-1)
    }

    return answer;
}
