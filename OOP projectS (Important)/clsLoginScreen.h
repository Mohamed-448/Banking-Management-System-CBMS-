#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
       

        bool LoginFaild = false;
        int NumberOfTriaels = 3;

        string Username, Password;
     
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\n you have " <<-- NumberOfTriaels   << "trials to login\n ";
                if (NumberOfTriaels==0)
                {
                    system("cls");
                    
                    return true;
                }
               
            }
           

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        return false;

       // 
     

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        if (_Login()==false)
        {

            clsUser U = U;
             U= CurrentUser;
            CurrentUser.RegisterLogin(U);
            

             clsMainScreen::ShowMainMenue();
        }
        else
        {
            return false;
        }

        

    }

   

};
