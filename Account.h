#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED


class Account
{
    public:
        Account(int, double);
        void deposit(double);
        virtual double withdraw(double) = 0;
        virtual double Benefit() = 0;
        double getBalance();
        int* getSummary();
        double* getSumCash();
        void setBalance(double);
        int getID();
    private:
        double sumCash[5];
        int summary[5];
        double balance;
        int ID;
};

#endif // ACCOUNT_H_INCLUDED
