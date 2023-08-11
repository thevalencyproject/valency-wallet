#ifndef WALLETINTERFACE_H
#define WALLETINTERFACE_H

#include "/valency-core/ui/gui/CPP-Interface.h"


class WalletInterface {
private:
    CPPInterface interface;     // The interface (the server that communicates with the JavaScript)

    // Custom Functions
    std::string login(std::string input);
    std::string transaction(std::string input);
    std::string smartContract(std::string input);
    std::string transactionHistory(std::string input);
    std::string logout();

public:
    WalletInterface() {};

    template<typename T>
    void run(int port);
};

#endif