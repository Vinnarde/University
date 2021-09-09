/********************************************************************************
** Form generated from reading UI file 'book.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_H
#define UI_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Book
{
public:

    void setupUi(QDialog *Book)
    {
        if (Book->objectName().isEmpty())
            Book->setObjectName(QString::fromUtf8("Book"));
        Book->setEnabled(true);
        Book->resize(1280, 720);
        QFont font;
        font.setPointSize(12);
        Book->setFont(font);

        retranslateUi(Book);

        QMetaObject::connectSlotsByName(Book);
    } // setupUi

    void retranslateUi(QDialog *Book)
    {
        Book->setWindowTitle(QCoreApplication::translate("Book", "Book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Book: public Ui_Book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_H
