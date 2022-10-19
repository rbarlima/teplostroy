#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>

/* My Includes */
#include <qdynamicbutton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();    // СЛОТ-обработчик нажатия кнопки добавления
    void on_calculateButton_clicked(); // СЛОТ-для получения калькуляции
    void slotDeliteLine();           // СЛОТ для удаления строки
    void on_helpButton_clicked();
    void on_aboutButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
