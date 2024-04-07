#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QPushButton>
#include <vector>
#include <QString>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    activeButton(100,ui->pbCoffee);
    activeButton(150,ui->pbTea);
    activeButton(200,ui->pbMilk);
}

void Widget::activeButton(int price,QPushButton* bev){
    if(money >= price){
        bev->setEnabled(true);
    } else {
        bev->setEnabled(false);
    }
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    vector<int> num;
    change_reset(money,&num);
    mb.information(this,"Reset","500won : "+QString::number(num[0])+"\n"
                +"100won : "+QString::number(num[1]) + "\n"
                +"50won : "+QString::number(num[2]) + "\n"
                +"10won : "+QString::number(num[3]));
}

void Widget::change_reset(int total, vector<int>* num){
    int temp;
    int c_500,c_100,c_50,c_10;
    c_500 = (total / 500);
    (*num).push_back(c_500);

    temp = total - 500 * c_500;

    c_100 = (temp / 100);
    (*num).push_back(c_100);

    temp = temp - 100 * c_100;

    c_50 = (temp / 50);
    (*num).push_back(c_50);

    temp = temp - 50 * c_50;

    c_10 = temp / 10;
    (*num).push_back(c_10);
}
