#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "interface/DictionaryInterface.h"
#include "DictionaryProvider/DictionaryProvider.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchButton_clicked();

    void on_InsertButton_clicked();

    void on_return_2_clicked();

    void on_pushButton_clicked();

    void on_return_1_clicked();

    void on_start_search_clicked();

    void on_insert_button_clicked();

    void on_data_struc_currentTextChanged(const QString &arg1);

private:

    Ui::MainWindow *ui;
    DictionaryProvider* dictprovider;
    DictionaryInterface* dict;
};
#endif // MAINWINDOW_H
