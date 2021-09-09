#include "tables.h"
#include "ui_tables.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>

Tables::Tables(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tables)
{
    ui->setupUi(this);

    /* Book start */
    QSqlQueryModel *modelTypes = new QSqlQueryModel();
    QSqlQuery queryGetTypes;
    queryGetTypes.exec("SELECT typeId from Type");

    modelTypes->setQuery(queryGetTypes);
    ui->comboBoxBookTypeId_2->setModel(modelTypes);

    QSqlQueryModel *modelAuthorsId = new QSqlQueryModel();
    QSqlQuery queryGetAuthors;
    queryGetAuthors.exec("Select author_id from Author");

    modelAuthorsId->setQuery(queryGetAuthors);
    ui->comboBoxBookAuthorId_2->setModel(modelAuthorsId);

    QSqlQueryModel *modelPublishersId = new QSqlQueryModel();
    QSqlQuery queryGetPublishers;
    queryGetPublishers.exec("Select publisher_id from Publisher");

    modelPublishersId->setQuery(queryGetPublishers);
    ui->comboBoxBookPublisherId_2->setModel(modelPublishersId);

    QSqlQueryModel *modelNames = new QSqlQueryModel();
    QSqlQuery queryGetNames;
    queryGetNames.exec("Select name from Book");

    modelNames->setQuery(queryGetNames);
    ui->comboBoxBookName_2->setModel(modelNames);
    emit on_pushButtonLoadDataBooks_clicked();
    /* Book End */

    /* Student start */

    QSqlQueryModel *modelStudentsId = new QSqlQueryModel();
    QSqlQuery queryGetStudentsId;
    queryGetStudentsId.exec("SELECT student_id from Student");

    modelStudentsId->setQuery(queryGetStudentsId);
    ui->comboBoxStudentStudentId->setModel(modelStudentsId);

    QSqlQueryModel *modelCourses = new QSqlQueryModel();
    QSqlQuery queryGetCourses;
    queryGetCourses.exec("SELECT distinct course from Student");

    modelCourses->setQuery(queryGetCourses);
    ui->comboBoxStudentCourse->setModel(modelCourses);

    QSqlQueryModel *modelSex = new QSqlQueryModel();
    QSqlQuery queryGetSex;
    queryGetSex.exec("SELECT distinct sex from Student");

    modelSex->setQuery(queryGetSex);
    ui->comboBoxStudentSex->setModel(modelSex);

    //ui->comboBoxStudentStudentId->setCurrentIndex(1);

    emit on_comboBoxStudentStudentId_currentIndexChanged(0);
    emit on_pushButtonStudentLoadData_clicked();
    /* Student end */
}

Tables::~Tables()
{
    delete ui;
}

/* Book start */
void Tables::on_tableViewBooks_activated(const QModelIndex &index)
{

    QString book_id = index.sibling(index.row(), 0).data().toString();

    QMessageBox::warning(this,tr("Warning::"), book_id);

    QSqlQuery query;

    query.prepare("Select * from Book where book_id = :bookId");
    query.bindValue(":bookId", book_id);

    if (query.exec())
    {
        while(query.next())
        {
            ui->comboBoxBookTypeId_2->setCurrentText(query.value(1).toString());
            ui->comboBoxBookName_2->setCurrentText(query.value(2).toString());
            ui->lineEditBookPageCount_2->setText(query.value(3).toString());
            ui->lineEditBookPrice_2->setText(query.value(4).toString());
            ui->comboBoxBookAuthorId_2->setCurrentText(query.value(5).toString());
            ui->comboBoxBookPublisherId_2->setCurrentText(query.value(6).toString());
            ui->lineEditBookAmount_2->setText(query.value(7).toString());
        }
    }
    else
    {
        qDebug() << "Some shit happed again!\n";
        qDebug() << query.lastError().text();
    }
}


void Tables::on_pushButtonBookAdd_2_clicked()
{
    QString data[7];
    data[0] = ui->comboBoxBookTypeId_2->currentText();
    data[1] = ui->comboBoxBookName_2->currentText();
    data[2] = ui->lineEditBookPageCount_2->text();
    data[3] = ui->lineEditBookPrice_2->text();
    data[4] = ui->comboBoxBookAuthorId_2->currentText();
    data[5] = ui->comboBoxBookPublisherId_2->currentText();
    data[6] = ui->lineEditBookAmount_2->text();

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


void Tables::on_pushButtonLoadDataBooks_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Book");
    modal->setQuery(query);
    ui->tableViewBooks->setModel(modal);

    qDebug() << modal->rowCount();
}


void Tables::on_pushButtonBookEdit_2_clicked()
{
    QModelIndex index = ui->tableViewBooks->selectionModel()->currentIndex();
    QString book_id = index.sibling(index.row(), 0).data().toString();
    QString data[7];
    data[0] = ui->comboBoxBookTypeId_2->currentText();
    data[1] = ui->comboBoxBookName_2->currentText();
    data[2] = ui->lineEditBookPageCount_2->text();
    data[3] = ui->lineEditBookPrice_2->text();
    data[4] = ui->comboBoxBookAuthorId_2->currentText();
    data[5] = ui->comboBoxBookPublisherId_2->currentText();
    data[6] = ui->lineEditBookAmount_2->text();

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
    query.bindValue(":bookId", book_id);
    //query.bindValue("", data[]);

    if (query.exec())
    {
        qDebug() << "Book#!" << book_id << " was successfuly edited into book table!\n";
    }
    else
    {
        qDebug() << "Something went wrong with editing book#" << book_id << " in book table!";
    }
}


void Tables::on_pushButtonBookDelete_2_clicked()
{
    QModelIndex index = ui->tableViewBooks->selectionModel()->currentIndex();
    QString book_id = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;
    query.prepare("Delete from Book Where book_id = :bookId");
    query.bindValue(":bookId", book_id);

    if (query.exec())
    {
        qDebug() << "Book#" << book_id << " was deleted!\n";
    }
    else
    {
        qDebug() << "Something went wrong with deleting book#" << book_id << " from book table!\n";
    }
}
/* Book end */

/* Student start */
void Tables::on_pushButtonStudentLoadData_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Student");
    modal->setQuery(query);
    ui->tableViewStudents->setModel(modal);

    qDebug() << modal->rowCount();
}


void Tables::on_tableViewStudents_activated(const QModelIndex &index)
{
    QString student_id = index.sibling(index.row(), 0).data().toString();

    //QMessageBox::warning(this,tr("Warning::"), student_id);

    QSqlQuery query;

    query.prepare("Select * from Student where student_id = :studentId");
    query.bindValue(":studentId", student_id);

    if (query.exec())
    {
        while(query.next())
        {
            ui->comboBoxStudentStudentId->setCurrentText(query.value(0).toString());
            ui->lineEditStudentFirstName->setText(query.value(1).toString());
            ui->lineEditStudentSurname->setText(query.value(2).toString());
            ui->comboBoxStudentCourse->setCurrentText(query.value(3).toString());
            ui->lineEditStudentPhone->setText(query.value(4).toString());
            ui->dateEditStudentBirthDate->setDate(query.value(5).toDate());
            ui->comboBoxStudentSex->setCurrentText(query.value(6).toString());
        }
    }
    else
    {
        qDebug() << "Something went from when retrieving data from Student table!\n";
        qDebug() << query.lastError().text();
    }
}


void Tables::on_comboBoxStudentStudentId_currentIndexChanged(int index)
{
    QString student_id = ui->comboBoxStudentStudentId->currentText();

    //QMessageBox::warning(this,tr("Warning::"), student_id);

    QSqlQuery query;

    query.prepare("Select * from Student where student_id = :studentId");
    query.bindValue(":studentId", student_id);

    if (query.exec())
    {
        while(query.next())
        {
            ui->comboBoxStudentStudentId->setCurrentText(query.value(0).toString());
            ui->lineEditStudentFirstName->setText(query.value(1).toString());
            ui->lineEditStudentSurname->setText(query.value(2).toString());
            ui->comboBoxStudentCourse->setCurrentText(query.value(3).toString());
            ui->lineEditStudentPhone->setText(query.value(4).toString());
            ui->dateEditStudentBirthDate->setDate(query.value(5).toDate());
            ui->comboBoxStudentSex->setCurrentText(query.value(6).toString());
        }
    }
    else
    {
        qDebug() << "Something went from when retrieving data from Student table!\n";
        qDebug() << query.lastError().text();
    }
}


void Tables::on_pushButtonStudentAdd_clicked()
{
    QString data[6];
    data[0] = ui->lineEditStudentFirstName->text();
    data[1] = ui->lineEditStudentSurname->text();
    data[2] = ui->comboBoxStudentCourse->currentText();
    data[3] = ui->lineEditStudentPhone->text();
    data[4] = ui->dateEditStudentBirthDate->date().toString("yyyy.MM.dd");
    data[5] = ui->comboBoxStudentSex->currentText();

    for (auto e : data)
        qDebug() << e << '\n';

    //"Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :Surname, :course, :phone, :birthDate, :sex)";
    QSqlQuery query;
    query.prepare(QString("Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :surname, :course, :phone, :birthDate, :sex)"));
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);
    query.bindValue(":course", data[2]);
    query.bindValue(":phone", data[3]);
    query.bindValue(":birthDate", data[4]);
    query.bindValue(":sex", data[5]);

    if (query.exec())
    {
        qDebug() << "Student " << data[0]  <<  ' ' << data[1]<< " was successfuly added into student table!\n";
    }
    else
    {
        qDebug() << "Something went wrong with adding new row int student table!";
        qDebug() << query.lastError().text();
    }
}


void Tables::on_pushButtonStudentEdit_clicked()
{
    QString studentId = ui->comboBoxStudentStudentId->currentText();

    QString data[6];
    data[0] = ui->lineEditStudentFirstName->text();
    data[1] = ui->lineEditStudentSurname->text();
    data[2] = ui->comboBoxStudentCourse->currentText();
    data[3] = ui->lineEditStudentPhone->text();
    data[4] = ui->dateEditStudentBirthDate->date().toString("yyyy.MM.dd");
    data[5] = ui->comboBoxStudentSex->currentText();

    for (auto e : data)
        qDebug() << e << '\n';

    //"Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :Surname, :course, :phone, :birthDate, :sex)";
    QSqlQuery query;
    query.prepare(QString("Update Student set first_name = :firstName, second_name = :surname, course = :course, phone = :phone, birth_date = :birthDate, sex = :sex Where student_id = :studentId"));
    query.bindValue(":studentId", studentId);
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);
    query.bindValue(":course", data[2]);
    query.bindValue(":phone", data[3]);
    query.bindValue(":birthDate", data[4]);
    query.bindValue(":sex", data[5]);

    if (query.exec())
    {
        qDebug() << "Student " << data[0]  <<  ' ' << data[1]<< " was successfuly added into student table!\n";
    }
    else
    {
        qDebug() << "Something went wrong with adding new row int student table!";
        qDebug() << query.lastError().text();
    }
}


void Tables::on_pushButtonStudentDelete_clicked()
{
    QString studentId = ui->comboBoxStudentStudentId->currentText();

    QSqlQuery query;
    query.prepare("Delete from Student Where student_id = :studentId");
    query.bindValue(":studentId", studentId);

    if (query.exec())
    {
        qDebug() << "Student#" << studentId << " was deleted!\n";
    }
    else
    {
        qDebug() << "Something went wrong with deleting student#" << studentId << " from Student table!\n";
        qDebug() << query.lastError().text();
    }
}

