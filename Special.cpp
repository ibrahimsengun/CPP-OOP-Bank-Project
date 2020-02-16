#include "Special.h"
#include "Account.h"
#include "Bank.h"

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

Special::Special(int id, double b, int t):Account(id, b)
{
    initialBalance = b;
    setTutionRate(t);
}

void Special::setTutionRate(int t)
{
    tutionRate = t;
}

int Special::getTutionRate()
{
    return tutionRate;
}

int Special::getInitialBalance()
{
    return initialBalance;
}


double Special::withdraw(double m)
{
    double b = getBalance();
    if(b - m > initialBalance)
    {
        int tmp;
        int *sum;
        double *sumC;
        sum = getSummary();
        sumC = getSumCash();
        for(int i = 0; i < 5; i++)
        {
            if(sum[i] == -1)
            {
                tmp = i;
            }
        }
        sum[tmp] = 2;
        sumC[tmp] = m;
        b -= m;
        setBalance(b);
        return m;
    }
    cout << "You don't have enough money." << endl;
    return 0;
}

double Special::Benefit()
{
    Bank bank;
    double num = 1;
    num*=getTutionRate();
    num/=100;
    double b = getBalance();
    int day = difftime(bank.getDate(),bank.getAlteredTime())/(60*60*24);
    float gain = b * ((day/365) * num);
    b += gain;
    setBalance(b);
    cout << "Benefit: " << gain << endl << "New Balance:" << getBalance() << endl;
    return gain;
}
