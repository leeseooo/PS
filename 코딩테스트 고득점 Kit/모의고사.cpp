#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int arr_1[] = {1,2,3,4,5};
    int arr_2[] = {2,1,2,3,2,4,2,5};
    int arr_3[] = {3,3,1,1,2,2,4,4,5,5};
    
    int idx1=0,idx2=0,idx3=0;
    int sum[3]={0,};
    for(int i=0;i<answers.size();i++){
        if(idx1 == 5)idx1=0;
        if(idx2 == 8)idx2=0;
        if(idx3 == 10)idx3=0;
        
        if(answers[i] == arr_1[idx1++])sum[0]++;
        if(answers[i] == arr_2[idx2++])sum[1]++;
        if(answers[i] == arr_3[idx3++])sum[2]++;
    }
    int max_n=0;
    for(int i=0;i<3;i++){
        if(max_n <= sum[i])max_n = sum[i];
    }
    for(int i=0;i<3;i++){
        if(sum[i] == max_n){
            answer.push_back(i+1);
        }
    }
    return answer;
}
