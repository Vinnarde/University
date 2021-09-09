#include "login.h"
#include "ui_login.h"
#include <QtSql>
#include <QDebug>
#include "book.h"
#include "tables.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pixmap("C:/Users/Pepega/Downloads/Login.jpeg");
    ui->label_picture->setPixmap(pixmap);

    myDatabase = QSqlDatabase::addDatabase("QODBC");

    QString connectString = "DRIVER={SQL SERVER}; ";
    connectString.append("SERVER=LOCALHOST; ");
    connectString.append("Database=Library; ");
    connectString.append("PORT=1433; ");
    //connectString.append("UID=admin; ");
    //connectString.append("PWD=admin");


    myDatabase.setDatabaseName(connectString);
    //myDatabase.setUserName("admin");
    //myDatabase.setPassword("admin");

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_signIn_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    myDatabase.setUserName(username);
    myDatabase.setPassword(password);

    if (connOpen())
    {
        this->hide();

        Tables table;
        table.setModal(true);
        table.exec();


        //Book book;
        //book.setModal(true);
        //book.exec();
    }
}

void Login::connClose()
{
    myDatabase.close();
    myDatabase.removeDatabase(QSqlDatabase::defaultConnection);
}

bool Login::connOpen()
{
    if (myDatabase.open())
    {
        qDebug() << "Connection successful!\n";
        return true;
        //ui->label->setText( "Status: Connected");
            }
    else
    {
        qDebug() << "Something went wrong!\n";
        return false;
        //ui->label->setText("Status: Not Connected");
    }
}


