function solution(s) {
    let cntZero = 0;
    let totalCnt = 0;
    while(s !== '1'){
        cntZero += s.split('0').length - 1;
        s = s.split('0').join('').length.toString(2);
        totalCnt++;
    }
    let answer = [];
    answer.push(totalCnt, cntZero);
    return answer;
}
