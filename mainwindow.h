#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "integralquestion.h"
#include "derivativequestion.h"
#include "limitquestion.h"
#include "integralformulasheet.h"
#include "derivativeformulasheet.h"
#include "limitformulasheet.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnStart_clicked();

    void on_btnExit_clicked();

    void on_btnQuestion_clicked();

    void on_btnFormulas_clicked();



    void on_BtnMainBack_clicked();

    void on_btnIntegralQuestion_clicked();

    void on_btnDerivativeQuestion_clicked();

    void on_btnLimitQuestion_clicked();

    void on_btnTopicBack_clicked();


    void on_btnFeedBackBack_clicked();

    void on_btnNextQuestion_clicked();

    void on_btnSubmit_clicked();

    void on_btnQuestionBack_clicked();

    void on_btnExitScreen_clicked();

    void on_btnExitBack_clicked();

    void on_btnIntegralFormulas_clicked();

    void on_btnDerivativeFormulas_clicked();

    void on_btnLimitFormulas_clicked();

    void on_btnFormulaBack_clicked();

private:
    Ui::MainWindow *ui;
    // Question banks
    std::vector<IntegralQuestion> integralBank;
    std::vector<DerivativeQuestion> derivativeBank;
    std::vector<LimitQuestion> limitBank;

    // Formula sheets
    IntegralFormulaSheet integralSheet;
    DerivativeFormulaSheet derivativeSheet;
    LimitFormulaSheet limitSheet;

    QString currentTopic;
    int currentIndex = 0;

    // Helper functions
    void startTopic(const QString &topic);
    void loadFormulaSheet(const QString &topic);
};
#endif // MAINWINDOW_H
