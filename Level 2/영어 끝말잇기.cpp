#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string>wordSet;
    bool flag = false;
    int round = 1;
    int member = 1;
    //init
    string word = words[0];
    wordSet.insert(word);
    member++;
    
    for(int i=1;i<words.size();i++){
        if(i % n == 0){
            member = 1;
            round++;
        }
        if(words[i][0] == word[word.size()-1]){
            word = words[i];
            
            auto iter = wordSet.find(word);
            
            //already exist word
            if(iter != wordSet.end()){
                answer.push_back(member);
                answer.push_back(round);
                flag = true;
                break;
            }else{
                wordSet.insert(word);
            }
        }else{
            answer.push_back(member);
            answer.push_back(round);
            flag = true;
            break;
        }
        member++;
    }
    if(!flag){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }else return answer;
}
