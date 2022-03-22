#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long max_time = times[times.size()-1];
    
    long long low = 1;
    long long high = max_time * n;
    while(low<=high){
        long long mid = (high+low)/2;
        long long sum = 0;
        for(int i=0;i<times.size();i++){
            sum += mid / times[i]; //mid 시간동안 한 심사대에서 체크가능한 사람 수
        }
        if(sum < n){
            low = mid+1;
        }
        else{
            //n명과 같거나 그 이상 심사할 수 있는 경우
            high = mid-1;
            answer = mid;
        }
    }
    return answer;
}
