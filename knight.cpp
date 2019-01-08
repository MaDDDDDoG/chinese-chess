#include "knight.h"

Knight::Knight(QWidget *parent, int x, int y, TYPE type)
    :Pieces(parent, x, y, type)
{
    //set initial picture
    remove_lock();
}

//set lock picture.
void Knight::lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_knight_touch.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_knight_touch.png");
        this->setPixmap(pix);
    }
}

//remove lock picture.
void Knight::remove_lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_knight.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_knight.png");
        this->setPixmap(pix);
    }
}

//Can the piece move to the click point?
bool Knight::go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)
{
    /*
     *          c-c     K=Knight
     *         a-P-b    P=any Pieces
     *          PKP     a,b,c,d=destination
     *         a-P-b
     *          d-d
     */
    if(nc==pc-2&&(nr==pr+1||nr==pr-1)&&B[pr][pc-1]==nullptr){  //a
        return true;
    }else if(nc==pc+2&&(nr==pr+1||nr==pr-1)&&B[pr][pc+1]==nullptr){  //b
        return true;
    }else if(nr==pr-2&&(nc==pc+1||nc==pc-1)&&B[pr-1][pc]==nullptr){  //c
        return true;
    }else if(nr==pr+2&&(nc==pc+1||nc==pc-1)&&B[pr+1][pc]==nullptr){  //d
        return true;
    }else{
        return false;
    }
}
