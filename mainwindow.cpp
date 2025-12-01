#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QString>
#include <QDebug>
#include <QTextEdit>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // Load question banks
    integralBank = IntegralQuestion::loadFromFile("IntegralQuestion.txt");
    derivativeBank = DerivativeQuestion::loadFromFile("DerivativeQuestion.txt");
    limitBank = LimitQuestion::loadFromFile("LimitQuestion.txt");

    // Debug prints
    qDebug() << "Integral loaded:" << integralBank.size();
    qDebug() << "Derivative loaded:" << derivativeBank.size();
    qDebug() << "Limit loaded:" << limitBank.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------------------------------------
// BASIC NAVIGATION
// ---------------------------------------------

void MainWindow::on_btnStart_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnExit_clicked()
{
    close();
}

void MainWindow::on_btnQuestion_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnFormulas_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_BtnMainBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnTopicBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnQuestionBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnFeedBackBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnExitScreen_clicked()
{
    close();

}

void MainWindow::on_btnExitBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btnFormulaBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


// ----------------------------------------------------
// TOPIC SELECTION
// ----------------------------------------------------

void MainWindow::startTopic(const QString &topic)
{
    currentTopic = topic;
    currentIndex = 0;

    if (topic == "Integral") {
        ui->label_2->setText(QString::fromStdString(integralBank[currentIndex].getPrompt()));
    }
    else if (topic == "Derivative") {
        ui->label_2->setText(QString::fromStdString(derivativeBank[currentIndex].getPrompt()));
    }
    else if (topic == "Limit") {
        ui->label_2->setText(QString::fromStdString(limitBank[currentIndex].getPrompt()));
    }

    ui->lineEdit->clear();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btnIntegralQuestion_clicked()
{
    startTopic("Integral");
}

void MainWindow::on_btnDerivativeQuestion_clicked()
{
    startTopic("Derivative");
}

void MainWindow::on_btnLimitQuestion_clicked()
{
    startTopic("Limit");
}


// ----------------------------------------------------
// ANSWER SUBMISSION
// ----------------------------------------------------

void MainWindow::on_btnSubmit_clicked()
{
    QString userInput = ui->lineEdit->text();
    bool correct = false;
    QString correctAns;
    QString explanationText;

    if (currentTopic == "Integral") {
        correct = integralBank[currentIndex].checkAnswer(userInput.toStdString());
        correctAns = QString::fromStdString(integralBank[currentIndex].getCorrectAnswer());
        explanationText = QString::fromStdString(integralBank[currentIndex].getExplanation());
    }
    else if (currentTopic == "Derivative") {
        correct = derivativeBank[currentIndex].checkAnswer(userInput.toStdString());
        correctAns = QString::fromStdString(derivativeBank[currentIndex].getCorrectAnswer());
        explanationText = QString::fromStdString(derivativeBank[currentIndex].getExplanation());
    }
    else if (currentTopic == "Limit") {
        correct = limitBank[currentIndex].checkAnswer(userInput.toStdString());
        correctAns = QString::fromStdString(limitBank[currentIndex].getCorrectAnswer());
        explanationText = QString::fromStdString(limitBank[currentIndex].getExplanation());
    }

    ui->label_3->setText(correct ? "Correct!" : "Incorrect!");
    ui->label_4->setText("Answer: " + correctAns + "\nExplanation: " + explanationText);

    ui->stackedWidget->setCurrentIndex(4);
}


// ----------------------------------------------------
// NEXT QUESTION
// ----------------------------------------------------

void MainWindow::on_btnNextQuestion_clicked()
{
    currentIndex++;

    if (currentTopic == "Integral") {
        if (currentIndex >= integralBank.size()) currentIndex = 0;
        ui->label_2->setText(QString::fromStdString(integralBank[currentIndex].getPrompt()));
    }
    else if (currentTopic == "Derivative") {
        if (currentIndex >= derivativeBank.size()) currentIndex = 0;
        ui->label_2->setText(QString::fromStdString(derivativeBank[currentIndex].getPrompt()));
    }
    else if (currentTopic == "Limit") {
        if (currentIndex >= limitBank.size()) currentIndex = 0;
        ui->label_2->setText(QString::fromStdString(limitBank[currentIndex].getPrompt()));
    }

    ui->lineEdit->clear();
    ui->stackedWidget->setCurrentIndex(3);
}


// ----------------------------------------------------
// FORMULA SHEET LOADING
// ----------------------------------------------------

void MainWindow::loadFormulaSheet(const QString &topic)
{
    QString filename;

    if (topic == "Integral") filename = "IntegralFormulaSheet.txt";
    if (topic == "Derivative") filename = "DerivativeFormulaSheet.txt";
    if (topic == "Limit") filename = "LimitFormulaSheet.txt";

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->FormulaBrowser->setText("Cannot load formula sheet.");
        return;
    }

    QString content = file.readAll();
    ui->FormulaBrowser->setText(content);
}

void MainWindow::on_btnIntegralFormulas_clicked()
{
    loadFormulaSheet("Integral");
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btnDerivativeFormulas_clicked()
{
    loadFormulaSheet("Derivative");
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btnLimitFormulas_clicked()
{
    loadFormulaSheet("Limit");
    ui->stackedWidget->setCurrentIndex(6);
}

