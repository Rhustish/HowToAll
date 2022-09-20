const arr = [1,2,3,4,5,6,7,8,9];

// map
let a = arr.map((value,index,array)=>{
    // console.log(value,index,array);
    return value + 1
})

// filter

let a2 = arr.filter((elem)=>{
    return elem > 5;
})


//reduce 
let a3 = arr.reduce((k,l)=>{
    console.log(k,l);
    
    return k + l ;
})


console.log(a3);
