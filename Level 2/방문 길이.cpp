#include <string>
#include <map>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    map<pair<pair<int, int>, pair<int, int>>, bool>m;
    int curx = 5;
    int cury = 5;
    for(int i=0;i<dirs.size();i++){
        int sx = curx;
        int sy = cury;
        
        if(dirs[i] == 'U'){
            if(cury + 1 > 10)continue;
            cury++;
        }
        else if(dirs[i] == 'D'){
            if(cury - 1 < 0)continue;
            cury--;
        }
        else if(dirs[i] == 'R' ){
            if(curx + 1 > 10)continue;
            curx++;
        }
        else if(dirs[i] == 'L'){
            if(curx - 1 < 0)continue;
            curx--;
        }
        
        if(m[{{sx,sy},{curx,cury}}] == true)continue;
        
        m[{{sx,sy},{curx,cury}}] = true;
        m[{{curx,cury},{sx,sy}}] = true;
        answer++;
    }
    return answer;
}
