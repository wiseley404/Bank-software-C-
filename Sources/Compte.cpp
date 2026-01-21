/**
 * \file Compte.cpp
 * \brief Implantation de la classe Compte
 * \author Petiton Wiseley
 * \version 1.0
 */
#include"Compte.h"
#include"ContratException.h"
#include"Date.h"
#include<memory>
#include<sstream>


using namespace std;

namespace bancaire
{
/**
 * \brief Constructeur de la classe Compte
 *        On construit un objet Compte à partir de valeurs passées en paramètres.
 *        Les attributs sont assignés seulement si les renseignements 
 *        fournis sont considérés comme valides.
 *        Autrement, une erreur de précondition est générée.
 * \param[in] p_noCompte est un entier qui représente le numéro du compte
 * \param[in] p_tauxInteret est un double qui représente le taux d'intérêt du compte
 * \param[in] p_solde est un double qui représente le solde du compte
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte
 * \param[in] p_dateOuverture est un objet Date qui représente la date d'ouverture du compte
 * \pre p_noCompte doit correspondre à un entier supérieur à zéro
 * \pre p_tauxInteret doit correspondre à une valeur dans l'intervalle [0, 100]
 * \pre p_description ne doit pas correspondre à une chaîne vide
 * \pre p_dateOuverture doit correspondre à la date actuelle
 * \post L'objet construit a été initialisé à partir des valeurs passées en paramètres
 */
Compte::Compte(int p_noCompte, double p_tauxInteret, double p_solde, 
         const std::string& p_description, const util::Date& p_dateOuverture):
         m_noCompte(p_noCompte), m_tauxInteret(p_tauxInteret), m_solde(p_solde),
        m_description(p_description), m_dateOuverture(p_dateOuverture)
{
  PRECONDITION(p_noCompte>0);
  PRECONDITION(p_tauxInteret>=0 && p_tauxInteret<=100);
  PRECONDITION(!(p_description.empty()));
  //date par defaut fixee dans l'interface du constructeur
  PRECONDITION(p_dateOuverture==util::Date()); 
  
  POSTCONDITION(m_noCompte==p_noCompte);
  POSTCONDITION(m_tauxInteret==p_tauxInteret);
  POSTCONDITION(m_solde==p_solde);
  POSTCONDITION(m_description==p_description);
  POSTCONDITION(m_dateOuverture==p_dateOuverture); 
  
  INVARIANTS();
}


/**
 * \brief Destructeur de la classe Compte
 *        On détruit un objet compte.
 *        Les attributs doivent être valides avant leur destruction.
 *        Autrement, une erreur d'INVARIANT est générée.
 * \invariant m_noCompte doit correspondre à un entier supérieur à zéro
 * \invariant m_tauxInteret doit correspondre à une valeur dans l'intervalle [0, 100]
 */
Compte::~Compte()
{
  INVARIANTS();
}


/**
 * \brief Retourne le numéro d'un compte du client
 * \return un entier qui représente le numéro du compte
 */
int Compte::reqNoCompte() const
{
  return m_noCompte;
}


/**
 * \brief Retourne le taux d'intérêt d'un compte 
 * \return un double qui représente le taux d'intérêt 
 */
double Compte::reqTauxInteret() const
{
  return m_tauxInteret;
}


/**
 * \brief Retourne le solde d'un compte 
 * \return un double qui représente le solde
 */
double Compte::reqSolde() const
{
  return m_solde;
}


/**
 * \brief Retourne la description d'un compte
 * \return une chaîne de caractères qui représente la description
 */
const std::string& Compte::reqDescription() const
{
  return m_description;
}


/**
 * \brief Retourne la date d'ouverture d'un compte
 * \return un objet Date qui représente la date d'ouverture
 */
const util::Date& Compte::reqDateOuverture() const
{
  return m_dateOuverture;
}


/**
 * \brief Assigne un taux d'intérêt à l'objet courant
 * \param[in] p_tauxInteret est un double qui représente le taux d'intérêt
 * \pre p_tauxInteret doit correspondre à une valeur dans l'intervalle [0, 100]
 * \post L'objet a été assigné à partir du taux passé en paramètre
 */
void Compte::asgTauxInteret(double p_tauxInteret)
{
  PRECONDITION(p_tauxInteret>=0 && p_tauxInteret<=100); 
  
  m_tauxInteret = p_tauxInteret;
  
  POSTCONDITION(m_tauxInteret==p_tauxInteret);
  
  INVARIANTS();
}


/**
 * \brief Assigne un solde à l'objet courant
 * \param[in] p_solde est un double qui représente le solde à assigner
 * \post L'objet a été assigné à partir du solde passé en paramètre
 */
void Compte::asgSolde(double p_solde)
{
  m_solde = p_solde;
  
  POSTCONDITION(m_solde==p_solde);
  
  INVARIANTS();
}


/**
 * \brief Assigne une description à l'objet courant
 * \param[in] p_description est une chaîne de caractères qui représente la description à assigner
 * \post L'objet a été assigné à partir de la description passée en paramètre
 */
void Compte::asgDescription(const std::string& p_description)
{
  PRECONDITION(!(p_description.empty()))
          
  m_description = p_description;
  
  POSTCONDITION(m_description==p_description);
  
  INVARIANTS();
}


/**
 * \brief Calcule un intérêt nul pour un compte qui ne définit pas ses règles
 * \return La valeur 0 qui représente l'intérêt 
 */
double Compte::calculerInteret() const
{
  return 0;
}


/**
 * \brief Construit le texte complet relié aux données d'un compte
 * \return Une chaîne de caractères correspondant aux données du compte
 */
std::string Compte::reqCompteFormate() const
{
  ostringstream os;
  os<<"numero : "<<m_noCompte<<endl;
  os<<"Description : "<<m_description<<endl; 
  os<<"Date d'ouverture : "<<m_dateOuverture.reqDateFormatee()<<endl;
  os<<"Taux d'interet : "<<m_tauxInteret<<endl;
  os<<"Solde : "<<m_solde<<" $"<<endl;
  
  return os.str();
}


/**
 * \brief Teste les invariants de la classe Compte. 
 * \invariant m_noCompte doit correspondre à un entier supérieur à zéro
 * \invariant m_description ne doit pas correspondre à une chaîne vide
 */
void Compte::verifieInvariant() const
{
  INVARIANT(m_noCompte>0);
  INVARIANT(m_tauxInteret>=0 && m_tauxInteret<=100)
  INVARIANT(!(m_description.empty()));
}

} //namespace bancaire