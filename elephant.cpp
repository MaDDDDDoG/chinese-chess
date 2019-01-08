#include "elephant.h"

Elephant::Elephant(QWidget *parent, int x, int y, TYPE type)
    :Pieces(parent, x, y, type)
{
    //set initial picture
    remove_lock();
}

//set lock picture.
void Elephant::lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_elephant_touch.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_elephant_touch.png");
        this->setPixmap(pix);
    }
}

//remove lock picture.
void Elephant::remove_lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_elephant.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_elephant.png");
        this->setPixmap(pix);
    }
}

//Can the piece move to the click point?
bool Elephant::go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)
{
    /*
     *        a---b     E=Elephant
     *         P-P      P=any Pieces
     *          E       a,b,c,d=destination
     *         P-P
     *        c---d
     */
    if((type==TYPE::BLACK&&nr>4)||(type==TYPE::RED&&nr<5)){  //can't cross river.
        return false;
    }else if(nr==pr-2&&nc==pc-2&&B[pr-1][pc-1]==nullptr){  //a
        return true;
    }else if(nr==pr+2&&nc==pc-2&&B[pr+1][pc-1]==nullptr){  //c
        return true;
    }else if(nr==pr-2&&nc==pc+2&&B[pr-1][pc+1]==nullptr){  //b
        return true;
    }else if(nr==pr+2&&nc==pc+2&&B[pr+1][pc+1]==nullptr){  //d
        return true;
    }else{
        return false;
    }
}
