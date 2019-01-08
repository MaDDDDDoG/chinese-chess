#ifndef PIECES_H
#define PIECES_H
#include <QLabel>
#include "type.h"

class Pieces:public QLabel
{
    Q_OBJECT

public:
    explicit Pieces(QWidget *parent=0, int x=0, int y=0, TYPE type=TYPE::BLACK);
    virtual ~Pieces();
    virtual void lock()=0;
    virtual void remove_lock()=0;
    virtual bool go_here(int pr, int pc, int nr, int nc, const std::array<std::array<Pieces *, 9>, 10> &B)=0;
    TYPE gettype() const;
protected:
    TYPE type;
};
#endif // PIECES_H
