/**
 * \file Epargne.h
 * \brief Fichier qui contient l'interface de la classe Epargne.
 * \author Petiton Wiseley
 * \version 1.0
 */

#ifndef EPARGNE_H
#define EPARGNE_H
#include<string>
#include"Compte.h"
#include"Date.h"
#include<memory>

namespace bancaire
{
/**
 * \class Epargne
 * \brief Cette classe sert à la gestion d'un compte épargne.
 *
 * Elle calcule un intérêt en fonction d'un taux simple, pour un solde nul ou positif.
 * 
 * Elle est héritée de la classe Compte et développe un ensemble de méthodes
 * virtuelles dont elle hérite, en les personnalisant à sa convenance.
 * 
 */
class Epargne : public Compte
{
public:
  Epargne(int p_noCompte, double p_tauxInteret, double p_solde, 
         const std::string& p_description, const util::Date& p_dateOuverture=util::Date());
  ~Epargne() override;
  
  //mutateurs
  void asgTauxInteret(double p_tauxInteret) override;
  void asgSolde(double p_solde) override;
  
  //methodes
  double calculerInteret() const override;
  std::unique_ptr<Compte> clone() const override;
  std::string reqCompteFormate()  const override; 
  
private:
  void verifieInvariant() const;
};
} //namespace bancaire

#endif /* EPARGNE_H */

