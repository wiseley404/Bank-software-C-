/********************************************************************************
** Form generated from reading UI file 'AjoutCheque.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCHEQUE_H
#define UI_AJOUTCHEQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjoutCheque
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonAjoutCheque;
    QLineEdit *lineEdit_compte;
    QLineEdit *lineEdit_tauxInteret;
    QLineEdit *lineEdit_Solde;
    QLineEdit *lineEdit_Description;
    QLineEdit *lineEdit_Transactions;
    QLineEdit *lineEdit_tauxmin;

    void setupUi(QDialog *AjoutCheque)
    {
        if (AjoutCheque->objectName().isEmpty())
            AjoutCheque->setObjectName(QString::fromUtf8("AjoutCheque"));
        AjoutCheque->resize(474, 401);
        label = new QLabel(AjoutCheque);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 91, 31));
        label_2 = new QLabel(AjoutCheque);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 91, 16));
        label_3 = new QLabel(AjoutCheque);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 58, 16));
        label_4 = new QLabel(AjoutCheque);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 160, 91, 16));
        label_5 = new QLabel(AjoutCheque);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 200, 151, 16));
        label_6 = new QLabel(AjoutCheque);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 240, 58, 16));
        pushButtonAjoutCheque = new QPushButton(AjoutCheque);
        pushButtonAjoutCheque->setObjectName(QString::fromUtf8("pushButtonAjoutCheque"));
        pushButtonAjoutCheque->setGeometry(QRect(210, 310, 90, 28));
        lineEdit_compte = new QLineEdit(AjoutCheque);
        lineEdit_compte->setObjectName(QString::fromUtf8("lineEdit_compte"));
        lineEdit_compte->setGeometry(QRect(160, 30, 201, 28));
        lineEdit_tauxInteret = new QLineEdit(AjoutCheque);
        lineEdit_tauxInteret->setObjectName(QString::fromUtf8("lineEdit_tauxInteret"));
        lineEdit_tauxInteret->setGeometry(QRect(160, 70, 201, 28));
        lineEdit_Solde = new QLineEdit(AjoutCheque);
        lineEdit_Solde->setObjectName(QString::fromUtf8("lineEdit_Solde"));
        lineEdit_Solde->setGeometry(QRect(160, 110, 201, 28));
        lineEdit_Description = new QLineEdit(AjoutCheque);
        lineEdit_Description->setObjectName(QString::fromUtf8("lineEdit_Description"));
        lineEdit_Description->setGeometry(QRect(160, 150, 201, 28));
        lineEdit_Transactions = new QLineEdit(AjoutCheque);
        lineEdit_Transactions->setObjectName(QString::fromUtf8("lineEdit_Transactions"));
        lineEdit_Transactions->setGeometry(QRect(160, 190, 201, 28));
        lineEdit_tauxmin = new QLineEdit(AjoutCheque);
        lineEdit_tauxmin->setObjectName(QString::fromUtf8("lineEdit_tauxmin"));
        lineEdit_tauxmin->setGeometry(QRect(160, 230, 201, 28));

        retranslateUi(AjoutCheque);
        QObject::connect(pushButtonAjoutCheque, SIGNAL(clicked()), AjoutCheque, SLOT(slotConfirmerCheque()));

        QMetaObject::connectSlotsByName(AjoutCheque);
    } // setupUi

    void retranslateUi(QDialog *AjoutCheque)
    {
        AjoutCheque->setWindowTitle(QCoreApplication::translate("AjoutCheque", "AjoutCheque", nullptr));
        label->setText(QCoreApplication::translate("AjoutCheque", "No de compte :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutCheque", "Taux d'interet :", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutCheque", "Solde :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutCheque", "Description :", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutCheque", "Nbre Transactions :", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutCheque", "Taux min :", nullptr));
        pushButtonAjoutCheque->setText(QCoreApplication::translate("AjoutCheque", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutCheque: public Ui_AjoutCheque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCHEQUE_H
