/**
 * \file Client.h
 * \brief Fichier qui contient l'interface de la classe Client.
 * \author Petiton Wiseley
 * \version 1.0
 */
#ifndef CLIENT_H
#define CLIENT_H
#include<string>
#include"Compte.h"
#include"Date.h"
#include<vector>

namespace bancaire
{
/**
 * \class Client
 * \brief Cette classe sert à l'enregistrement d'un nouveau client
 *
 * Elle manipule les renseignements personnels du client.
 * Elle vérifie les données qui lui sont fournies et n'accepte que des données
 * valides. Il est de la responsabilité de l'utilisateur de s'en assurer.
 * 
 * Elle est liée à la classe Compte par une relation de composition et fournit
 * un ensemble de méthodes qui permettent, entre autres, d'ajouter un nouveau
 * compte, d'accéder à ses renseignements personnels, relevés, etc.
 */
class Client
{
public:
  Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom,
         const std::string& p_telephone, const util::Date& p_dateNaissance);
  Client(const Client& p_client);
  Client& operator=(const Client& p_client);
  
  //accesseurs
  int reqNoFolio() const;
  const std::string& reqNom() const;    
  const std::string& reqPrenom() const;   
  const std::string& reqTelephone() const;
  const util::Date& reqDateNaissance() const; 
  
  //methodes
  size_t reqComptes() const;
  bool operator<(const Client& p_client) const; 
  void ajouterCompte(const Compte& p_nouveauCompte);
  void supprimerCompte(int p_noCompte);
  std::string reqClientFormate() const;  
  std::string reqReleves() const;  
  

  
private:
  int m_noFolio;
  std::string m_nom;
  std::string m_prenom;
  std::string m_telephone;
  util::Date m_dateNaissance;
  std::vector<std::unique_ptr<Compte>> m_comptes;
  bool compteEstDejaPresent(int p_noCompte) const;
  void verifieInvariant() const;
};

} //namespace bancaire

#endif /* CLIENT_H */

