/*
 * File:   SupprimerCompte.cpp
 * Author: etudiant
 *
 * Created on 20 avril 2025, 07 h 25
 */

#include "SupprimerCompte.h"
#include <QMessageBox>

SupprimerCompte::SupprimerCompte ()
{
  widget.setupUi (this);
}

SupprimerCompte::~SupprimerCompte () { }

void SupprimerCompte::slotConfirmerSuppression() 
{
  accept();
}

int SupprimerCompte::reqNoCompte() const 
{
  return widget.lineEdit->text ().toInt();
}
