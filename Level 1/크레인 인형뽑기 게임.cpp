#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>st;
    
    for(int i=0;i<moves.size();i++){
        int num = moves[i]-1;
        for(int j=0;j<board.size();j++){
            if(board[j][num] != 0){
                if(!st.empty() && st.top() == board[j][num]){
                    st.pop();
                    answer += 2;
                }
                else{
                    st.push(board[j][num]);
                }
                board[j][num] = 0;
                break;
            }
        }
    }
    return answer;
}
