function solution(numbers) {
    const tmp = [];
    let set = new Set();
    
    let len = numbers.length;
    for(let i=0;i<len;i++){
        for(let j=i+1;j<len;j++){
           tmp.push(numbers[i] + numbers[j]);
        }
    }
    
    const answer = [...new Set(tmp)];
    answer.sort((a,b)=>a-b);
    return answer;
}
