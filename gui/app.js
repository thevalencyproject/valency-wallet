/* This file is a part of The Valency Project which is released under the GNU Lesser General Public License v2.1
   Go to https://github.com/thevalencyproject/valency-wallet/blob/main/LICENSE for further license details.        */

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
    var loginDetails = document.getElementById("user").value + document.getElementById("pass").value + '|' + document.getElementById("privatekey").value;

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
    // Remove Login Screen Elements and Show Main Screen Elements
}
function removeMainScreen() {
    // Remove Main Screen Elements and Show Login Screen Elements
}


// Transaction Task Functions
function sendTransactionRequest() {  // C++ Sender Function
    let i = "001";
    
    var transactionDetails = document.getElementById("receiverKey").value + document.getElementById("transactionAmount").value + /* numofonionnodeshere */;

    ws.send(i + calculatorDetails);
}
function receiveTransactionResult(input) {
    document.getElementById("result").innerHTML = input;
}

// Smart Contract Task Functions
function sendSmartContractRequest() {
    let i = "002";

    var contractRequest = /* numofonionnodeshere */ + document.getElementById("fileselect").value;

    ws.send(i + contractRequest);
}
function receiveSmartContractResult(input) {
    document.getElementById("smartcontractuploadresult").innerHTML = input;
}

// Transaction History Task Functions
function sendTransactionHistoryRequest() {
    let i = "003";
    ws.send(i);
}
function receiveTransactionHistoryResult(input) {
    document.getElementById("transactionhistoryresult").innerHTML = input;
}

// Logout Task Functions
function sendLogoutRequest() {
    let i = "004";
    ws.send(i);
}
function receiveLogoutResult(input) {
    // Get rid of main screen and display login screen
    removeMainScreen();
}