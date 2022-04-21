#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int answer = 0;
int arr[3] = {0,};
bool visit[3001] = {false,};

bool isPrime(int n){
    if(n == 0 || n == 1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0)return false;
    }
    return true;
}
void combination(vector<int>nums, int cnt, int idx){
    if(cnt == 3){
        int sum = 0;
        for(int i=0;i<3;i++){
            sum += arr[i];
        }
        if(isPrime(sum))answer++;
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(!visit[i]){
            visit[i] = true;
            arr[cnt] = nums[i];
            combination(nums, cnt + 1, i + 1);
            visit[i] = false;
        }
    }
}

int solution(vector<int> nums) {
    combination(nums, 0, 0);

    return answer;
}
