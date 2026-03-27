#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

signals:
    void pass_json(QJsonObject _jObj);

public slots:
    void on_SubmitButton_clicked();
private slots:
    void on_DateInput_userDateChanged(const QDate &date);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_NameEdit_textChanged(const QString &arg1);

    void on_AgeEdit_textChanged(const QString &arg1);



private:
    Ui::MainWindow *ui;
    QJsonObject _jObj;
    void create_jobj(const QString &_name,
                     const int     &_age,
                     const QDate   &_date);

};
#endif // MAINWINDOW_H
