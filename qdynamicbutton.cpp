#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton(QWidget *parent) :
    QWidget(parent)
{
    ResID++;            // Увеличение счетчика на единицу
    lineID = ResID;   /* Присвоение кнопке номера, по которому будет производиться
                         * дальнейшая работа с кнопок
                         * */

    box = new QHBoxLayout(this);
    label = new QLabel(this);
    line = new QLineEdit(this);
    spinN = new QSpinBox(this);
    comboT = new QComboBox(this);
    comboE = new QComboBox(this);
    comboD = new QComboBox(this);
    comboP = new QComboBox(this);
    spinT = new QSpinBox(this);
    comboF = new QComboBox(this);
    comboA = new QComboBox(this);
    comboB = new QComboBox(this);
    comboR = new QComboBox(this);
    check = new QCheckBox(this);
    button = new QPushButton(this);
    box->addWidget(label);
    box->addWidget(line);
    box->addWidget(spinN);
    box->addWidget(comboT);
    box->addWidget(comboE);
    box->addWidget(comboD);
    box->addWidget(comboP);
    box->addWidget(spinT);
    box->addWidget(comboF);
    box->addWidget(comboA);
    box->addWidget(comboB);
    box->addWidget(comboR);
    box->addWidget(check);
    box->addWidget(button);


//    QHBoxLayout * box;
//    QLabel * label;
//    QLineEdit * line;
//    QSpinBox * spinN;
//    QComboBox * comboT;
//    QComboBox * comboE;
//    QComboBox * comboD;
//    QComboBox * comboP;
//    QSpinBox * spinT;
//    QComboBox * comboF;
//    QComboBox * comboA;
//    QComboBox * comboB;
//    QComboBox * comboR;
//    QCheckBox * check;
//    QPushButton * button;
}

QDynamicButton::~QDynamicButton()
{

}

/* Метод для возврата значения номера кнопки
 * */
int QDynamicButton::getID()
{
    return lineID;
}

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int QDynamicButton::ResID = 0;
