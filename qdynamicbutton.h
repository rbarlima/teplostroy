#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>

class QDynamicButton : public QWidget
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    static int ResID;   // Статическая переменная, счетчик номеров кнопок
    int getID();        // Функция для возврата локального номера кнопки
    std::string getName();        // Функция для возврата локального номера кнопки


public slots:

public:
    int lineID = 0;   // Локальная переменная, номер кнопки
    std::string lineName;   // Локальная переменная, номер кнопки
    QHBoxLayout * box;
    QLabel * label;
    QLineEdit * line;
    QSpinBox * spinN;
    QComboBox * comboT;
    QComboBox * comboE;
    QComboBox * comboD;
    QComboBox * comboP;
    QSpinBox * spinT;
    QComboBox * comboF;
    QComboBox * comboA;
    QComboBox * comboB;
    QComboBox * comboR;
    QCheckBox * check;
    QPushButton * button;
};

#endif // QDYNAMICBUTTON_H
