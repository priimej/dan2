#include "mainwindow.h"
#include "./ui_mainwindow.h"

// when submitting, the name and age cannot be empty or negative
QString _name;
int _age = -1;
QDate _date;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_jobj(const QString &name,
                 const int     &age,
                 const QDate   &date) {

    MainWindow::_jObj = {
                    { "Name", name },
                    { "Age" , age },
                    { "Date", date.toString() },
                    };
}

void MainWindow::on_DateInput_userDateChanged(const QDate &date)
{
    _date = date;

    // validated through the qdate / edit button
}

void MainWindow::on_NameEdit_textChanged(const QString &input)
{
    _name = input;

    // technically don't need to validate? it's their name afterall
    // i dont judge
}

void MainWindow::on_AgeEdit_textChanged(const QString &input)
{
    // make it only accept numbers
    if(input.isEmpty()) {
    } else {
        for(int i = 0; i < input.size(); i++) {
            if( !input[i].isDigit() ) {
                ui->AgeEdit->setStyleSheet("border: 1px solid red;");
                return;
            }
        }
        ui->AgeEdit->setStyleSheet("");
        _age = input.toInt();
    }
}

void MainWindow::on_SubmitButton_clicked()
{
    // verify that inputs are not empty, technincally date is null if user doesnt change it ever
    if(_name.isNull() || _age < 0 || _date.isNull()) {
        ui->SubmitButton->setStyleSheet("border: 1px solid red;");
        return;
    } else {
        // reset the ui
        ui->SubmitButton->setStyleSheet("");
        MainWindow::create_jobj(_name, _age, _date);
        emit pass_json(this->_jObj);
    }
}
