import { useState } from 'react';
import './App.css';
// import About from './components/About';
import Navbar from './components/Navbar';
import Text from './components/Text';

function App() {

  const [mode, setMode] = useState("light");

  const toggleMode = ()=>{
    if(mode === 'light'){
      setMode('dark')
      document.body.style.backgroundColor = "#0a0e11";
    }else{
      setMode("light");
      document.body.style.backgroundColor = "white";
    }
  }
  return (
    <>
    <Navbar title='Hello World' modex={`${mode}`} toggleMode = {toggleMode}/>
    <div className="container" >
      <Text text = "Enter you text here"/>
      {/* <About/> */}
      
    </div>
    </>
  );
}

export default App;
