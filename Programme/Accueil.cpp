/*
 * File:   Accueil.cpp
 * Author: etudiant
 *
 * Created on 20 avril 2025, 06 h 52
 */

#include "Accueil.h"
#include "Date.h"
#include "CompteException.h"
#include "AjoutCheque.h"
#include "AjoutEpargne.h"
#include "SupprimerCompte.h"
#include "Epargne.h"
#include "Cheque.h"
#include <QMessageBox>


Accueil::Accueil () : m_client(1000, "Florentino", "Perez", "418 656-0235", util::Date(19, 03, 1975))
{
  widget.setupUi (this);
  widget.textEditReleveClient->setPlainText(m_client.reqReleves ().c_str());
}

Accueil::~Accueil () { }

void Accueil::slotAjouterCheque ()
{
  AjoutCheque cheque;
  if (cheque.exec ())
    {
      try
        {
          bancaire::Cheque unCheque(cheque.reqNoCompte (), cheque.reqTransactions (), cheque.reqSolde (), 
                          cheque.reqTauxInteret (), cheque.reqDescription (), cheque.reqTauxMin ());
          m_client.ajouterCompte (unCheque);
        }   
      catch(CompteDejaPresentException& erreur)
        {
          QString message = (erreur.what ());
          QMessageBox::information(this, "ERREUR", message);
        }
      widget.textEditReleveClient->setPlainText (m_client.reqReleves ().c_str ());
    }
}

void Accueil::slotAjouterEpargne ()
{
  AjoutEpargne epargne;
  if(epargne.exec())
    {
      try
        {
          bancaire::Epargne unEpargne(epargne.reqNoCompte (), epargne.reqTauxInteret (),
                            epargne.reqSolde (), epargne.reqDescription ());
          m_client.ajouterCompte (unEpargne);
        }
      catch(CompteDejaPresentException& erreur)
        {
          QString message = (erreur.what());
          QMessageBox::information (this, "ERREUR", message);
        }
      widget.textEditReleveClient->setPlainText (m_client.reqReleves ().c_str());
    }
}

void Accueil::slotSupprimerCompte ()
{
  SupprimerCompte suppression;
  if(suppression.exec ())
    {
      try
        {
          m_client.supprimerCompte (suppression.reqNoCompte ());
        }
      catch(CompteAbsentException& erreur)
        {
          QString message = (erreur.what());
          QMessageBox::information (this, "ERREUR", message);
        }
      widget.textEditReleveClient->setPlainText (m_client.reqReleves ().c_str());
    }
}
