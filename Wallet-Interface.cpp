#include "Wallet-Interface.h"


std::string WalletInterface::login(std::string input) {
    // Set the private and public information here
    if(input[0] == '|') {   // Logged in using public key
        input.erase(0);               // Erase the first number
        std::string publickey = ;     // Generate the public key from the inputted private key

        // Save the private and public keys in C++ Backend

        return ;    // Return the public and private key
    }

    std::string privatekey = ;    // Generate the private key from the username and password
    std::string publickey = ;     // Generate the public key from the private key

    // Save the private and public keys in C++ Backend

    return ;    // Return the public and private key (generated from the username and password inputted)
}
std::string WalletInterface::transaction(std::string input) {

}
std::string WalletInterface::smartContract(std::string input) {

}
std::string WalletInterface::transactionHistory(std::string input) {

}
std::string WalletInterface::logout() {
    // Clear the private and public address/key information here

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