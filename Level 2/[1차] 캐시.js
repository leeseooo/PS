function solution(cacheSize, cities) {
    let cache = [];
    let currentSize = 0;
    let totalTime = 0;
    
    if(cacheSize === 0){
        return cities.length * 5;
    }
    cities.forEach((city)=>{
        city = city.toUpperCase();
        let isExist = cache.includes(city);
        
        if(isExist){ // cache hit
            totalTime += 1;
            let index = cache.indexOf(city);
            cache.splice(index,1); //erase same value
            currentSize--;
            
            if(currentSize >= cacheSize){//already full
                cache.splice(0,1);
            }else{
                currentSize++;
            }
        }else{//cache miss
            totalTime += 5;
            
            if(currentSize >= cacheSize){
                cache.splice(0,1);
            }else{
                currentSize++;
            }
        }
        cache.push(city);
    })
    return totalTime;
}
