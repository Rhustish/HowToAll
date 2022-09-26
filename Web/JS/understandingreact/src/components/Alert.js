import React from 'react'

export default function Alert(props) {
  return (
   <>
        <div className="alert alert-warning alert-dismissible fade show mx-3" role="alert">
            <strong>{props.alertBold}</strong> {props.alertMsg}
            <button type="button" className="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
        </div>
   </> 
)}