#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QLabel>
#include<QPushButton>
#include<QMouseEvent>
#include"scene.h"
#include"lefttower.h"
#include"arrow.h"
#include<QWidget>
#include<QDockWidget>
#include<QHBoxLayout>
#include<QGridLayout>
#include"btn.h"
#include"drawcards.h"
#include"dialog.h"
#include"rank.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene1;

    void settingBg();
    void ManageCard();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
    void create1_1();
    void create1_2();
    void create1_3();
    void create1_4();
    void create1_5();
    void create1_6();
    void create1_7();
    void create1_8();
    void create1_9();
    void create1_10();
    void create1_11();
    void create1_12();
    void create1_13();
    void create1_14();
    void create1_15();
    void create1_16();
    void create1_17();
    void create1_18();
    void create1_19();
    void create1_20();
    void create1_21();
    void closeChoose();
    void set1();
    void set2();
    void set3();
    void set4();
    void set5();
    void set6();
    void set7();
    void set8();
    void set9();
    void set10();
    void set11();
    void set12();
    void set13();
    void set14();
    void recover1();
    void recover2();
    void recover3();
    void recover4();
    void recover5();
    void recover6();
    void recover7();
    void recover8();
    void recover9();
    void recover10();
    void recover11();
    void recover12();
    void recover13();
    void recover14();
    void getRandom();
    void chooseStart();
    //void popup();

private:
    Ui::MainWindow *ui;
    QPushButton *card_luffy, *card_zoro, *card_bread, *card_curry, *card_din, *card_bo, *card_totoro, *card_lulumi;
    QPushButton *card_pd2, *card_linear, *card_electric, *card_matlab, *card_lens, *card_light;
    QPushButton *card_tornado,*card_fog, *card_smallLight, *card_dizzy, *card_bomb, *card_enlarge, *card_door;
    bool luffy, zoro, bread, curry, din, bo, totoro, lulumi;
    bool pd2, linear, electric, matlab, lens, light;
    bool tornado,fog,smallLight,dizzy,bomb,enlarge,door;
    QDockWidget *choose,*dock;
    QWidget *allCards,*btnWidget,*extra2;
    QGridLayout *layout,*layout2;
    QHBoxLayout *btnLayout;
    Rank * rankBoard;
    DrawCards * draw;
    int number;
    Dialog * dialog;

};

#endif // MAINWINDOW_H
