#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "designation.h"
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include "/usr/local/include/OpenXLSX/OpenXLSX.hpp"
#include <QFileDialog>
#include <QDate>

//#ifdef LINUX
//usleep(100000);
//#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_addButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Метод для добавления динамической кнопки
 * */
void MainWindow::on_addButton_clicked()
{
    QDynamicButton *line = new QDynamicButton(this);  // Создаем объект динамической кнопки
    /* Устанавливаем текст с номером этой кнопки
     * */
    line->label->setText(QString::number(ui->verticalLayout->count() + 1));

    line->spinN->setMinimum(1);
    line->spinN->setMaximum(999);
    line->spinN->setMinimumWidth(60);
    line->spinN->setMaximumWidth(60);

    line->comboT->setMinimumWidth(90);
    line->comboT->setMaximumWidth(90);
    line->comboT->addItem("Матрас");
    line->comboT->addItem("Стандарт");
    line->comboT->addItem("Другое");

    line->comboE->setMinimumWidth(110);
    line->comboE->setMaximumWidth(110);
    line->comboE->addItem("Фланец");
    line->comboE->addItem("Задвижка");
    line->comboE->addItem("Кран");
    line->comboE->addItem("Затвор дисковый");
    line->comboE->addItem("Клапан запорный");
    line->comboE->addItem("Клапан обратный");
    line->comboE->addItem("Регулятор");
    line->comboE->addItem("Фильтр");
    line->comboE->addItem("Другое");

    line->comboD->setMinimumWidth(80);
    line->comboD->setMaximumWidth(80);
    line->comboD->addItem("DN10");
    line->comboD->addItem("DN15");
    line->comboD->addItem("DN20");
    line->comboD->addItem("DN25");
    line->comboD->addItem("DN32");
    line->comboD->addItem("DN40");
    line->comboD->addItem("DN50");
    line->comboD->addItem("DN65");
    line->comboD->addItem("DN80");
    line->comboD->addItem("DN100");
    line->comboD->addItem("DN125");
    line->comboD->addItem("DN150");
    line->comboD->addItem("DN175");
    line->comboD->addItem("DN200");
    line->comboD->addItem("DN225");
    line->comboD->addItem("DN250");
    line->comboD->addItem("DN300");
    line->comboD->addItem("DN350");
    line->comboD->addItem("DN400");

    line->comboP->setMinimumWidth(80);
    line->comboP->setMaximumWidth(80);
    line->comboP->addItem("PN 1-10");
    line->comboP->addItem("PN 16");
    line->comboP->addItem("PN 25");
    line->comboP->addItem("PN 40");
    line->comboP->addItem("PN 63");

    line->spinT->setMinimum(0);
    line->spinT->setMaximum(400);
    line->spinT->setValue(200);
    line->spinT->setMinimumWidth(70);
    line->spinT->setMaximumWidth(70);

    line->comboF->setMinimumWidth(70);
    line->comboF->setMaximumWidth(70);
    line->comboF->addItem("Г1");
    line->comboF->addItem("НГ");

    line->comboA->setMinimumWidth(110);
    line->comboA->setMaximumWidth(110);
    line->comboA->addItem("Помещение");
    line->comboA->addItem("Улица");

    line->comboB->setMinimumWidth(90);
    line->comboB->setMaximumWidth(90);
    line->comboB->addItem("Широкая");
    line->comboB->addItem("Узкая");
    line->comboB->addItem("Без юбки");

    line->comboR->setMinimumWidth(70);
    line->comboR->setMaximumWidth(70);
    line->comboR->addItem("Нерж");
    line->comboR->addItem("Никель");

    line->check->setChecked("thrue");

    line->button->setText("X"); line->button->setMaximumSize(16,16);
    line->button->setObjectName(QString::number(line->getID()));
    /* Добавляем кнопку в слой с вертикальной компоновкой
     * */
    ui->verticalLayout->addWidget(line);
    /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
     * */
    connect(line->button, SIGNAL(clicked()), this, SLOT(slotDeliteLine()));

}

/* Метод для получения калькуляции
 * */
void MainWindow::on_calculateButton_clicked()
{
    OpenXLSX::XLDocument doc;
    doc.open("./template.data");
    auto wks = doc.workbook().worksheet("sheet1");
    double total = 0;
    int totalLine = 0;
    for(int i = 0; i < ui->verticalLayout->count(); i++){
        QDynamicButton *line = qobject_cast<QDynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
        QString name = makeName(line);
    QString price = makePrice(line);
      wks.cell(11+i, 2).value() = i+1;
      wks.cell(11+i, 3).value() = line->line->text().toStdString();
      wks.cell(11+i, 4).value() = name.toStdString();
      wks.cell(11+i, 5).value() = line->comboD->currentText().toStdString();
      wks.cell(11+i, 6).value() = line->spinT->value();
      wks.cell(11+i, 7).value() = line->comboP->currentText().toStdString();
      wks.cell(11+i, 8).value() = line->comboA->currentText().toStdString();
      wks.cell(11+i, 9).value() = line->comboB->currentText().toStdString();
      wks.cell(11+i, 10).value() = line->comboR->currentText().toStdString();
      if (line->check->checkState() == false) wks.cell(11+i, 11).value() = "Нет";
      else wks.cell(11+i, 11).value() = "Есть";
      wks.cell(11+i, 12).value() = price.toStdString();
      wks.cell(11+i, 13).value() = line->spinN->value();
      double sum = price.toDouble()*double(line->spinN->value());
      wks.cell(11+i, 14).value() = sum;
      totalLine = i;
      total = total + sum;
    }

    wks.cell(13+totalLine, 13).value() = "Итого:";
    wks.cell(13+totalLine, 14).value() = total;
    QString cd = QDate::currentDate().toString();
    wks.cell(7, 3).value() = cd.toStdString();

    QString filename = QFileDialog::getSaveFileName(this,
        tr("Save Document"),
        "Calculation.xlsx",
        tr("Documents (*.xlsx)") );

    if (!filename.isNull()) {
       doc.saveAs(filename.toStdString());
    }
    doc.close();
}

/* СЛОТ для удаления строки
 * */
void MainWindow::slotDeliteLine()
{
    if(ui->verticalLayout->count() > 1) {
        /* Определяем объект, который вызвал сигнал
         * */
        QDynamicButton *lineToDel = (QDynamicButton*) sender();
        /* Выполняем перебор всех элементов слоя, где располагаются динамические кнопки
         * */
        for(int i = 0; i < ui->verticalLayout->count(); i++){
            /* Производим каст элемента слоя в объект динамической кнопки
             * */
            QDynamicButton *line = qobject_cast<QDynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
            /* Если номер кнопки соответствует числу, которое установлено
             * в lineEdit, то производим удаление данной кнопки
             * */
            if(line->getID() == lineToDel->objectName().toInt()){
                line->hide();
                delete line;
            }
        }
        for(int i = 0; i < ui->verticalLayout->count(); i++){
            /* Производим каст элемента слоя в объект динамической кнопки
             * */
            QDynamicButton *line = qobject_cast<QDynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
            line->label->setText(QString::number(i+1)); // присваиваем номера строк
        }
    }
}

void MainWindow::on_aboutButton_clicked()
{
    QMessageBox::information(this, "О программе", "Программа разработана для ГК Теплострой.\nВерсия 1.0-beta (октябрь 2022г.)");
}

void MainWindow::on_helpButton_clicked()
{
    QMessageBox::information(this, "Помощь", "Для получения калькуляции заполните все поля, и нажмите кнопку 'Рассчитать'.\n\n"
                                             "Для добавления новой строчки нажмите кнопку 'Добавить позицию'.\n\n"
                                             "Для удаления определённой строчки нажмите на крестик справа от этой строки.\n\n"
                                             "Позиция- обозначение изделия в вашей документации.\n"
                                             "Кол-во- количество изделий данной позиции.\n"
                                             "Тип исполнения:\n   матрас- сшитые края элементов, гибкая форма.\n   стандарт- оформленные торцы элементов, строгая форма.\n"
                                             "Оборудование- вид арматуры, которую нужно утеплить.\n"
                                             "D арматуры- условный диаметр арматуры (DN/Ду).\n"
                                             "Давление- давление, на которое рассчитана арматура.\n"
                                             "t носителя- максимальная температура среды внутри системы.\n"
                                             "Группа горючести- группа горючести по ГОСТ.\n"
                                             "Применение- уличное применение, либо внутри помещения.\n"
                                             "Юбка- боковая утягивающая манжета.\n"
                                             "Тип D-колец- сварные полукольца из нержавеющей/никелерованной стали.\n"
                                             "Доп. крепление- уберите галочку, если дополнительное крепление не требуется.\n");
}
