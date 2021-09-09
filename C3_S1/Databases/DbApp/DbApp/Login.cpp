#include "Login.h"
#include "stdafx.h"

Login::Login(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);

  QSqlDatabase myDatabase;

  QString connectString = "Driver={SQL SERVER}; ";
  connectString.append("Server=localhost, 1433; ");
  connectString.append("Database=Library; ");
  connectString.append("UID=admin; ");
  connectString.append("PWD=admin;");

  myDatabase.setDatabaseName(connectString);

  if (myDatabase.open()) {
    ui.statusBar->showMessage("Connected");

  } else {
    ui.statusBar->showMessage("Not Connected");
  }
}
