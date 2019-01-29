#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>

namespace Ui {
class Configuration;
}

class Configuration : public QDialog
{
    Q_OBJECT

public:
    explicit Configuration(QWidget *parent = 0);
    ~Configuration();

private slots:
    void on_Refresh_clicked();

    void on_buttonBox_accepted();

    void on_JoinTopic_clicked();

    void on_createTopic_clicked();

private:
    Ui::Configuration *ui;
};

#endif // CONFIGURATION_H
