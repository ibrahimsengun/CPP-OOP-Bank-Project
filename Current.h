#ifndef CURRENT_H_INCLUDED
#define CURRENT_H_INCLUDED

#include "Account.h"

class Current : public Account
{
    public:
        Current(int, double);
        virtual double withdraw(double);
        virtual double Benefit();
};

#endif // CURRENT_H_INCLUDED
