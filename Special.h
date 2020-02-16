#ifndef SPECIAL_H_INCLUDED
#define SPECIAL_H_INCLUDED

#include "Account.h"

class Special : public Account
{
public:
        Special(int, double, int);
        virtual double withdraw(double);
        virtual double Benefit();
        void setTutionRate(int);
        int getTutionRate();
        int getInitialBalance();
    private:
        int tutionRate;
        int initialBalance;
};

#endif // SPECIAL_H_INCLUDED
