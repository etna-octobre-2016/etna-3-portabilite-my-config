#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QtCharts>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>

#include <QLineSeries>
#include <QChart>
#include <QChartView>

#include <QDateTime>
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
    void setUrlApi(QString new_url_api);


private:
    Ui::MainWindow *ui;
    QString url_api;
    int seconds;
    QChartView *chartView;
    QJsonObject dataRam;
    void updateChart();
    void loadSettings();
    void saveSettings();

private slots:
    void on_actionSetIp_triggered();
    void on_actionExportData_triggered();
    void loadCpu(QNetworkReply* reply);
    void loadOs(QNetworkReply* reply);
    void loadRam(QNetworkReply* reply);
    void refreshRam();
};

#endif // MAINWINDOW_H
