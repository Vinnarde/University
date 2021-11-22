#ifndef TABLES_H
#define TABLES_H

#include <QDialog>

namespace Ui {
class Tables;
}

class Tables : public QDialog
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

    void on_pushButtonEmployeeLoadData_clicked();

    void on_comboBoxEmployeeEmpId_currentIndexChanged(int index);

    void on_pushButtonEmployeeAdd_clicked();

    void on_pushButtonEmployeeEdit_clicked();

    void on_pushButtonEmployeeDelete_clicked();

    void on_tableViewEmployees_activated(const QModelIndex &index);

    void on_pushButtonAuthorLoadData_clicked();

    void on_comboBoxAuthorAuthorId_currentIndexChanged(const QString &arg1);

    void on_tableViewAuthors_activated(const QModelIndex &index);

    void on_pushButtonAuthorAdd_clicked();

    void on_pushButtonAuthorEdit_clicked();

    void on_pushButtonAuthorDelete_clicked();

    void on_pushButtonPublisherLoadData_clicked();

    void on_comboBoxPublisherPublisherId_currentIndexChanged(const QString &arg1);

    void on_tableViewPublishers_activated(const QModelIndex &index);

    void on_pushButtonPublisherAdd_clicked();

    void on_pushButtonPublisherEdit_clicked();

    void on_pushButtonPublisherDelete_clicked();

    void on_pushButtonTypeLoadData_clicked();

    void on_comboBoxTypeTypeId_activated(const QString &arg1);

    void on_tableViewTypes_activated(const QModelIndex &index);

    void on_pushButtonTypeAdd_clicked();

    void on_pushButtonTypeEdit_clicked();

    void on_pushButtonTypeDelete_clicked();

    void on_pushButtonBookPopularityReport_clicked();

    void on_pushButtonDetailedBookReport_clicked();

    void on_pushButtonExpiredBooks_clicked();

    void on_pushButtonEmployeeReport_clicked();

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
    void getEmployeesId();

    void getPositionId();

    void testPosition();

};

#endif // TABLES_H
