#include "Bank.h"
#include "Account.h"
#include "ShortTerm.h"
#include "LongTerm.h"
#include "Special.h"
#include "Current.h"

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

Bank::Bank()
{

}

Bank::Bank(int x)
{
    alteredTime = 0;
    i = 0;
    menu();
}

void Bank::menu()
{
    for(int j = 0; j < 100; j++)
    {
        accounts[j] = NULL;
    }
    int id = 1000;
    char ch = 'Y';
    int selection;
    Account *ptr;

    do
    {
        cout << "1 - Create_S_ID_balance\n" << "2 - Create_L_ID_balance\n" << "3 - Create_O_ID_balance\n"
             << "4 - Create_C_ID_balance\n" << "5 - Increase_ID_cash\n" << "6 - Decrease_ID_cash\n"
             << "7 - Set_dd_mm_yy\n" << "8 - ShowAccountSummary\n" << "9 - ShowIDs and Balances\n" << "10 - Sortition\n" << endl;
        cin >> selection;
        switch(selection)
        {
        case 1:
        {
            cout << "Interest rate on Short-Term accounts is 17." << endl << "Minimum Balance:1000.0" << endl;
            int balance;
            cout << "Balance: ";
            cin >> balance;
            if(balance < 1000)
                cout << "Balance must be greater than 1000." << endl;
            else
            {
                ptr = new ShortTerm(id, balance, 17);
                cout << "Your ID: " << id << endl;
                id++;
                accounts[i] = ptr;
                i++;
            }
            cout << "########################################" << endl;
            break;
        }
        case 2:
        {
            cout << "Interest rate on Long-Term accounts is 24." << endl << "Minimum Balance:1500.0" << endl;
            int balance;
            cout << "Balance: ";
            cin >> balance;
            if(balance < 1500)
                cout << "Balance must be greater than 1500." << endl;
            else
            {
                ptr = new LongTerm(id, balance, 24);
                cout << "Your ID: " << id << endl;
                id++;
                accounts[i] = ptr;
                i++;
            }
            cout << "########################################" << endl;
            break;
        }
        case 3:
        {
            cout << "Interest rate on Special accounts is 12." << endl << "Minimum Balance:Initial Balance" << endl;
            int balance;
            cout << "Initial balance: ";
            cin >> balance;
            ptr = new Special(id, balance, 12);
            cout << "Your ID: " << id << endl;
            id++;
            accounts[i] = ptr;
            i++;
            cout << "########################################" << endl;
            break;
        }
        case 4:
        {
            cout << "Interest rate on Current accounts is 0." << endl << "Minimum Balance:0" << endl;
            int balance;
            cout << "Balance: ";
            cin >> balance;
            ptr = new Current(id, balance);
            cout << "Your ID: " << id << endl;
            id++;
            accounts[i] = ptr;
            i++;
            cout << "########################################" << endl;
            break;
        }
        case 5:
        {
            int targetID;
            int cash;
            cout << "ID: ";
            cin >> targetID;

            if(getAccount(accounts, targetID, 100) != NULL)
            {
                cout << "Cash: ";
                cin >> cash;
                deposit(targetID, cash);
            }
            else
            {
                cout << "Account not found." << endl;
            }
            cout << "########################################" << endl;
            break;
        }
        case 6:
        {
            int targetID;
            int cash;
            cout << "ID: ";
            cin >> targetID;

            if(getAccount(accounts, targetID, 100) != NULL)
            {
                cout << "Cash: ";
                cin >> cash;
                withdraw(targetID, cash);
            }
            else
                cout << "Account not found." << endl;

            cout << "########################################" << endl;
            break;
        }
        case 7:
        {
            setDate();
            for(int i = 0; i < 100; i++)
            {
                if(accounts[i] != NULL)
                    accounts[i]->Benefit();
            }
            break;
        }
        case 8:
        {
            int id;
            int *sum;
            double *sumC;
            cout << "ID: ";
            cin >> id;
            Account* ac = getAccount(accounts, id, 100);
            if(ac != NULL)
            {
                sum = ac->getSummary();
                sumC = ac->getSumCash();
                for(int i = 0; i < 5; i++)
                {
                    if(sum[0] == 1 || sum[0] == 2)
                    {
                        if(sum[i] == 1)
                            cout << sumC[i] <<  " Deposit" << " - ";

                        else if(sum[i] == 2)
                            cout << sumC[i] << " Withdraw" << " - ";
                    }
                    else
                    {
                        cout << "No Summary.";
                        break;
                    }

                }
                cout << endl;
            }
            else
                cout << "Account not found." << endl;
            break;
        }
        case 9:
        {
            printAccounts(accounts);
            cout << "########################################" << endl;
            break;
        }
        case 10:
        {
            bool isFound= false;
            int ctrlRate=0;

            if(accounts[0] == NULL)
            {
                cout<<"Sistemde Hesap Bulunmamaktadir!"<<endl;
                break;
            }
            for(int i =0; i< 100; i++)
            {
                if(accounts[i] != NULL)
                {
                    if(((Special*)accounts[i])-> getTutionRate()== 12)
                    {
                        ctrlRate+= accounts[i]->getBalance()/2000;
                        isFound = true;
                    }
                }

            }
            if(isFound==false || ctrlRate == 0)
            {
                cout<<"Sistemde Ozel Hesap Bulumamaktadir! Veya Cekilis Haklari Yoktur!"<<endl;
                break;
            }
            int rate;
            bool isWin= false;
            int winnerNumber = rand()%100+1;
            while(isWin==false)
            {
                for(int i=0; i< 100; i++)
                {
                    if(accounts[i]!=NULL && ((Special*)accounts[i])-> getTutionRate()== 12 && isWin==false)
                    {
                        rate = accounts[i]->getBalance()/2000;

                        for(int j=0; j<rate; j++)
                        {
                            int randomNumber = rand()%100+1;
                            if(randomNumber==winnerNumber && isWin == false)
                            {
                                cout<<"Cekilisi ID : "<<accounts[i]->getID()<<" Kazandi!"<<endl;
                                accounts[i]->deposit(10000);
                                cout<<"Yeni Bakiye : "<<accounts[i]->getBalance()<<" TL"<<endl;
                                isWin=true;
                            }
                        }


                    }
                }
            }
            break;
        }
        default:
        {
            cout << "Wrong Choice." << endl;
            cout << "########################################" << endl;
        }
        }
        cout << "Continue ? (Y or N): ";
        cin >> ch;
        cout << "########################################" << endl;
    }
    while(ch == 'y' || ch == 'Y');
}

void Bank::setDate()
{
    int d,m,y;
    cout << "Date: (Day,Month,Year)";
    cin >> d >> m >> y;
    time_t start = time(NULL);
    tm *start_up = localtime(&start);
    start_up->tm_mday = d;
    start_up->tm_mon = m - 1;
    start_up->tm_year = y - 1900;
    alteredTime = mktime(start_up);
}

time_t Bank::getAlteredTime()
{
    return alteredTime;
}

time_t Bank::getDate()
{
    time_t date = time(NULL);
    return date;
}

Account* Bank::getAccount(Account* arr[], int id, int n)
{
    for(int j = 0; j < n; j++)
    {
        if(arr[j] != NULL)
            if(arr[j]->getID() == id)
                return arr[j];
    }
    return NULL;
}

void Bank::deposit(int id, double cash)
{
    Account* a = getAccount(accounts, id, 100);
    a->deposit(cash);
    cout << "New Balance: " << a->getBalance() << endl;
}

double Bank::withdraw(int id, double cash)
{
    Account* a = getAccount(accounts, id, 100);
    a->withdraw(cash);
    cout << "New Balance: " << a->getBalance() << endl;
    return cash;
}

void Bank::printAccounts(Account* arr[])
{
    for(int j = 0; j < 100; j++)
    {
        if(arr[j] != NULL)
            cout << "ID: " << arr[j]->getID() << " Balance: " << arr[j]->getBalance() << endl;
    }
    cout << endl;
}

