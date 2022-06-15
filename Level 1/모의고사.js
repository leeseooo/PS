function solution(answers) {
    var answer = [];
    const supoman1 = [1,2,3,4,5];
    const supoman2 = [2, 1, 2, 3, 2, 4, 2, 5];
    const supoman3 = [3,3,1,1,2,2,4,4,5,5];
    let cnt = [0,0,0];
    
    for(let i=0;i<answers.length;i++){
        if(answers[i] === supoman1[i % supoman1.length])cnt[0]++;
        if(answers[i] === supoman2[i % supoman2.length])cnt[1]++;
        if(answers[i] === supoman3[i % supoman3.length])cnt[2]++;
    }
    const max = Math.max(cnt[0], cnt[1], cnt[2]);
    for(let i=0;i<cnt.length;i++){
        if(max === cnt[i])answer.push(i+1);
    }
    return answer;
}
