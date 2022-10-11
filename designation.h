#ifndef DESIGNATION_H
#define DESIGNATION_H
#include <QDebug>
#include <qdynamicbutton.h>

QString makeName(QDynamicButton *line){
    QString fire ("KM1-");
    if (line->comboF->currentText() == "НГ"){fire = "KM0-";}
    QString equipment ("ZS ");
    if (line->comboE->currentText() == "Задвижка"){equipment = "ZZ ";
    }else if (line->comboE->currentText() == "Кран"){equipment = "ZK ";
    }else if (line->comboE->currentText() == "Затвор дисковый"){equipment = "ZD ";
    }else if (line->comboE->currentText() == "Клапан запорный"){equipment = "ZV ";
    }else if (line->comboE->currentText() == "Клапан обратный"){equipment = "ZO ";
    }else if (line->comboE->currentText() == "Регулятор"){equipment = "ZR ";
    }else if (line->comboE->currentText() == "Фильтр"){equipment = "ZF ";
    }else if (line->comboE->currentText() == "Другое"){equipment = "NX ";
    }
    QString insulation ("C");
    QString material (" C");
    if (line->spinT->value() > 350){insulation = " M"; material = " P";}
    QString width ("50");
    // Здесь создаём и заполняем матрицу зависимости толщины утеплителя от температуры и диаметра
    int matrix[19][8];
    for (int i = 0; i < 3; i++) { matrix[i][0] = 30;}
    for (int i = 3; i < 8; i++) { matrix[i][0] = 40;}
    for (int i = 8; i < 12; i++) { matrix[i][0] = 50;}
    for (int i = 12; i < 19; i++) { matrix[i][0] = 60;}

    for (int i = 0; i < 4; i++) { matrix[i][1] = 40;}
    for (int i = 4; i < 12; i++) { matrix[i][1] = 50;}
    for (int i = 12; i < 17; i++) { matrix[i][1] = 60;}
    for (int i = 17; i < 19; i++) { matrix[i][1] = 70;}

    for (int i = 0; i < 10; i++) { matrix[i][2] = 50;}
    for (int i = 10; i < 16; i++) { matrix[i][2] = 60;}
    for (int i = 16; i < 18; i++) { matrix[i][2] = 70;}
    for (int i = 18; i < 19; i++) { matrix[i][2] = 80;}

    for (int i = 0; i < 9; i++) { matrix[i][3] = 50;}
    for (int i = 9; i < 10; i++) { matrix[i][3] = 60;}
    for (int i = 10; i < 14; i++) { matrix[i][3] = 70;}
    for (int i = 14; i < 17; i++) { matrix[i][3] = 80;}
    for (int i = 17; i < 18; i++) { matrix[i][3] = 90;}
    for (int i = 18; i < 19; i++) { matrix[i][3] = 100;}

    for (int i = 0; i < 6; i++) { matrix[i][4] = 50;}
    for (int i = 6; i < 9; i++) { matrix[i][4] = 60;}
    for (int i = 9; i < 12; i++) { matrix[i][4] = 70;}
    for (int i = 12; i < 16; i++) { matrix[i][4] = 80;}
    for (int i = 16; i < 19; i++) { matrix[i][4] = 100;}

    for (int i = 0; i < 6; i++) { matrix[i][5] = 50;}
    for (int i = 6; i < 9; i++) { matrix[i][5] = 60;}
    for (int i = 9; i < 12; i++) { matrix[i][5] = 70;}
    for (int i = 12; i < 16; i++) { matrix[i][5] = 80;}
    for (int i = 16; i < 19; i++) { matrix[i][5] = 100;}

    for (int i = 0; i < 7; i++) { matrix[i][6] = 50;}
    for (int i = 7; i < 10; i++) { matrix[i][6] = 60;}
    for (int i = 10; i < 16; i++) { matrix[i][6] = 80;}
    for (int i = 16; i < 18; i++) { matrix[i][6] = 90;}
    for (int i = 18; i < 19; i++) { matrix[i][6] = 100;}

    for (int i = 0; i < 6; i++) { matrix[i][7] = 50;}
    for (int i = 6; i < 10; i++) { matrix[i][7] = 60;}
    for (int i = 10; i < 12; i++) { matrix[i][7] = 80;}
    for (int i = 12; i < 14; i++) { matrix[i][7] = 90;}
    for (int i = 14; i < 16; i++) { matrix[i][7] = 100;}
    for (int i = 16; i < 19; i++) { matrix[i][7] = 120;}
    // Закончили заполнять матрицу
    int i = 0; int j = 3;
    if(line->comboD->currentText() == "DN10") {i = 0;
    } else if(line->comboD->currentText() == "DN15") {i = 1;
    } else if(line->comboD->currentText() == "DN20") {i = 2;
    } else if(line->comboD->currentText() == "DN25") {i = 3;
    } else if(line->comboD->currentText() == "DN32") {i = 4;
    } else if(line->comboD->currentText() == "DN40") {i = 5;
    } else if(line->comboD->currentText() == "DN50") {i = 6;
    } else if(line->comboD->currentText() == "DN65") {i = 7;
    } else if(line->comboD->currentText() == "DN80") {i = 8;
    } else if(line->comboD->currentText() == "DN100") {i = 9;
    } else if(line->comboD->currentText() == "DN125") {i = 10;
    } else if(line->comboD->currentText() == "DN150") {i = 11;
    } else if(line->comboD->currentText() == "DN175") {i = 12;
    } else if(line->comboD->currentText() == "DN200") {i = 13;
    } else if(line->comboD->currentText() == "DN225") {i = 14;
    } else if(line->comboD->currentText() == "DN250") {i = 15;
    } else if(line->comboD->currentText() == "DN300") {i = 16;
    } else if(line->comboD->currentText() == "DN350") {i = 17;
    } else if(line->comboD->currentText() == "DN400") {i = 18;
    }
    if(line->spinT->value() <=50) {j = 0;
    } else if(line->spinT->value() >50 && line->spinT->value() <= 100) {j = 1;
    } else if(line->spinT->value() >100 && line->spinT->value() <= 150) {j = 2;
    } else if(line->spinT->value() >150 && line->spinT->value() <= 200) {j = 3;
    } else if(line->spinT->value() >200 && line->spinT->value() <= 250) {j = 4;
    } else if(line->spinT->value() >250 && line->spinT->value() <= 300) {j = 5;
    } else if(line->spinT->value() >300 && line->spinT->value() <= 350) {j = 6;
    } else if(line->spinT->value() >350 && line->spinT->value() <= 400) {j = 7;
    }
    width = QString::number(matrix[i][j]);
    QString type ("-M");
    if (line->comboT->currentText() == "Стандарт"){type = "-S";
    }else if (line->comboT->currentText() == "Другое"){type = "-K";
    }
    QString name = "Термочехол FORPRO " + fire + equipment + line->comboD->currentText() + "-C " + \
            insulation + width + material + type + "-00000-" + line->label->text();
    return name;
}
#endif // DESIGNATION_H
