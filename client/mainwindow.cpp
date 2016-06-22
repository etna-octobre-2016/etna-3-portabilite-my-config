#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initTab();
    this->url_api = "";
}

void MainWindow::initTab()
{
    if (this->url_api != "") {
        ui->os_value->setText("os_value");
        ui->cpu_value->setText("cpu_value");
        ui->number_cores_value->setText("cores_value");
        ui->architecture_value->setText("architecture_value");
        ui->ram_tot_value->setText("ram_tot_value");
        ui->ram_free_value->setText("ram_free");
        ui->ram_used_value->setText("ram_used");
    }
}

void MainWindow::setUrlApi(std::string new_url_api)
{
    this->url_api = new_url_api;
    this->initTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSetIp_triggered()
{
    QString new_url_api = QInputDialog::getText(this, "URL de l'API", "Quelle est l'URL de l'API ?");
    this->url_api = new_url_api.toStdString();
    this->initTab();
}

void MainWindow::on_actionAbout_triggered()
{
    About w;
    w.show();
}
