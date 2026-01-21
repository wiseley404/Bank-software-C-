/**
 * \file FonctionsEntree.cpp
 * \brief Fonctions utilitaires d'un système bancaire
 * \author Petiton Wiseley
 * \version 1.0
 */
#include <iostream>
#include"Client.h"
#include"validationFormat.h"
#include<limits> 
#include "FonctionsEntree.h"
#include <vector>

using namespace std;
using namespace bancaire;

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
 
  
int 
EntreeFolio() 
{
  int folio;
  cout<<"Folio : ";
  cin>>folio; 
  while(cin.fail() || folio<1000 || folio>=10000)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"numero incorrect, doit etre dans l'intervalle [1000, 10000[, recommencez"<<endl;
      cout<<"Folio : ";
      cin>>folio; 
    }
  cin.ignore();
 
  return folio;
}

string
EntreeNom()
{
  string nom;
  cout<<"Nom : ";
  getline(cin, nom);
  while(!(util::validerFormatNom (nom)))
    {
      cout<<"nom invalide, recommencez"<<endl;
      cout<<"Nom : ";
      getline(cin, nom); 
    }
  return nom;
}

string
EntreePrenom()
{
  string prenom;
  cout<<"Prenom : ";
  getline(cin, prenom);
  while(!(util::validerFormatNom (prenom)))
    {
      cout<<"prenom invalide, recommencez"<<endl;
      cout<<"Prenom : ";
      getline(cin, prenom);
    }
  return prenom;
}

vector<int>
EntreeDate()
{
  int jour;
  int mois;
  int annee;
  vector<int> Date;
  bool valide = false;
  
  while(!valide)
    {
        cout<<"Date de naissance"<<endl;
        cout<<"Le jour [1...31] : ";
        cin>>jour;
        cout<<"Le mois [1...12] : ";
        cin>>mois;
        cout<<"L'annee : ";
        cin>>annee;  
        
      if (cin.fail())
          {
            cin.clear();
            cin.ignore (max_size, '\n');
            cout<<"Date invalide, recommencez"<<endl;
          }

      else
        {
            valide =util::Date::validerDate (jour, mois, annee);
            if(!valide)
              {
                cout<<"Date invalide, recommencez"<<endl;
              } 
        }
    }
  cin.ignore(max_size, '\n');
  
  Date.push_back (jour);
  Date.push_back (mois);
  Date.push_back (annee);
  
  return Date;  
}

string
EntreeTel()
{
  string telephone;
  cout<<"Telephone : ";
  getline(cin, telephone);
  while(telephone.empty())
    {
      cout<<"telephone invalide,ne doit pas etre vide, recommencez"<<endl;
      cout<<"Telephone : ";
      getline(cin, telephone); 
    }
  return telephone;
}

int
EntreeNoCompteCheque()
{
    int no_compteCheque;
  cout<<"numero de compte? ";
  cin>>no_compteCheque;
  while(cin.fail() || no_compteCheque<=0)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"Le no du compte doit etre un chifrre superieur a zero,"
              "recommencez"<<endl;
      cout<<"numero de compte? ";
      cin>>no_compteCheque;  
    }
  cin.ignore();
  
  return no_compteCheque;
}

string
EntreeDescriptionCheque()
{
  string description;
  cout<<"Description : ";
  getline(cin, description);
  
  return description;
}

double
EntreeTauxCheque()
{
  double taux;
  cout<<"Taux d'Interet : ";
  cin>>taux;
  while(cin.fail() || taux<0 || taux>100)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"taux invalide, doit etre entre 0% et 100%,"
              "recommencez"<<endl;
      cout<<"Taux d'Interet : ";
      cin>>taux; 
    }
  return taux;
}

double 
EntreeSoldeCheque()
{
  double solde;
  cout<<"Solde : ";
  cin>>solde;
  while(cin.fail())
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"Solde invalide, entrez un chiffre"<<endl;
      cout<<"Solde : ";
      cin>>solde;
    }
  return solde;
}


int
EntreeTransactionsCheque()
{
  int transactions;
  cout<<"Nombre de transactions : ";
  cin>>transactions; 
  while(cin.fail() || transactions <0 || transactions >40)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"nombre de transactions invalide, doit etre entre 0 et 40,"
              "recommencez"<<endl;
      cout<<"Nombre de transactions : ";
      cin>>transactions; 
    }
  cin.ignore();
  
  return transactions;
}

double
EntreeTauxminCheque()
{
  double tauxmin=0.1; //par defaut
  string tauxminimum;
  cout<<"Taux d'interet minimum : ";
  getline(cin, tauxminimum);
  if(!tauxminimum.empty())
    {
      tauxmin = stod(tauxminimum);
      while(tauxmin<0 || tauxmin>100 || tauxmin>EntreeTauxCheque ())
        {   
            cout<<"Le taux d'interet minimum, doit etre inferieur ou egal"
                    " au taux du compte, recommencez"<<endl;
            cout<<"Taux d'interet minimum : ";
            cin>>tauxmin;
        }
    }
  
  return tauxmin;
}

int
EntreeNoCompteEpargne()
{
  int no_compteEpargne;
  cout<<"numero de compte? ";
  cin>>no_compteEpargne;
  while(no_compteEpargne<=0)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"Le no du compte doit etre un chifrre superieur a zero,"
              "recommencez"<<endl;
      cout<<"numero de compte? ";
      cin>>no_compteEpargne;
    }
  cin.ignore();
  
  return no_compteEpargne;
}


string
EntreeDescriptionEpargne()
{
  string desciptionEpargne;
  cout<<"Description : ";
  getline(cin, desciptionEpargne);
  
  return desciptionEpargne;
}


double 
EntreeTauxEpargne()
{
  double tauxEpargne;
  cout<<"Taux d'Interet : ";
  cin>>tauxEpargne;
  while(cin.fail() || tauxEpargne<0.1 || tauxEpargne>3.5)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"taux invalide, doit etre entre 0.1% et 3.5%, recommencez"<<endl;
      cout<<"Taux d'Interet : ";
      cin>>tauxEpargne;
    }
  return tauxEpargne;
}


double 
EntreeSoldeEpargne()
{
  double soldeEpargne;
  cout<<"Solde : ";
  cin>>soldeEpargne;
  while(cin.fail() || soldeEpargne<0)
    {
      cin.clear();
      cin.ignore (max_size, '\n');
      cout<<"solde epargne invalide, doit etre superieur ou egal a zero,"
              "recommencez"<<endl;
      cout<<"Solde : ";
      cin>>soldeEpargne;
    }
  return soldeEpargne;
}