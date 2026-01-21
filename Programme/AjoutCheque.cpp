
/*
 * File:   AjoutCheque.cpp
 * Author: etudiant
 *
 * Created on 20 avril 2025, 06 h 04
 */

#include <qt5/QtWidgets/qmessagebox.h>

#include "AjoutCheque.h"
#include <QMessageBox>

AjoutCheque::AjoutCheque ()
{
  widget.setupUi (this);
}

AjoutCheque::~AjoutCheque () { }

void AjoutCheque::slotConfirmerCheque() 
{
  if (reqNoCompte ()<0)
    {
      QString message("Le numero de compte doit etre un entier positif");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTransactions ()<0 || reqTauxInteret ()>40)
    {
      QString message("Le nombre de transactions doit etre entre 0 et 40");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTauxInteret ()<0 || reqTauxInteret ()>100)
    {
      QString message("Le taux d'interet doit etre entre 0 et 100%");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTauxMin ()> reqTauxInteret () || reqTauxMin () <0)
    {
      QString message("Le taux d'interet minimum doit etre un taux positif inferieur au taux du compte");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  // La description peut etre vide, ca prend "Cheque" par defaut
  accept();
}


int AjoutCheque::reqNoCompte() const 
{
  return widget.lineEdit_compte->text ().toInt();
}


int AjoutCheque::reqTransactions() const 
{
  return widget.lineEdit_Transactions->text ().toInt();
}


double AjoutCheque::reqSolde() const 
{
  return widget.lineEdit_Solde->text ().toDouble();
}


double AjoutCheque::reqTauxInteret() const 
{
  return widget.lineEdit_tauxInteret->text ().toDouble();
}


double AjoutCheque::reqTauxMin () const 
{
  // Le taux d'interet minimum est 0.1 par defaut
  if(widget.lineEdit_tauxmin->text ().isEmpty ())
    {
     return 0.1;
    }
  return widget.lineEdit_tauxmin->text ().toDouble();
}


std::string AjoutCheque::reqDescription() const 
{
  return widget.lineEdit_Description->text ().toStdString();
}
