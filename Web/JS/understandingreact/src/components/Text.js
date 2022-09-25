import React, { useState } from 'react'

export default function Text(props) {

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

    const [text, setText] = useState("Enter text heeere");
    
  return (
    <>
    <div className='textbox'>

        <h1>{props.text}</h1>

        <div className="mb-3">
            <label htmlFor="exampleFormControlTextarea1"  className="form-label"></label>
            <textarea className="form-control" id="exampleFormControlTextarea1" onChange={handleOnChange} rows="8" value={text}></textarea>
        </div>

        <button className="btn btn-primary" onClick={handleUpClick}>Converet To Uppercase</button>
        <button className="btn btn-primary mx-3" onClick={handleLoClick}>Converet To Lowercase</button>

    </div>
    <div className="container my-3">
        <h1>Your text Summary</h1>
        <p>{text.split(" ").length} words , {text.length} chatacters</p>
        <h3>Preview</h3>
        <p>{text}</p>
    </div>
    </>
  )
}
