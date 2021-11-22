#include "book.h"
#include "ui_book.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "login.h"

#include <QMessageBox>

Book::Book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);

    QSqlQueryModel *modelTypes = new QSqlQueryModel();
    QSqlQuery queryGetTypes;
    queryGetTypes.exec("SELECT typeId from Type");

    modelTypes->setQuery(queryGetTypes);
   // ui->comboBoxBookTypeId->setModel(modelTypes);

    QSqlQueryModel *modelAuthorsId = new QSqlQueryModel();
    QSqlQuery queryGetAuthors;
    queryGetAuthors.exec("Select author_id from Author");

    modelAuthorsId->setQuery(queryGetAuthors);
   // ui->comboBoxBookAuthorId->setModel(modelAuthorsId);

    QSqlQueryModel *modelPublishersId = new QSqlQueryModel();
    QSqlQuery queryGetPublishers;
    queryGetPublishers.exec("Select publisher_id from Publisher");

    modelPublishersId->setQuery(queryGetPublishers);
   // ui->comboBoxBookPublisherId->setModel(modelPublishersId);

    QSqlQueryModel *modelNames = new QSqlQueryModel();
    QSqlQuery queryGetNames;
    queryGetNames.exec("Select name from Book");

    modelNames->setQuery(queryGetNames);
    //ui->fontComboBoxBookName->setModel(modelNames);
}

Book::~Book()
{
    delete ui;
}

void Book::on_pushButtonLoadDataBooks_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    //Login conn;
    //conn.connClose();
    //conn.connOpen();
    QSqlQuery query;

    //query->prepare("select * from book");
    query.exec("SELECT * from Book");
    modal->setQuery(query);
   // ui->tableViewBooks->setModel(modal);

    qDebug() << modal->rowCount();
}


void Book::on_tableViewBooks_activated(const QModelIndex &index)
{
    //QString indexValue = ui->tableViewBooks->model()->data(index).toString();

    //QModelIndex val = ui->tableViewBooks->selectionModel()->currentIndex();
    QString value = index.sibling(index.row(), 0).data().toString();

    //QMessageBox::warning(this,tr("Warning::"), value);

    QSqlQuery query;

    query.prepare("Select * from Book where book_id = '" + value + "'");

    if (query.exec())
    {
        while(query.next())
        {
           // ui->comboBoxBookTypeId->setCurrentText(query.value(1).toString());
           // ui->fontComboBoxBookName->setCurrentText(query.value(2).toString());
            //ui->lineEditBookPageCount->setText(query.value(3).toString());
           //ui->lineEditBookPrice->setText(query.value(4).toString());
            //ui->comboBoxBookAuthorId->setCurrentText(query.value(5).toString());
           // ui->comboBoxBookPublisherId->setCurrentText(query.value(6).toString());
            //ui->lineEditBookAmount->setText(query.value(7).toString());
        }
    }
    else
    {
        qDebug() << "Some shit happed again!\n";
    }
}


void Book::on_pushButtonBookAdd_clicked()
{
    QString data[7];
    //data[0] = ui->comboBoxBookTypeId->currentText();
    //data[1] = ui->fontComboBoxBookName->currentText();
    //data[2] = ui->lineEditBookPageCount->text();
    //data[3] = ui->lineEditBookPrice->text();
    //data[4] = ui->comboBoxBookAuthorId->currentText();
    //data[5] = ui->comboBoxBookPublisherId->currentText();
    //data[6] = ui->lineEditBookAmount->text();

    for (auto e : data)
        qDebug() << e << '\n';

    QSqlQuery query;
    query.prepare(QString("Insert into Book(typeId, name, page_count, price, author_id, publisher_id, amount) values(:type, :name, :pageCount, :price, :author, :publisher, :amount)"));
    query.bindValue(":type", data[0]);
    query.bindValue(":name", data[1]);
    query.bindValue(":pageCount", data[2]);
    query.bindValue(":price", data[3]);
    query.bindValue(":author", data[4]);
    query.bindValue(":publisher", data[5]);
    query.bindValue(":amount", data[6]);
    //query.bindValue("", data[]);

    if (query.exec())
    {
        qDebug() << "Book " << data[1]  << " was successfuly added into book table!\n";
    }
    else
    {
        qDebug() << "Something went wrong with adding new row int book table!";
    }

}


void Book::on_pushButtonBookEdit_clicked()
{
    //QModelIndex index = ui->tableViewBooks->selectionModel()->currentIndex();
    //QString book_id = index.sibling(index.row(), 0).data().toString();
    QString data[7];
    //data[0] = ui->comboBoxBookTypeId->currentText();
    //data[1] = ui->fontComboBoxBookName->currentText();
    //data[2] = ui->lineEditBookPageCount->text();
    //data[3] = ui->lineEditBookPrice->text();
    //data[4] = ui->comboBoxBookAuthorId->currentText();
    //data[5] = ui->comboBoxBookPublisherId->currentText();
    //data[6] = ui->lineEditBookAmount->text();

    for (auto e : data)
        qDebug() << e << '\n';

    QSqlQuery query;
    query.prepare(QString("Update Book set typeId = :type, name = :name, page_count = :pageCount, price = :price, author_id = :author, publisher_id = :publisher, amount = :amount Where book_id = :bookId"));
    query.bindValue(":type", data[0]);
    query.bindValue(":name", data[1]);
    query.bindValue(":pageCount", data[2]);
    query.bindValue(":price", data[3]);
    query.bindValue(":author", data[4]);
    query.bindValue(":publisher", data[5]);
    query.bindValue(":amount", data[6]);
    //query.bindValue(":bookId", book_id);
    //query.bindValue("", data[]);

    if (query.exec())
    {
       // qDebug() << "Book#!" << book_id << " was successfuly edited into book table!\n";
    }
    else
    {
       // qDebug() << "Something went wrong with editing book#" << book_id << " in book table!";
    }
}


void Book::on_pushButtonBookDelete_clicked()
{
    //QModelIndex index = ui->tableViewBooks->selectionModel()->currentIndex();
    //QString book_id = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;
    query.prepare("Delete from Book Where book_id = :bookId");
    //query.bindValue(":bookId", book_id);

    if (query.exec())
    {
        //qDebug() << "Book#" << book_id << " was deleted!\n";
    }
    else
    {
        //qDebug() << "Something went wrong with deleting book#" << book_id << " from book table!\n";
    }


}

