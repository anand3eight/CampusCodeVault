function add(x){
    return function(y){
        return x + y;
    }
}

console.log("Answer : ", add(3)(8))