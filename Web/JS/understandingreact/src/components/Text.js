import React, { useState } from 'react'

export default function Text(props) {

    const styler = ()=>{
        let c = {
            backgroundColor : "gray",
            color : "white"
        };
        if(props.modex === 'light'){
            c = {
                backgroundColor : "white",
                color :"black"
            }
            return c;
        }
        return c;
    }

    const handleUpClick = ()=>{
        // console.log('uppercase was called' );
        let newText = text.toLocaleUpperCase();
        setText(newText);
    }

    const handleLoClick = ()=>{
        // console.log('uppercase was called' );
        let newText = text.toLocaleLowerCase();
        setText(newText);
    }

    const handleOnChange = (event)=>{
        // console.log(event);
        setText(event.target.value)
    }

    const [text, setText] = useState("");
    
  return (
    <>
    <div className='textbox'>

        <h1 className={`text-${props.modex === 'dark'?"light":"dark"}`}>{props.text}</h1>

        <div className="mb-3">
            <label htmlFor="exampleFormControlTextarea1"  className="form-label"></label>
            <textarea className="form-control" style={styler()} id="exampleFormControlTextarea1" placeholder='Enter text here' onChange={handleOnChange} rows="8" value={text}></textarea>
        </div>

        <button className={`btn btn-primary text-${props.modex === 'dark'?"light":"dark"}`} onClick={handleUpClick}>Converet To Uppercase</button>
        <button className={`btn btn-primary mx-3 text-${props.modex === 'dark'?"light":"dark"}`} onClick={handleLoClick}>Converet To Lowercase</button>

    </div>
    <div className="container my-3">
        <h1 className={`text-${props.modex === 'dark'?"light":"dark"}`}>Your text Summary</h1>
        <p className={`text-${props.modex === 'dark'?"light":"dark"}`}>{text.split(" ").length} words , {text.length} chatacters</p>
        <h3 className={`text-${props.modex === 'dark'?"light":"dark"}`}>Preview</h3>
        <p className={`text-${props.modex === 'dark'?"light":"dark"}`}>{text === "" ? "Enter text to preview..." : text}</p>
    </div>
    </>
  )
}
