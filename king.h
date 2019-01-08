#ifndef KING_H
#define KING_H
#include "pieces.h"

class King:public Pieces
{
    Q_OBJECT

public:
    explicit King(QWidget *parent=0, int x=0, int y=0, TYPE type=TYPE::BLACK);
    virtual void lock() override;
    virtual void remove_lock() override;
    virtual bool go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B) override;
};

#endif // KING_H
