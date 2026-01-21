/* 
 * File:   SupprimerCompte.h
 * Author: etudiant
 *
 * Created on 20 avril 2025, 07 h 25
 */

#ifndef _SUPPRIMERCOMPTE_H
#define _SUPPRIMERCOMPTE_H

#include "ui_SupprimerCompte.h"


class SupprimerCompte : public QDialog
{
  Q_OBJECT
public:
  SupprimerCompte ();
  virtual ~SupprimerCompte ();
  
  int reqNoCompte() const;
  
  private slots:
    void slotConfirmerSuppression();
  
private:
  Ui::SupprimerCompte widget;
};

#endif /* _SUPPRIMERCOMPTE_H */
