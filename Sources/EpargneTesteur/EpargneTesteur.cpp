/**
 * \file EpargneTesteur.cpp
 * \brief Test unitaire de la classe Epargne.
 *
 * À tester :
 *         Epargne(int p_noCompte, double p_tauxInteret, double p_solde, 
 *         const std::string& p_description, const util::Date& p_dateOuverture = util::Date());
 *         void asgTauxInteret(double p_tauxInteret) override;
 *         void asgSolde(double p_solde) override;
 *         double calculerInteret() const override;
 *         std::unique_ptr<Compte> clone() const override;
 *         std::string reqCompteFormate() const override;
 *
 */

#include <gtest/gtest.h>
#include "Epargne.h"
#include "ContratException.h"
#include <sstream>

using namespace bancaire;
using namespace std;

/**
 * \brief Test du constructeur
 *     Cas valides : constructeurParametreValide — création d'un objet Epargne 
 *                   avec des valeurs valides et vérification de tous les attributs.
 *                   DescriptionParDefaut: La description doit retourner "Epargne"
 *     Cas invalides : constructeurParametreInvalide — 
 *                     TauxInvalide : le taux d'intérêt est < 0,1 ou > 3,5.
 *                     SoldeInvalide : le solde est négatif.
 */
TEST (EpargneTest, constructeur_Parametresvalides_EpargneValide)
{
  Epargne CompteEpargne(1230, 2.5, 5000, "Etudes");
  ASSERT_EQ(2.5, CompteEpargne.reqTauxInteret ());
  ASSERT_EQ(5000, CompteEpargne.reqSolde ());
  ASSERT_EQ("Etudes", CompteEpargne.reqDescription ());
}

TEST (EpargneTest, constructeur_DescriptionParDefaut_EpargneValide)
{
  Epargne CompteEpargne(1230, 2.5, 5000, "");
  ASSERT_EQ("Epargne", CompteEpargne.reqDescription ());
}


TEST (EpargneTest, constructeur_noCompteInvalide_PreconditionException)
{
  ASSERT_THROW(Epargne CompteEpargne(-1230, 2.5, 5000, "Etudes"), PreconditionException)
          <<"Le numéro de compte doit être supérieur à zéro.";
  
  ASSERT_THROW(Epargne CompteEpargne(0, 2.5, 5000, "Etudes"), PreconditionException)
          <<"Le numéro de compte doit être supérieur à zéro.";
}


TEST (EpargneTest, constructeur_tauxInvalide_PreconditionException)
{
  ASSERT_THROW(Epargne CompteEpargne(1230, 0.09, 5000, "Etudes"), PreconditionException)
          <<"Le taux d'intérêt du compte doit être compris entre 0,1 et 3,5";
  
  ASSERT_THROW(Epargne CompteEpargne(1230, 3.51, 5000, "Etudes"), PreconditionException)
          <<"Le taux d'intérêt du compte doit être compris entre 0,1 et 3,5";
}


TEST (EpargneTest, constructeur_soldeNegatif_PreconditionException)
{
  ASSERT_THROW(Epargne CompteEpargne(1230, 2.5, -5000, "Etudes"), PreconditionException)
          <<" Le solde du compte doit être positif";
}

TEST (EpargneTest, constructeur_dateOuvertureInvalide_PreconditionException)
{
  ASSERT_THROW(Epargne CompteEpargne(1230, 2.5, -5000, "Etudes", util::Date (5, 12, 2024)), PreconditionException)
          <<"La date d'ouverture du compte doit être cohérente avec la date actuelle à laquelle le compte est créé.";
}


/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Epargne
 */
class CompteEpargne : public ::testing::Test
{
public:

  CompteEpargne () :
  f_epargne (1500, 3, 10000, "Epargne-Retraite") { }
  Epargne f_epargne;
};


/**
 * \brief Assigner une nouvelle taux d'interet
 * 		  Cas valide : asgTauxValide assigner un taux valide
 * 		  Cas invalide : asgTauxInvalide:  taux supérieure à 3.5
 *                               asgTauxInvalide: taux inférieur a 0.1
 */
TEST_F(CompteEpargne, asgTaux_tauxValide_2)
{
  f_epargne.asgTauxInteret (2);
  ASSERT_EQ(2, f_epargne.reqTauxInteret ());
}

TEST_F(CompteEpargne, asgTaux_tauxInvalide_PreconditionException)
{
  ASSERT_THROW(f_epargne.asgTauxInteret (0), PreconditionException)
                <<"Le taux doit être compris entre 0,1 et 3,5. ";
  ASSERT_THROW(f_epargne.asgTauxInteret (5), PreconditionException)
                <<" Le taux doit être compris entre 0,1 et 3,5. ";
}


/**
 * \brief Assigner une nouveau solde 
 * 		  Cas valide : asgSoldeValide: un solde valide
 * 		  Cas invalide : asgSoldeInvalide: solde negatif                  
 */
TEST_F(CompteEpargne, asgSolde_soldeValide_1000)
{
  f_epargne.asgSolde (1000);
  ASSERT_EQ(1000, f_epargne.reqSolde ());
}

TEST_F(CompteEpargne, asgSolde_soldeNegatif_PreconditionException)
{
  ASSERT_THROW(f_epargne.asgSolde (-1000), PreconditionException)
                <<"Le solde doit être positif";
}


/**
 * \brief Test de la méthode calculerInteret() const.
 *     Cas valide: calcul de l'interet du compte.
 *     Cas invalide: aucun.
 */
TEST_F (CompteEpargne, calculerInteret_résultatConforme)
{
  ASSERT_EQ(f_epargne.calculerInteret (), f_epargne.reqSolde()*(f_epargne.reqTauxInteret()/100));
}


/**
 * \brief Test de la méthode clone() const.
 *     Cas valide: clonage reussi.
 *     Cas invalide: aucun.
 */
TEST_F (CompteEpargne, clone_reussi)
{
    std::unique_ptr<Compte> clone = f_epargne.clone();
    ASSERT_EQ(clone->reqNoCompte(), f_epargne.reqNoCompte());
    ASSERT_EQ(clone->reqSolde(), f_epargne.reqSolde ());
    ASSERT_EQ(clone->reqTauxInteret(), f_epargne.reqTauxInteret());
    ASSERT_EQ(clone->reqDescription (), f_epargne.reqDescription ());
    ASSERT_EQ(clone->reqDateOuverture (), f_epargne.reqDateOuverture ());
}


/**
 * \brief Test de la méthode std::string reqCompteFormate()
 *        Cas valides: vérifier le retour des informations sur l'objet Compte formaté.
 *        Cas invalides: aucun.
 */
TEST_F (CompteEpargne, reqCompteFormate_formatConforme)
{
  ostringstream os;
  os<<"Compte Epargne"<<endl;
  os<<"numero : "<<f_epargne.reqNoCompte ()<<endl;
  os<<"Description : "<<f_epargne.reqDescription ()<<endl; 
  os<<"Date d'ouverture : "<<f_epargne.reqDateOuverture ().reqDateFormatee()<<endl;
  os<<"Taux d'interet : "<<f_epargne.reqTauxInteret ()<<endl;
  os<<"Solde : "<<f_epargne.reqSolde ()<<" $"<<endl;
  os<<"Interet : "<<f_epargne.calculerInteret ()<<" $"<<endl;
  
  ASSERT_EQ (os.str(), f_epargne.reqCompteFormate ());
}
        