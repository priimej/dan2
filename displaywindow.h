#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public slots:
    void display_content();
    void recieve_json(const QJsonObject &inputJson) {
        jobj = inputJson; display_content();}

public:
    explicit DisplayWindow(QWidget *parent = nullptr);
    ~DisplayWindow();

    QJsonValue get_value(const QString &key) {
        return jobj.find(key).value();
    }
private:
    Ui::DisplayWindow *ui;
    QJsonObject jobj;
};

#endif // DISPLAYWINDOW_H
