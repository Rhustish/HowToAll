import pyttsx3

textToSpeech = pyttsx3.init();

with open('Python/temp.txt') as f:
    lines = f.readlines()
    word , time = lines[0].split(" ");
    textToSpeech.say(word)
    textToSpeech.runAndWait();
    word,time = lines[1].split(" ");
    textToSpeech.say(word);
    textToSpeech.runAndWait();