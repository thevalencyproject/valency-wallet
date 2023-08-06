const ws = new WebSocket("localhost:3030");     // Create the connection to the C++ Server


// C++ Receiver Function
ws.onmessage = (event) => {                               // Whenever a message arrives from the C++ Server
    let index = event.data.slice(0, 3);                   // Get the function index (sent by C++ server as first 3 digits), and run it's respective function
    let data = event.data.slice(3, event.data.length);    // Cut the first 3 characters in the string

    switch(i) {
    case "000": receiveLoginResult(data); break;            // Login
    case "001": receiveTransactionResult(data); break;      // Transaction
    case "002": receiveSmartContractResult(data); break;    // Smart Contract
    case "003": receiveTransactionHistory(data); break;     // Transaction History
    case "004": receiveLogoutResult(data); break;           // Logout
    default: console.log("Invalid Server Message")
    }
};

// Login Task Functions
function sendLoginRequest() {   // C++ Sender Function
    let i = "000";
    var loginDetails = document.getElementById("user").value + document.getElementById("pass").value + document.getElementById("privatekey").value;

    ws.send(i + loginDetails);
}
function receiveLoginSuccess(input) {
    switch(result) {    // 1 = Success, 0 = Failure
    case 0: deployMainScreen(input); break;
    case 1: document.getElementById("loginerror").innerHTML = "[ERROR]: Invalid Login Credentials"; break;
    default: console.log("Invalid Login Server Message");
    }
}
function deployMainScreen(input) {
    
}


// Transaction Task Functions
function sendCalculatorRequest() {  // C++ Sender Function
    let i = "001";
    var calculatorDetails = document.getElementById("firstnum").value + " " + document.getElementById("secondnum").value;

    ws.send(i + calculatorDetails);
}
function receiveCalculatorResult(input) {
    document.getElementById("result").innerHTML = input;
}

// Smart Contract Task Functions


// Transaction History Task Functions


// Logout Task Functions