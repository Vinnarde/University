/********************************************************************************
** Form generated from reading UI file 'tables.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLES_H
#define UI_TABLES_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tables
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelBookTypeId_2;
    QComboBox *comboBoxBookTypeId_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelBookName_2;
    QComboBox *comboBoxBookName_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelBookPageCount_2;
    QLineEdit *lineEditBookPageCount_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelBookPrice_2;
    QLineEdit *lineEditBookPrice_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelBookAuthorId_2;
    QComboBox *comboBoxBookAuthorId_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelBookPublisherId_2;
    QComboBox *comboBoxBookPublisherId_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelBookAmount_2;
    QLineEdit *lineEditBookAmount_2;
    QTableView *tableViewBooks;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButtonBookAdd_2;
    QPushButton *pushButtonBookEdit_2;
    QPushButton *pushButtonBookDelete_2;
    QPushButton *pushButtonLoadDataBooks;
    QWidget *tab_2;
    QTableView *tableViewStudents;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *pushButtonStudentAdd;
    QPushButton *pushButtonStudentEdit;
    QPushButton *pushButtonStudentDelete;
    QPushButton *pushButtonStudentLoadData;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_17;
    QLabel *labelStudentStudentId;
    QComboBox *comboBoxStudentStudentId;
    QHBoxLayout *horizontalLayout_18;
    QLabel *labelStudentFirstName;
    QLineEdit *lineEditStudentFirstName;
    QHBoxLayout *horizontalLayout_19;
    QLabel *labelStudentSurname;
    QLineEdit *lineEditStudentSurname;
    QHBoxLayout *horizontalLayout_20;
    QLabel *labelStudentCourse;
    QComboBox *comboBoxStudentCourse;
    QHBoxLayout *horizontalLayout_21;
    QLabel *labelStudentPhone;
    QLineEdit *lineEditStudentPhone;
    QHBoxLayout *horizontalLayout_22;
    QLabel *labelStudentBirthDate;
    QDateEdit *dateEditStudentBirthDate;
    QHBoxLayout *horizontalLayout_23;
    QLabel *labelStudentSex;
    QComboBox *comboBoxStudentSex;

    void setupUi(QDialog *Tables)
    {
        if (Tables->objectName().isEmpty())
            Tables->setObjectName(QString::fromUtf8("Tables"));
        Tables->resize(1280, 720);
        QFont font;
        font.setPointSize(14);
        Tables->setFont(font);
        gridLayout = new QGridLayout(Tables);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Tables);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 2, 481, 411));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelBookTypeId_2 = new QLabel(layoutWidget);
        labelBookTypeId_2->setObjectName(QString::fromUtf8("labelBookTypeId_2"));

        horizontalLayout_9->addWidget(labelBookTypeId_2);

        comboBoxBookTypeId_2 = new QComboBox(layoutWidget);
        comboBoxBookTypeId_2->setObjectName(QString::fromUtf8("comboBoxBookTypeId_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxBookTypeId_2->sizePolicy().hasHeightForWidth());
        comboBoxBookTypeId_2->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBoxBookTypeId_2);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labelBookName_2 = new QLabel(layoutWidget);
        labelBookName_2->setObjectName(QString::fromUtf8("labelBookName_2"));

        horizontalLayout_10->addWidget(labelBookName_2);

        comboBoxBookName_2 = new QComboBox(layoutWidget);
        comboBoxBookName_2->setObjectName(QString::fromUtf8("comboBoxBookName_2"));
        sizePolicy.setHeightForWidth(comboBoxBookName_2->sizePolicy().hasHeightForWidth());
        comboBoxBookName_2->setSizePolicy(sizePolicy);
        comboBoxBookName_2->setEditable(true);

        horizontalLayout_10->addWidget(comboBoxBookName_2);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        labelBookPageCount_2 = new QLabel(layoutWidget);
        labelBookPageCount_2->setObjectName(QString::fromUtf8("labelBookPageCount_2"));

        horizontalLayout_11->addWidget(labelBookPageCount_2);

        lineEditBookPageCount_2 = new QLineEdit(layoutWidget);
        lineEditBookPageCount_2->setObjectName(QString::fromUtf8("lineEditBookPageCount_2"));

        horizontalLayout_11->addWidget(lineEditBookPageCount_2);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        labelBookPrice_2 = new QLabel(layoutWidget);
        labelBookPrice_2->setObjectName(QString::fromUtf8("labelBookPrice_2"));

        horizontalLayout_12->addWidget(labelBookPrice_2);

        lineEditBookPrice_2 = new QLineEdit(layoutWidget);
        lineEditBookPrice_2->setObjectName(QString::fromUtf8("lineEditBookPrice_2"));

        horizontalLayout_12->addWidget(lineEditBookPrice_2);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        labelBookAuthorId_2 = new QLabel(layoutWidget);
        labelBookAuthorId_2->setObjectName(QString::fromUtf8("labelBookAuthorId_2"));

        horizontalLayout_13->addWidget(labelBookAuthorId_2);

        comboBoxBookAuthorId_2 = new QComboBox(layoutWidget);
        comboBoxBookAuthorId_2->setObjectName(QString::fromUtf8("comboBoxBookAuthorId_2"));
        sizePolicy.setHeightForWidth(comboBoxBookAuthorId_2->sizePolicy().hasHeightForWidth());
        comboBoxBookAuthorId_2->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(comboBoxBookAuthorId_2);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        labelBookPublisherId_2 = new QLabel(layoutWidget);
        labelBookPublisherId_2->setObjectName(QString::fromUtf8("labelBookPublisherId_2"));

        horizontalLayout_14->addWidget(labelBookPublisherId_2);

        comboBoxBookPublisherId_2 = new QComboBox(layoutWidget);
        comboBoxBookPublisherId_2->setObjectName(QString::fromUtf8("comboBoxBookPublisherId_2"));
        sizePolicy.setHeightForWidth(comboBoxBookPublisherId_2->sizePolicy().hasHeightForWidth());
        comboBoxBookPublisherId_2->setSizePolicy(sizePolicy);
        comboBoxBookPublisherId_2->setEditable(false);

        horizontalLayout_14->addWidget(comboBoxBookPublisherId_2);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        labelBookAmount_2 = new QLabel(layoutWidget);
        labelBookAmount_2->setObjectName(QString::fromUtf8("labelBookAmount_2"));

        horizontalLayout_15->addWidget(labelBookAmount_2);

        lineEditBookAmount_2 = new QLineEdit(layoutWidget);
        lineEditBookAmount_2->setObjectName(QString::fromUtf8("lineEditBookAmount_2"));

        horizontalLayout_15->addWidget(lineEditBookAmount_2);


        verticalLayout_2->addLayout(horizontalLayout_15);

        tableViewBooks = new QTableView(tab);
        tableViewBooks->setObjectName(QString::fromUtf8("tableViewBooks"));
        tableViewBooks->setGeometry(QRect(490, -10, 771, 661));
        tableViewBooks->setAutoFillBackground(true);
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 430, 481, 51));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        pushButtonBookAdd_2 = new QPushButton(layoutWidget_2);
        pushButtonBookAdd_2->setObjectName(QString::fromUtf8("pushButtonBookAdd_2"));

        horizontalLayout_16->addWidget(pushButtonBookAdd_2);

        pushButtonBookEdit_2 = new QPushButton(layoutWidget_2);
        pushButtonBookEdit_2->setObjectName(QString::fromUtf8("pushButtonBookEdit_2"));

        horizontalLayout_16->addWidget(pushButtonBookEdit_2);

        pushButtonBookDelete_2 = new QPushButton(layoutWidget_2);
        pushButtonBookDelete_2->setObjectName(QString::fromUtf8("pushButtonBookDelete_2"));

        horizontalLayout_16->addWidget(pushButtonBookDelete_2);

        pushButtonLoadDataBooks = new QPushButton(tab);
        pushButtonLoadDataBooks->setObjectName(QString::fromUtf8("pushButtonLoadDataBooks"));
        pushButtonLoadDataBooks->setGeometry(QRect(10, 610, 471, 41));
        pushButtonLoadDataBooks->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableViewStudents = new QTableView(tab_2);
        tableViewStudents->setObjectName(QString::fromUtf8("tableViewStudents"));
        tableViewStudents->setGeometry(QRect(490, 0, 771, 661));
        tableViewStudents->setAutoFillBackground(true);
        layoutWidget_3 = new QWidget(tab_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 360, 471, 51));
        horizontalLayout_24 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        pushButtonStudentAdd = new QPushButton(layoutWidget_3);
        pushButtonStudentAdd->setObjectName(QString::fromUtf8("pushButtonStudentAdd"));

        horizontalLayout_24->addWidget(pushButtonStudentAdd);

        pushButtonStudentEdit = new QPushButton(layoutWidget_3);
        pushButtonStudentEdit->setObjectName(QString::fromUtf8("pushButtonStudentEdit"));

        horizontalLayout_24->addWidget(pushButtonStudentEdit);

        pushButtonStudentDelete = new QPushButton(layoutWidget_3);
        pushButtonStudentDelete->setObjectName(QString::fromUtf8("pushButtonStudentDelete"));

        horizontalLayout_24->addWidget(pushButtonStudentDelete);

        pushButtonStudentLoadData = new QPushButton(tab_2);
        pushButtonStudentLoadData->setObjectName(QString::fromUtf8("pushButtonStudentLoadData"));
        pushButtonStudentLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonStudentLoadData->setFont(font);
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(7, 20, 471, 321));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        labelStudentStudentId = new QLabel(widget);
        labelStudentStudentId->setObjectName(QString::fromUtf8("labelStudentStudentId"));

        horizontalLayout_17->addWidget(labelStudentStudentId);

        comboBoxStudentStudentId = new QComboBox(widget);
        comboBoxStudentStudentId->setObjectName(QString::fromUtf8("comboBoxStudentStudentId"));
        sizePolicy.setHeightForWidth(comboBoxStudentStudentId->sizePolicy().hasHeightForWidth());
        comboBoxStudentStudentId->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(comboBoxStudentStudentId);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        labelStudentFirstName = new QLabel(widget);
        labelStudentFirstName->setObjectName(QString::fromUtf8("labelStudentFirstName"));

        horizontalLayout_18->addWidget(labelStudentFirstName);

        lineEditStudentFirstName = new QLineEdit(widget);
        lineEditStudentFirstName->setObjectName(QString::fromUtf8("lineEditStudentFirstName"));

        horizontalLayout_18->addWidget(lineEditStudentFirstName);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        labelStudentSurname = new QLabel(widget);
        labelStudentSurname->setObjectName(QString::fromUtf8("labelStudentSurname"));

        horizontalLayout_19->addWidget(labelStudentSurname);

        lineEditStudentSurname = new QLineEdit(widget);
        lineEditStudentSurname->setObjectName(QString::fromUtf8("lineEditStudentSurname"));

        horizontalLayout_19->addWidget(lineEditStudentSurname);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        labelStudentCourse = new QLabel(widget);
        labelStudentCourse->setObjectName(QString::fromUtf8("labelStudentCourse"));

        horizontalLayout_20->addWidget(labelStudentCourse);

        comboBoxStudentCourse = new QComboBox(widget);
        comboBoxStudentCourse->setObjectName(QString::fromUtf8("comboBoxStudentCourse"));
        sizePolicy.setHeightForWidth(comboBoxStudentCourse->sizePolicy().hasHeightForWidth());
        comboBoxStudentCourse->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(comboBoxStudentCourse);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        labelStudentPhone = new QLabel(widget);
        labelStudentPhone->setObjectName(QString::fromUtf8("labelStudentPhone"));

        horizontalLayout_21->addWidget(labelStudentPhone);

        lineEditStudentPhone = new QLineEdit(widget);
        lineEditStudentPhone->setObjectName(QString::fromUtf8("lineEditStudentPhone"));

        horizontalLayout_21->addWidget(lineEditStudentPhone);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        labelStudentBirthDate = new QLabel(widget);
        labelStudentBirthDate->setObjectName(QString::fromUtf8("labelStudentBirthDate"));

        horizontalLayout_22->addWidget(labelStudentBirthDate);

        dateEditStudentBirthDate = new QDateEdit(widget);
        dateEditStudentBirthDate->setObjectName(QString::fromUtf8("dateEditStudentBirthDate"));
        dateEditStudentBirthDate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateEditStudentBirthDate->setTimeSpec(Qt::LocalTime);

        horizontalLayout_22->addWidget(dateEditStudentBirthDate);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        labelStudentSex = new QLabel(widget);
        labelStudentSex->setObjectName(QString::fromUtf8("labelStudentSex"));

        horizontalLayout_23->addWidget(labelStudentSex);

        comboBoxStudentSex = new QComboBox(widget);
        comboBoxStudentSex->setObjectName(QString::fromUtf8("comboBoxStudentSex"));
        sizePolicy.setHeightForWidth(comboBoxStudentSex->sizePolicy().hasHeightForWidth());
        comboBoxStudentSex->setSizePolicy(sizePolicy);

        horizontalLayout_23->addWidget(comboBoxStudentSex);


        verticalLayout_3->addLayout(horizontalLayout_23);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        retranslateUi(Tables);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Tables);
    } // setupUi

    void retranslateUi(QDialog *Tables)
    {
        Tables->setWindowTitle(QCoreApplication::translate("Tables", "Dialog", nullptr));
        labelBookTypeId_2->setText(QCoreApplication::translate("Tables", "TypeId", nullptr));
        labelBookName_2->setText(QCoreApplication::translate("Tables", "Name", nullptr));
        labelBookPageCount_2->setText(QCoreApplication::translate("Tables", "Page count", nullptr));
        labelBookPrice_2->setText(QCoreApplication::translate("Tables", "Price", nullptr));
        labelBookAuthorId_2->setText(QCoreApplication::translate("Tables", "AuthorId", nullptr));
        labelBookPublisherId_2->setText(QCoreApplication::translate("Tables", "PublisherId", nullptr));
        labelBookAmount_2->setText(QCoreApplication::translate("Tables", "Amount", nullptr));
        pushButtonBookAdd_2->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonBookEdit_2->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonBookDelete_2->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        pushButtonLoadDataBooks->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Tables", "Book", nullptr));
        pushButtonStudentAdd->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonStudentEdit->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonStudentDelete->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        pushButtonStudentLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        labelStudentStudentId->setText(QCoreApplication::translate("Tables", "StudentId", nullptr));
        labelStudentFirstName->setText(QCoreApplication::translate("Tables", "First name", nullptr));
        labelStudentSurname->setText(QCoreApplication::translate("Tables", "Surname", nullptr));
        labelStudentCourse->setText(QCoreApplication::translate("Tables", "Course", nullptr));
        labelStudentPhone->setText(QCoreApplication::translate("Tables", "Phone", nullptr));
        labelStudentBirthDate->setText(QCoreApplication::translate("Tables", "Birth date", nullptr));
        dateEditStudentBirthDate->setDisplayFormat(QCoreApplication::translate("Tables", "yyyy.MM.dd", nullptr));
        labelStudentSex->setText(QCoreApplication::translate("Tables", "Sex", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Tables", "Student", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tables: public Ui_Tables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLES_H
