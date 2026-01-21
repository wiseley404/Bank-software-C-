/**
 * \file Client.cpp
 * \brief Implantation de la classe Client
 * \author Petiton Wiseley
 * \version 1.0
 */
#include"Client.h"
#include"ContratException.h"
#include"Compte.h"
#include"Date.h"
#include"validationFormat.h"
#include "CompteException.h"
#include<sstream>
#include <algorithm>


using namespace std;

namespace bancaire
{
/**
 * \brief Constructeur de la classe Client
 *        On construit un objet Client à partir de valeurs passées en paramètres.
 *        Les attributs sont assignés seulement si les renseignements 
 *        fournis sont considérés comme valides.
 *        Autrement, une erreur de précondition est générée.
 * \param[in] p_noFolio est un entier qui représente le numéro du portefeuille
 * \param[in] p_nom est une chaîne de caractères qui représente le nom du client
 * \param[in] p_prenom est une chaîne de caractères qui représente le prénom du client
 * \param[in] p_telephone est une chaîne de caractères qui représente le téléphone du client
 * \param[in] p_dateNaissance est un objet Date qui représente sa date de naissance
 * \pre p_noFolio doit correspondre à un entier dans l'intervalle [1000, 10000[
 * \pre p_nom, p_prenom doivent correspondre à des noms valides
 * \pre p_telephone doit correspondre à un numéro de téléphone valide et non vide
 * \pre p_dateNaissance doit correspondre à une date valide
 * \post L'objet construit a été initialisé à partir des valeurs passées en paramètres
 */
Client::Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom,
         const std::string& p_telephone, const util::Date& p_dateNaissance):
        m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), m_telephone(p_telephone),
        m_dateNaissance(p_dateNaissance)
{
  PRECONDITION(p_noFolio>=1000 && p_noFolio<10000);
  PRECONDITION(util::validerFormatNom(p_nom));
  PRECONDITION(util::validerFormatNom (p_prenom));
  PRECONDITION(!p_telephone.empty());
                // Valide la conformite de la date
  PRECONDITION(util::Date::validerDate (p_dateNaissance.reqJour(),
                                        p_dateNaissance.reqMois (),
                                        p_dateNaissance.reqAnnee ()));
  
  POSTCONDITION(m_noFolio==p_noFolio);
  POSTCONDITION(m_nom==p_nom);
  POSTCONDITION(m_prenom==p_prenom);
  POSTCONDITION(m_telephone==p_telephone);
  POSTCONDITION(m_dateNaissance==p_dateNaissance);
  
  INVARIANTS();
}  
/**
 * \brief Constructeur copie de la classe Client
 *        On réalise une copie à partir d'un objet Client en paramètre.
 *        Les attributs sont assignés seulement si les renseignements 
 *        fournis sont considérés comme valides.
 *        Autrement, une erreur de précondition est générée.
 * \param[in] p_client est un objet Client qui représente un client
 * \post La copie a été réalisée à partir des attributs de l'objet Client passé en paramètre
 */
Client::Client(const Client& p_client) : m_noFolio(p_client.m_noFolio), 
        m_nom(p_client.m_nom), m_prenom(p_client.m_prenom), 
        m_telephone(p_client.m_telephone),m_dateNaissance(p_client.m_dateNaissance)
{
  
  for(const auto& element : p_client.m_comptes)
    {
      m_comptes.push_back (element->clone());
    }
  
  POSTCONDITION(m_noFolio==p_client.m_noFolio);
  POSTCONDITION(m_nom==p_client.m_nom);
  POSTCONDITION(m_prenom==p_client.m_prenom);
  POSTCONDITION(m_telephone==p_client.m_telephone);
  POSTCONDITION(m_dateNaissance==p_client.m_dateNaissance);
  
  INVARIANTS();
}
/**
 * \brief Opérateur copie de la classe Client
 *        On surcharge l'opérateur "=" pour permettre une copie avec "="
 *        à partir d'un objet Client en paramètre.
 *        Les attributs sont assignés seulement si les renseignements 
 *        fournis sont considérés comme valides.
 *        Autrement, une erreur de précondition est générée.
 * \param[in] p_client est un objet Client qui représente un client
 * \post La copie a été réalisée à partir des attributs de l'objet Client passé en paramètre
 */
Client& Client::operator=(const Client& p_client)
{
  if(!(this == &p_client))
    {
      m_noFolio = p_client.m_noFolio;
      m_nom = p_client.m_nom;
      m_prenom = p_client.m_prenom;
      m_telephone = p_client.m_telephone;
      m_dateNaissance = p_client.m_dateNaissance;
      m_comptes.clear ();
      
      for(const auto& element : p_client.m_comptes)
        {
          m_comptes.push_back (element->clone());
        }
      
  POSTCONDITION(m_noFolio==p_client.m_noFolio);
  POSTCONDITION(m_nom==p_client.m_nom);
  POSTCONDITION(m_prenom==p_client.m_prenom);
  POSTCONDITION(m_telephone==p_client.m_telephone);
  POSTCONDITION(m_dateNaissance==p_client.m_dateNaissance);
  
  INVARIANTS();
  
    }
  
  return *this;
}


/**
 * \brief Retourne le numéro du folio du client
 * \return un entier qui représente le numéro du folio
 */
int Client::reqNoFolio() const
{
  return m_noFolio;
}


/**
 * \brief Retourne le nom du client
 * \return une chaîne de caractères qui représente le nom du client
 */
const std::string& Client::reqNom() const
{
  return m_nom;
}


/**
 * \brief Retourne le prénom du client
 * \return une chaîne de caractères qui représente le prénom du client
 */
const std::string& Client::reqPrenom() const
{
  return m_prenom;
}


/**
 * \brief Retourne le numéro de téléphone du client
 * \return une chaîne de caractères qui représente le numéro de téléphone
 */
const std::string& Client::reqTelephone() const
{
  return m_telephone;
}


/**
 * \brief Retourne la date de naissance du client
 * \return un objet Date qui représente la date de naissance
 */
const util::Date& Client::reqDateNaissance() const
{
  return m_dateNaissance;
}


/**
 * \brief Retourne le nombre de comptes du client
 * \return un size_t qui représente le nombre de comptes
 */
size_t Client::reqComptes() const
{
  return m_comptes.size();
}


/**
 * \brief Surcharge de l'opérateur <
 * \param[in] p_client à comparer à l'objet Client courant
 * \return un booléen indiquant si les numéros de folio des deux clients sont inférieurs ou non
 */
bool Client::operator<(const Client& p_client) const
{
  return m_noFolio < p_client.m_noFolio;
}


/**
 * \brief Ajoute un nouveau compte au portefeuille du client à partir de son numéro.
 * 
 * Cette méthode crée et ajoute un compte correspondant au numéro fourni,
 * à condition qu’aucun autre compte du client ne possède déjà ce numéro.
 * 
 * \param[in] p_noCompte Le numéro du compte à ajouter.
 * \exception CompteDejaPresentException Levée si un compte avec ce numéro est déjà présent dans le portefeuille du client.
 * \post Le compte est présent dans le portefeuille du client après l'exécution de la méthode.
 */
void Client::ajouterCompte(const Compte& p_nouveauCompte)
{ 
  if(!compteEstDejaPresent (p_nouveauCompte.reqNoCompte ()))
    {
      m_comptes.push_back (p_nouveauCompte.clone ());
    }
  else
    {
      throw CompteDejaPresentException("Il existe deja un compte avec le numero "+ to_string(p_nouveauCompte.reqNoCompte ()));
    }
  
  POSTCONDITION(compteEstDejaPresent (p_nouveauCompte.reqNoCompte ()));
  INVARIANTS();
}


/**
 * \brief Supprime un compte du portefeuille du client à partir de son numéro.
 * 
 * Cette méthode retire le compte correspondant au numéro fourni s'il est présent
 * dans la liste des comptes du client.
 * 
 * \param[in] p_noCompte Le numéro du compte à supprimer.
 * \exception CompteAbsentException Levée si aucun compte ne correspond au numéro fourni.
 * \post Aucun compte du portefeuille du client ne possède le numéro spécifié après l'exécution de la méthode.
 */
void Client::supprimerCompte(int p_noCompte)
{
  vector<unique_ptr<Compte>>::iterator it;  
  for (it = m_comptes.begin(); it != m_comptes.end(); ++it)
    {
      if((*it)->reqNoCompte()== p_noCompte)
        {
          m_comptes.erase (it);
          return;
        }
    }
   throw CompteAbsentException("Vous ne pouvez pas supprimer un compte qui n'existe pas");

  POSTCONDITION(!compteEstDejaPresent (p_noCompte));
  INVARIANTS();
}



/**
 * \brief Construit le texte complet relié aux renseignements personnels du client
 * \return une chaîne de caractères correspondant aux renseignements personnels
 */
std::string Client::reqClientFormate() const
{
  ostringstream os;
  os<<"Client no de folio : "<<reqNoFolio ()<<endl;
  os<<reqPrenom ()<<" "<<reqNom ()<<endl;
  os<<"Date de naissance : "<<reqDateNaissance ().reqDateFormatee ()<<endl;
  os<<reqTelephone ()<<endl;
  
  return os.str();
}


/**
 * \brief Construit le texte complet relié à un relevé bancaire
 * \return une chaîne de caractères correspondant au relevé
 */
std::string Client::reqReleves() const
{ 
  ostringstream os;
  os<<reqClientFormate();
  for (size_t i =0; i< m_comptes.size (); i++)
    {
       os<<m_comptes[i]->reqCompteFormate();
    }
  return os.str();
}


/**
 * \brief Vérifie si un compte avec un numéro donné est déjà associé au client.
 * 
 * Cette méthode parcourt les comptes du client et retourne true si un compte
 * avec le numéro fourni existe déjà. Sinon, elle retourne false.
 *
 * \param[in] p_noCompte Le numéro du compte à vérifier.
 * \return true si le compte est déjà présent, false sinon.
 */
bool Client::compteEstDejaPresent(int p_noCompte) const
{ 
  bool present = false;
  vector<unique_ptr<Compte>>::const_iterator it;
  for (it = m_comptes.begin(); it != m_comptes.end(); ++it)
    {
      if((*it)->reqNoCompte()== p_noCompte)
        {
          present = true;
          break;
        }
    }
  return present;
}

/**
 * \brief Teste les invariants de la classe Client. 
 * \invariant m_noFolio doit correspondre à un entier dans l'intervalle [1000, 10000[
 * \invariant m_nom, m_prenom doivent correspondre à des noms valides
 * \invariant m_telephone doit correspondre à un numéro de téléphone valide et non vide
 * \invariant m_dateNaissance doit correspondre à une date valide
 */
void Client::verifieInvariant() const
{
  INVARIANT(m_noFolio>=1000 && m_noFolio<10000);
  INVARIANT(util::validerFormatNom (m_nom));
  INVARIANT(util::validerFormatNom (m_prenom));
  INVARIANT(!m_telephone.empty());
  INVARIANT(util::Date::validerDate (m_dateNaissance.reqJour (),
                                     m_dateNaissance.reqMois (),
                                     m_dateNaissance.reqAnnee ()));
}

} //namespace bancaire