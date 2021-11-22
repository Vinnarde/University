#include "tables.h"
#include "ui_tables.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>
#include <QRegExpValidator>
#include <QRegExp>

Tables::Tables(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Tables) {
    ui->setupUi(this);

    QRegExp phoneRegExp("\\d{11}");
    QRegExpValidator* phoneValidator = new QRegExpValidator(phoneRegExp);

    ui->lineEditStudentPhone->setValidator(phoneValidator);
    ui->lineEditEmployeePhone->setValidator(phoneValidator);

    /* Book start */

    getTypes();

    getAuthorsId();

    getPublishersId();

    getBookName();


    /* Book End */

    /* Student start */

    getStudentsId();

    getCourses();

    getSex();



    //ui->comboBoxStudentStudentId->setCurrentIndex(1);


    /* Student end */

    getBooksId();

    getBorrowsId();
    getEmployeesId();
    getPositionId();

    testPosition();

    ui->tableViewBorrows->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewStudents->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewAuthors->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewEmployees->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewPublishers->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewTypes->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewPosititions->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableViewViews->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    emit on_comboBoxStudentStudentId_currentIndexChanged(0);

    emit on_pushButtonStudentLoadData_clicked();
    emit on_pushButtonLoadDataBooks_clicked();
    emit on_pushButtonBorrowsLoadData_clicked();
    emit on_pushButtonEmployeeLoadData_clicked();
    emit on_pushButtonAuthorLoadData_clicked();
    emit on_pushButtonPublisherLoadData_clicked();
    emit on_pushButtonTypeLoadData_clicked();
}

Tables::~Tables() {
    delete ui;
}

void Tables::getTypes() {
    QSqlQueryModel *modelTypes = new QSqlQueryModel();
    QSqlQuery queryGetTypes;
    queryGetTypes.exec("SELECT typeId, name from Type");

    modelTypes->setQuery(queryGetTypes);
    ui->comboBoxBookTypeId_2->setModel(modelTypes);
    ui->comboBoxTypeTypeId->setModel(modelTypes);
}

void Tables::getAuthorsId() {
    QSqlQueryModel *modelAuthorsId = new QSqlQueryModel();
    QSqlQuery queryGetAuthors;
    queryGetAuthors.exec("Select author_id from Author");

    modelAuthorsId->setQuery(queryGetAuthors);
    ui->comboBoxBookAuthorId_2->setModel(modelAuthorsId);
    ui->comboBoxAuthorAuthorId->setModel(modelAuthorsId);
}

void Tables::getPublishersId() {
    QSqlQueryModel *modelPublishersId = new QSqlQueryModel();
    QSqlQuery queryGetPublishers;
    queryGetPublishers.exec("Select publisher_id from Publisher");

    modelPublishersId->setQuery(queryGetPublishers);
    ui->comboBoxBookPublisherId_2->setModel(modelPublishersId);
    ui->comboBoxPublisherPublisherId->setModel(modelPublishersId);
}

void Tables::getBookName() {
    QSqlQueryModel *modelNames = new QSqlQueryModel();
    QSqlQuery queryGetNames;
    queryGetNames.exec("Select name from Book");

    modelNames->setQuery(queryGetNames);
    ui->comboBoxBookName_2->setModel(modelNames);
}

void Tables::getStudentsId() {
    QSqlQueryModel *modelStudentsId = new QSqlQueryModel();
    QSqlQuery queryGetStudentsId;
    queryGetStudentsId.exec("SELECT student_id from Student");

    modelStudentsId->setQuery(queryGetStudentsId);
    ui->comboBoxStudentStudentId->setModel(modelStudentsId);
    ui->comboBoxBorrowsStudentId->setModel(modelStudentsId);
}

void Tables::getCourses() {
    QSqlQueryModel *modelCourses = new QSqlQueryModel();
    QSqlQuery queryGetCourses;
    queryGetCourses.exec("SELECT distinct course from Student");

    modelCourses->setQuery(queryGetCourses);
    ui->comboBoxStudentCourse->setModel(modelCourses);
}

void Tables::getSex() {
    QSqlQueryModel *modelSex = new QSqlQueryModel();
    QSqlQuery queryGetSex;
    queryGetSex.exec("SELECT distinct sex from Student");

    modelSex->setQuery(queryGetSex);
    ui->comboBoxStudentSex->setModel(modelSex);
}

void Tables::getBooksId() {
    QSqlQueryModel *modelBooksId = new QSqlQueryModel();
    QSqlQuery queryGetBooksId;
    queryGetBooksId.exec("SELECT book_id from Book");

    modelBooksId->setQuery(queryGetBooksId);
    ui->comboBoxBorrowsBookId->setModel(modelBooksId);
}

void Tables::getBorrowsId() {
    QSqlQueryModel *modelBorrowsId = new QSqlQueryModel();
    QSqlQuery queryGetBorrowsId;
    queryGetBorrowsId.exec("SELECT borrow_id from Borrows");

    modelBorrowsId->setQuery(queryGetBorrowsId);
    ui->comboBoxBorrowsBorrowId->setModel(modelBorrowsId);
}

void Tables::getEmployeesId() {
    QSqlQueryModel *modelEmployeesId = new QSqlQueryModel();
    QSqlQuery queryGetEmployeesId;
    queryGetEmployeesId.exec("SELECT emp_id from Employee");

    modelEmployeesId->setQuery(queryGetEmployeesId);
    ui->comboBoxBorrowsEmployeeId->setModel(modelEmployeesId);
    ui->comboBoxEmployeeEmpId->setModel(modelEmployeesId);
}

void Tables::getPositionId() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.exec("SELECT position_id from Position");

    model->setQuery(query);
    ui->comboBoxEmployeePositionId->setModel(model);
}

void Tables::testPosition() {

    QSqlQuery query;
    query.exec("SELECT position_id from Position");

    while (query.next())
    {
        ui->comboBoxPositionPositionId->addItem(query.value(0).toString(),query.value(1));
    }
}


/* Book start */
void Tables::on_tableViewBooks_activated(const QModelIndex &index) {

    QString book_id = index.sibling(index.row(), 0).data().toString();

    //QMessageBox::warning(this,tr("Warning::"), book_id);

    QSqlQuery query;

    query.prepare("Select * from Book where book_id = :bookId");
    query.bindValue(":bookId", book_id);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxBookTypeId_2->setCurrentText(query.value(1).toString());
            ui->comboBoxBookName_2->setCurrentText(query.value(2).toString());
            ui->lineEditBookPageCount_2->setText(query.value(3).toString());
            ui->lineEditBookPrice_2->setText(query.value(4).toString());
            ui->comboBoxBookAuthorId_2->setCurrentText(query.value(5).toString());
            ui->comboBoxBookPublisherId_2->setCurrentText(query.value(6).toString());
            ui->lineEditBookAmount_2->setText(query.value(7).toString());
        }
    } else {
        qDebug() << "Some shit happened again!\n";
        qDebug() << query.lastError().text();
    }
}


void Tables::on_pushButtonBookAdd_2_clicked() {
    QString data[7];
    data[0] = ui->comboBoxBookTypeId_2->currentText();
    data[1] = ui->comboBoxBookName_2->currentText();
    data[2] = ui->lineEditBookPageCount_2->text();
    data[3] = ui->lineEditBookPrice_2->text();
    data[4] = ui->comboBoxBookAuthorId_2->currentText();
    data[5] = ui->comboBoxBookPublisherId_2->currentText();
    data[6] = ui->lineEditBookAmount_2->text();

    for (auto e: data)
        qDebug() << e << '\n';

    QSqlQuery query;
    query.prepare(
            QString("Insert into Book(typeId, name, page_count, price, author_id, publisher_id, amount) values(:type, :name, :pageCount, :price, :author, :publisher, :amount)"));
    query.bindValue(":type", data[0]);
    query.bindValue(":name", data[1]);
    query.bindValue(":pageCount", data[2]);
    query.bindValue(":price", data[3]);
    query.bindValue(":author", data[4]);
    query.bindValue(":publisher", data[5]);
    query.bindValue(":amount", data[6]);
    //query.bindValue("", data[]);

    if (query.exec()) {
        qDebug() << "Book " << data[1] << " was successfully added into book table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row int book table!";

        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getBooksId();
    getBookName();
    emit on_pushButtonLoadDataBooks_clicked();
}


void Tables::on_pushButtonLoadDataBooks_clicked() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Book");
    modal->setQuery(query);
    ui->tableViewBooks->setModel(modal);

    qDebug() << modal->rowCount();
}


void Tables::on_pushButtonBookEdit_2_clicked() {
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

    for (auto e: data)
        qDebug() << e << '\n';

    QSqlQuery query;
    query.prepare(
            QString("Update Book set typeId = :type, name = :name, page_count = :pageCount, price = :price, author_id = :author, publisher_id = :publisher, amount = :amount Where book_id = :bookId"));
    query.bindValue(":type", data[0]);
    query.bindValue(":name", data[1]);
    query.bindValue(":pageCount", data[2]);
    query.bindValue(":price", data[3]);
    query.bindValue(":author", data[4]);
    query.bindValue(":publisher", data[5]);
    query.bindValue(":amount", data[6]);
    query.bindValue(":bookId", book_id);
    //query.bindValue("", data[]);

    if (query.exec()) {
        qDebug() << "Book#!" << book_id << " was successfully edited into book table!\n";
    } else {
        qDebug() << "Something went wrong with editing book#" << book_id << " in book table!";
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getBooksId();
    getBookName();
    emit on_pushButtonLoadDataBooks_clicked();
}


void Tables::on_pushButtonBookDelete_2_clicked() {
    QModelIndex index = ui->tableViewBooks->selectionModel()->currentIndex();
    QString book_id = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;
    query.prepare("Delete from Book Where book_id = :bookId");
    query.bindValue(":bookId", book_id);

    if (query.exec()) {
        qDebug() << "Book#" << book_id << " was deleted!\n";
    } else {
        qDebug() << "Something went wrong with deleting book#" << book_id << " from book table!\n";
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getBooksId();
    getBookName();
    emit on_pushButtonLoadDataBooks_clicked();
}
/* Book end */

/* Student start */
void Tables::on_pushButtonStudentLoadData_clicked() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Student");
    modal->setQuery(query);
    ui->tableViewStudents->setModel(modal);

    qDebug() << modal->rowCount();
}


void Tables::on_tableViewStudents_activated(const QModelIndex &index) {
    QString student_id = index.sibling(index.row(), 0).data().toString();

    //QMessageBox::warning(this,tr("Warning::"), student_id);

    QSqlQuery query;

    query.prepare("Select * from Student where student_id = :studentId");
    query.bindValue(":studentId", student_id);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxStudentStudentId->setCurrentText(query.value(0).toString());
            ui->lineEditStudentFirstName->setText(query.value(1).toString());
            ui->lineEditStudentSurname->setText(query.value(2).toString());
            ui->comboBoxStudentCourse->setCurrentText(query.value(3).toString());
            ui->lineEditStudentPhone->setText(query.value(4).toString());
            ui->dateEditStudentBirthDate->setDate(query.value(5).toDate());
            ui->comboBoxStudentSex->setCurrentText(query.value(6).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Student table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_comboBoxStudentStudentId_currentIndexChanged(int index) {
    QString student_id = ui->comboBoxStudentStudentId->currentText();

    //QMessageBox::warning(this,tr("Warning::"), student_id);

    QSqlQuery query;

    query.prepare("Select * from Student where student_id = :studentId");
    query.bindValue(":studentId", student_id);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxStudentStudentId->setCurrentText(query.value(0).toString());
            ui->lineEditStudentFirstName->setText(query.value(1).toString());
            ui->lineEditStudentSurname->setText(query.value(2).toString());
            ui->comboBoxStudentCourse->setCurrentText(query.value(3).toString());
            ui->lineEditStudentPhone->setText(query.value(4).toString());
            ui->dateEditStudentBirthDate->setDate(query.value(5).toDate());
            ui->comboBoxStudentSex->setCurrentText(query.value(6).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Student table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_pushButtonStudentAdd_clicked() {
    QString data[6];
    data[0] = ui->lineEditStudentFirstName->text();
    data[1] = ui->lineEditStudentSurname->text();
    data[2] = ui->comboBoxStudentCourse->currentText();
    data[3] = ui->lineEditStudentPhone->text();
    data[4] = ui->dateEditStudentBirthDate->date().toString("yyyy.MM.dd");
    data[5] = ui->comboBoxStudentSex->currentText();

    for (auto e: data)
        qDebug() << e << '\n';

    //"Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :Surname, :course, :phone, :birthDate, :sex)";
    QSqlQuery query;
    query.prepare(
            QString("Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :surname, :course, :phone, :birthDate, :sex)"));
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);
    query.bindValue(":course", data[2]);
    query.bindValue(":phone", data[3]);
    query.bindValue(":birthDate", data[4]);
    query.bindValue(":sex", data[5]);

    if (query.exec()) {
        qDebug() << "Student " << data[0] << ' ' << data[1] << " was successfully added into student table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row int student table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getStudentsId();
    emit on_pushButtonStudentLoadData_clicked();
}


void Tables::on_pushButtonStudentEdit_clicked() {
    QString studentId = ui->comboBoxStudentStudentId->currentText();

    QString data[6];
    data[0] = ui->lineEditStudentFirstName->text();
    data[1] = ui->lineEditStudentSurname->text();
    data[2] = ui->comboBoxStudentCourse->currentText();
    data[3] = ui->lineEditStudentPhone->text();
    data[4] = ui->dateEditStudentBirthDate->date().toString("yyyy.MM.dd");
    data[5] = ui->comboBoxStudentSex->currentText();

    for (auto e: data)
        qDebug() << e << '\n';

    //"Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :Surname, :course, :phone, :birthDate, :sex)";
    QSqlQuery query;
    query.prepare(
            QString("Update Student set first_name = :firstName, second_name = :surname, course = :course, phone = :phone, birth_date = :birthDate, sex = :sex Where student_id = :studentId"));
    query.bindValue(":studentId", studentId);
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);
    query.bindValue(":course", data[2]);
    query.bindValue(":phone", data[3]);
    query.bindValue(":birthDate", data[4]);
    query.bindValue(":sex", data[5]);

    if (query.exec()) {
        qDebug() << "Student " << data[0] << ' ' << data[1] << " was successfully added into student table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row int student table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getStudentsId();
    emit on_pushButtonStudentLoadData_clicked();
}


void Tables::on_pushButtonStudentDelete_clicked() {
    QString studentId = ui->comboBoxStudentStudentId->currentText();

    QSqlQuery query;
    query.prepare("Delete from Student Where student_id = :studentId");
    query.bindValue(":studentId", studentId);

    if (query.exec()) {
        qDebug() << "Student#" << studentId << " was deleted!\n";
    } else {
        qDebug() << "Something went wrong with deleting student#" << studentId << " from Student table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getStudentsId();
    emit on_pushButtonStudentLoadData_clicked();
}
/* Student end */


/* Borrows start */
void Tables::on_pushButtonBorrowsLoadData_clicked() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Borrows");
    modal->setQuery(query);
    ui->tableViewBorrows->setModel(modal);

    qDebug() << "Borrow table. Rows loaded: " << modal->rowCount();
}


void Tables::on_comboBoxBorrowsBorrowId_currentIndexChanged(int index) {
    QString borrow_id = ui->comboBoxBorrowsBorrowId->currentText();

    QSqlQuery query;

    query.prepare("Select * from Borrows where borrow_id = :borrowId");
    query.bindValue(":borrowId", borrow_id);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxBorrowsBorrowId->setCurrentText(query.value(0).toString());
            ui->comboBoxBorrowsStudentId->setCurrentText(query.value(1).toString());
            ui->comboBoxBorrowsBookId->setCurrentText(query.value(2).toString());
            ui->comboBoxBorrowsEmployeeId->setCurrentText(query.value(3).toString());
            ui->dateEditBorrowsTakenDate->setDate(query.value(4).toDate());

            if (query.value(5).toString().isEmpty()) {

                ui->dateEditBorrowsBroughtDate->setDate(ui->dateEditBorrowsBroughtDate->maximumDate());
            } else {
                ui->dateEditBorrowsBroughtDate->setDate(query.value(5).toDate());
            }
        }
    } else {
        qDebug() << "Something went from when retrieving data from Borrows table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_tableViewBorrows_activated(const QModelIndex &index) {
    QString borrow_id = index.sibling(index.row(), 0).data().toString();


    QSqlQuery query;

    query.prepare("Select * from Borrows where borrow_id = :borrowId");
    query.bindValue(":borrowId", borrow_id);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxBorrowsBorrowId->setCurrentText(query.value(0).toString());
            ui->comboBoxBorrowsStudentId->setCurrentText(query.value(1).toString());
            ui->comboBoxBorrowsBookId->setCurrentText(query.value(2).toString());
            ui->comboBoxBorrowsEmployeeId->setCurrentText(query.value(3).toString());
            ui->dateEditBorrowsTakenDate->setDate(query.value(4).toDate());

            if (query.value(5).toString().isEmpty()) {

                ui->dateEditBorrowsBroughtDate->setDate(ui->dateEditBorrowsBroughtDate->maximumDate());
            } else {
                ui->dateEditBorrowsBroughtDate->setDate(query.value(5).toDate());
            }
        }
    } else {
        qDebug() << "Something went from when retrieving data from Borrows table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_pushButtonBorrowsGiveBook_clicked() {
    QString data[4];
    data[0] = ui->comboBoxBorrowsStudentId->currentText();
    data[1] = ui->comboBoxBorrowsBookId->currentText();
    data[2] = ui->comboBoxBorrowsEmployeeId->currentText();
    data[3] = QDate::currentDate().toString("yyyy.MM.dd");

    for (const auto& e: data) {
        qDebug() << e << '\n';
    }

    QSqlQuery query;
    query.prepare(
            QString("Insert into Borrows(student_id, book_id, employee_id, taken_date) values(:studentId, :bookId, :empId, :takenDate)"));
    query.bindValue(":studentId", data[0]);
    query.bindValue(":bookId", data[1]);
    query.bindValue(":empId", data[2]);
    query.bindValue(":takenDate", data[3]);

    if (query.exec()) {
        qDebug() << "Book " << data[1] << " was successfully given to Student#" << data[0] << "!\n";
    } else {
        qDebug() << "Something went wrong with adding new row int book table!";
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getBorrowsId();
    emit on_pushButtonBorrowsLoadData_clicked();
}


void Tables::on_pushButtonBorrowsReturnBook_clicked() {
    QString borrow_id = ui->comboBoxBorrowsBorrowId->currentText();

    QSqlQuery query;
    query.prepare("Select brought_date from Borrows Where borrow_id = :borrowId");
    query.bindValue(":borrowId", borrow_id);

    if (query.exec()) {
        while (query.next()) {
            qDebug() << "Query result: " << query.value(0).toString();
            if (query.value(0).toString().isEmpty()) {
                query.prepare("Update Borrows set brought_date = :date Where borrow_id =:borrowId");
                query.bindValue(":date", QDate::currentDate().toString("yyyy.MM.dd"));
                query.bindValue(":borrowId", borrow_id);


                if (query.exec()) {
                    qDebug() << "Book has returned";
                } else {
                    qDebug() << "Something went wrong with adding new row int book table!";
                }
            } else {
                QMessageBox::warning(this, tr("Warning::"), "Borrow#" + borrow_id + " has been already returned!");
            }
        }
    } else {
        qDebug() << "Something went wrong with adding new row int book table!";
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
    getBorrowsId();
    emit on_pushButtonBorrowsLoadData_clicked();
}

/* Borrows end */


/* Employee start */
void Tables::on_pushButtonEmployeeLoadData_clicked() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Employee");
    modal->setQuery(query);
    ui->tableViewEmployees->setModel(modal);

    qDebug() << "Employee table. Rows loaded: " << modal->rowCount();
}


void Tables::on_comboBoxEmployeeEmpId_currentIndexChanged(int index) {
    QString emp_id = ui->comboBoxEmployeeEmpId->currentText();

    QSqlQuery query;

    query.prepare("Select * from Employee where emp_id = :emp_id");
    query.bindValue(":emp_id", emp_id);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxEmployeeEmpId->setCurrentText(query.value(0).toString());
            ui->lineEditEmployeeFirstName->setText(query.value(1).toString());
            ui->lineEditEmployeeSurname->setText(query.value(2).toString());
            ui->lineEditEmployeePhone->setText(query.value(3).toString());
            ui->lineEditEmployeeSalary->setText(query.value(4).toString());
            ui->comboBoxEmployeePositionId->setCurrentText(query.value(5).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Employee table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_pushButtonEmployeeAdd_clicked() {
    QString data[5];
    data[0] = ui->lineEditEmployeeFirstName->text();
    data[1] = ui->lineEditEmployeeSurname->text();
    data[2] = ui->lineEditEmployeePhone->text();
    data[3] = ui->lineEditEmployeeSalary->text();
    data[4] = ui->comboBoxEmployeePositionId->currentText();

    for (const auto& e : data) {
        qDebug() << e << '\n';
    }

    //"Insert into Student(first_name, second_name, course, phone, birth_date, sex) values(:firstName, :Surname, :course, :phone, :birthDate, :sex)";
    //"Insert into Employee(first_name, second_name, phone, salary, position_id) values(:firstName, :surname, :phone, :salary, :position_id)"
    QSqlQuery query;
    query.prepare(
            QString("Insert into Employee(first_name, second_name, phone, salary, position_id) values(:firstName, :surname, :phone, :salary, :positionId)"));
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);
    query.bindValue(":phone", data[2]);
    query.bindValue(":salary", data[3]);
    query.bindValue(":positionId", data[4]);

    if (query.exec()) {
        qDebug() << "Employee " << data[0] << ' ' << data[1] << " was successfully added into Employee table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row into Employee table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getEmployeesId();
    emit on_pushButtonEmployeeLoadData_clicked();
}


void Tables::on_pushButtonEmployeeEdit_clicked() {
    QString empId = ui->comboBoxEmployeeEmpId->currentText();

    QString data[5];
    data[0] = ui->lineEditEmployeeFirstName->text();
    data[1] = ui->lineEditEmployeeSurname->text();
    data[2] = ui->lineEditEmployeePhone->text();
    data[3] = ui->lineEditEmployeeSalary->text();
    data[4] = ui->comboBoxEmployeePositionId->currentText();

    for (auto e: data)
        qDebug() << e << '\n';

    QSqlQuery query;
    query.prepare(
            QString("Update Employee set first_name = :firstName, second_name = :surname, phone= :phone, salary = :salary, position_id = :positionId Where emp_id = :empId"));
    query.bindValue(":empId", empId);
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);
    query.bindValue(":phone", data[2]);
    query.bindValue(":salary", data[3]);
    query.bindValue(":positionId", data[4]);

    if (query.exec()) {
        qDebug() << "Employee " << data[0] << ' ' << data[1] << " was successfully altered into Employee table!\n";
    } else {
        qDebug() << "Something went wrong with altering Employee#" << empId << " into Employee table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
    emit on_pushButtonEmployeeLoadData_clicked();
}


void Tables::on_pushButtonEmployeeDelete_clicked() {
    QString empId = ui->comboBoxEmployeeEmpId->currentText();

    QSqlQuery query;
    query.prepare("Delete from Employee Where emp_id = :empId");
    query.bindValue(":empId", empId);

    if (query.exec()) {
        qDebug() << "Employee#" << empId << " was deleted!\n";
    } else {
        qDebug() << "Something went wrong with deleting employee#" << empId << " from Employee table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getEmployeesId();
    emit on_pushButtonEmployeeLoadData_clicked();
}


void Tables::on_tableViewEmployees_activated(const QModelIndex &index) {
    QString empId = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;

    query.prepare("Select * from Employee where emp_id = :emp_id");
    query.bindValue(":emp_id", empId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxEmployeeEmpId->setCurrentText(query.value(0).toString());
            ui->lineEditEmployeeFirstName->setText(query.value(1).toString());
            ui->lineEditEmployeeSurname->setText(query.value(2).toString());
            ui->lineEditEmployeePhone->setText(query.value(3).toString());
            ui->lineEditEmployeeSalary->setText(query.value(4).toString());
            ui->comboBoxEmployeePositionId->setCurrentText(query.value(5).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Employee table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}

/* Employee end */


/* Author start */
void Tables::on_pushButtonAuthorLoadData_clicked() {
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Author");
    modal->setQuery(query);
    ui->tableViewAuthors->setModel(modal);

    qDebug() << "Author table. Rows loaded: " << modal->rowCount();
}


void Tables::on_comboBoxAuthorAuthorId_currentIndexChanged(const QString &arg1) {
    const QString& authorId = arg1;

    QSqlQuery query;

    query.prepare("Select * from Author where author_id = :authorId");
    query.bindValue(":authorId", authorId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxAuthorAuthorId->setCurrentText(query.value(0).toString());
            ui->lineEditAuthorFirstName->setText(query.value(1).toString());
            ui->lineEditAuthorSurname->setText(query.value(2).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Author table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_tableViewAuthors_activated(const QModelIndex &index) {
    QString authorId = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;

    query.prepare("Select * from Author where author_id = :authorId");
    query.bindValue(":authorId", authorId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxAuthorAuthorId->setCurrentText(query.value(0).toString());
            ui->lineEditAuthorFirstName->setText(query.value(1).toString());
            ui->lineEditAuthorSurname->setText(query.value(2).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Author table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_pushButtonAuthorAdd_clicked() {
    QString data[2];
    data[0] = ui->lineEditAuthorFirstName->text();
    data[1] = ui->lineEditAuthorSurname->text();

    for (const auto& e: data) {
        qDebug() << e << '\n';
}

    QSqlQuery query;
    query.prepare(QString("Insert into Author(first_name, second_name) values(:firstName, :surname)"));
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);

    if (query.exec()) {
        qDebug() << "Author " << data[0] << ' ' << data[1] << " was successfully added into Author table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row into Author table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getAuthorsId();
    emit on_pushButtonAuthorLoadData_clicked();
}


void Tables::on_pushButtonAuthorEdit_clicked() {
    QString authorId = ui->comboBoxAuthorAuthorId->currentText();

    QString data[2];
    data[0] = ui->lineEditAuthorFirstName->text();
    data[1] = ui->lineEditAuthorSurname->text();

    for (const auto & e: data) {
        qDebug() << e << '\n';
    }

    QSqlQuery query;
    query.prepare(
            QString("Update Author set first_name = :firstName, second_name = :surname Where author_id = :authorId"));
    query.bindValue(":authorId", authorId);
    query.bindValue(":firstName", data[0]);
    query.bindValue(":surname", data[1]);


    if (query.exec()) {
        qDebug() << "Author# " << authorId << ' ' << data[0] << ' ' << data[1]
                 << " was successfully altered into Author table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row into Author table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
    emit on_pushButtonAuthorLoadData_clicked();
}


void Tables::on_pushButtonAuthorDelete_clicked() {
    QString authorId = ui->comboBoxAuthorAuthorId->currentText();

    QSqlQuery query;
    query.prepare(
        QString("Delete from Author Where author_id = :authorId"));
    query.bindValue(":authorId", authorId);


    if (query.exec()) {
        qDebug() << "Author# " << authorId << ' '
                 << " was successfully deleted from Author table!\n";
    } else {
        qDebug() << "Something went wrong with deleting row from Author table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
    getAuthorsId();
    emit on_pushButtonAuthorLoadData_clicked();
}

/* Author end */


/* Publisher start */
void Tables::on_pushButtonPublisherLoadData_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Publisher");
    model->setQuery(query);
    ui->tableViewPublishers->setModel(model);

    qDebug() << "Publisher table. Rows loaded: " << model->rowCount();
}


void Tables::on_comboBoxPublisherPublisherId_currentIndexChanged(const QString &arg1) {
    const QString& publisherId = arg1;

    QSqlQuery query;

    query.prepare("Select * from Publisher where publisher_id = :publisherId");
    query.bindValue(":publisherId", publisherId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxPublisherPublisherId->setCurrentText(query.value(0).toString());
            ui->lineEditPublisherName->setText(query.value(1).toString());
            ui->lineEditPublisherAddress->setText(query.value(2).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Publisher table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_tableViewPublishers_activated(const QModelIndex &index)
{
    QString publisherId = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;

    query.prepare("Select * from Publisher where publisher_id = :publisherId");
    query.bindValue(":publisherId", publisherId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxPublisherPublisherId->setCurrentText(query.value(0).toString());
            ui->lineEditPublisherName->setText(query.value(1).toString());
            ui->lineEditPublisherAddress->setText(query.value(2).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Publisher table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_pushButtonPublisherAdd_clicked() {
    QString data[2];
    data[0] = ui->lineEditPublisherName->text();
    data[1] = ui->lineEditPublisherAddress->text();

    for (const auto& e: data) {
        qDebug() << e << '\n';
    }

    QSqlQuery query;
    query.prepare(QString("Insert into Publisher(name, address) values(:name, :address)"));
    query.bindValue(":name", data[0]);
    query.bindValue(":address", data[1]);

    if (query.exec()) {
        qDebug() << "Publisher " << data[0] << ' ' << data[1] << " was successfully added into Publisher table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row into Publisher table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getPublishersId();
    emit on_pushButtonPublisherLoadData_clicked();
}


void Tables::on_pushButtonPublisherEdit_clicked() {
    QString publisherId = ui->comboBoxPublisherPublisherId->currentText();


    QString data[2];
    data[0] = ui->lineEditPublisherName->text();
    data[1] = ui->lineEditPublisherAddress->text();

    for (const auto& e: data) {
        qDebug() << e << '\n';
    }

    QSqlQuery query;
    query.prepare(QString("Update Publisher set name = :name, address = :address Where publisher_id = :publisherId"));
    query.bindValue(":name", data[0]);
    query.bindValue(":address", data[1]);
    query.bindValue(":publisherId", publisherId);

    if (query.exec()) {
        qDebug() << "Publisher " << data[0] << ' ' << data[1] << " was successfully altered into Publisher table!\n";
    } else {
        qDebug() << "Something went wrong with altering row into Publisher table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    emit on_pushButtonPublisherLoadData_clicked();
}


void Tables::on_pushButtonPublisherDelete_clicked() {
    QString publisherId = ui->comboBoxPublisherPublisherId->currentText();

    QSqlQuery query;
    query.prepare(QString("Delete from Publisher Where publisher_id = :publisherId"));
    query.bindValue(":publisherId", publisherId);

    if (query.exec()) {
        qDebug() << "Publisher#"  << publisherId << ' '  << " was successfully deleted from Publisher table!\n";
    } else {
        qDebug() << "Something went wrong with deleting row from Publisher table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getPublishersId();
    emit on_pushButtonPublisherLoadData_clicked();
}

/* Publisher end*/


/* Type start */
void Tables::on_pushButtonTypeLoadData_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.exec("SELECT * from Type");
    model->setQuery(query);
    ui->tableViewTypes->setModel(model);

    qDebug() << "Type table. Rows loaded: " << model->rowCount();
}


void Tables::on_comboBoxTypeTypeId_activated(const QString &arg1) {
    const QString& typeId = arg1;

    QSqlQuery query;

    query.prepare("Select * from Type where typeId = :typeId");
    query.bindValue(":typeId", typeId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxTypeTypeId->setCurrentText(query.value(0).toString());
            ui->lineEditTypeName->setText(query.value(1).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Type table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_tableViewTypes_activated(const QModelIndex &index) {
    QString typeId = index.sibling(index.row(), 0).data().toString();

    QSqlQuery query;

    query.prepare("Select * from Type where typeId = :typeId");
    query.bindValue(":typeId", typeId);

    if (query.exec()) {
        while (query.next()) {
            ui->comboBoxTypeTypeId->setCurrentText(query.value(0).toString());
            ui->lineEditTypeName->setText(query.value(1).toString());
        }
    } else {
        qDebug() << "Something went from when retrieving data from Type table!\n";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }
}


void Tables::on_pushButtonTypeAdd_clicked() {
    QString data[1];
    data[0] = ui->lineEditTypeName->text();

    for (const auto& e: data) {
        qDebug() << e << '\n';
    }

    QSqlQuery query;
    query.prepare(QString("Insert into Type(name) values(:name)"));
    query.bindValue(":name", data[0]);

    if (query.exec()) {
        qDebug() << "Type " << data[0] << " was successfully added into Publisher table!\n";
    } else {
        qDebug() << "Something went wrong with adding new row into Type table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getTypes();
    emit on_pushButtonTypeLoadData_clicked();
}


void Tables::on_pushButtonTypeEdit_clicked() {
    QString typeId = ui->comboBoxTypeTypeId->currentText();


    QString data[2];
    data[0] = ui->lineEditTypeName->text();


    for (const auto& e: data) {
        qDebug() << e << '\n';
    }

    QSqlQuery query;
    query.prepare(QString("Update Type set name = :name Where typeid = :typeId"));
    query.bindValue(":name", data[0]);
    query.bindValue(":typeId", typeId);

    if (query.exec()) {
         qDebug() << "Type# " << typeId << " was successfully altered into Publisher table!\n";
    } else {
        qDebug() << "Something went wrong with altering row into Type table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    emit on_pushButtonTypeLoadData_clicked();
}


void Tables::on_pushButtonTypeDelete_clicked() {
    QString typeId = ui->comboBoxTypeTypeId->currentText();

    QSqlQuery query;
    query.prepare(QString("Delete from Type Where typeId = :typeId"));
    query.bindValue(":typeId", typeId);

    if (query.exec()) {
        qDebug() << "Type#"  << typeId << ' '  << " was successfully deleted from Type table!\n";
    } else {
        qDebug() << "Something went wrong with deleting row from Type table!";
        qDebug() << query.lastError().text();
        QMessageBox::critical(this, "Error", query.lastError().text());
    }

    getTypes();
    emit on_pushButtonTypeLoadData_clicked();
}


void Tables::on_pushButtonBookPopularityReport_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.exec("Select * from BookPopularityReport");

    model->setQuery(query);
    ui->tableViewViews->setModel(model);
}




void Tables::on_pushButtonDetailedBookReport_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.exec("Select * from [Test View]");

    model->setQuery(query);
    ui->tableViewViews->setModel(model);
}



void Tables::on_pushButtonExpiredBooks_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.exec("Select * from [EmployeeReport]");

    model->setQuery(query);
    ui->tableViewViews->setModel(model);
}


void Tables::on_pushButtonEmployeeReport_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.exec("Select * from [ExpiredBooks]");

    model->setQuery(query);
    ui->tableViewViews->setModel(model);
}

