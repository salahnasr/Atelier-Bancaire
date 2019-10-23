#include"BankMED.h"


int main()
{
    bank NewBank;
    bool Quit(false),ReturnToMenu(false);
    int choice;

    do
   {

        cout <<"\t\t\t\t\tWelcome"<<endl<<endl<<"\t1-Add user"<<endl<<"\t2-Delete User"<<endl<<"\t3-Display Users"<<endl<<"\t4-Search User"
            <<endl<<"\t5-Edit User"<<endl<<"\t6-Quit"<<endl<<endl<<"\t\t Choice : ";
        do
        cin >> choice;
        while(choice>6||choice<1);
        cout <<endl<<endl;
        switch (choice)
        {
        case 1:
            NewBank.adduser();
            break;
        case 2:
            NewBank.deleteuser();
            break;
        case 3:
            NewBank.BrowseDatabase();
            break;
        case 4:
            NewBank.searchuser();
            break;
        case 5:
            NewBank.EditUser();
            break;
        case 6:
            Quit=true;
            break;
        }
    }
    while(Quit==false);
    return 0;
}
