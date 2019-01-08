#include "game.h"
#include "ui_game.h"
#include "type.h"
#include "board.h"
#include "pawn.h"
#include "cannon.h"
#include "knight.h"
#include "rook.h"
#include "elephant.h"
#include "advisor.h"
#include "king.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    //set chessboard.
    QPalette background;
    background.setBrush(QPalette::Background, QBrush(QPixmap(":/image/image/ChessBoard.png")));
    this->setPalette(background);
    //set size.
    this->resize(720, 805);
    //mouse.
    setMouseTracking(true);

    //P fill nullptr.
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            P[i][j]=nullptr;
        }
    }

    //set attack-defend label.
    black->setGeometry(0,0,80,80);
    red->setGeometry(640,725,80,80);
    change_attack_defend();

    //set pawns.
    P[3][0]=new Pawn(this,0,3,TYPE::BLACK);
    P[3][2]=new Pawn(this,2,3,TYPE::BLACK);
    P[3][4]=new Pawn(this,4,3,TYPE::BLACK);
    P[3][6]=new Pawn(this,6,3,TYPE::BLACK);
    P[3][8]=new Pawn(this,8,3,TYPE::BLACK);
    P[6][0]=new Pawn(this,0,6,TYPE::RED);
    P[6][2]=new Pawn(this,2,6,TYPE::RED);
    P[6][4]=new Pawn(this,4,6,TYPE::RED);
    P[6][6]=new Pawn(this,6,6,TYPE::RED);
    P[6][8]=new Pawn(this,8,6,TYPE::RED);
    //set cannons.
    P[2][1]=new Cannon(this,1,2,TYPE::BLACK);
    P[2][7]=new Cannon(this,7,2,TYPE::BLACK);
    P[7][1]=new Cannon(this,1,7,TYPE::RED);
    P[7][7]=new Cannon(this,7,7,TYPE::RED);
    //set knights.
    P[0][1]=new Knight(this,1,0,TYPE::BLACK);
    P[0][7]=new Knight(this,7,0,TYPE::BLACK);
    P[9][1]=new Knight(this,1,9,TYPE::RED);
    P[9][7]=new Knight(this,7,9,TYPE::RED);
    //set rooks.
    P[0][0]=new Rook(this,0,0,TYPE::BLACK);
    P[0][8]=new Rook(this,8,0,TYPE::BLACK);
    P[9][0]=new Rook(this,0,9,TYPE::RED);
    P[9][8]=new Rook(this,8,9,TYPE::RED);
    //set elephants.
    P[0][2]=new Elephant(this,2,0,TYPE::BLACK);
    P[0][6]=new Elephant(this,6,0,TYPE::BLACK);
    P[9][2]=new Elephant(this,2,9,TYPE::RED);
    P[9][6]=new Elephant(this,6,9,TYPE::RED);
    //set advisors.
    P[0][3]=new Advisor(this,3,0,TYPE::BLACK);
    P[0][5]=new Advisor(this,5,0,TYPE::BLACK);
    P[9][3]=new Advisor(this,3,9,TYPE::RED);
    P[9][5]=new Advisor(this,5,9,TYPE::RED);
    //set kings.
    P[0][4]=new King(this,4,0,TYPE::BLACK);
    P[9][4]=new King(this,4,9,TYPE::RED);
}

game::~game()
{
    delete ui;
}

void game::mousePressEvent(QMouseEvent *event)
{
    //find click node, if is not node, row=-1 and column=-1.
    now_row=Board::y_convert_row(event->y());
    now_column=Board::x_convert_column(event->x());

    if(now_row>=0&&now_column>=0){
        if(P[now_row][now_column]!=nullptr){
            if(is_lock){
                if(P[previous_row][prevoius_column]->go_here(previous_row, prevoius_column, now_row, now_column, P)){
                    if(P[previous_row][prevoius_column]->gettype()==P[now_row][now_column]->gettype()){
                        //lock.
                        pieces_lock();
                    }else{
                        //replace.
                        pieces_replace();
                        change_attack_defend();
                    }
                }else if(P[previous_row][prevoius_column]->gettype()==P[now_row][now_column]->gettype()&&
                         (previous_row!=now_row||prevoius_column!=now_column)){
                     //lock.
                    pieces_lock();
                }
            }else if(P[now_row][now_column]->gettype()==attack){
                //first lock, no previous piece.
                P[now_row][now_column]->lock();
                is_lock=true;
                previous_row=now_row;
                prevoius_column=now_column;
                error_place=false;
            }
        }else if(is_lock&&P[previous_row][prevoius_column]->go_here(previous_row, prevoius_column, now_row, now_column, P)){
            //move.
            pieces_move();
            change_attack_defend();
        }
    }

    if(error_place){
        QApplication::beep();  //error place note sounds.
    }else{
        error_place=true;
    }
}

void game::change_attack_defend()
{
    if(attack==TYPE::RED){
        //red is attack and black is defend.
        QPixmap red_pix(":/image/image/red_attack.png");
        QPixmap black_pix(":/image/image/black_defend.png");
        red->setPixmap(red_pix);
        black->setPixmap(black_pix);
    }else{
        //black is attack and red is defend.
        QPixmap red_pix(":/image/image/red_defend.png");
        QPixmap black_pix(":/image/image/black_attack.png");
        red->setPixmap(red_pix);
        black->setPixmap(black_pix);
    }
}

void game::pieces_move()
{
    P[now_row][now_column]=P[previous_row][prevoius_column];
    P[previous_row][prevoius_column]=nullptr;
    P[now_row][now_column]->move(Board::column_convert_x(now_column), Board::row_convert_y(now_row));
    is_lock=false;
    P[now_row][now_column]->remove_lock();
    attack=(attack==TYPE::RED) ? TYPE::BLACK : TYPE::RED;
    error_place=false;
}

void game::pieces_lock()
{
    P[now_row][now_column]->lock();
    P[previous_row][prevoius_column]->remove_lock();
    is_lock=true;
    previous_row=now_row;
    prevoius_column=now_column;
    error_place=false;
}

void game::pieces_replace()
{
    delete P[now_row][now_column];
    P[now_row][now_column]=P[previous_row][prevoius_column];
    P[previous_row][prevoius_column]=nullptr;
    P[now_row][now_column]->move(Board::column_convert_x(now_column), Board::row_convert_y(now_row));
    is_lock=false;
    P[now_row][now_column]->remove_lock();
    attack=(attack==TYPE::RED) ? TYPE::BLACK : TYPE::RED;
    error_place=false;
}
