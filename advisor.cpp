#include "advisor.h"

Advisor::Advisor(QWidget *parent, int x, int y, TYPE type)
    :Pieces(parent, x, y, type)
{
    //set initial picture
    remove_lock();
}

//set lock picture.
void Advisor::lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_advisor_touch.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_advisor_touch.png");
        this->setPixmap(pix);
    }
}

//remove lock picture.
void Advisor::remove_lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_advisor.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_advisor.png");
        this->setPixmap(pix);
    }
}

//Can the piece move to the click point?
bool Advisor::go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)
{
    if(nc<3||nc>5||(type==TYPE::BLACK&&nr>2)||(type==TYPE::RED&&nr<7)){
        return false;
    }else if(nr==pr-1&&nc==pc-1){
        return true;
    }else if(nr==pr-1&&nc==pc+1){
        return true;
    }else if(nr==pr+1&&nc==pc-1){
        return true;
    }else if(nr==pr+1&&nc==pc+1){
        return true;
    }else{
        return false;
    }
}
