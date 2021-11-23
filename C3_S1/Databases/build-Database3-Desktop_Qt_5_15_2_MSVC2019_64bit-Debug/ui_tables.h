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
    QWidget *tabHome;
    QTableView *tableViewViews;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonBookPopularityReport;
    QPushButton *pushButtonDetailedBookReport;
    QPushButton *pushButtonExpiredBooks;
    QPushButton *pushButtonEmployeeReport;
    QWidget *tabBook;
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
    QWidget *tabStudent;
    QTableView *tableViewStudents;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *pushButtonStudentAdd;
    QPushButton *pushButtonStudentEdit;
    QPushButton *pushButtonStudentDelete;
    QPushButton *pushButtonStudentLoadData;
    QWidget *layoutWidget1;
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
    QWidget *tabBorrows;
    QTableView *tableViewBorrows;
    QWidget *layoutWidget_24;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_121;
    QLabel *labelBorrowsBorrowId;
    QComboBox *comboBoxBorrowsBorrowId;
    QHBoxLayout *horizontalLayout_122;
    QLabel *labelBorrowsStudentId;
    QComboBox *comboBoxBorrowsStudentId;
    QHBoxLayout *horizontalLayout_123;
    QLabel *labelBorrowsBookId;
    QComboBox *comboBoxBorrowsBookId;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBorrowsEmployeeId;
    QComboBox *comboBoxBorrowsEmployeeId;
    QHBoxLayout *horizontalLayout_126;
    QLabel *labelBorrowsTakenDate;
    QDateEdit *dateEditBorrowsTakenDate;
    QHBoxLayout *horizontalLayout_127;
    QLabel *labelBorrowsBroughtDate;
    QDateEdit *dateEditBorrowsBroughtDate;
    QWidget *layoutWidget_25;
    QHBoxLayout *horizontalLayout_128;
    QPushButton *pushButtonBorrowsGiveBook;
    QPushButton *pushButtonBorrowsReturnBook;
    QPushButton *pushButtonBorrowsLoadData;
    QWidget *tabEmployee;
    QPushButton *pushButtonEmployeeLoadData;
    QTableView *tableViewEmployees;
    QWidget *layoutWidget_12;
    QHBoxLayout *horizontalLayout_57;
    QPushButton *pushButtonEmployeeAdd;
    QPushButton *pushButtonEmployeeEdit;
    QPushButton *pushButtonEmployeeDelete;
    QWidget *layoutWidget_13;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_58;
    QLabel *labeEmployeeEmpId;
    QComboBox *comboBoxEmployeeEmpId;
    QHBoxLayout *horizontalLayout_59;
    QLabel *labelEmployeeFirstName;
    QLineEdit *lineEditEmployeeFirstName;
    QHBoxLayout *horizontalLayout_60;
    QLabel *labelEmployeeSurname;
    QLineEdit *lineEditEmployeeSurname;
    QHBoxLayout *horizontalLayout_61;
    QLabel *labelEmployeePhone;
    QLineEdit *lineEditEmployeePhone;
    QHBoxLayout *horizontalLayout_62;
    QLabel *labelEmployeeSalary;
    QLineEdit *lineEditEmployeeSalary;
    QHBoxLayout *horizontalLayout_66;
    QLabel *labelEmployeePositionId;
    QComboBox *comboBoxEmployeePositionId;
    QWidget *tabAuthor;
    QTableView *tableViewAuthors;
    QWidget *layoutWidget_14;
    QHBoxLayout *horizontalLayout_85;
    QPushButton *pushButtonAuthorAdd;
    QPushButton *pushButtonAuthorEdit;
    QPushButton *pushButtonAuthorDelete;
    QPushButton *pushButtonAuthorLoadData;
    QWidget *layoutWidget_15;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_86;
    QLabel *labelAuthorAuthorId;
    QComboBox *comboBoxAuthorAuthorId;
    QHBoxLayout *horizontalLayout_87;
    QLabel *labelAuthorFirstName;
    QLineEdit *lineEditAuthorFirstName;
    QHBoxLayout *horizontalLayout_88;
    QLabel *labelAuthorSurname;
    QLineEdit *lineEditAuthorSurname;
    QWidget *tabPublisher;
    QPushButton *pushButtonPublisherLoadData;
    QWidget *layoutWidget_16;
    QHBoxLayout *horizontalLayout_89;
    QPushButton *pushButtonPublisherAdd;
    QPushButton *pushButtonPublisherEdit;
    QPushButton *pushButtonPublisherDelete;
    QWidget *layoutWidget_17;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_90;
    QLabel *labelPublisherPublisherId;
    QComboBox *comboBoxPublisherPublisherId;
    QHBoxLayout *horizontalLayout_91;
    QLabel *labelPublisherName;
    QLineEdit *lineEditPublisherName;
    QHBoxLayout *horizontalLayout_92;
    QLabel *labelPublisherAddress;
    QLineEdit *lineEditPublisherAddress;
    QTableView *tableViewPublishers;
    QWidget *tabType;
    QWidget *layoutWidget_48;
    QVBoxLayout *verticalLayout_26;
    QHBoxLayout *horizontalLayout_158;
    QLabel *labelTypeTypeId;
    QComboBox *comboBoxTypeTypeId;
    QHBoxLayout *horizontalLayout_159;
    QLabel *labelTypeName;
    QLineEdit *lineEditTypeName;
    QWidget *layoutWidget_49;
    QHBoxLayout *horizontalLayout_161;
    QPushButton *pushButtonTypeAdd;
    QPushButton *pushButtonTypeEdit;
    QPushButton *pushButtonTypeDelete;
    QTableView *tableViewTypes;
    QPushButton *pushButtonTypeLoadData;
    QWidget *tabPosition;
    QPushButton *pushButtonPositionLoadData;
    QWidget *layoutWidget_50;
    QHBoxLayout *horizontalLayout_162;
    QPushButton *pushButtonPositionAdd;
    QPushButton *pushButtonPositionEdit;
    QPushButton *pushButtonPositionDelete;
    QWidget *layoutWidget_51;
    QVBoxLayout *verticalLayout_27;
    QHBoxLayout *horizontalLayout_160;
    QLabel *labelPositionPositionId;
    QComboBox *comboBoxPositionPositionId;
    QHBoxLayout *horizontalLayout_163;
    QLabel *labelPositionName;
    QLineEdit *lineEditPositionName;
    QTableView *tableViewPosititions;

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
        tabWidget->setTabBarAutoHide(false);
        tabHome = new QWidget();
        tabHome->setObjectName(QString::fromUtf8("tabHome"));
        tableViewViews = new QTableView(tabHome);
        tableViewViews->setObjectName(QString::fromUtf8("tableViewViews"));
        tableViewViews->setGeometry(QRect(490, 0, 771, 661));
        tableViewViews->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(tabHome);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 180, 381, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonBookPopularityReport = new QPushButton(verticalLayoutWidget);
        pushButtonBookPopularityReport->setObjectName(QString::fromUtf8("pushButtonBookPopularityReport"));

        verticalLayout->addWidget(pushButtonBookPopularityReport);

        pushButtonDetailedBookReport = new QPushButton(verticalLayoutWidget);
        pushButtonDetailedBookReport->setObjectName(QString::fromUtf8("pushButtonDetailedBookReport"));

        verticalLayout->addWidget(pushButtonDetailedBookReport);

        pushButtonExpiredBooks = new QPushButton(verticalLayoutWidget);
        pushButtonExpiredBooks->setObjectName(QString::fromUtf8("pushButtonExpiredBooks"));

        verticalLayout->addWidget(pushButtonExpiredBooks);

        pushButtonEmployeeReport = new QPushButton(verticalLayoutWidget);
        pushButtonEmployeeReport->setObjectName(QString::fromUtf8("pushButtonEmployeeReport"));

        verticalLayout->addWidget(pushButtonEmployeeReport);

        tabWidget->addTab(tabHome, QString());
        tabBook = new QWidget();
        tabBook->setObjectName(QString::fromUtf8("tabBook"));
        layoutWidget = new QWidget(tabBook);
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

        tableViewBooks = new QTableView(tabBook);
        tableViewBooks->setObjectName(QString::fromUtf8("tableViewBooks"));
        tableViewBooks->setGeometry(QRect(490, -10, 771, 661));
        tableViewBooks->setAutoFillBackground(true);
        layoutWidget_2 = new QWidget(tabBook);
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

        pushButtonLoadDataBooks = new QPushButton(tabBook);
        pushButtonLoadDataBooks->setObjectName(QString::fromUtf8("pushButtonLoadDataBooks"));
        pushButtonLoadDataBooks->setGeometry(QRect(10, 610, 471, 41));
        pushButtonLoadDataBooks->setFont(font);
        tabWidget->addTab(tabBook, QString());
        tabStudent = new QWidget();
        tabStudent->setObjectName(QString::fromUtf8("tabStudent"));
        tableViewStudents = new QTableView(tabStudent);
        tableViewStudents->setObjectName(QString::fromUtf8("tableViewStudents"));
        tableViewStudents->setGeometry(QRect(490, 0, 771, 661));
        tableViewStudents->setAutoFillBackground(true);
        layoutWidget_3 = new QWidget(tabStudent);
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

        pushButtonStudentLoadData = new QPushButton(tabStudent);
        pushButtonStudentLoadData->setObjectName(QString::fromUtf8("pushButtonStudentLoadData"));
        pushButtonStudentLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonStudentLoadData->setFont(font);
        layoutWidget1 = new QWidget(tabStudent);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(7, 20, 471, 340));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        labelStudentStudentId = new QLabel(layoutWidget1);
        labelStudentStudentId->setObjectName(QString::fromUtf8("labelStudentStudentId"));

        horizontalLayout_17->addWidget(labelStudentStudentId);

        comboBoxStudentStudentId = new QComboBox(layoutWidget1);
        comboBoxStudentStudentId->setObjectName(QString::fromUtf8("comboBoxStudentStudentId"));
        sizePolicy.setHeightForWidth(comboBoxStudentStudentId->sizePolicy().hasHeightForWidth());
        comboBoxStudentStudentId->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(comboBoxStudentStudentId);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        labelStudentFirstName = new QLabel(layoutWidget1);
        labelStudentFirstName->setObjectName(QString::fromUtf8("labelStudentFirstName"));

        horizontalLayout_18->addWidget(labelStudentFirstName);

        lineEditStudentFirstName = new QLineEdit(layoutWidget1);
        lineEditStudentFirstName->setObjectName(QString::fromUtf8("lineEditStudentFirstName"));

        horizontalLayout_18->addWidget(lineEditStudentFirstName);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        labelStudentSurname = new QLabel(layoutWidget1);
        labelStudentSurname->setObjectName(QString::fromUtf8("labelStudentSurname"));

        horizontalLayout_19->addWidget(labelStudentSurname);

        lineEditStudentSurname = new QLineEdit(layoutWidget1);
        lineEditStudentSurname->setObjectName(QString::fromUtf8("lineEditStudentSurname"));

        horizontalLayout_19->addWidget(lineEditStudentSurname);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        labelStudentCourse = new QLabel(layoutWidget1);
        labelStudentCourse->setObjectName(QString::fromUtf8("labelStudentCourse"));

        horizontalLayout_20->addWidget(labelStudentCourse);

        comboBoxStudentCourse = new QComboBox(layoutWidget1);
        comboBoxStudentCourse->setObjectName(QString::fromUtf8("comboBoxStudentCourse"));
        sizePolicy.setHeightForWidth(comboBoxStudentCourse->sizePolicy().hasHeightForWidth());
        comboBoxStudentCourse->setSizePolicy(sizePolicy);

        horizontalLayout_20->addWidget(comboBoxStudentCourse);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        labelStudentPhone = new QLabel(layoutWidget1);
        labelStudentPhone->setObjectName(QString::fromUtf8("labelStudentPhone"));

        horizontalLayout_21->addWidget(labelStudentPhone);

        lineEditStudentPhone = new QLineEdit(layoutWidget1);
        lineEditStudentPhone->setObjectName(QString::fromUtf8("lineEditStudentPhone"));

        horizontalLayout_21->addWidget(lineEditStudentPhone);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        labelStudentBirthDate = new QLabel(layoutWidget1);
        labelStudentBirthDate->setObjectName(QString::fromUtf8("labelStudentBirthDate"));

        horizontalLayout_22->addWidget(labelStudentBirthDate);

        dateEditStudentBirthDate = new QDateEdit(layoutWidget1);
        dateEditStudentBirthDate->setObjectName(QString::fromUtf8("dateEditStudentBirthDate"));
        dateEditStudentBirthDate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateEditStudentBirthDate->setTimeSpec(Qt::LocalTime);

        horizontalLayout_22->addWidget(dateEditStudentBirthDate);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        labelStudentSex = new QLabel(layoutWidget1);
        labelStudentSex->setObjectName(QString::fromUtf8("labelStudentSex"));

        horizontalLayout_23->addWidget(labelStudentSex);

        comboBoxStudentSex = new QComboBox(layoutWidget1);
        comboBoxStudentSex->setObjectName(QString::fromUtf8("comboBoxStudentSex"));
        sizePolicy.setHeightForWidth(comboBoxStudentSex->sizePolicy().hasHeightForWidth());
        comboBoxStudentSex->setSizePolicy(sizePolicy);

        horizontalLayout_23->addWidget(comboBoxStudentSex);


        verticalLayout_3->addLayout(horizontalLayout_23);

        tabWidget->addTab(tabStudent, QString());
        tabBorrows = new QWidget();
        tabBorrows->setObjectName(QString::fromUtf8("tabBorrows"));
        tableViewBorrows = new QTableView(tabBorrows);
        tableViewBorrows->setObjectName(QString::fromUtf8("tableViewBorrows"));
        tableViewBorrows->setGeometry(QRect(493, 0, 771, 661));
        tableViewBorrows->setAutoFillBackground(true);
        layoutWidget_24 = new QWidget(tabBorrows);
        layoutWidget_24->setObjectName(QString::fromUtf8("layoutWidget_24"));
        layoutWidget_24->setGeometry(QRect(10, 10, 471, 321));
        verticalLayout_16 = new QVBoxLayout(layoutWidget_24);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_121 = new QHBoxLayout();
        horizontalLayout_121->setObjectName(QString::fromUtf8("horizontalLayout_121"));
        labelBorrowsBorrowId = new QLabel(layoutWidget_24);
        labelBorrowsBorrowId->setObjectName(QString::fromUtf8("labelBorrowsBorrowId"));

        horizontalLayout_121->addWidget(labelBorrowsBorrowId);

        comboBoxBorrowsBorrowId = new QComboBox(layoutWidget_24);
        comboBoxBorrowsBorrowId->setObjectName(QString::fromUtf8("comboBoxBorrowsBorrowId"));
        sizePolicy.setHeightForWidth(comboBoxBorrowsBorrowId->sizePolicy().hasHeightForWidth());
        comboBoxBorrowsBorrowId->setSizePolicy(sizePolicy);

        horizontalLayout_121->addWidget(comboBoxBorrowsBorrowId);


        verticalLayout_16->addLayout(horizontalLayout_121);

        horizontalLayout_122 = new QHBoxLayout();
        horizontalLayout_122->setObjectName(QString::fromUtf8("horizontalLayout_122"));
        labelBorrowsStudentId = new QLabel(layoutWidget_24);
        labelBorrowsStudentId->setObjectName(QString::fromUtf8("labelBorrowsStudentId"));

        horizontalLayout_122->addWidget(labelBorrowsStudentId);

        comboBoxBorrowsStudentId = new QComboBox(layoutWidget_24);
        comboBoxBorrowsStudentId->setObjectName(QString::fromUtf8("comboBoxBorrowsStudentId"));
        sizePolicy.setHeightForWidth(comboBoxBorrowsStudentId->sizePolicy().hasHeightForWidth());
        comboBoxBorrowsStudentId->setSizePolicy(sizePolicy);

        horizontalLayout_122->addWidget(comboBoxBorrowsStudentId);


        verticalLayout_16->addLayout(horizontalLayout_122);

        horizontalLayout_123 = new QHBoxLayout();
        horizontalLayout_123->setObjectName(QString::fromUtf8("horizontalLayout_123"));
        labelBorrowsBookId = new QLabel(layoutWidget_24);
        labelBorrowsBookId->setObjectName(QString::fromUtf8("labelBorrowsBookId"));

        horizontalLayout_123->addWidget(labelBorrowsBookId);

        comboBoxBorrowsBookId = new QComboBox(layoutWidget_24);
        comboBoxBorrowsBookId->setObjectName(QString::fromUtf8("comboBoxBorrowsBookId"));
        sizePolicy.setHeightForWidth(comboBoxBorrowsBookId->sizePolicy().hasHeightForWidth());
        comboBoxBorrowsBookId->setSizePolicy(sizePolicy);

        horizontalLayout_123->addWidget(comboBoxBorrowsBookId);


        verticalLayout_16->addLayout(horizontalLayout_123);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelBorrowsEmployeeId = new QLabel(layoutWidget_24);
        labelBorrowsEmployeeId->setObjectName(QString::fromUtf8("labelBorrowsEmployeeId"));

        horizontalLayout->addWidget(labelBorrowsEmployeeId);

        comboBoxBorrowsEmployeeId = new QComboBox(layoutWidget_24);
        comboBoxBorrowsEmployeeId->setObjectName(QString::fromUtf8("comboBoxBorrowsEmployeeId"));
        sizePolicy.setHeightForWidth(comboBoxBorrowsEmployeeId->sizePolicy().hasHeightForWidth());
        comboBoxBorrowsEmployeeId->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(comboBoxBorrowsEmployeeId);


        verticalLayout_16->addLayout(horizontalLayout);

        horizontalLayout_126 = new QHBoxLayout();
        horizontalLayout_126->setObjectName(QString::fromUtf8("horizontalLayout_126"));
        labelBorrowsTakenDate = new QLabel(layoutWidget_24);
        labelBorrowsTakenDate->setObjectName(QString::fromUtf8("labelBorrowsTakenDate"));

        horizontalLayout_126->addWidget(labelBorrowsTakenDate);

        dateEditBorrowsTakenDate = new QDateEdit(layoutWidget_24);
        dateEditBorrowsTakenDate->setObjectName(QString::fromUtf8("dateEditBorrowsTakenDate"));
        dateEditBorrowsTakenDate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateEditBorrowsTakenDate->setTimeSpec(Qt::LocalTime);

        horizontalLayout_126->addWidget(dateEditBorrowsTakenDate);


        verticalLayout_16->addLayout(horizontalLayout_126);

        horizontalLayout_127 = new QHBoxLayout();
        horizontalLayout_127->setObjectName(QString::fromUtf8("horizontalLayout_127"));
        labelBorrowsBroughtDate = new QLabel(layoutWidget_24);
        labelBorrowsBroughtDate->setObjectName(QString::fromUtf8("labelBorrowsBroughtDate"));

        horizontalLayout_127->addWidget(labelBorrowsBroughtDate);

        dateEditBorrowsBroughtDate = new QDateEdit(layoutWidget_24);
        dateEditBorrowsBroughtDate->setObjectName(QString::fromUtf8("dateEditBorrowsBroughtDate"));
        dateEditBorrowsBroughtDate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateEditBorrowsBroughtDate->setTimeSpec(Qt::LocalTime);

        horizontalLayout_127->addWidget(dateEditBorrowsBroughtDate);


        verticalLayout_16->addLayout(horizontalLayout_127);

        layoutWidget_25 = new QWidget(tabBorrows);
        layoutWidget_25->setObjectName(QString::fromUtf8("layoutWidget_25"));
        layoutWidget_25->setGeometry(QRect(3, 360, 481, 51));
        horizontalLayout_128 = new QHBoxLayout(layoutWidget_25);
        horizontalLayout_128->setObjectName(QString::fromUtf8("horizontalLayout_128"));
        horizontalLayout_128->setContentsMargins(0, 0, 0, 0);
        pushButtonBorrowsGiveBook = new QPushButton(layoutWidget_25);
        pushButtonBorrowsGiveBook->setObjectName(QString::fromUtf8("pushButtonBorrowsGiveBook"));

        horizontalLayout_128->addWidget(pushButtonBorrowsGiveBook);

        pushButtonBorrowsReturnBook = new QPushButton(layoutWidget_25);
        pushButtonBorrowsReturnBook->setObjectName(QString::fromUtf8("pushButtonBorrowsReturnBook"));

        horizontalLayout_128->addWidget(pushButtonBorrowsReturnBook);

        pushButtonBorrowsLoadData = new QPushButton(tabBorrows);
        pushButtonBorrowsLoadData->setObjectName(QString::fromUtf8("pushButtonBorrowsLoadData"));
        pushButtonBorrowsLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonBorrowsLoadData->setFont(font);
        tabWidget->addTab(tabBorrows, QString());
        tabEmployee = new QWidget();
        tabEmployee->setObjectName(QString::fromUtf8("tabEmployee"));
        pushButtonEmployeeLoadData = new QPushButton(tabEmployee);
        pushButtonEmployeeLoadData->setObjectName(QString::fromUtf8("pushButtonEmployeeLoadData"));
        pushButtonEmployeeLoadData->setGeometry(QRect(10, 610, 471, 41));
        pushButtonEmployeeLoadData->setFont(font);
        tableViewEmployees = new QTableView(tabEmployee);
        tableViewEmployees->setObjectName(QString::fromUtf8("tableViewEmployees"));
        tableViewEmployees->setGeometry(QRect(493, 10, 771, 661));
        tableViewEmployees->setAutoFillBackground(true);
        layoutWidget_12 = new QWidget(tabEmployee);
        layoutWidget_12->setObjectName(QString::fromUtf8("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(10, 340, 471, 51));
        horizontalLayout_57 = new QHBoxLayout(layoutWidget_12);
        horizontalLayout_57->setObjectName(QString::fromUtf8("horizontalLayout_57"));
        horizontalLayout_57->setContentsMargins(0, 0, 0, 0);
        pushButtonEmployeeAdd = new QPushButton(layoutWidget_12);
        pushButtonEmployeeAdd->setObjectName(QString::fromUtf8("pushButtonEmployeeAdd"));

        horizontalLayout_57->addWidget(pushButtonEmployeeAdd);

        pushButtonEmployeeEdit = new QPushButton(layoutWidget_12);
        pushButtonEmployeeEdit->setObjectName(QString::fromUtf8("pushButtonEmployeeEdit"));

        horizontalLayout_57->addWidget(pushButtonEmployeeEdit);

        pushButtonEmployeeDelete = new QPushButton(layoutWidget_12);
        pushButtonEmployeeDelete->setObjectName(QString::fromUtf8("pushButtonEmployeeDelete"));

        horizontalLayout_57->addWidget(pushButtonEmployeeDelete);

        layoutWidget_13 = new QWidget(tabEmployee);
        layoutWidget_13->setObjectName(QString::fromUtf8("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(10, 10, 471, 321));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_13);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setObjectName(QString::fromUtf8("horizontalLayout_58"));
        labeEmployeeEmpId = new QLabel(layoutWidget_13);
        labeEmployeeEmpId->setObjectName(QString::fromUtf8("labeEmployeeEmpId"));

        horizontalLayout_58->addWidget(labeEmployeeEmpId);

        comboBoxEmployeeEmpId = new QComboBox(layoutWidget_13);
        comboBoxEmployeeEmpId->setObjectName(QString::fromUtf8("comboBoxEmployeeEmpId"));
        sizePolicy.setHeightForWidth(comboBoxEmployeeEmpId->sizePolicy().hasHeightForWidth());
        comboBoxEmployeeEmpId->setSizePolicy(sizePolicy);

        horizontalLayout_58->addWidget(comboBoxEmployeeEmpId);


        verticalLayout_8->addLayout(horizontalLayout_58);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setObjectName(QString::fromUtf8("horizontalLayout_59"));
        labelEmployeeFirstName = new QLabel(layoutWidget_13);
        labelEmployeeFirstName->setObjectName(QString::fromUtf8("labelEmployeeFirstName"));

        horizontalLayout_59->addWidget(labelEmployeeFirstName);

        lineEditEmployeeFirstName = new QLineEdit(layoutWidget_13);
        lineEditEmployeeFirstName->setObjectName(QString::fromUtf8("lineEditEmployeeFirstName"));

        horizontalLayout_59->addWidget(lineEditEmployeeFirstName);


        verticalLayout_8->addLayout(horizontalLayout_59);

        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setObjectName(QString::fromUtf8("horizontalLayout_60"));
        labelEmployeeSurname = new QLabel(layoutWidget_13);
        labelEmployeeSurname->setObjectName(QString::fromUtf8("labelEmployeeSurname"));

        horizontalLayout_60->addWidget(labelEmployeeSurname);

        lineEditEmployeeSurname = new QLineEdit(layoutWidget_13);
        lineEditEmployeeSurname->setObjectName(QString::fromUtf8("lineEditEmployeeSurname"));

        horizontalLayout_60->addWidget(lineEditEmployeeSurname);


        verticalLayout_8->addLayout(horizontalLayout_60);

        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setObjectName(QString::fromUtf8("horizontalLayout_61"));
        labelEmployeePhone = new QLabel(layoutWidget_13);
        labelEmployeePhone->setObjectName(QString::fromUtf8("labelEmployeePhone"));

        horizontalLayout_61->addWidget(labelEmployeePhone);

        lineEditEmployeePhone = new QLineEdit(layoutWidget_13);
        lineEditEmployeePhone->setObjectName(QString::fromUtf8("lineEditEmployeePhone"));

        horizontalLayout_61->addWidget(lineEditEmployeePhone);


        verticalLayout_8->addLayout(horizontalLayout_61);

        horizontalLayout_62 = new QHBoxLayout();
        horizontalLayout_62->setObjectName(QString::fromUtf8("horizontalLayout_62"));
        labelEmployeeSalary = new QLabel(layoutWidget_13);
        labelEmployeeSalary->setObjectName(QString::fromUtf8("labelEmployeeSalary"));

        horizontalLayout_62->addWidget(labelEmployeeSalary);

        lineEditEmployeeSalary = new QLineEdit(layoutWidget_13);
        lineEditEmployeeSalary->setObjectName(QString::fromUtf8("lineEditEmployeeSalary"));

        horizontalLayout_62->addWidget(lineEditEmployeeSalary);


        verticalLayout_8->addLayout(horizontalLayout_62);

        horizontalLayout_66 = new QHBoxLayout();
        horizontalLayout_66->setObjectName(QString::fromUtf8("horizontalLayout_66"));
        labelEmployeePositionId = new QLabel(layoutWidget_13);
        labelEmployeePositionId->setObjectName(QString::fromUtf8("labelEmployeePositionId"));

        horizontalLayout_66->addWidget(labelEmployeePositionId);

        comboBoxEmployeePositionId = new QComboBox(layoutWidget_13);
        comboBoxEmployeePositionId->setObjectName(QString::fromUtf8("comboBoxEmployeePositionId"));
        sizePolicy.setHeightForWidth(comboBoxEmployeePositionId->sizePolicy().hasHeightForWidth());
        comboBoxEmployeePositionId->setSizePolicy(sizePolicy);

        horizontalLayout_66->addWidget(comboBoxEmployeePositionId);


        verticalLayout_8->addLayout(horizontalLayout_66);

        tabWidget->addTab(tabEmployee, QString());
        tabAuthor = new QWidget();
        tabAuthor->setObjectName(QString::fromUtf8("tabAuthor"));
        tableViewAuthors = new QTableView(tabAuthor);
        tableViewAuthors->setObjectName(QString::fromUtf8("tableViewAuthors"));
        tableViewAuthors->setGeometry(QRect(490, 10, 771, 661));
        tableViewAuthors->setAutoFillBackground(true);
        layoutWidget_14 = new QWidget(tabAuthor);
        layoutWidget_14->setObjectName(QString::fromUtf8("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(10, 190, 471, 51));
        horizontalLayout_85 = new QHBoxLayout(layoutWidget_14);
        horizontalLayout_85->setObjectName(QString::fromUtf8("horizontalLayout_85"));
        horizontalLayout_85->setContentsMargins(0, 0, 0, 0);
        pushButtonAuthorAdd = new QPushButton(layoutWidget_14);
        pushButtonAuthorAdd->setObjectName(QString::fromUtf8("pushButtonAuthorAdd"));

        horizontalLayout_85->addWidget(pushButtonAuthorAdd);

        pushButtonAuthorEdit = new QPushButton(layoutWidget_14);
        pushButtonAuthorEdit->setObjectName(QString::fromUtf8("pushButtonAuthorEdit"));

        horizontalLayout_85->addWidget(pushButtonAuthorEdit);

        pushButtonAuthorDelete = new QPushButton(layoutWidget_14);
        pushButtonAuthorDelete->setObjectName(QString::fromUtf8("pushButtonAuthorDelete"));

        horizontalLayout_85->addWidget(pushButtonAuthorDelete);

        pushButtonAuthorLoadData = new QPushButton(tabAuthor);
        pushButtonAuthorLoadData->setObjectName(QString::fromUtf8("pushButtonAuthorLoadData"));
        pushButtonAuthorLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonAuthorLoadData->setFont(font);
        layoutWidget_15 = new QWidget(tabAuthor);
        layoutWidget_15->setObjectName(QString::fromUtf8("layoutWidget_15"));
        layoutWidget_15->setGeometry(QRect(10, 10, 471, 171));
        verticalLayout_12 = new QVBoxLayout(layoutWidget_15);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_86 = new QHBoxLayout();
        horizontalLayout_86->setObjectName(QString::fromUtf8("horizontalLayout_86"));
        labelAuthorAuthorId = new QLabel(layoutWidget_15);
        labelAuthorAuthorId->setObjectName(QString::fromUtf8("labelAuthorAuthorId"));

        horizontalLayout_86->addWidget(labelAuthorAuthorId);

        comboBoxAuthorAuthorId = new QComboBox(layoutWidget_15);
        comboBoxAuthorAuthorId->setObjectName(QString::fromUtf8("comboBoxAuthorAuthorId"));
        sizePolicy.setHeightForWidth(comboBoxAuthorAuthorId->sizePolicy().hasHeightForWidth());
        comboBoxAuthorAuthorId->setSizePolicy(sizePolicy);

        horizontalLayout_86->addWidget(comboBoxAuthorAuthorId);


        verticalLayout_12->addLayout(horizontalLayout_86);

        horizontalLayout_87 = new QHBoxLayout();
        horizontalLayout_87->setObjectName(QString::fromUtf8("horizontalLayout_87"));
        labelAuthorFirstName = new QLabel(layoutWidget_15);
        labelAuthorFirstName->setObjectName(QString::fromUtf8("labelAuthorFirstName"));

        horizontalLayout_87->addWidget(labelAuthorFirstName);

        lineEditAuthorFirstName = new QLineEdit(layoutWidget_15);
        lineEditAuthorFirstName->setObjectName(QString::fromUtf8("lineEditAuthorFirstName"));

        horizontalLayout_87->addWidget(lineEditAuthorFirstName);


        verticalLayout_12->addLayout(horizontalLayout_87);

        horizontalLayout_88 = new QHBoxLayout();
        horizontalLayout_88->setObjectName(QString::fromUtf8("horizontalLayout_88"));
        labelAuthorSurname = new QLabel(layoutWidget_15);
        labelAuthorSurname->setObjectName(QString::fromUtf8("labelAuthorSurname"));

        horizontalLayout_88->addWidget(labelAuthorSurname);

        lineEditAuthorSurname = new QLineEdit(layoutWidget_15);
        lineEditAuthorSurname->setObjectName(QString::fromUtf8("lineEditAuthorSurname"));

        horizontalLayout_88->addWidget(lineEditAuthorSurname);


        verticalLayout_12->addLayout(horizontalLayout_88);

        tabWidget->addTab(tabAuthor, QString());
        tabPublisher = new QWidget();
        tabPublisher->setObjectName(QString::fromUtf8("tabPublisher"));
        pushButtonPublisherLoadData = new QPushButton(tabPublisher);
        pushButtonPublisherLoadData->setObjectName(QString::fromUtf8("pushButtonPublisherLoadData"));
        pushButtonPublisherLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonPublisherLoadData->setFont(font);
        layoutWidget_16 = new QWidget(tabPublisher);
        layoutWidget_16->setObjectName(QString::fromUtf8("layoutWidget_16"));
        layoutWidget_16->setGeometry(QRect(10, 190, 471, 51));
        horizontalLayout_89 = new QHBoxLayout(layoutWidget_16);
        horizontalLayout_89->setObjectName(QString::fromUtf8("horizontalLayout_89"));
        horizontalLayout_89->setContentsMargins(0, 0, 0, 0);
        pushButtonPublisherAdd = new QPushButton(layoutWidget_16);
        pushButtonPublisherAdd->setObjectName(QString::fromUtf8("pushButtonPublisherAdd"));

        horizontalLayout_89->addWidget(pushButtonPublisherAdd);

        pushButtonPublisherEdit = new QPushButton(layoutWidget_16);
        pushButtonPublisherEdit->setObjectName(QString::fromUtf8("pushButtonPublisherEdit"));

        horizontalLayout_89->addWidget(pushButtonPublisherEdit);

        pushButtonPublisherDelete = new QPushButton(layoutWidget_16);
        pushButtonPublisherDelete->setObjectName(QString::fromUtf8("pushButtonPublisherDelete"));

        horizontalLayout_89->addWidget(pushButtonPublisherDelete);

        layoutWidget_17 = new QWidget(tabPublisher);
        layoutWidget_17->setObjectName(QString::fromUtf8("layoutWidget_17"));
        layoutWidget_17->setGeometry(QRect(10, 10, 471, 171));
        verticalLayout_13 = new QVBoxLayout(layoutWidget_17);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_90 = new QHBoxLayout();
        horizontalLayout_90->setObjectName(QString::fromUtf8("horizontalLayout_90"));
        labelPublisherPublisherId = new QLabel(layoutWidget_17);
        labelPublisherPublisherId->setObjectName(QString::fromUtf8("labelPublisherPublisherId"));

        horizontalLayout_90->addWidget(labelPublisherPublisherId);

        comboBoxPublisherPublisherId = new QComboBox(layoutWidget_17);
        comboBoxPublisherPublisherId->setObjectName(QString::fromUtf8("comboBoxPublisherPublisherId"));
        sizePolicy.setHeightForWidth(comboBoxPublisherPublisherId->sizePolicy().hasHeightForWidth());
        comboBoxPublisherPublisherId->setSizePolicy(sizePolicy);

        horizontalLayout_90->addWidget(comboBoxPublisherPublisherId);


        verticalLayout_13->addLayout(horizontalLayout_90);

        horizontalLayout_91 = new QHBoxLayout();
        horizontalLayout_91->setObjectName(QString::fromUtf8("horizontalLayout_91"));
        labelPublisherName = new QLabel(layoutWidget_17);
        labelPublisherName->setObjectName(QString::fromUtf8("labelPublisherName"));

        horizontalLayout_91->addWidget(labelPublisherName);

        lineEditPublisherName = new QLineEdit(layoutWidget_17);
        lineEditPublisherName->setObjectName(QString::fromUtf8("lineEditPublisherName"));

        horizontalLayout_91->addWidget(lineEditPublisherName);


        verticalLayout_13->addLayout(horizontalLayout_91);

        horizontalLayout_92 = new QHBoxLayout();
        horizontalLayout_92->setObjectName(QString::fromUtf8("horizontalLayout_92"));
        labelPublisherAddress = new QLabel(layoutWidget_17);
        labelPublisherAddress->setObjectName(QString::fromUtf8("labelPublisherAddress"));

        horizontalLayout_92->addWidget(labelPublisherAddress);

        lineEditPublisherAddress = new QLineEdit(layoutWidget_17);
        lineEditPublisherAddress->setObjectName(QString::fromUtf8("lineEditPublisherAddress"));

        horizontalLayout_92->addWidget(lineEditPublisherAddress);


        verticalLayout_13->addLayout(horizontalLayout_92);

        tableViewPublishers = new QTableView(tabPublisher);
        tableViewPublishers->setObjectName(QString::fromUtf8("tableViewPublishers"));
        tableViewPublishers->setGeometry(QRect(490, 10, 771, 661));
        tableViewPublishers->setAutoFillBackground(true);
        tabWidget->addTab(tabPublisher, QString());
        tabType = new QWidget();
        tabType->setObjectName(QString::fromUtf8("tabType"));
        layoutWidget_48 = new QWidget(tabType);
        layoutWidget_48->setObjectName(QString::fromUtf8("layoutWidget_48"));
        layoutWidget_48->setGeometry(QRect(10, 10, 471, 171));
        verticalLayout_26 = new QVBoxLayout(layoutWidget_48);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        verticalLayout_26->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_158 = new QHBoxLayout();
        horizontalLayout_158->setObjectName(QString::fromUtf8("horizontalLayout_158"));
        labelTypeTypeId = new QLabel(layoutWidget_48);
        labelTypeTypeId->setObjectName(QString::fromUtf8("labelTypeTypeId"));

        horizontalLayout_158->addWidget(labelTypeTypeId);

        comboBoxTypeTypeId = new QComboBox(layoutWidget_48);
        comboBoxTypeTypeId->setObjectName(QString::fromUtf8("comboBoxTypeTypeId"));
        sizePolicy.setHeightForWidth(comboBoxTypeTypeId->sizePolicy().hasHeightForWidth());
        comboBoxTypeTypeId->setSizePolicy(sizePolicy);

        horizontalLayout_158->addWidget(comboBoxTypeTypeId);


        verticalLayout_26->addLayout(horizontalLayout_158);

        horizontalLayout_159 = new QHBoxLayout();
        horizontalLayout_159->setObjectName(QString::fromUtf8("horizontalLayout_159"));
        labelTypeName = new QLabel(layoutWidget_48);
        labelTypeName->setObjectName(QString::fromUtf8("labelTypeName"));

        horizontalLayout_159->addWidget(labelTypeName);

        lineEditTypeName = new QLineEdit(layoutWidget_48);
        lineEditTypeName->setObjectName(QString::fromUtf8("lineEditTypeName"));

        horizontalLayout_159->addWidget(lineEditTypeName);


        verticalLayout_26->addLayout(horizontalLayout_159);

        layoutWidget_49 = new QWidget(tabType);
        layoutWidget_49->setObjectName(QString::fromUtf8("layoutWidget_49"));
        layoutWidget_49->setGeometry(QRect(10, 190, 471, 51));
        horizontalLayout_161 = new QHBoxLayout(layoutWidget_49);
        horizontalLayout_161->setObjectName(QString::fromUtf8("horizontalLayout_161"));
        horizontalLayout_161->setContentsMargins(0, 0, 0, 0);
        pushButtonTypeAdd = new QPushButton(layoutWidget_49);
        pushButtonTypeAdd->setObjectName(QString::fromUtf8("pushButtonTypeAdd"));

        horizontalLayout_161->addWidget(pushButtonTypeAdd);

        pushButtonTypeEdit = new QPushButton(layoutWidget_49);
        pushButtonTypeEdit->setObjectName(QString::fromUtf8("pushButtonTypeEdit"));

        horizontalLayout_161->addWidget(pushButtonTypeEdit);

        pushButtonTypeDelete = new QPushButton(layoutWidget_49);
        pushButtonTypeDelete->setObjectName(QString::fromUtf8("pushButtonTypeDelete"));

        horizontalLayout_161->addWidget(pushButtonTypeDelete);

        tableViewTypes = new QTableView(tabType);
        tableViewTypes->setObjectName(QString::fromUtf8("tableViewTypes"));
        tableViewTypes->setGeometry(QRect(490, 10, 771, 661));
        tableViewTypes->setAutoFillBackground(true);
        pushButtonTypeLoadData = new QPushButton(tabType);
        pushButtonTypeLoadData->setObjectName(QString::fromUtf8("pushButtonTypeLoadData"));
        pushButtonTypeLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonTypeLoadData->setFont(font);
        tabWidget->addTab(tabType, QString());
        tabPosition = new QWidget();
        tabPosition->setObjectName(QString::fromUtf8("tabPosition"));
        pushButtonPositionLoadData = new QPushButton(tabPosition);
        pushButtonPositionLoadData->setObjectName(QString::fromUtf8("pushButtonPositionLoadData"));
        pushButtonPositionLoadData->setGeometry(QRect(10, 620, 471, 41));
        pushButtonPositionLoadData->setFont(font);
        layoutWidget_50 = new QWidget(tabPosition);
        layoutWidget_50->setObjectName(QString::fromUtf8("layoutWidget_50"));
        layoutWidget_50->setGeometry(QRect(10, 190, 471, 51));
        horizontalLayout_162 = new QHBoxLayout(layoutWidget_50);
        horizontalLayout_162->setObjectName(QString::fromUtf8("horizontalLayout_162"));
        horizontalLayout_162->setContentsMargins(0, 0, 0, 0);
        pushButtonPositionAdd = new QPushButton(layoutWidget_50);
        pushButtonPositionAdd->setObjectName(QString::fromUtf8("pushButtonPositionAdd"));

        horizontalLayout_162->addWidget(pushButtonPositionAdd);

        pushButtonPositionEdit = new QPushButton(layoutWidget_50);
        pushButtonPositionEdit->setObjectName(QString::fromUtf8("pushButtonPositionEdit"));

        horizontalLayout_162->addWidget(pushButtonPositionEdit);

        pushButtonPositionDelete = new QPushButton(layoutWidget_50);
        pushButtonPositionDelete->setObjectName(QString::fromUtf8("pushButtonPositionDelete"));

        horizontalLayout_162->addWidget(pushButtonPositionDelete);

        layoutWidget_51 = new QWidget(tabPosition);
        layoutWidget_51->setObjectName(QString::fromUtf8("layoutWidget_51"));
        layoutWidget_51->setGeometry(QRect(10, 10, 471, 171));
        verticalLayout_27 = new QVBoxLayout(layoutWidget_51);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        verticalLayout_27->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_160 = new QHBoxLayout();
        horizontalLayout_160->setObjectName(QString::fromUtf8("horizontalLayout_160"));
        labelPositionPositionId = new QLabel(layoutWidget_51);
        labelPositionPositionId->setObjectName(QString::fromUtf8("labelPositionPositionId"));

        horizontalLayout_160->addWidget(labelPositionPositionId);

        comboBoxPositionPositionId = new QComboBox(layoutWidget_51);
        comboBoxPositionPositionId->setObjectName(QString::fromUtf8("comboBoxPositionPositionId"));
        sizePolicy.setHeightForWidth(comboBoxPositionPositionId->sizePolicy().hasHeightForWidth());
        comboBoxPositionPositionId->setSizePolicy(sizePolicy);

        horizontalLayout_160->addWidget(comboBoxPositionPositionId);


        verticalLayout_27->addLayout(horizontalLayout_160);

        horizontalLayout_163 = new QHBoxLayout();
        horizontalLayout_163->setObjectName(QString::fromUtf8("horizontalLayout_163"));
        labelPositionName = new QLabel(layoutWidget_51);
        labelPositionName->setObjectName(QString::fromUtf8("labelPositionName"));

        horizontalLayout_163->addWidget(labelPositionName);

        lineEditPositionName = new QLineEdit(layoutWidget_51);
        lineEditPositionName->setObjectName(QString::fromUtf8("lineEditPositionName"));

        horizontalLayout_163->addWidget(lineEditPositionName);


        verticalLayout_27->addLayout(horizontalLayout_163);

        tableViewPosititions = new QTableView(tabPosition);
        tableViewPosititions->setObjectName(QString::fromUtf8("tableViewPosititions"));
        tableViewPosititions->setGeometry(QRect(490, 10, 771, 661));
        tableViewPosititions->setAutoFillBackground(true);
        tabWidget->addTab(tabPosition, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);


        retranslateUi(Tables);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Tables);
    } // setupUi

    void retranslateUi(QDialog *Tables)
    {
        Tables->setWindowTitle(QCoreApplication::translate("Tables", "Dialog", nullptr));
        pushButtonBookPopularityReport->setText(QCoreApplication::translate("Tables", "Book's popularity", nullptr));
        pushButtonDetailedBookReport->setText(QCoreApplication::translate("Tables", "Book's report", nullptr));
        pushButtonExpiredBooks->setText(QCoreApplication::translate("Tables", "Employee Report", nullptr));
        pushButtonEmployeeReport->setText(QCoreApplication::translate("Tables", "Expired Books", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHome), QCoreApplication::translate("Tables", "\342\214\202", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tabBook), QCoreApplication::translate("Tables", "Book", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tabStudent), QCoreApplication::translate("Tables", "Student", nullptr));
        labelBorrowsBorrowId->setText(QCoreApplication::translate("Tables", "BorrowId", nullptr));
        labelBorrowsStudentId->setText(QCoreApplication::translate("Tables", "StudentId", nullptr));
        labelBorrowsBookId->setText(QCoreApplication::translate("Tables", "BookId", nullptr));
        labelBorrowsEmployeeId->setText(QCoreApplication::translate("Tables", "EmployeeId", nullptr));
        labelBorrowsTakenDate->setText(QCoreApplication::translate("Tables", "Taken date", nullptr));
        dateEditBorrowsTakenDate->setDisplayFormat(QCoreApplication::translate("Tables", "yyyy.MM.dd", nullptr));
        labelBorrowsBroughtDate->setText(QCoreApplication::translate("Tables", "Brought date", nullptr));
        dateEditBorrowsBroughtDate->setDisplayFormat(QCoreApplication::translate("Tables", "yyyy.MM.dd", nullptr));
        pushButtonBorrowsGiveBook->setText(QCoreApplication::translate("Tables", "Give book", nullptr));
        pushButtonBorrowsReturnBook->setText(QCoreApplication::translate("Tables", "Return book", nullptr));
        pushButtonBorrowsLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabBorrows), QCoreApplication::translate("Tables", "Borrows", nullptr));
        pushButtonEmployeeLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        pushButtonEmployeeAdd->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonEmployeeEdit->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonEmployeeDelete->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        labeEmployeeEmpId->setText(QCoreApplication::translate("Tables", "EmployeeId", nullptr));
        labelEmployeeFirstName->setText(QCoreApplication::translate("Tables", "First name", nullptr));
        labelEmployeeSurname->setText(QCoreApplication::translate("Tables", "Surname", nullptr));
        labelEmployeePhone->setText(QCoreApplication::translate("Tables", "Phone", nullptr));
        labelEmployeeSalary->setText(QCoreApplication::translate("Tables", "Salary", nullptr));
        labelEmployeePositionId->setText(QCoreApplication::translate("Tables", "Position", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEmployee), QCoreApplication::translate("Tables", "Employee", nullptr));
        pushButtonAuthorAdd->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonAuthorEdit->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonAuthorDelete->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        pushButtonAuthorLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        labelAuthorAuthorId->setText(QCoreApplication::translate("Tables", "AuthorId", nullptr));
        labelAuthorFirstName->setText(QCoreApplication::translate("Tables", "First name", nullptr));
        labelAuthorSurname->setText(QCoreApplication::translate("Tables", "Surname", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAuthor), QCoreApplication::translate("Tables", "Author", nullptr));
        pushButtonPublisherLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        pushButtonPublisherAdd->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonPublisherEdit->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonPublisherDelete->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        labelPublisherPublisherId->setText(QCoreApplication::translate("Tables", "PublisherId", nullptr));
        labelPublisherName->setText(QCoreApplication::translate("Tables", "Name", nullptr));
        labelPublisherAddress->setText(QCoreApplication::translate("Tables", "Address", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPublisher), QCoreApplication::translate("Tables", "Publisher", nullptr));
        labelTypeTypeId->setText(QCoreApplication::translate("Tables", "TypeId", nullptr));
        labelTypeName->setText(QCoreApplication::translate("Tables", "Name", nullptr));
        pushButtonTypeAdd->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonTypeEdit->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonTypeDelete->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        pushButtonTypeLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabType), QCoreApplication::translate("Tables", "Type", nullptr));
        pushButtonPositionLoadData->setText(QCoreApplication::translate("Tables", "Load data", nullptr));
        pushButtonPositionAdd->setText(QCoreApplication::translate("Tables", "Add", nullptr));
        pushButtonPositionEdit->setText(QCoreApplication::translate("Tables", "Edit", nullptr));
        pushButtonPositionDelete->setText(QCoreApplication::translate("Tables", "Delete", nullptr));
        labelPositionPositionId->setText(QCoreApplication::translate("Tables", "PositionId", nullptr));
        labelPositionName->setText(QCoreApplication::translate("Tables", "Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPosition), QCoreApplication::translate("Tables", "Position", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tables: public Ui_Tables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLES_H
