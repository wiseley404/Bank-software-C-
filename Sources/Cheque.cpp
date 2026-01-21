/**
 * \file Compte.cpp
 * \brief Implantation de la classe Cheque
 * \author Petiton Wiseley
 * \version 1.0
 */
#include"Cheque.h"
#include"ContratException.h"
#include"Date.h"
#include"Compte.h"
#include<memory>
#include<sstream>

using namespace std;

namespace bancaire
{
/**
 * \brief Constructeur de la classe Chèque
 *        On construit un compte chèque à partir de valeurs passées en paramètres,
 *        qui initialisent la classe de base Compte, et deux attributs lui sont spécifiques.
 *        Les attributs sont assignés seulement si les renseignements 
 *        fournis sont considérés comme valides.
 *        Autrement, une erreur de précondition est générée.
 * \param[in] p_noCompte est un entier qui représente le numéro du portefeuille
 * \param[in] p_nombreTransactions est un entier qui représente le nombre de transactions
 * \param[in] p_solde est un double qui représente le solde du compte
 * \param[in] p_tauxInteret est un double qui représente le taux d'intérêt du compte
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte
 * \param[in] p_tauxInteretMinimum est un double qui représente le taux d'intérêt minimum du compte
 * \param[in] p_dateOuverture est un objet Date qui représente la date d'ouverture du compte
 * \pre p_nombreTransactions doit correspondre à un entier dans l'intervalle [0, 40]
 * \pre p_tauxInteretMinimum doit être inférieur au taux du compte
 * \post Le compte chèque a été initialisé à partir des valeurs passées en paramètres
 */
Cheque::Cheque(int p_noCompte, int p_nombreTransactions, double p_solde, 
         double p_tauxInteret, const std::string& p_description,
         double p_tauxInteretMinimum, const util::Date& p_dateOuverture):
        Compte(p_noCompte, p_tauxInteret, p_solde, p_description.empty()?"Cheque":
                                                   p_description, p_dateOuverture),
        m_nombreTransactions(p_nombreTransactions), m_tauxInteretMinimum(p_tauxInteretMinimum)
{
  PRECONDITION(p_nombreTransactions>=0 && p_nombreTransactions<=40);
  PRECONDITION(p_tauxInteret >= p_tauxInteretMinimum);
  
  POSTCONDITION(m_nombreTransactions == p_nombreTransactions);
  POSTCONDITION(m_tauxInteretMinimum == p_tauxInteretMinimum);
  
  INVARIANTS();

}


/**
 * \brief Destructeur de la classe Chèque
 *        On détruit un objet chèque.
 *        Les attributs doivent être valides avant leur destruction.
 *        Autrement, une erreur d'INVARIANT est générée.
 * \invariant m_nombreTransactions doit correspondre à un entier dans l'intervalle [0, 40]
 * \invariant m_tauxInteretMinimum doit être inférieur au taux du compte
 */
Cheque::~Cheque()
{
  INVARIANTS();
}


/**
 * \brief Retourne le nombre de transactions sur le compte chèque du client
 * \return un entier qui représente le nombre de transactions
 */
int Cheque::reqNombreTransactions() const
{
  return m_nombreTransactions;
}


/**
 * \brief Retourne le taux d'intérêt minimum du compte chèque
 * \return un double qui représente le taux d'intérêt minimum
 */
double Cheque::reqTauxInteretMinimum() const
{
  return m_tauxInteretMinimum;
}


/**
 * \brief Assigne un taux d'intérêt à l'objet courant
 * \param[in] p_tauxInteret est un double qui représente le taux d'intérêt
 */
void Cheque::asgTauxInteret(double p_tauxInteret)
{
  Compte::asgTauxInteret (p_tauxInteret);
}


/**
 * \brief Assigne un solde à l'objet courant
 * \param[in] p_solde est un double qui représente le solde à assigner
 */
void Cheque::asgSolde(double p_solde)
{
  Compte::asgSolde (p_solde);
}


/**
 * \brief Assigne un nombre de transactions à l'objet courant
 * \param[in] p_nombreTransactions est un entier qui représente le nombre de transactions
 * \pre p_nombreTransactions doit correspondre à un entier dans l'intervalle [0, 40]
 * \post L'objet a été assigné à partir du nombre de transactions passé en paramètre
 */
void Cheque::asgNombreTransactions(int p_nombreTransactions)
{
  PRECONDITION(p_nombreTransactions>=0 && p_nombreTransactions<=40);
  
  m_nombreTransactions = p_nombreTransactions;
  
  POSTCONDITION(m_nombreTransactions==p_nombreTransactions);
  
  INVARIANTS();
}


/**
 * \brief Calcule l'intérêt selon des règles prédéfinies pour un compte chèque
 * \return un double qui représente l'intérêt pour un compte chèque
 */
double Cheque::calculerInteret() const
{
  if (reqSolde()>=0)
    {
      return 0;
    }
  else
    {
      if (reqNombreTransactions()>=0 && reqNombreTransactions()<=10)
        {
          return -reqSolde()*(reqTauxInteretMinimum()/100);
        }
      else if(reqNombreTransactions()>=11 && reqNombreTransactions()<=25)
        {
          int interet = -reqSolde()*(reqTauxInteretMinimum()/100);
          return interet+(0.4*interet);
        }
      else if(reqNombreTransactions()>=26 && reqNombreTransactions()<=35)
        {
          int interet = -reqSolde()*(reqTauxInteretMinimum()/100);
          return interet+(0.8*interet);
        }
      else
        {
          return -reqSolde()*(reqTauxInteret()/100);
        }
    }
}


/**
 * \brief Construit le texte complet relié aux données d'un compte chèque
 * \return une chaîne de caractères correspondant aux données du compte
 */
std::string Cheque::reqCompteFormate()  const
{
  ostringstream os;
  os<<"Compte Cheque"<<endl;
  os<<Compte::reqCompteFormate ();
  os<<"nombre de transactions : "<<reqNombreTransactions()<<endl;
  os<<"Taux d'interet minimum : "<<reqTauxInteretMinimum()<<endl;
  os<<"Interet : "<<calculerInteret()<<" $"<<endl;
  
  return os.str();
}


/**
 * \brief Fait une copie de l'objet courant chèque
 * \return un pointeur unique qui pointe vers un objet courant chèque
 */
std::unique_ptr<Compte> Cheque::clone() const
{
  return make_unique<Cheque>(*this);
}


/**
 * \brief Teste les invariants de la classe Chèque. 
 * \invariant m_nombreTransactions doit correspondre à un entier dans l'intervalle [0, 40]
 * \invariant m_tauxInteretMinimum doit être inférieur au taux du compte
 */
void Cheque::verifieInvariant() const
{
  INVARIANT(m_nombreTransactions>=0 && m_nombreTransactions<=40);
  INVARIANT(reqTauxInteret() >= m_tauxInteretMinimum);
}

} //namespace bancaire