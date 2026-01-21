/**
 * \file ChequeTesteur.cpp
 * \brief Test unitaire de la classe Cheque.
 *
 * À tester :
 * Cheque(int p_noCompte, int p_nombreTransactions, double p_solde, 
 *        double p_tauxInteret, const std::string& p_description,
 *        double p_tauxInteretMinimum=0.1, const util::Date& p_dateOuverture=util::Date());   
 *        int reqNombreTransactions() const;
 *        double reqTauxInteretMinimum() const;
 *        void asgTauxInteret(double p_tauxInteret) override;
 *        void asgSolde(double p_solde) override;
 *        void asgNombreTransactions(int p_nombreTransactions); 
 *        double calculerInteret() const override;
 *        std::string reqCompteFormate()  const override; 
 *        std::unique_ptr<Compte> clone() const override;
 * 
 *
 */

#include <gtest/gtest.h>
#include "Cheque.h"
#include "ContratException.h"
#include <sstream>

using namespace bancaire;
using namespace std;

/**
 * \brief Test du constructeur
 *     Cas valides : constructeurParametreValide — création d'un objet Epargne 
 *                   avec des valeurs valides et vérification de tous les attributs.
 *                   TauxInteretMinimumParDefaut: Le taux minimum doit retourner 0.1
 *                   DescriptionParDefaut : La description doit retourner "Cheque"
 *     Cas invalides : constructeurParametreInvalide — 
 *                     NombreTransactionsInvalide : le nombre de transactions doit etre entre 0 et 40.
 *                     OrdreGrandeurTauxInvalide : le taux d'interet minimum doi etre inferieur au taux du compte.
 */
TEST (ChequeTest, constructeur_Parametresvalides_ChequeValide)
{
  Cheque CompteCheque(1230, 30, 25000, 15, "Achat Maison", 3);
  ASSERT_EQ(30, CompteCheque.reqNombreTransactions ());
  ASSERT_EQ(3, CompteCheque.reqTauxInteretMinimum ());
  ASSERT_EQ("Achat Maison", CompteCheque.reqDescription ());
}

TEST (ChequeTest, constructeur_ParametresParDefaut_ChequeValide)
{
  Cheque CompteCheque(1230, 30, 25000, 15, "");
  ASSERT_EQ("Cheque", CompteCheque.reqDescription ());
  ASSERT_EQ(0.1, CompteCheque.reqTauxInteretMinimum ());
}

TEST (ChequeTest, constructeur_NombreTransactionsInvalide_PreconditionException)
{
  ASSERT_THROW(Cheque CompteCheque(1230, 50, 25000, 15, "Achat Maison", 3) , PreconditionException)
                <<" Le nombre de transactions doit être compris entre 0 et 40";
}

TEST (ChequeTest, constructeur_OrdreGrandeurTauxInvalide_PreconditionException)
{
  ASSERT_THROW(Cheque CompteCheque(1230, 50, 25000, 10, "Achat Maison", 13) , PreconditionException)
                <<" Le taux d'intérêt minimum doit être inférieur au taux du compte.";
}

/**
 * \brief Création d'une fixture utilisée pour les tests de la classe Cheque
 */
class CompteCheque : public ::testing::Test
{
public:
  CompteCheque():
  f_cheque(1350, 25, 32500, 15, "Loyer", 5) {}
  Cheque f_cheque;
};


/**
 * \brief Test de la méthode int reqNombreTransactions() const;
 *        Cas valides : reqNombreTransactions — vérifier le retour du nombre de transactions.
 *        Cas invalides : aucun.
 */
TEST_F(CompteCheque, reqNombreTransactions_valide_25)
{
  ASSERT_EQ(25, f_cheque.reqNombreTransactions ());
}

/**
 * \brief Test de la méthode int reqTauxInteretMinimum() const;
 *        Cas valides : reqTauxInteretMinimum — vérifier le retour du taux d’intérêt minimum.
 *        Cas invalides : aucun.
 */
TEST_F(CompteCheque, reqTauxInteretMinimum_valide_5)
{
  ASSERT_EQ(5, f_cheque.reqTauxInteretMinimum ());
}

/**
 * \brief Assigner un nouveau taux d’intérêt
 *        Cas valide : asgTauxValide — assigner un taux valide
 *        Cas invalide : asgTauxInvalide — assigner un taux négatif                  
 */
TEST_F(CompteCheque, asgTauxInteret_valide_35)
{
  f_cheque.asgTauxInteret (35);
  ASSERT_EQ(35, f_cheque.reqTauxInteret ());
}

TEST_F(CompteCheque, asgTauxInteret_Invalide_PreconditionException)
{
  ASSERT_THROW(f_cheque.asgTauxInteret (-35), PreconditionException)
                <<" Le taux doit être compris entre 0 et 100.";
  
  ASSERT_THROW(f_cheque.asgTauxInteret (101), PreconditionException)
                <<" Le taux doit être compris entre 0 et 100.";
}

/**
 * \brief Assigner une nouveau solde 
 * 		  Cas valide : asgSoldeValide assigner un solde valide
 * 		  Cas invalide : aucun identifié                
 */
TEST_F(CompteCheque, asgSolde_soldePositif_valide)
{
  f_cheque.asgSolde (1000);
  ASSERT_EQ(1000, f_cheque.reqSolde ());
}

TEST_F(CompteCheque, asgSolde_soldeNegatif_valide)
{
  f_cheque.asgSolde (-1000);
  ASSERT_EQ(-1000, f_cheque.reqSolde ());
}


/**
 * \brief Assigner un nouveau nombre de transactions
 *        Cas valide : asgNombreTransactionsValide — assigner un nombre de transactions valide
 *        Cas invalide : asgNombreTransactionsInvalide — valeur supérieure à 40
 */
TEST_F(CompteCheque, asgTransactions_Valide_25)
{
  ASSERT_EQ(25, f_cheque.reqNombreTransactions ());
}

TEST_F(CompteCheque, asgTransactions_Invalide_PreconditionException)
{
  ASSERT_THROW(f_cheque.asgNombreTransactions (50), PreconditionException);
}

/**
 * \brief Test de la méthode calculerInteret() const.
 *     Cas valides : Solde positif
 *             solde negatif
 *         - 0 à 10 transactions
 *         - 11 à 25 transactions
 *         - 26 à 35 transactions
 *         - plus de 35 transactions
 *     Cas invalide : aucun.
 */
TEST_F(CompteCheque, calculInteret_soldePositif_0)
{
  ASSERT_EQ(0, f_cheque.calculerInteret ());
}

TEST_F(CompteCheque, calculInteret_soldeNegatifTransaction5_Valide)
{
  f_cheque.asgNombreTransactions (5);
  f_cheque.asgSolde (-1000);
  ASSERT_EQ((-f_cheque.reqSolde()*(f_cheque.reqTauxInteretMinimum()/100)), f_cheque.calculerInteret ());
}

TEST_F(CompteCheque, calculInteret_soldeNegatifTransaction15_Valide)
{
  f_cheque.asgNombreTransactions (15);
  f_cheque.asgSolde (-1000);
  ASSERT_EQ((-f_cheque.reqSolde() * (f_cheque.reqTauxInteretMinimum() / 100)) * 1.4, f_cheque.calculerInteret ());
}

TEST_F(CompteCheque, calculInteret_soldeNegatifTransaction30_Valide)
{
  f_cheque.asgNombreTransactions (30);
  f_cheque.asgSolde (-1000);
  ASSERT_EQ((-f_cheque.reqSolde() * (f_cheque.reqTauxInteretMinimum() / 100)) * 1.8, f_cheque.calculerInteret ());
}

TEST_F(CompteCheque, calculInteret_soldeNegatifTransaction36_Valide)
{
  f_cheque.asgNombreTransactions (36);
  f_cheque.asgSolde (-1000);
  ASSERT_EQ(-f_cheque.reqSolde()*(f_cheque.reqTauxInteret()/100), f_cheque.calculerInteret ());
}

/**
 * \brief Test de la méthode std::string reqCompteFormate()
 *        Cas valides: vérifier le retour des informations sur l'objet Compte formaté.
 *        Cas invalides: aucun.
 */
TEST_F (CompteCheque, reqCompteFormate_formatConforme)
{
  ostringstream os;
  os<<"Compte Cheque"<<endl;
  os<<"numero : "<<f_cheque.reqNoCompte ()<<endl;
  os<<"Description : "<<f_cheque.reqDescription ()<<endl; 
  os<<"Date d'ouverture : "<<f_cheque.reqDateOuverture ().reqDateFormatee()<<endl;
  os<<"Taux d'interet : "<<f_cheque.reqTauxInteret ()<<endl;
  os<<"Solde : "<<f_cheque.reqSolde ()<<" $"<<endl;
  os<<"nombre de transactions : "<<f_cheque.reqNombreTransactions()<<endl;
  os<<"Taux d'interet minimum : "<<f_cheque.reqTauxInteretMinimum()<<endl;
  os<<"Interet : "<<f_cheque.calculerInteret()<<" $"<<endl;
  
  ASSERT_EQ (os.str(), f_cheque.reqCompteFormate ());
}

/**
 * \brief Test de la méthode clone() const.
 *     Cas valide: clonage reussi.
 *     Cas invalide: aucun.
 */
TEST_F (CompteCheque, clone_reussi)
{
    std::unique_ptr<Compte> clone = f_cheque.clone();
    ASSERT_EQ(clone->reqNoCompte(), f_cheque.reqNoCompte());
    ASSERT_EQ(clone->reqSolde(), f_cheque.reqSolde ());
    ASSERT_EQ(clone->reqTauxInteret(), f_cheque.reqTauxInteret());
    ASSERT_EQ(clone->reqDescription (), f_cheque.reqDescription ());
    ASSERT_EQ(clone->reqDateOuverture (), f_cheque.reqDateOuverture ());
}