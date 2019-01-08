#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <array>
#include "pieces.h"
#include "type.h"


namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();


private:
    void mousePressEvent(QMouseEvent *event) override;
    void pieces_move();
    void pieces_lock();
    void pieces_replace();
    void change_attack_defend();

    Ui::game *ui;

    //virtual chessboard.
    std::array<std::array<Pieces *, 9>, 10> P;
    //whether any piece is locked.
    bool is_lock=false;
    //preivous lock piece's row and column.
    int previous_row, prevoius_column;
    //now click piece's row and column.
    int now_row, now_column;
    //which is attack.
    TYPE attack=TYPE::RED;
    QLabel *black=new QLabel(this);
    QLabel *red=new QLabel(this);
    //error place pieces.
    bool error_place=true;
};

#endif // GAME_H
