/**
 * \file CompteTesteur.cpp
 * \brief Test unitaire de la classe Compte.
 *
 * À tester :
 *         Compte(int p_noCompte, double p_tauxInteret, double p_solde, 
 *         const std::string& p_description, const util::Date& p_dateOuverture);
 *         int reqNoCompte() const;
 *         double reqTauxInteret() const;
 *         double reqSolde() const;
 *         const std::string& reqDescription() const; //a surveiller const&
 *         const util::Date& reqDateOuverture() const;
 *         virtual void asgTauxInteret(double p_tauxInteret);
 *         virtual void asgSolde(double p_solde);
 *         void asgDescription(const std::string& p_description);
 *         virtual std::unique_ptr<Compte> clone() const=0;
 *         virtual double calculerInteret() const;
 *         virtual std::string reqCompteFormate() const; 
 *
 */

#include <gtest/gtest.h>
#include "Compte.h"
#include "ContratException.h"
#include <sstream>

using namespace bancaire;
using namespace std;

/**
 * \brief classe de test permettant de tester la classe abstraite Compte
 */
class CompteDeTest : public Compte
{
public:
  CompteDeTest(int p_noCompte, double p_tauxInteret, double p_solde, 
         const std::string& p_description, const util::Date& p_dateOuverture=util::Date()):
  Compte(p_noCompte, p_tauxInteret, p_solde, p_description, p_dateOuverture){};
          
  std::unique_ptr<Compte> clone() const override
    {
       return std::make_unique<CompteDeTest>(*this);
    }
};

/**
 * \brief Test du constructeur
 *     Cas valides : constructeurParametreValide — création d'un objet Epargne 
 *                   avec des valeurs valides et vérification de tous les attributs.
 *     Cas invalides : constructeurParametreInvalide — 
 *                     noCompteInvalide : Le numéro du compte doit être supérieur à zéro.
 *                     tauxInvalide :  Le taux doit être compris entre 0 % et 100 %.
 *                     descriptionInvalide: La description doit être non vide.
 *                     dateOuvertureInvalide :  La date doit correspondre à la date de création
 */

TEST(CompteTest,  constructeur_ParametresValides_objetvalide)
{
  CompteDeTest unCompte(128500, 13, 250000, "Projet");
  ASSERT_EQ(128500, unCompte.reqNoCompte ());
  ASSERT_EQ(13, unCompte.reqTauxInteret ());
  ASSERT_EQ(250000, unCompte.reqSolde ());
  ASSERT_EQ("Projet", unCompte.reqDescription ());
}

TEST(CompteTest, constructeur_noCompteInvalide_Preconditionexception)
{
  ASSERT_THROW(CompteDeTest unCompte(-128500, 13, 250000, "Projet"), PreconditionException)
                <<"Le numéro du compte doit être supérieur à zéro.";
  
  ASSERT_THROW(CompteDeTest unCompte(0, 13, 250000, "Projet"), PreconditionException)
                <<"Le numéro du compte doit être supérieur à zéro.";
}

TEST(CompteTest, constructeur_tauxInvalide_PreconditionException)
{
  ASSERT_THROW(CompteDeTest unCompte(128500, -13, 250000, "Projet"), PreconditionException)
          <<"Le taux doit être compris entre 0 et 100.";
  
  ASSERT_THROW(CompteDeTest unCompte(128500, 120, 250000, "Projet"), PreconditionException)
          <<"Le taux doit être compris entre 0 et 100.";
}

TEST(CompteTest, constructeur_DescriptionVide_PreconditionException)
{
  ASSERT_THROW(CompteDeTest unCompte(128500, 13, 250000, ""), PreconditionException)
          <<"La description doit être non vide.";

}

TEST(CompteTest, constructeur_DateOuvertureInvalide_PreconditionException)
{
  ASSERT_THROW(CompteDeTest unCompte(128500, 13, 250000, "Projet", util::Date(2,05,2020)), PreconditionException)
          <<"La date doit correspondre à la date de création";

}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Compte
 */
class Comptebase : public ::testing::Test
{
public:
  Comptebase():
  f_compte(1200, 8, 24500, "Etudes"){}
  CompteDeTest f_compte;
};


/**
 * \brief Test de la méthode int reqNoCompte() const;
 *        Cas valide : vérifier que le numéro de compte est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(Comptebase, reqNoCompte_valide_1200)
{
  ASSERT_EQ(1200, f_compte.reqNoCompte());
}

/**
 * \brief Test de la méthode double reqTauxInteret() const;
 *        Cas valide : vérifier que le taux d’intérêt est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(Comptebase, reqTauxInteret_valide_8)
{
  ASSERT_EQ(8, f_compte.reqTauxInteret());
}

/**
 * \brief Test de la méthode double reqSolde() const;
 *        Cas valide : vérifier que le solde est correctement retourné.
 *        Cas invalide : aucun.
 */
TEST_F(Comptebase, reqSolde_valide_24500)
{
  ASSERT_EQ(24500, f_compte.reqSolde());
}

/**
 * \brief Test de la méthode std::string reqDescription() const;
 *        Cas valide : vérifier que la description est correctement retournée.
 *        Cas invalide : aucun.
 */
TEST_F(Comptebase, reqDescription_valide)
{
  ASSERT_EQ("Etudes", f_compte.reqDescription());
}

/**
 * \brief Test de la méthode util::Date reqDateOuverture() const;
 *        Cas valide : vérifier que la date d’ouverture est correctement retournée.
 *        Cas invalide : aucun.
 */
TEST_F(Comptebase, reqDateOuverture_valide)
{
  ASSERT_EQ(util::Date(), f_compte.reqDateOuverture());
}

/**
 * \brief Assigner une nouvelle taux d'interet
 * 		  Cas valide : asgTauxValide assigner un taux valide
 * 		  Cas invalide : asgTauxInvalide: taux en dehors de l'intervalle [0,100]
 */
TEST_F(Comptebase, asgTauxInteret_TauxValide_25)
{
  f_compte.asgTauxInteret (25);
  ASSERT_EQ(25, f_compte.reqTauxInteret ());
}

TEST_F(Comptebase, asgTauxInteret_TauxNegatif_Preconditionexception)
{
  ASSERT_THROW(f_compte.asgTauxInteret (-25), PreconditionException);
}

TEST_F(Comptebase, asgTauxInteret_Tauxsup100_Preconditionexception)
{
  ASSERT_THROW(f_compte.asgTauxInteret (125), PreconditionException);
}

/**
 * \brief Assigner une nouveau solde 
 * 		  Cas valide : asgSoldeValide: un solde valide
 * 		  Cas invalide : aucun                
 */
TEST_F(Comptebase, asgSolde_SoldeValide_250)
{
  f_compte.asgSolde (250);
  ASSERT_EQ(250, f_compte.reqSolde ());
}

/**
 * \brief Assigner une nouvelle description
 * 		  Cas valide : asgDescriptionValide une description valide
 * 		  Cas invalide : asgDescriptionInValide une description vide              
 */
TEST_F(Comptebase, asgDescription_valide)
{
  f_compte.asgDescription ("Ecole");
  ASSERT_EQ("Ecole", f_compte.reqDescription ());
}

TEST_F(Comptebase, asgDescription_Invalide)
{
  ASSERT_THROW(f_compte.asgDescription (""), PreconditionException);
}

/**
 * \brief Test de la méthode calculerInteret() const.
 *     Cas valide: calcul de l'interet d'un compte.
 *     Cas invalide: aucun.
 */
TEST_F(Comptebase, calculerInteret_valide)
{
  ASSERT_EQ(0, f_compte.calculerInteret ());
}

/**
 * \brief Test de la méthode std::string reqCompteFormate()
 *        Cas valides: vérifier le retour des informations sur l'objet Compte formaté.
 *        Cas invalides: aucun.
 */
TEST_F(Comptebase, reqCompteFormate_valide)
{
  ostringstream os;
  os<<"numero : "<<f_compte.reqNoCompte ()<<endl;
  os<<"Description : "<<f_compte.reqDescription ()<<endl; 
  os<<"Date d'ouverture : "<<f_compte.reqDateOuverture ().reqDateFormatee()<<endl;
  os<<"Taux d'interet : "<<f_compte.reqTauxInteret ()<<endl;
  os<<"Solde : "<<f_compte.reqSolde ()<<" $"<<endl;
  
  ASSERT_EQ (os.str(), f_compte.reqCompteFormate ());
}