function solution(d, budget) {
    let answer = 0;
    d.sort((a,b)=>a-b);
    let tmp = 0;
    for(let i=0;i<d.length;i++){
        if(tmp + d[i] > budget)break;
        tmp += d[i];
        answer++;
    }
    return answer;
}
