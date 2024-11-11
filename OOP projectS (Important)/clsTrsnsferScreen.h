#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsTrsnsferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumberFrom()
    {
        string AccountNumberFrom = "";
        cout << "\nPlease enter AccountNumber To Transfer From? ";
        cin >> AccountNumberFrom;
        return AccountNumberFrom;
    }

    static string _ReadAccountNumberTo()
    {
        string AccountNumberTo = "";
        cout << "\nPlease enter AccountNumber To Transfer From? ";
        cin >> AccountNumberTo;
        return AccountNumberTo;

    }


public:

    static void ShowTransfer()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        string AccountNumberFrom = _ReadAccountNumberFrom();


        while (!clsBankClient::IsClientExist(AccountNumberFrom))
        {
            cout << "\nClient with [" << AccountNumberFrom << "] does not exist.\n";
            AccountNumberFrom = _ReadAccountNumberFrom();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumberFrom);
        _PrintClient(Client1);



        string AccountNumberTo = _ReadAccountNumberTo();
        

        while (!clsBankClient::IsClientExist(AccountNumberTo))
        {
            cout << "\nClient with [" << AccountNumberTo << "] does not exist.\n";
            AccountNumberTo = _ReadAccountNumberFrom();
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumberTo);
        _PrintClient(Client2);



        double Amount = 0;
        
        cout << "\nPlease enter Transfer amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount>Client1.AccountBalance)
        {
            cout << "Amount Exceeds The Availble Balance,Enter Another Amount \n";
            Amount = clsInputValidate::ReadDblNumber();

        }

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;


         if (Answer == 'Y' || Answer == 'y')
       {
           Client1.Withdraw(Amount);
           Client2.Deposit(Amount);
           cout << "\nAmount Transferd Successfully.\n";
           cout << "\nNew Balance Is: " << Client1.AccountBalance;
           cout << "\nNew Balance Is: " << Client2.AccountBalance;

       }
       else
       {
           cout << "\nOperation was cancelled.\n";
       }







       // /*if (Answer == 'Y' || Answer == 'y')
       //{
       //    if (Client1.Withdraw(Amount))
       //    {
       //        cout << "\nAmount Withdrew Successfully.\n";
       //        cout << "\nNew Balance Is: " << Client1.AccountBalance;
       //    }
       //    else
       //    {
       //        cout << "\nCannot withdraw, Insuffecient Balance!\n";
       //        cout << "\nAmout to withdraw is: " << Amount;
       //        cout << "\nYour Balance is: " << Client1.AccountBalance;

       //    }
       //}
       //else
       //{
       //    cout << "\nOperation was cancelled.\n";
       //}*/




      
       

    }

};


