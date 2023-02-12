#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <cstring>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:

    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_Zero_clicked();

    void on_dot_clicked();

    void on_Plus_clicked();

    void on_Minus_clicked();

    void on_Multiply_clicked();

    void on_Divide_clicked();

    void on_Equal_clicked();

    void on_Ac_clicked();

    bool on_Clear_clicked();

    void on_Input_returnPressed();

    void on_About_clicked();

    void print_num(std::string s);

    bool check_op_limit(std::string s);

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
