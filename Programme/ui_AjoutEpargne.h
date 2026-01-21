/********************************************************************************
** Form generated from reading UI file 'AjoutEpargne.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTEPARGNE_H
#define UI_AJOUTEPARGNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutEpargne
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Compte;
    QLineEdit *lineEdit_Description;
    QLineEdit *lineEdit_Solde;
    QLineEdit *lineEdit_TauxInteret;
    QPushButton *pushButtonAjouterEpargne;

    void setupUi(QDialog *AjoutEpargne)
    {
        if (AjoutEpargne->objectName().isEmpty())
            AjoutEpargne->setObjectName(QString::fromUtf8("AjoutEpargne"));
        AjoutEpargne->resize(462, 389);
        label = new QLabel(AjoutEpargne);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 101, 21));
        label_2 = new QLabel(AjoutEpargne);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 180, 101, 21));
        label_3 = new QLabel(AjoutEpargne);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 130, 101, 21));
        label_4 = new QLabel(AjoutEpargne);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 80, 101, 21));
        lineEdit_Compte = new QLineEdit(AjoutEpargne);
        lineEdit_Compte->setObjectName(QString::fromUtf8("lineEdit_Compte"));
        lineEdit_Compte->setGeometry(QRect(160, 30, 171, 28));
        lineEdit_Description = new QLineEdit(AjoutEpargne);
        lineEdit_Description->setObjectName(QString::fromUtf8("lineEdit_Description"));
        lineEdit_Description->setGeometry(QRect(160, 80, 171, 28));
        lineEdit_Solde = new QLineEdit(AjoutEpargne);
        lineEdit_Solde->setObjectName(QString::fromUtf8("lineEdit_Solde"));
        lineEdit_Solde->setGeometry(QRect(160, 130, 171, 28));
        lineEdit_TauxInteret = new QLineEdit(AjoutEpargne);
        lineEdit_TauxInteret->setObjectName(QString::fromUtf8("lineEdit_TauxInteret"));
        lineEdit_TauxInteret->setGeometry(QRect(160, 180, 171, 28));
        pushButtonAjouterEpargne = new QPushButton(AjoutEpargne);
        pushButtonAjouterEpargne->setObjectName(QString::fromUtf8("pushButtonAjouterEpargne"));
        pushButtonAjouterEpargne->setGeometry(QRect(190, 280, 90, 28));

        retranslateUi(AjoutEpargne);
        QObject::connect(pushButtonAjouterEpargne, SIGNAL(clicked()), AjoutEpargne, SLOT(slotConfirmerEpargne()));

        QMetaObject::connectSlotsByName(AjoutEpargne);
    } // setupUi

    void retranslateUi(QDialog *AjoutEpargne)
    {
        AjoutEpargne->setWindowTitle(QCoreApplication::translate("AjoutEpargne", "AjoutEpargne", nullptr));
        label->setText(QCoreApplication::translate("AjoutEpargne", "No de Compte :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutEpargne", "Taux d'Interet :", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutEpargne", "Solde :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutEpargne", "Description :", nullptr));
        pushButtonAjouterEpargne->setText(QCoreApplication::translate("AjoutEpargne", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutEpargne: public Ui_AjoutEpargne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTEPARGNE_H
