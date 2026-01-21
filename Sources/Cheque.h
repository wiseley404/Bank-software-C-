/**
 * \file Cheque.h
 * \brief Fichier qui contient l'interface de la classe Cheque.
 * \author Petiton Wiseley
 * \version 1.0
 */
#ifndef CHEQUE_H
#define CHEQUE_H
#include<string>
#include"Compte.h"
#include"Date.h"
#include<memory>

namespace bancaire
{
/**
 * \class Cheque
 * \brief Cette classe sert à la gestion d'un compte chèque.
 *
 * Elle calcule un intérêt en fonction du nombre de transactions (limité entre 0 et 40),
 * et un taux minimum, pour un solde négatif.
 * Elle est héritée de la classe Compte et développe un ensemble de méthodes
 * virtuelles dont elle hérite, en les personnalisant à sa convenance.
 * 
 */
class Cheque : public Compte
{
public:
  Cheque(int p_noCompte, int p_nombreTransactions, double p_solde, 
         double p_tauxInteret, const std::string& p_description,
         double p_tauxInteretMinimum=0.1, const util::Date& p_dateOuverture=util::Date());
  
  ~Cheque() override;
  
  //accesseurs
  int reqNombreTransactions() const;
  double reqTauxInteretMinimum() const;
  
  //mutateurs
  void asgTauxInteret(double p_tauxInteret) override;
  void asgSolde(double p_solde) override;
  void asgNombreTransactions(int p_nombreTransactions); 
  
  //methodes
  double calculerInteret() const override;
  std::string reqCompteFormate()  const override; 
  std::unique_ptr<Compte> clone() const override;
  
  
private:
  int m_nombreTransactions;
  double m_tauxInteretMinimum;        
  void verifieInvariant() const;
};
} //namespace bancaire

#endif /* CHEQUE_H */

