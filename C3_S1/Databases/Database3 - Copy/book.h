#ifndef BOOK_H
#define BOOK_H

#include <QDialog>

namespace Ui {
class Book;
}

class Book : public QDialog
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = nullptr);
    ~Book();

private slots:
    void on_pushButtonLoadDataBooks_clicked();

    void on_tableViewBooks_activated(const QModelIndex &index);

    void on_pushButtonBookAdd_clicked();

    void on_pushButtonBookEdit_clicked();

    void on_pushButtonBookDelete_clicked();

private:
    Ui::Book *ui;
};

#endif // BOOK_H
