#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>students(n,1);
    for(int i=0;i<reserve.size();i++){
        students[reserve[i]-1]++;
    }
    for(int i=0;i<lost.size();i++){
        students[lost[i]-1]--;
    }
    for(int i=0;i<n;i++){
        if(students[i] > 0)continue;
        if(students[i-1]>1){
            if(i == 0)continue;
            students[i-1]--;
            students[i]++;
        }
        else if(students[i+1]>1){
            if(i == n-1)continue;
            students[i+1]--;
            students[i]++;
        }
    }
    for(int i=0;i<students.size();i++){
        if(students[i] > 0){
            answer++;
        }
    }
    return answer;
}
