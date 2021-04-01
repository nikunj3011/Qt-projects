#ifndef CARDQPUSHBUTTON_H
#define CARDQPUSHBUTTON_H
#include <QPushButton>

class CardButton : public QPushButton
{


public:
    CardButton(int i) : QPushButton(), index(i){}

    int getIndex() const {return index;}

private:
    int index;
};

#endif // CARDQPUSHBUTTON_H

