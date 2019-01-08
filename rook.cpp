#include "rook.h".h"

Rook::Rook(QWidget *parent, int x, int y, TYPE type)
    :Pieces(parent, x, y, type)
{
    //set initial picture
    remove_lock();
}

//set lock picture.
void Rook::lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_rook_touch.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_rook_touch.png");
        this->setPixmap(pix);
    }
}

//remove lock picture.
void Rook::remove_lock()
{
    if(type==TYPE::BLACK){
        QPixmap pix(":/image/image/black_rook.png");
        this->setPixmap(pix);
    }else{
        QPixmap pix(":/image/image/red_rook.png");
        this->setPixmap(pix);
    }
}

//Can the piece move to the click point?
bool Rook::go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)
{
    int mid_pieces=0, i;
    if(pr==nr&&pc!=nc){  //equal row and different column.
        //count pieces between now piece and previous piece.
        if(pc>nc){
            for(i=nc+1;i<pc;i++){
                if(B[nr][i]!=nullptr){mid_pieces++;}
            }
        }else{
            for(i=pc+1;i<nc;i++){
                if(B[nr][i]!=nullptr){mid_pieces++;}
            }
        }
    }else if(pc==nc&&pr!=nr){ //equal column and different row.
        //count pieces between now piece and previous piece.
        if(pr>nr){
            for(i=nr+1;i<pr;i++){
                if(B[i][nc]!=nullptr){mid_pieces++;}
            }
        }else{
            for(i=pr+1;i<nr;i++){
                if(B[i][nc]!=nullptr){mid_pieces++;}
            }
        }
    }else{
        return false;
    }

    return (mid_pieces==0) ? true : false;
}
