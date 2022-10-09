#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    line->label->setText(QString::number(line->getID()));

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
    line->comboD->addItem("DN 10");
    line->comboD->addItem("DN 15");
    line->comboD->addItem("DN 20");
    line->comboD->addItem("DN 25");
    line->comboD->addItem("DN 32");
    line->comboD->addItem("DN 40");
    line->comboD->addItem("DN 50");
    line->comboD->addItem("DN 65");
    line->comboD->addItem("DN 80");
    line->comboD->addItem("DN 100");
    line->comboD->addItem("DN 125");
    line->comboD->addItem("DN 150");
    line->comboD->addItem("DN 200");
    line->comboD->addItem("DN 250");
    line->comboD->addItem("DN 300");
    line->comboD->addItem("DN 350");
    line->comboD->addItem("DN 400");

    line->comboP->setMinimumWidth(80);
    line->comboP->setMaximumWidth(80);
    line->comboP->addItem("PN 1-10");
    line->comboP->addItem("PN 16");
    line->comboP->addItem("PN 25");
    line->comboP->addItem("PN 40");
    line->comboP->addItem("PN 63");

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

    line->button->setText("X"); line->button->setMaximumSize(16,16);
    line->button->setObjectName(QString::number(line->getID()));
    /* Добавляем кнопку в слой с вертикальной компоновкой
     * */
    ui->verticalLayout->addWidget(line);
    /* Подключаем сигнал нажатия кнопки к СЛОТ получения номера кнопки
     * */
    connect(line->button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));

}

/* Метод для получения калькуляции
 * */
void MainWindow::on_deleteButton_clicked()
{
    QMessageBox::information(this, "Рассчёт", "Открывается PDF-документ с готовой калькуляцией");
}

/* СЛОТ для удаления строки
 * */
void MainWindow::slotGetNumber()
{
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
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "О программе", "Программа разработана для ГК Теплострой");
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Помощь", "Открывается инструкция по работе с программой");
}
