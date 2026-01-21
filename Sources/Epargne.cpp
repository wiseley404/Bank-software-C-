/**
 * \file Epargne.cpp
 * \brief Implantation de la classe Epargne
 * \author Petiton Wiseley
 * \version 1.0
 */
#include"Epargne.h"
#include"ContratException.h"
#include"Compte.h"
#include"Date.h"
#include<sstream>
#include<memory>

using namespace std;

namespace bancaire
{
/**
 * \brief Constructeur de la classe Épargne
 *        On construit un compte épargne à partir de valeurs passées en paramètres
 *        qui initialisent la classe de base Compte. On n'a pas d'attribut particulier.
 *        Le constructeur vérifie les conditions spécifiques du taux d'intérêt et du solde.
 *        Autrement, une erreur de précondition est générée.
 * \param[in] p_noCompte est un entier qui représente le numéro du portefeuille
 * \param[in] p_tauxInteret est un double qui représente le taux d'intérêt du compte
 * \param[in] p_solde est un double qui représente le solde du compte
 * \param[in] p_description est une chaîne de caractères qui représente la description du compte
 * \param[in] p_dateOuverture est un objet Date qui représente la date d'ouverture du compte
 * \pre p_tauxInteret doit correspondre à un double dans l'intervalle [0.1, 3.5]
 * \pre p_solde doit être nul ou supérieur à zéro
 * \post Le compte épargne a été initialisé à partir des valeurs passées en paramètres
 */
Epargne::Epargne(int p_noCompte, double p_tauxInteret, double p_solde, 
         const std::string& p_description, const util::Date& p_dateOuverture):
        Compte(p_noCompte, p_tauxInteret, p_solde, p_description.empty() ?"Epargne":
            p_description, p_dateOuverture)
{

  PRECONDITION(p_tauxInteret>=0.1 && p_tauxInteret<=3.5);
  PRECONDITION(p_solde>=0);
  
  POSTCONDITION(reqTauxInteret() == p_tauxInteret);
  POSTCONDITION(reqSolde() == p_solde);
  
  INVARIANTS();
}


/**
 * \brief Destructeur de la classe Épargne
 *        On détruit un objet épargne.
 *        Les attributs doivent être valides avant leur destruction.
 *        Autrement, une erreur d'INVARIANT est générée.
 * \invariant m_tauxInteret doit correspondre à un double dans l'intervalle [0.1, 3.5]
 * \invariant m_solde doit être nul ou supérieur à zéro
 */
Epargne::~Epargne()
{
  INVARIANTS();
}


/**
 * \brief Assigne un taux d'intérêt à l'objet courant
 * \param[in] p_tauxInteret est un double qui représente le taux d'intérêt
 * \pre p_tauxInteret doit correspondre à un double dans l'intervalle [0.1, 3.5]
 */
void Epargne::asgTauxInteret(double p_tauxInteret)
{
  PRECONDITION(p_tauxInteret>=0.1 && p_tauxInteret<=3.5);
  Compte::asgTauxInteret (p_tauxInteret);
}


/**
 * \brief Assigne un solde à l'objet courant
 * \param[in] p_solde est un double qui représente le solde
 * \pre p_solde doit être nul ou supérieur à zéro
 * \post L'objet a été assigné à partir du solde passé en paramètre
 */
void Epargne::asgSolde(double p_solde)
{
  PRECONDITION(p_solde>=0);
  Compte::asgSolde (p_solde);
}


/**
 * \brief Calcule l'intérêt selon des règles prédéfinies pour un compte épargne
 * \return un double qui représente l'intérêt pour un compte épargne
 */
double Epargne::calculerInteret() const
{
  return reqSolde()*(reqTauxInteret()/100);
}


/**
 * \brief Fait une copie de l'objet courant épargne
 * \return un pointeur unique qui pointe vers un objet courant épargne
 */
std::unique_ptr<Compte> Epargne::clone() const
{
  return make_unique<Epargne>(*this);
}


/**
 * \brief Construit le texte complet relié aux données d'un compte épargne
 * \return une chaîne de caractères correspondant aux données du compte
 */
std::string Epargne::reqCompteFormate() const
{
  ostringstream os;
  os<<"Compte Epargne"<<endl;
  os<<Compte::reqCompteFormate ();
  os<<"Interet : "<<calculerInteret()<<" $"<<endl;
  
  return os.str();
} 
  

/**
 * \brief Teste les invariants de la classe Épargne.
 * \invariant m_solde doit être supérieur à zéro
 * \invariant m_tauxInteret doit être dans l'intervalle [0.1, 3.5]
 */
void Epargne::verifieInvariant () const
{
  INVARIANT(reqSolde()>=0);
  INVARIANT(reqTauxInteret()>=0.1 && reqTauxInteret()<=3.5); 
}

} //namespace bancaire






