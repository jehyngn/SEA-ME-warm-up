/********************************************************************************
** Form generated from reading UI file 'tabel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABEL_H
#define UI_TABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabel
{
public:

    void setupUi(QWidget *tabel)
    {
        if (tabel->objectName().isEmpty())
            tabel->setObjectName(QString::fromUtf8("tabel"));
        tabel->resize(480, 640);

        retranslateUi(tabel);

        QMetaObject::connectSlotsByName(tabel);
    } // setupUi

    void retranslateUi(QWidget *tabel)
    {
        tabel->setWindowTitle(QCoreApplication::translate("tabel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tabel: public Ui_tabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABEL_H
