const fs = require("fs");

const readStream  = fs.createReadStream("./hell.txt",{encoding:'utf-8'});

const writeStream = fs.createWriteStream("./Lawliet.txt",{encoding:"utf-8"});

//this ".on" is an even listener... it listens to a data event on this readstream
// readStream.on('data',(chunk)=>{
    // console.log(chunk);
    // console.log("---NEW---");
    // writeStream.write("\n NEW CHUNKERS \n")
    // writeStream.write(chunk);
// })


//pipe : everytime it recieves a chunk , it piptes it to the 
readStream.pipe(writeStream);



