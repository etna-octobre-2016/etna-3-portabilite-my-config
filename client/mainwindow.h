#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "about.h"
#include "request.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initTab();
    void setUrlApi(std::string new_url_api);


private:
    Ui::MainWindow *ui;
    std::string url_api;

private slots:
    void on_actionSetIp_triggered();
    void loadCpu(QNetworkReply* reply);
    void loadOs(QNetworkReply* reply);
    void loadRam(QNetworkReply* reply);
};

#endif // MAINWINDOW_H
