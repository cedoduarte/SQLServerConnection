#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QODBC");
    m_db.setDatabaseName("Driver={ODBC Driver 17 for SQL Server};Server=localhost\\SQLEXPRESS;Database=master;Trusted_Connection=yes;TrustServerCertificate=yes;");
    if (!m_db.open())
    {
        qDebug() << m_db.lastError().text();
        return;
    }
    m_model = new QSqlQueryModel(this);
    m_model->setQuery(QSqlQuery("select * from users"));
    ui->tableView->setModel(m_model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
