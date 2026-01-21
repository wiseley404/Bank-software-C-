/********************************************************************************
** Form generated from reading UI file 'SupprimerCompte.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERCOMPTE_H
#define UI_SUPPRIMERCOMPTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerCompte
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButtonSupprimer;

    void setupUi(QDialog *SupprimerCompte)
    {
        if (SupprimerCompte->objectName().isEmpty())
            SupprimerCompte->setObjectName(QString::fromUtf8("SupprimerCompte"));
        SupprimerCompte->resize(400, 300);
        label = new QLabel(SupprimerCompte);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 70, 91, 16));
        lineEdit = new QLineEdit(SupprimerCompte);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 90, 171, 28));
        pushButtonSupprimer = new QPushButton(SupprimerCompte);
        pushButtonSupprimer->setObjectName(QString::fromUtf8("pushButtonSupprimer"));
        pushButtonSupprimer->setGeometry(QRect(150, 160, 90, 28));

        retranslateUi(SupprimerCompte);
        QObject::connect(pushButtonSupprimer, SIGNAL(clicked()), SupprimerCompte, SLOT(slotConfirmerSuppression()));

        QMetaObject::connectSlotsByName(SupprimerCompte);
    } // setupUi

    void retranslateUi(QDialog *SupprimerCompte)
    {
        SupprimerCompte->setWindowTitle(QCoreApplication::translate("SupprimerCompte", "SupprimerCompte", nullptr));
        label->setText(QCoreApplication::translate("SupprimerCompte", "No de Compte :", nullptr));
        pushButtonSupprimer->setText(QCoreApplication::translate("SupprimerCompte", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerCompte: public Ui_SupprimerCompte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERCOMPTE_H
