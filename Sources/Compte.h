/**
 * \file Compte.h
 * \brief Fichier qui contient l'interface de la classe Compte.
 * \author Petiton Wiseley
 * \version 1.0
 */
#ifndef COMPTE_H
#define COMPTE_H
#include"Date.h"
#include<memory>

namespace bancaire
{
/**
 * \class Compte
 * \brief Hiérarchisation de classes pour la gestion des comptes.
 *
 * Cette classe est au sommet de la hiérarchisation des comptes et fournit
 * une interface commune pour la gestion des comptes à travers un ensemble 
 * de méthodes virtuelles, que les classes dérivées sont soit tenues de les 
 * implémenter obligatoirement (comme la méthode clone), ou de profiter 
 * d'une implémentation déjà fournie.
 * 
 * Elle vérifie les données qui lui sont fournies et n'accepte que des données 
 * valides. Il est de la responsabilité de l'utilisateur de s'en assurer.
 * 
 */ 
class Compte
{
public:
  Compte(int p_noCompte, double p_tauxInteret, double p_solde, 
         const std::string& p_description, const util::Date& p_dateOuverture=util::Date()); 
  virtual ~Compte();
  
  //accesseurs
  int reqNoCompte() const;
  double reqTauxInteret() const;
  double reqSolde() const;
  const std::string& reqDescription() const;
  const util::Date& reqDateOuverture() const; 
  
  //mutateurs
  virtual void asgTauxInteret(double p_tauxInteret);
  virtual void asgSolde(double p_solde);
  void asgDescription(const std::string& p_description);
  
  //methodes
  virtual std::unique_ptr<Compte> clone() const=0;
  virtual double calculerInteret() const;
  virtual std::string reqCompteFormate() const; 
  
private:
  int m_noCompte;
  double m_tauxInteret;
  double m_solde;
  std::string m_description;
  const util::Date m_dateOuverture; 
  void verifieInvariant() const;
  
};
} //namespace bancaire

#endif /* COMPTE_H */

