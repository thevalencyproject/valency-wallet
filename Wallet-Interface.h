#ifndef WALLETINTERFACE_H
#define WALLETINTERFACE_H

#include "/valency-core/ui/gui/CPP-Interface.h"
#include "/valency-network/wallet-functions/WalletFunctions.h"


class WalletInterface {
private:
    CPPInterface interface;       // The interface (the server that communicates with the JavaScript)
    WalletFunctions functions;    // The Wallet Functions Framework

    // Custom Functions
    std::string login(std::string input);
    std::string transaction(std::string input);
    std::string smartContract(std::string input);
    std::string transactionHistory(std::string input);
    std::string logout();

    std::string transactionHistory;
    std::string privateKey;
    std::string publicKey;

public:
    WalletInterface() {};

    template<typename T>
    void run(int port);
};

#endif