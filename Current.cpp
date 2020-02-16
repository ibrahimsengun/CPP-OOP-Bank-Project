#include "Current.h"
#include "Account.h"

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

Current::Current(int id, double b):Account(id, b)
{

}

double Current::withdraw(double m)
{
    double b = getBalance();
    if(b - m > 0)
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
    return 0;
}

double Current::Benefit()
{
    return 0;
}
