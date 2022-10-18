const fs = require("fs");

//read
// fs.readFile("./hell.txt", (err,data)=>{
//     if(err){
//         console.log(err);
//     }
//     console.log(data.toString());
// });

//write
fs.writeFile("./hell.txt","Hello World",()=>{
    console.log("Henry"); 
})