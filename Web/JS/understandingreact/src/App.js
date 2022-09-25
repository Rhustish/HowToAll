import './App.css';
import Navbar from './components/Navbar';
import Text from './components/Text';

function App() {
  return (
    <>
    <Navbar/>
    
    <div className="container">
      <Text text = "Enter you text here"/>
    </div>
    </>
  );
}

export default App;
