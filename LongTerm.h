#ifndef LONGTERM_H_INCLUDED
#define LONGTERM_H_INCLUDED

#include "Account.h"

class LongTerm:public Account
{
    public:
        LongTerm(int, double, int);
        virtual double withdraw(double);
        virtual double Benefit();
        void setTutionRate(int);
        int getTutionRate();
    private:
        int tutionRate;
};
#endif // LONGTERM_H_INCLUDED
