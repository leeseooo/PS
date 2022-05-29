#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
string toBinary(int n){
    string str;
    while (n != 0){
        str += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return str;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int>v[16];
    
    for(int i=0;i<arr1.size();i++){
        string tmp = toBinary(arr1[i]);
        reverse(tmp.begin(),tmp.end());
        if(tmp.size() != n){
            while(tmp.size() != n){
                tmp = '0' + tmp;
            }
        }
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] == '1'){
                v[i].push_back('#');
            }else{
                v[i].push_back(' ');
            }
        }
        
    }
    for(int i=0;i<arr2.size();i++){
        string tmp = toBinary(arr2[i]);
        reverse(tmp.begin(),tmp.end());
        if(tmp.size() != n){
            while(tmp.size() != n){
                tmp = '0' + tmp;
            }
        }
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] == '1'){
                v[i][j] = '#';
            }
        }
    }
    for(int i=0;i<n;i++){
        string tmp = "";
        for(int j=0;j<v[i].size();j++){
            tmp += v[i][j];
        }
        answer.push_back(tmp);
    }
    return answer;
}
