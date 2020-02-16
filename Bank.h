#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <ctime>

#include "Account.h"
#include "Special.h"

class Bank
{
    public:
        Bank(int);
        Bank();
        time_t getAlteredTime();
        time_t getDate();
        void setDate();
        void deposit(int, double);
        double withdraw(int, double);
        int sortition(Account *[]);
        void menu();
        Account* getAccount(Account *[], int, int);
        void printAccounts(Account* []);
    private:
        int i;
        time_t alteredTime;
        Account* accounts[100];
};
#endif // BANK_H_INCLUDED
