#include "widget.h"
#include "ui_widget.h"
#include "functions.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pwd_box,SIGNAL(returnPressed()),this,SLOT(on_pushButton_2_clicked()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
    {
    using namespace main_functions;
    QString username_QString=ui->username_box->text();
    std::string username=username_QString.toStdString();
    QString pwd_QString=ui->pwd_box->text();
    std::string pwd=pwd_QString.toStdString();

    login_if* checker=new login_if;
    int result=checker->if_is_true(username.c_str(),pwd.c_str());
    switch(result){
    case 1:
        //founded,wrong pwd
        QMessageBox::information(this,"WARNING","Wrong Password!");
        break;
    case 2:
        //wrong username
        QMessageBox::information(this,"WARNING","Username Not Found!");
        break;

    case 0:
        //good
        QMessageBox::information(this,"WELCOME","HELLO!!!!!");
        break;
    default:
        //error
        QMessageBox::information(this,"ERROR","ERROR!!!!!!!!!!");
        break;
    }

    delete checker;
    checker=NULL;

}


void Widget::on_login_button_clicked()
{
    system("neofetch");
    exit(0);
}

