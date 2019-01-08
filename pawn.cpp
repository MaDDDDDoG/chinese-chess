#include "pawn.h"

Pawn::Pawn(QWidget *parent, int x, int y, TYPE type)
    :Pieces(parent, x, y, type)
{
    //set initial picture
    remove_lock();
}

//set lock picture.
void Pawn::lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_pawn_touch.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_pawn_touch.png");
        this->setPixmap(pix);
    }
}

//remove lock picture.
void Pawn::remove_lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_pawn.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_pawn.png");
        this->setPixmap(pix);
    }
}

//Can the piece move to the click point?
bool Pawn::go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)
{
    if(pr==nr&&(pc-nc==1||pc-nc==-1)){  //move horizontally.
        if(type==TYPE::BLACK){
            return (pr>4) ? true : false;  //cross river.
        }else{
            return (pr<5) ? true : false;  //cross river.
        }
    }else if(pc==nc){  //move vertically.
        if(type==TYPE::BLACK){
            return (pr-nr==-1) ? true : false;  //go ahead.
        }else{
            return (pr-nr==1) ? true : false;  //go ahead.
        }
    }else{
        return false;
    }
}
