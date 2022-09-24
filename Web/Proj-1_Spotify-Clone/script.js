console.log("hello");

//Initializing variables

let songIndex = 0;
let audioElement = new Audio("songs/1.mp3");
let myprgbar = document.getElementById("prgbar");
let playButton = document.getElementById("playButton");
let prevButton = document.getElementById("prevButton");
let nextButton = document.getElementById("nextButton");
let vogif = document.getElementById("vogif");
let songitems = Array.from(document.getElementsByClassName("songitem"));
let infofsong = document.getElementsByClassName("songinfo");
let songs = [
    {songName: "Let me down" , filepath: "songs/1.mp3" , coverPath: "covers/1.jpg"},
    {songName: "Put me up" , filepath: "songs/2.mp3" , coverPath: "covers/2.jpg"},
    {songName: "Where are you" , filepath: "songs/3.mp3" , coverPath: "covers/3.jpg"},
    {songName: "I am here" , filepath: "songs/4.mp3" , coverPath: "covers/4.jpg"},
    {songName: "All might??" , filepath: "songs/5.mp3" , coverPath: "covers/5.jpg"},
    {songName: "Nah just a copy" , filepath: "songs/6.mp3" , coverPath: "covers/6.jpg"},
    {songName: "Okay, fair" , filepath: "songs/7.mp3" , coverPath: "covers/7.jpg"},
    {songName: "You got me" , filepath: "songs/8.mp3" , coverPath: "covers/8.jpg"},
    {songName: "No Kidding I did" , filepath: "songs/9.mp3" , coverPath: "covers/9.jpg"},
    {songName: "LMFAO" , filepath: "songs/10.mp3" , coverPath: "covers/10.jpg"}
]

const listReset= ()=>{
    Array.from(document.getElementsByClassName("listplay")).forEach((item)=>{
        item.classList.remove("fa-pause");
        item.classList.add("fa-play");
    })
}

const pauseOrPlay = ()=>{
    if(audioElement.currentTime <=0 || audioElement.paused){
        audioElement.play();
        playButton.classList.remove('fa-play');
        playButton.classList.add('fa-pause');
        vogif.style.opacity = 1;
        
    }else{

        audioElement.pause();
        playButton.classList.remove('fa-pause');
        playButton.classList.add('fa-play');
        vogif.style.opacity = 0;
    }
}

songitems.forEach((oneofs,i)=>{
    oneofs.getElementsByTagName("img")[0].src = songs[i].coverPath;
    oneofs.getElementsByClassName("nameofsong")[0].textContent = songs[i].songName;
    let tempAudio = new Audio(songs[i].filepath);
    tempAudio.onloadedmetadata = (()=>{
        let p = parseInt(tempAudio.duration);
        let m = parseInt(p/60); let s = p%60;
        oneofs.getElementsByClassName("timespan")[0].textContent = `${m}:${s}`;
    })
})


//Handle play-pause
playButton.addEventListener('click' ,pauseOrPlay);
//Listen to events 
audioElement.addEventListener('timeupdate',()=>{
    // console.log("timeupdate");
    //Update seekbar
    let progress = Number((audioElement.currentTime/audioElement.duration)*100);
    // console.log(progress);
    myprgbar.value = progress;
})

myprgbar.addEventListener('change',()=>{
    audioElement.currentTime = (myprgbar.value * audioElement.duration)/100;
})

Array.from(document.getElementsByClassName("listplay")).forEach(element => {
    element.addEventListener("click",()=>{

        if(element.classList.contains("fa-pause")){
            pauseOrPlay();
            element.classList.remove("fa-pause");
            element.classList.add("fa-play");
        }else{

        listReset();
        element.classList.remove("fa-play");
        element.classList.add("fa-pause");
        songIndex = Number(element.id);
        audioElement.src = songs[songIndex].filepath;
        audioElement.currentTime = 0;
        pauseOrPlay();
        }
    })
});

prevButton.addEventListener("click",()=>{
    if(songIndex>0){
        songIndex--;
    }
    audioElement.src = songs[songIndex].filepath;
    audioElement.currentTime = 0;
    pauseOrPlay();
})

nextButton.addEventListener("click",()=>{
    if(songIndex<9){
        songIndex++;
    }
    audioElement.src = songs[songIndex].filepath;
    audioElement.currentTime = 0;
    pauseOrPlay();
})