#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QtCharts>
#include "about.h"
#include "request.h"

using namespace QtCharts;

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
    QChartView *chartView;
    QJsonObject dataRam;
    void updateChart();

private slots:
    void on_actionSetIp_triggered();
    void loadCpu(QNetworkReply* reply);
    void loadOs(QNetworkReply* reply);
    void loadRam(QNetworkReply* reply);
    void refreshRam();
};

#endif // MAINWINDOW_H
