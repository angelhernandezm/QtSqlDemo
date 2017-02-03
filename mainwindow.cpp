#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include "employeedal.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnRunQuery_clicked() {
    auto index = 0;
    EmployeeDal dalObj;
    auto results = dalObj.GetPeople();
    auto lstView = findChild<QTableWidget*>("lstQueryResult");

    if (results.size() > 0 && lstView != nullptr) {
        lstView->clearContents();

        lstView->setRowCount(results.size());

        std::for_each(results.begin(), results.end(), [&](EmployeeDto& employee) {
            lstView->setItem(index, 0, new QTableWidgetItem(QString::number(employee.Id_get())));
            lstView->setItem(index, 1, new QTableWidgetItem(employee.FirstName_get()));
            lstView->setItem(index, 2, new QTableWidgetItem(employee.LastName_get()));
            index++;
        });
    }
}

void MainWindow::on_btnClose_clicked() {
    auto code =  [&]() {close();};
    Messenger("Are you sure you want to quit?", reinterpret_cast<const QMainWindow*>(this), code);
}
