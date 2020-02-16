#include "Account.h"

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

Account::Account(int id, double b)
{
    ID = id;
    balance = b;
}

double Account::getBalance()
{
    return balance;
}

void Account::setBalance(double cash)
{
    balance = cash;
}

int Account::getID()
{
    return ID;
}

void Account::deposit(double cash)
{
    int tmp = 0;

    for(int i = 0; i < 5; i++)
    {
        if(summary[i] == -1)
        {
            tmp = i;
            break;
        }
    }

    summary[tmp] = 1;
    sumCash[tmp] = cash;
    balance += cash;
}

int* Account::getSummary()
{
    return summary;
}

double* Account::getSumCash()
{
    return sumCash;
}
