/* This file is a part of The Valency Project which is released under the GNU Lesser General Public License v2.1
   Go to https://github.com/thevalencyproject/valency-wallet/blob/main/LICENSE for further license details.        */
   
#include "Wallet-Interface.h"


std::string WalletInterface::login(std::string input) {
    // Set the private and public information here
    if(input[0] == '|') {   // Logged in using private key
        input.erase(0);               // Erase the first number
        
        privateKey = input;
        publicKey = functions.generatePublicKey(input);     // Generate the public key from the inputted private key

        return input + publicKey;    // Return the public and private key
    }

    // First 2 characters represent the length of the username (max username length 99 chars)
    int userLength = stoi(input.substr(0, 2));
    std::string username = input.substr(2, userLength);
    std::string password = input.substr(userLength + 2, input.size() - userLength + 3);     // + 3 to avoid the '|' between user+pass and privkey

    // Generate a key pair from the username and password
    std::pair<std::string, std::string> keyPair = functions.generateKeyPair(username, password);

    // Save the private and public keys in C++ Backend
    privateKey = keyPair.first;
    publicKey = keyPair.second;

    return privateKey + publicKey;    // Return the public and private key (generated from the username and password inputted)
}
std::string WalletInterface::transaction(std::string input) {
    // Decode the input info

    // Send a transaction

    // If the transaction is a success, add the transctioninfo to the transctionInfo string (for when the user displays their history)

    // Return the transaction reciept/failure
}
std::string WalletInterface::smartContract(std::string input) {
    // Decode the smart contract info

    // Validate the smart contract

    // Send the smart contract

    // Return the transaction reciept/failure
}
std::string WalletInterface::transactionHistory(std::string input) {
    return transactionHistory;     // Return the transaction history
}
std::string WalletInterface::logout() {
    // Clear the private and public address/key information here
    privateKey.clear();
    transactionHistory.clear();
    publicKey.clear();

    return "success";   // Return logout succeeded
}

template<typename T>
void CPPGUIExample::run(int port) {
    // Create and fill the vectors with the custom functions
    std::vector<std::string (T::*)(std::string)> functions;
    functions.push_back(login);
    functions.push_back(transaction);
    functions.push_back(smartContract);
    functions.push_back(transactionHistory);
    functions.push_back(logout);

    interface.run(port, functions);     // Run the C++ Interface
}