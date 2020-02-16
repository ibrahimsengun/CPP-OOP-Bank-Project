#ifndef SHORTTERM_H_INCLUDED
#define SHORTTERM_H_INCLUDED

#include "Account.h"

class ShortTerm : public Account
{
    public:
        ShortTerm(int, double, int);
        virtual double withdraw(double);
        virtual double Benefit();
        void setTutionRate(int);
        int getTutionRate();
    private:
        int tutionRate;

};

#endif // SHORTTERM_H_INCLUDED
