
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <iostream>
#include <chrono>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    dictprovider = new DictionaryProvider();
    dict = dictprovider->getDict(dict, "Ternary Search Tree");
    ui->setupUi(this);

    QPixmap pixmap("./dic.jpg");
    ui->image->setPixmap(pixmap);
    ui->image->setScaledContents(true);
    ui->image->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}

// Search button-main
void MainWindow::on_searchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    dict = dictprovider->getDict(dict, "Ternary Search Tree");

}
// Insert button-main
void MainWindow::on_InsertButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

// return button Insert_page
void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// return button search_screen
void MainWindow::on_return_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

// Search Button
void MainWindow::on_start_search_clicked()
{
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::nanoseconds;
    high_resolution_clock::time_point startTime;

    string word = ui->input_word->toPlainText().toStdString();
    ui->meaning_output->setText("Searching...");
    for_each(word.begin(), word.end(), [](char& c) { c = tolower(c); });
    startTime = high_resolution_clock::now();
    word = dict->search(word);
    double stopTime = duration_cast<nanoseconds>(high_resolution_clock::now() - startTime).count();
    if (word == "")
       ui->meaning_output->setText("Word not Found in our Dictionary😔!! ");
    else
        ui->meaning_output->setText("Meaning: " + QString::fromUtf8(word.c_str()));
    ui->display_time->setText("Time: " + QString::number(stopTime)+ " ns");
}

// Choose Data structure
void MainWindow::on_data_struc_currentTextChanged(const QString &arg1)
{
    dict = dictprovider->getDict(dict, arg1.toStdString());
}


// ADD word Insert
void MainWindow::on_insert_button_clicked()
{
    string word = ui->wordToInsert->toPlainText().toStdString();
    string partOfSpeech = ui->partOfSpeech->currentText().toStdString();
    string meaning = ui->meaning->toPlainText().toStdString();

    if (partOfSpeech == "Noun") partOfSpeech = "n";
    else if (partOfSpeech == "Verb") partOfSpeech = "v";
    else if (partOfSpeech == "Adjective") partOfSpeech = "adj";
    else if (partOfSpeech == "Adverb") partOfSpeech = "adv";

    dictprovider->insertToFile(word, partOfSpeech, meaning);
    ui->stackedWidget->setCurrentIndex(0);
}
