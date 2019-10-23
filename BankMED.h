#ifndef BANKMED_H_INCLUDED
#define BANKMED_H_INCLUDED


#include <iostream>
#include <vector>
using namespace std;


class compte
{

public :

compte();
compte(int NumCompte,string NomProprietaire,float Solde);
void DeposerArgent();
void SetNumCompte();
void SetName();
bool TransferArgent(compte &AutreCompte);
void ConsulterSolde();
bool RetirerArgent(float montant);
void ConsulterUtilisateur();
int getNumcompte();
private :

int NumCompte;
string NomProprietaire;
float Solde;
};


class bank
{
public :
bank();
bool adduser();
void deleteuser();
void searchuser();
int searchuser(int AccountNum);
void BrowseDatabase();
void EditUser();
private :
vector <compte> Database;

};


#endif
