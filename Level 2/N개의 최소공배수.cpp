#include <string>
#include <vector>
#include <iostream>

using namespace std;
int gcd(int a,int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a,int b){
    return a * (b / gcd(a,b));
}
int solution(vector<int> arr) {
    vector<int>v;
    while(arr.size() > 1){
        v.clear();
        for(int i=0;i<arr.size() - 1;i++){
            int n = lcm(arr[i], arr[i+1]);
            v.push_back(n);
        }
        arr = v;
    }
    
    return arr[0];
}
