#ifndef TABLES_H
#define TABLES_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class Tables;
}

class Tables : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tables(QWidget *parent = nullptr);
    ~Tables();

private slots:
    void on_tableViewBooks_activated(const QModelIndex &index);

    void on_pushButtonBookAdd_2_clicked();

    void on_pushButtonLoadDataBooks_clicked();

    void on_pushButtonBookEdit_2_clicked();

    void on_pushButtonBookDelete_2_clicked();

    void on_pushButtonStudentLoadData_clicked();

    void on_tableViewStudents_activated(const QModelIndex &index);

    void on_comboBoxStudentStudentId_currentIndexChanged(int index);

    void on_pushButtonStudentAdd_clicked();

    void on_pushButtonStudentEdit_clicked();

    void on_pushButtonStudentDelete_clicked();

    void on_pushButtonBorrowsLoadData_clicked();

    void on_comboBoxBorrowsBorrowId_currentIndexChanged(int index);

    void on_tableViewBorrows_activated(const QModelIndex &index);

    void on_pushButtonBorrowsGiveBook_clicked();

    void on_pushButtonBorrowsReturnBook_clicked();

    void on_pushButtonStudentLoadData_6_clicked();

private:
    Ui::Tables *ui;

    void getTypes();
    void getAuthorsId();
    void getPublishersId();
    void getBookName();

    void getStudentsId();
    void getCourses();
    void getSex();

    void getBooksId();
    void getBorrowsId();
    void getEmpolyeesId();

};

#endif // TABLES_H
