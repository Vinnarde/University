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

private:
    Ui::Tables *ui;
};

#endif // TABLES_H
