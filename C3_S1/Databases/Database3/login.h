#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    void connClose();
    bool connOpen();
    QSqlDatabase myDatabase;

private slots:
    void on_pushButton_signIn_clicked();

private:
    Ui::Login *ui;

};
#endif // LOGIN_H
