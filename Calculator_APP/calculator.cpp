#include "calculator.h"
#include "ui_calculator.h"
#include <QMessageBox>
#include <sstream>
#include <QValidator>
#include <cstring>
#include <cmath>

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator)
{
    ui->setupUi(this);
    QRegularExpression expr("^([0-9]{1,15}[+\\/*\\.-])+[-][0-9]{1,15}$");
    QValidator *validator = new QRegularExpressionValidator(expr, this);
    ui->Input->setValidator(validator);
    ui->Input->setFocusPolicy(Qt::StrongFocus);
    ui->Input->setFocus();
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::print_num(std::string s){
    std::string str = ui->Input->text().toStdString();
    ui->Input->setText(ui->Input->text() + QString::fromStdString(s));
}

bool Calculator::check_op_limit(std::string s){
    std::string str = ui->Input->text().toStdString();
    int len = str.length() - 1;
    if(len < 0){
        return false;
    }
    else if(str.at(len) != '.' && str.at(len) != '-' && str.at(len) != '+' && str.at(len) != '/' && str.at(len) != '*'){
        ui->Input->setText(ui->Input->text() + QString::fromStdString(s));
    }
    return true;
}
void Calculator::on_One_clicked()
{
    Calculator::print_num("1");
}


void Calculator::on_Two_clicked()
{
    Calculator::print_num("2");
}


void Calculator::on_Three_clicked()
{
    Calculator::print_num("3");
}


void Calculator::on_Four_clicked()
{
    Calculator::print_num("4");
}


void Calculator::on_Five_clicked()
{
    Calculator::print_num("5");
}


void Calculator::on_Six_clicked()
{
    Calculator::print_num("6");
}


void Calculator::on_Seven_clicked()
{
    Calculator::print_num("7");
}


void Calculator::on_Eight_clicked()
{
    Calculator::print_num("8");
}


void Calculator::on_Nine_clicked()
{
    Calculator::print_num("9");
}


void Calculator::on_Zero_clicked()
{
    Calculator::print_num("0");
}


void Calculator::on_dot_clicked()
{
    Calculator::check_op_limit(".");
}


void Calculator::on_Plus_clicked()
{
    Calculator::check_op_limit("+");
}


void Calculator::on_Minus_clicked()
{
    Calculator::check_op_limit("-");
}


void Calculator::on_Multiply_clicked()
{

    Calculator::check_op_limit("*");
}


void Calculator::on_Divide_clicked()
{
    Calculator::check_op_limit("/");
}


void Calculator::on_Equal_clicked()
{
    long double output = 0;
    long double temp = 0;
    char op = '+';
    std::string str = ui->Input->text().toStdString();
    std::stringstream ss(str);
    while(ss>>temp){
          if(op == '+'){
            output+=temp;
          }
          else if(op == '-'){
            output-=temp;
          }
          else if(op == '*'){
            output*=temp;
          }
          else if(op == '/'){
            output/=temp;
          }
          else{
            continue;
          }
          ss>>op;
      }
    ui->Input->setText(QString::fromStdString(std::to_string(output)));
}


void Calculator::on_Ac_clicked()
{
    ui->Input->setText(QString::fromStdString(""));
}


bool Calculator::on_Clear_clicked()
{
    std::string str = ui->Input->text().toStdString();
    if(str.size() != 0){
        str.resize(str.size() - 1);
        ui->Input->setText(QString::fromStdString(str));
    }
    return false;
}

void Calculator::on_Input_returnPressed()
{
    Calculator::on_Equal_clicked();
}


void Calculator::on_About_clicked()
{
    QMessageBox aboutDev(QMessageBox::NoIcon,"About Developer","Made by Abrar Ahmed Shahok (21BSCS-20)\n"
                                                               "Features : Addition,Subtraction,Multiplication & Division\n"
                                                               "For Now It Does\'nt follow DMAS Rule, I'll Soon Fix It!\n"
                                                               "It Accepts only 15 Digits Input same as all Calculators\n"
                                                               "For More Info Vist : https://github.com/abrar-ahmed-21bscs20",QMessageBox::Ok);
    QPixmap devPic(":/resources/devPic.jpg");
    aboutDev.setIconPixmap(devPic.scaled(100,100,Qt::KeepAspectRatio));
    aboutDev.exec();
}
