const prompt = require("prompt-sync")();

let num = [1,2,3,4,5,67]



//for each
num.forEach((wlement)=>{
    console.log(wlement*wlement);
    
})

// let name be an HTML collection or string ... 
//to create an array from an HTML collecetion Array.from(name) is used

let name = "Jerry"
let array = Array.from(name);
console.log(array);

//for of

for(let i of num){
    console.log(i);
    
}

//for in

for(let i in num){
    console.log(num[i]);
    
}

//for objects, for in goes thru keys