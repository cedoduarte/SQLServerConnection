#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

class QSqlQueryModel;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QSqlQueryModel *m_model;
};

#endif // MAINWINDOW_H
