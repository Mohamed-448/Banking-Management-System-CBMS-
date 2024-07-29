#pragma once
#include <iostream>
#include "clsBankClient.h"
#include"clsPerson.h"
#include"clsString.h"
#include "clsInputValidate.h"
#include"clsMainScreen.h"



//void ReadClientInfo(clsBankClient& Client)
//{
//    cout << "\nEnter FirstName: ";
//    Client.FirstName = clsInputValidate::ReadString();
//
//    cout << "\nEnter LastName: ";
//    Client.LastName = clsInputValidate::ReadString();
//
//    cout << "\nEnter Email: ";
//    Client.Email = clsInputValidate::ReadString();
//
//    cout << "\nEnter Phone: ";
//    Client.Phone = clsInputValidate::ReadString();
//
//    cout << "\nEnter PinCode: ";
//    Client.PinCode = clsInputValidate::ReadString();
//
//    cout << "\nEnter Account Balance: ";
//    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
//}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";


   // ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;
  


    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
}


////////

void Add(clsBankClient& Clint,string& AccountNumber)
{

    cout << "\nEnter FirstName: ";
    Clint.FirstName = clsInputValidate::ReadString();
    
        cout << "\nEnter LastName: ";
        Clint.LastName = clsInputValidate::ReadString();
    
        cout << "\nEnter Email: ";
        Clint.Email = clsInputValidate::ReadString();
    
        cout << "\nEnter Phone: ";
        Clint.Phone = clsInputValidate::ReadString();
    
        cout << "\nEnter PinCode: ";
        Clint.PinCode = clsInputValidate::ReadString();
    
        cout << "\nEnter Account Balance: ";
        Clint.AccountBalance = clsInputValidate::ReadFloatNumber();
        Clint.AccountNumber() = AccountNumber;
        
}


void   AddSSNewClints()
{



    cout << "\nEnter Account Number : ";
    string AccountNumber = clsInputValidate::ReadString();

    while ((clsBankClient::IsClientExist(AccountNumber)))
    {
        cout << "User Alredy Use Chose Another one ";
        AccountNumber = clsInputValidate::ReadString();


    }


    clsBankClient Clint1 = clsBankClient::GetAddNewClientObject(AccountNumber);

   // cout<<Clint1.TotalBalance();

    


    cout << "Add New User : ";

    Add(Clint1,AccountNumber);




    vector <clsBankClient> vClint;

    vClint.push_back(Clint1);
    

   // Clint1.Savee(Clint1);
    Clint1.Print();


}


//////

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

/// <summary>
/// ////////
/// </summary>

//void AddNewClient()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease Enter Account Number: ";
//    AccountNumber = clsInputValidate::ReadString();
//    while (clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount Number Is Already Used, Choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
//
//
//    ReadClientInfo(NewClient);
//
//    clsBankClient::enSaveResults SaveResult;
//
//    SaveResult = NewClient.Save();
//
//    switch (SaveResult)
//    {
//    case  clsBankClient::enSaveResults::svSucceeded:
//    {
//        cout << "\nAccount Addeded Successfully :-)\n";
//        NewClient.Print();
//        break;
//    }
//    case clsBankClient::enSaveResults::svFaildEmptyObject:
//    {
//        cout << "\nError account was not saved because it's Empty";
//        break;
//
//    }
//    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
//    {
//        cout << "\nError account was not saved because account number is used!\n";
//        break;
//
//    }
//    }
//}






int main()

{
    //clsMainScreen::ShowMainMenue();

    //clsDate::PrintYearCalendar(2024);

   // UpdateClient();
   // AddNewClient();

    //AddSSNewClints();
    

    /*clsBankClient Client1 = clsBankClient::Find("A101");
    
    if (!Client1.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }

    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A101", "1234");
    if (!Client2.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    Client2.Print();


    cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101");*/

   
    system("pause>0");
    return 0;
}