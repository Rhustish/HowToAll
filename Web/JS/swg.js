const prompt = require("prompt-sync")();

const game = ()=>{
    const arr = [null,"snake","water","gun"];
    const dict = {
        "snake" : "water",
        "water" : "gun",
        "gun" : "snake"
    }

    let cpu=0,p1=0;

    while(cpu<3 && p1 <3){
        console.log();
        console.log();
        console.log(); 
        
        
        let cc = Math.floor(Math.random() * 3)+1;
        let pc = Number(prompt("Enter 1 for snake, 2 for water, 3 for gun"));

        console.log("The CPU chose ",arr[cc]," You chose ",arr[pc]);
        
        
        if(dict[arr[cc]] == arr[pc])cpu++;
        else if(dict[arr[pc]] == arr[cc])p1++;
        
        console.log("CPU : ",cpu,"            P1 : ", p1);
    }
    console.log();

    if(cpu == 3) console.log("YOU LOST");
    else console.log('YOU WON');
    return;
}

game();

