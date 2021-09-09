#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DbApp.h"
#include <QtSql/QtSql>


class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = Q_NULLPTR);

private:
    Ui::DbAppClass ui;
};
