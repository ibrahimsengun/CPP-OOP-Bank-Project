#include "ShortTerm.h"
#include "Account.h"
#include "Bank.h"

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

ShortTerm::ShortTerm(int id, double b, int t):Account(id, b)
{
    setTutionRate(t);
}

void ShortTerm::setTutionRate(int t)
{
    tutionRate = t;
}

int ShortTerm::getTutionRate()
{
    return tutionRate;
}

double ShortTerm::withdraw(double m)
{
    double b = getBalance();
    if(b - m > 1000)
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

double ShortTerm::Benefit()
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


