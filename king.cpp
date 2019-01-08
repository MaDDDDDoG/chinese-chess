#include "king.h"

King::King(QWidget *parent, int x, int y, TYPE type)
    :Pieces(parent, x, y, type)
{
    //set initial picture
    remove_lock();
}

//set lock picture.
void King::lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_king_touch.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_king_touch.png");
        this->setPixmap(pix);
    }
}

//remove lock picture.
void King::remove_lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_king.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_king.png");
        this->setPixmap(pix);
    }
}

//Can the piece move to the click point?
bool King::go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)
{
    if(pr==nr&&(pc-nc==1||pc-nc==-1)){  //move horizontally.
        return (3<=nc&&nc<=5) ? true : false;  //at palace.
    }else if(pc==nc&&(pr-nr==1||pr-nr==-1)){  //move vertically.
        if(type==TYPE::BLACK){
            return (nr<=2) ? true : false;  //at palace.
        }else{
            return (nr>=7) ? true : false;  //at palace.
        }
    }else{
        return false;
    }
}
