#include "Wallet-Interface.h"


std::string WalletInterface::login(std::string input) {

}
std::string WalletInterface::transaction(std::string input) {

}
std::string WalletInterface::smartContract(std::string input) {

}
std::string WalletInterface::transactionHistory(std::string input) {

}
std::string WalletInterface::logout() {

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