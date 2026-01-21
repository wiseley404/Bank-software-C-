/* 
 * File:   AjoutCheque.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 06 h 04
 */

#ifndef _AJOUTCHEQUE_H
#define _AJOUTCHEQUE_H

#include "ui_AjoutCheque.h"

class AjoutCheque : public QDialog
{
  Q_OBJECT
public:
  AjoutCheque ();
  virtual ~AjoutCheque ();
  
  int reqNoCompte() const;
  int reqTransactions() const;
  double reqSolde() const;
  double reqTauxInteret() const;
  double reqTauxMin () const;
  std::string reqDescription() const;
  
  
  private slots:
    void slotConfirmerCheque();
    
private:
  Ui::AjoutCheque widget;
};

#endif /* _AJOUTCHEQUE_H */
