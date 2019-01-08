#include "pieces.h"

//initialize pieces.
Pieces::Pieces(QWidget *parent, int x, int y, TYPE type)
    :QLabel(parent)
{
    this->type=type;
    //set location.
    this->setGeometry(65*x+70, 65*y+80, 60, 60);
}

TYPE Pieces::gettype() const
{
    return type;
}
Pieces::~Pieces()
{

}
