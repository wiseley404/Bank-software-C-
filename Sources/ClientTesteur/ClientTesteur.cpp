/**
 * \file ClientTesteur.cpp
 * \brief Test unitaire de la classe Client.
 *
 * À tester :
 *          Client(int p_noFolio, const std::string& p_nom, const std::string& p_prenom,
 *          const std::string& p_telephone, const util::Date& p_dateNaissance);
 *          Client(const Client& p_client);
 *          Client& operator=(const Client& p_client);
 *          int reqNoFolio() const;
 *          const std::string& reqNom() const;    
 *          const std::string& reqPrenom() const; 
 *          const std::string& reqTelephone() const;
 *          const util::Date& reqDateNaissance() const;
 *
 */

#include <gtest/gtest.h>
#include "Client.h"
#include "Date.h"
#include "ContratException.h"
#include "Epargne.h"
#include "Cheque.h"
#include "CompteException.h"
#include <sstream>
#include <iostream>

using namespace bancaire;
using namespace std;

/**
 * \brief Test du constructeur
 *     Cas valides : constructeurParametreValide — création d'un objet Client 
 *                   avec des valeurs valides et vérification de tous les attributs.
 *             
 *     Cas invalides : constructeurParametreInvalide — 
 *                     noFolioInvalide : le numéro de folio doit être entre 1000 et 9999.
 *                     nomInvalide : le nom doit être valide.
 *                     prenomInvalide : le prénom doit être valide.
 *                     telephoneInvalide : le numéro de téléphone doit être non vide.
 *                     dateDeNaissanceInvalide : la date doit être valide.
 */

TEST(ClientTest, constructeur_ParametresValides_objetValide)
{
  Client unClient(1000, "Jean", "Marie", "418 567-4213", util::Date(2,03,2000));
  ASSERT_EQ(1000, unClient.reqNoFolio ());
  ASSERT_EQ("Jean", unClient.reqNom ());
  ASSERT_EQ("Marie", unClient.reqPrenom ());
  ASSERT_EQ("418 567-4213", unClient.reqTelephone ());
  ASSERT_EQ(util::Date(2,03,2000), unClient.reqDateNaissance ());
}

TEST(ClientTest, constructeur_noFolioInvalide_PreconditionException)
{
  ASSERT_THROW(Client unClient(500, "Jean", "Marie", "418 567-4213", util::Date(2,03,2000)),PreconditionException)
                <<"le numéro de folio doit être entre 1000 et 9999.";
  
  ASSERT_THROW(Client unClient(10200, "Jean", "Marie", "418 567-4213", util::Date(2,03,2000)),PreconditionException)
                <<"le numéro de folio doit être entre 1000 et 9999.";
}

TEST(ClientTest, constructeur_nomInvalide_PreconditionException)
{
  ASSERT_THROW(Client unClient(1000, "B7", "Marie", "418 567-4213", util::Date(2,03,2000)),PreconditionException)
                <<"le nom doit être valide.";
}

TEST(ClientTest, constructeur_PrenomInvalide_PreconditionException)
{
  ASSERT_THROW(Client unClient(1000, "Jean", "San@dro*", "418 567-4213", util::Date(2,03,2000)),PreconditionException)
                <<"le prenom doit être valide.";
}

TEST(ClientTest, constructeur_telephoneInvalide_PreconditionException)
{
  ASSERT_THROW(Client unClient(1000, "Jean", "Marie", "", util::Date(2,03,2000)),PreconditionException)
                <<"le numéro de téléphone doit être non vide.";
}

TEST(ClientTest, constructeur_DateNaissanceInvalide_PreconditionException)
{
  ASSERT_THROW(Client unClient(1000, "Jean", "Marie", "418 567-4213", util::Date(2,20,2000)),PreconditionException)
                <<"la date doit être valide.";
  
  ASSERT_THROW(Client unClient(1000, "Jean", "Marie", "418 567-4213", util::Date(42,10,2000)),PreconditionException)
                <<"la date doit être valide.";
}


/**
 * \brief Test du constructeur de copie
 *     Cas valides : constructeurCopieValide — création d’un objet Client par copie,
 *                   avec vérification que tous les attributs ont été correctement copiés.
 *     Cas invalides : aucun (Il copie un objet deja valide).
 */
TEST(ClientTest, constructeurCopie_ParametresValides_CopieValide)
{
  util::Date dateDeNaissance(2, 03, 1900);
  Client unClient(1500, "Michel", "Leandro", "418 656-0345", dateDeNaissance);
  Client uneCopie(unClient);
  ASSERT_EQ(1500, uneCopie.reqNoFolio ());
  ASSERT_EQ("Michel", uneCopie.reqNom ());
  ASSERT_EQ("Leandro", uneCopie.reqPrenom ());
  ASSERT_EQ("418 656-0345", uneCopie.reqTelephone ());
  ASSERT_EQ(dateDeNaissance, uneCopie.reqDateNaissance ());         
}


/**
 * \brief Test de l'opérateur de copie
 *     Cas valides : operateurCopieValide — copie d’un objet Client,
 *                   avec vérification que tous les attributs ont été correctement copiés.
 *     Cas invalides : aucun (il copie un objet déjà valide).
 */
TEST(ClientTest, operateurCopie_ParametresValides_CopieValide)
{
  util::Date dateDeNaissance(12, 06, 1950);
  Client unClient(2300, "Isaac", "Newton", "581 232-0456", dateDeNaissance);
  Client uneCopie = unClient;
  ASSERT_EQ(2300, uneCopie.reqNoFolio ());
  ASSERT_EQ("Isaac", uneCopie.reqNom ());
  ASSERT_EQ("Newton", uneCopie.reqPrenom ());
  ASSERT_EQ("581 232-0456", uneCopie.reqTelephone ());
  ASSERT_EQ(dateDeNaissance, uneCopie.reqDateNaissance ());
}

/**
 * \brief Création d'une fixture utilisée pour les tests de la classe Client
 */
class ClientTest2 :public ::testing::Test
{
public:
  ClientTest2():
  dateDeNaissance(20, 01, 1983),
  f_client(2000, "Carlo", "Ancelotti", "590 234-0342", dateDeNaissance),
  f_client2(1000, "Jean", "Paul", "581 435-5632", dateDeNaissance),
  unCompte(1000, 2.5, 25000, "Etudes"),
  unCheque(1280, 25, 258342.33, 7.25, "Loyer", 2.5){}
  
  util::Date dateDeNaissance;
  Client f_client;
  Client f_client2;
  bancaire::Epargne unCompte;
  bancaire::Cheque unCheque;
};

/**
 * \brief Test de la méthode int reqNoFolio() const;
 *        Cas valide : reqNoFolio — vérifier que le numéro de folio est correctement retourné.
 *        Cas invalide : aucun
 */
TEST_F(ClientTest2, reqNoFolio_folioValide_2000)
{
  ASSERT_EQ(2000, f_client.reqNoFolio ());
}

/**
 * \brief Test de la méthode std::string reqNom() const;
 *        Cas valide : reqNom — vérifier que le nom est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(ClientTest2, reqNom_nomValide_Carlo)
{
  ASSERT_EQ("Carlo", f_client.reqNom ());
}

/**
 * \brief Test de la méthode std::string reqPrenom() const;
 *        Cas valide : reqPrenom — vérifier que le prénom est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(ClientTest2, reqPrenom_prenomValide_Ancelotti)
{
  ASSERT_EQ("Ancelotti", f_client.reqPrenom ());
}

/**
 * \brief Test de la méthode std::string reqTelephone() const;
 *        Cas valide : reqTelephone — vérifier que le numéro de téléphone est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(ClientTest2, reqTelephone_telephoneValide)
{
  ASSERT_EQ("590 234-0342", f_client.reqTelephone ());
}

/**
 * \brief Test de la méthode util::Date reqDateDeNaissance() const;
 *        Cas valide : reqDateDeNaissance — vérifier que la date de naissance est correctement retournée.
 *        Cas invalide : aucun.
 */
TEST_F(ClientTest2, reqDateDeNaissance_retourvalide)
{
  ASSERT_EQ(dateDeNaissance, f_client.reqDateNaissance ());
}

/**
 * \brief Test de la méthode size_t reqComptes() const;
 *        Cas valide : reqComptes — vérifier que le nombre de comptes est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(ClientTest2, reqComptes_1Compte_retour1)
{
  f_client.ajouterCompte (unCompte);
  ASSERT_EQ(1, f_client.reqComptes ());
}

/**
 * \brief Test de l'opérateur < surchargé
 *        Cas valides : comparer deux objets Client — 
 *                      vérifier que la comparaison respecte l’ordre défini par NoFolio.
 *        Cas invalides : aucun.
 */
TEST_F(ClientTest2, operateurInferieur_objetClient_comparaisonValide)
{
  ASSERT_LT(f_client2.reqNoFolio(), f_client.reqNoFolio());
}

/**
 * \brief Test de la méthode void ajouterCompte(const Compte& p_nouveauCompte);
 *        Cas valide : ajouterCompteValideNonExistant — ajouter un compte valide et non déjà présent à la liste des comptes du client.
 *        Cas invalide : ajouterCompteValideExistant — compte avec numéro de compte déjà existant dans le portefeuille du client.
 */
TEST_F(ClientTest2, ajouterCompte_CompteValide_CompteAjouté)
{
  ASSERT_EQ(0, f_client2.reqComptes());
  
  f_client2.ajouterCompte (unCompte);
  ASSERT_EQ(1, f_client2.reqComptes());
}

TEST_F(ClientTest2, ajouterCompte_CompteDejaPresent_CompteDejaPresentException)
{
  f_client2.ajouterCompte (unCompte);
  ASSERT_THROW(f_client2.ajouterCompte (unCompte), CompteDejaPresentException)
                <<"Ce compte n'etait pas deja present, echec du test d'exception "
                   "de compte deja present";
  
  f_client.ajouterCompte (unCheque);
  ASSERT_THROW(f_client.ajouterCompte (unCheque), CompteDejaPresentException)
                <<"Ce compte n'etait pas deja present, echec du test d'exception "
                   "de compte deja present";
}


/**
 * \brief Test de la méthode std::string reqClientFormate() const;
 *        Cas valides : vérifier le retour des informations sur l'objet Client formaté.
 *        Cas invalides : aucun.
 */
TEST_F(ClientTest2, reqClientFormate_formatValide)
{
  ostringstream os;
  os<<"Client no de folio : "<<f_client.reqNoFolio ()<<endl;
  os<<f_client.reqPrenom ()<<" "<<f_client.reqNom ()<<endl;
  os<<"Date de naissance : "<<f_client.reqDateNaissance ().reqDateFormatee ()<<endl;
  os<<f_client.reqTelephone ()<<endl;
  
  ASSERT_EQ(os.str(), f_client.reqClientFormate ());
}

/**
 * \brief Test de la méthode std::string reqReleves() const;
 *        Cas valides : vérifier que le relevé des comptes du client est correctement retourné.
 *        Cas invalides : aucun.
 */
TEST_F(ClientTest2, reqReleves_PasDeCompte_formatValide)
{
  ASSERT_EQ(f_client2.reqClientFormate (), f_client2.reqReleves ());
}

TEST_F(ClientTest2, reqReleves_1CompteEpargne_formatValide)
{
  f_client2.ajouterCompte (unCompte);
  
  ostringstream os;
  os<<f_client2.reqClientFormate ();
  os<<unCompte.reqCompteFormate ();
  
  ASSERT_EQ(os.str (), f_client2.reqReleves ());
}

TEST_F(ClientTest2, reqReleves_EpargneEtCheque_formatValide)
{
  f_client2.ajouterCompte (unCheque);
  f_client2.ajouterCompte (unCompte);
  
  
  ostringstream os;
  os<<f_client2.reqClientFormate ();
  os<<unCheque.reqCompteFormate ();
  os<<unCompte.reqCompteFormate ();
  
  ASSERT_EQ(os.str (), f_client2.reqReleves ());
}


/**
 * \brief Test de la méthode void supprimerCompte(int p_noCompte);
 * 
 * Cas valide : supprimerCompte_CompteExistant — supprimer un compte existant du portefeuille du client.
 * Cas invalide : supprimerCompteInexistant — tenter de supprimer un compte qui n'existe pas doit lever une exception de type CompteAbsentException.
 */
TEST_F(ClientTest2, supprimerCompte_CompteExistant_compteSupprimé)
{
  f_client.ajouterCompte (unCompte);
  ASSERT_EQ(1, f_client.reqComptes ());
  
  f_client.supprimerCompte (unCompte.reqNoCompte ());
  ASSERT_EQ(0, f_client.reqComptes ());
}


TEST_F(ClientTest2, supprimerCompte_CompteNonExistant_CompteAbsentException)
{ 
  ASSERT_THROW(f_client.supprimerCompte (5400), CompteAbsentException)
                <<"Echec du test de CompteAbsentException, y'a bien un compte existant.";
}
