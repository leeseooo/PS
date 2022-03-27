#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
vector<int>v;
set<int>s;
bool visit[8]={false,}; //numbers 길이 7 이하
string tmp="";

bool isPrime(int n){
    if(n < 2)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0)return false;
    }
    return true;
}
void solve(string numbers,int cnt){
    if(numbers.size() == cnt)return;
    
    for(int i=0;i<numbers.size();i++){
        if(!visit[i]){
            visit[i] = true;
            tmp += numbers[i];
            v.push_back(stoi(tmp)); //만들 수 있는 string 모두 벡터에 저장
            solve(numbers,cnt+1);
            visit[i] = false;
            tmp.pop_back();
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    solve(numbers,0);
    for(int i=0;i<v.size();i++){
        s.insert(v[i]);
    }
    for(auto &i : s){
        if(isPrime(i))answer++;
    }
    return answer;
}
