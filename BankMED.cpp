#include "BankMED.h"

compte::compte():NumCompte(0),NomProprietaire(""),Solde(0)
{
}

compte::compte(int c_NumCompte,string c_NomProprietaire,float c_Solde):NumCompte(c_NumCompte),NomProprietaire(c_NomProprietaire),Solde(c_Solde)
{
}

void compte::ConsulterSolde()
{
    cout << "Your Balance : "<<Solde<<endl;
}

void compte::DeposerArgent()
{
    float montant;
    do
    {
        cout<<"Amount : ";
        cin >> montant;
        if(montant<0)
            cout<<"invalid amount !"<<endl;
    }
    while(montant<0);
    Solde+=montant;
}

bool compte::TransferArgent(compte &AutreCompte)
{
    float montant;
    cout <<"Amount to transfer : ";
    cin >>montant;
    if ( montant>Solde )

        return false;

    else
    {
        AutreCompte.Solde+=montant;
        Solde-=montant;
        return true;
    }

}

bool compte::RetirerArgent(float montant)
{
    if(montant>Solde)
        return false;
    else
    {

        Solde-=montant;
        return true;
    }
}

void compte::SetNumCompte()
{
    cout << "Account number : ";
    do
    cin >>NumCompte;
    while (NumCompte<0);
}

void compte::SetName()
{
    cout << "Name : ";
    cin >>NomProprietaire;
}

void compte::ConsulterUtilisateur()
{
    cout <<"Name : "<<NomProprietaire<<"\t Account number : "<<NumCompte<<"\t Balance : "<<Solde<<endl;
}

int compte::getNumcompte()
{
    return NumCompte;
}

bank::bank()
{

}

bool bank::adduser()
{
    compte user;
    user.SetName();
    user.SetNumCompte();
    user.DeposerArgent();
   if (searchuser(user.getNumcompte())==-1)
    {
        Database.push_back(user);
        cout << "Add successfull !"<<endl;
        return true;
    }
    else
   {
       cout<< "Add failed !"<<endl;
       return false;
   }
}

void bank::searchuser()
{
    int AccountNum;
    cout <<"Account number : ";
    cin >>AccountNum;
    int Position=searchuser(AccountNum);
    if(Position!=-1)
    Database[Position].ConsulterUtilisateur();
    else
        cout <<"Account not Found !"<<endl;
}

int bank::searchuser(int AccountNum)
{
     int i;
    for (i=0; i<Database.size(); i++)
    {
        if (Database[i].getNumcompte()==AccountNum)
            return i;
    }
    return -1;
}

void bank::BrowseDatabase()
{
    unsigned int i;
    for (i=0; i<Database.size(); i++)
    {cout <<"|"<<i+1<<"| ";
     Database[i].ConsulterUtilisateur();
    }
}

void bank::deleteuser()
{
    compte user;
    int AccountNum;
    cout <<"Account Number : ";
    cin >>AccountNum;

int Position=searchuser(AccountNum);
if (Position!=-1)
{
    Database.erase(Database.begin()+Position);
    cout<<"Delete successfull !"<<endl;
}
else
    cout <<"Account Not Found !"<<endl;

}

void bank::EditUser()
{
    int AccountNum;
    cout <<"Account number :";
    cin >>AccountNum;
    int position=searchuser(AccountNum);
    bool quit(false);
    int choice;
    do
    {
        cout <<endl<<endl<<"\t1- Withdraw CASH "<<endl<<"\t2- Deposit Cash"<<endl<<"\t3- View Balance"
             <<endl<<"\t4- Transfer CASH"<<endl<<"\t5- Quit"<<endl<<endl<<"\t\tChoice : ";
do
        cin >> choice;
        while(choice<1||choice>5);
        switch(choice)
        {
        case 1 :
        {
            int montant;
            do
            {
                cout <<"Amount : ";
                cin>>montant;
                if (montant<0)
                    cout <<"Invalid Amount !"<<endl;
            }
            while(montant<0);

            if(Database[position].RetirerArgent(montant)==true)
                cout<<endl<<"\t Operation successful ! ";
            else
                cout<<endl<<"\t Operation failed ! ";

        }
        break;
        case 2:
            Database[position].DeposerArgent();
            break;
        case 3:
            Database[position].ConsulterSolde();
            break;
        case 4:
        {
            compte AutreCompte(123456789,"Salah",123);
            if(Database[position].TransferArgent(AutreCompte)==true)
                cout<<endl<<"\t Operation successful ! ";
            else
                cout<<endl<<"\t Operation failed ! ";
        }
        break;
        case 5:
            quit=true;
        }
    }
    while (quit==false);

}
