/*
 * File:   AjoutEpargne.cpp
 * Author: etudiant
 *
 * Created on 20 avril 2025, 07 h 17
 */

#include "AjoutEpargne.h"
#include <QMessageBox>

AjoutEpargne::AjoutEpargne ()
{
  widget.setupUi (this);
}

AjoutEpargne::~AjoutEpargne () { }


void AjoutEpargne::slotConfirmerEpargne() 
{
  if (reqNoCompte ()<0)
    {
      QString message("Le numero de compte doit etre un entier positif");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTauxInteret ()<0.1 || reqTauxInteret ()>3.5)
    {
      QString message("Le taux d'interet doit etre entre 0.1% et 3.5%");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqSolde () <0)
    {
      QString message("Le solde du compte doit etre positif");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  // La description peut etre vide, ca prend "Epargne" par defaut
  accept();
}


int AjoutEpargne::reqNoCompte() const 
{
  return widget.lineEdit_Compte->text ().toInt();
}


double AjoutEpargne::reqSolde() const 
{
  return widget.lineEdit_Solde->text ().toDouble();
}


double AjoutEpargne::reqTauxInteret() const 
{
  return widget.lineEdit_TauxInteret->text ().toDouble();
}


std::string AjoutEpargne::reqDescription() const 
{
  return widget.lineEdit_Description->text ().toStdString();
}
