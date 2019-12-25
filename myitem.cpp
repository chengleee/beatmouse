#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include "handler.h"
#include <QCursor>

myitem::myitem()
{
    this->setPixmap(QPixmap(":/bg/hole.jpg"));
    this->start = false;
    this->mouse = false;
    this->setCursor(QCursor(QPixmap(":/mouse/cz.png")));
}

void myitem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/dcz.png")));
    if(this->isStart())
    {
        handler *hand = handler::getInstance();
        if(this->isMouse())
        {
            hand->addScore();
            this->setPixmap(QPixmap(":/mouse/beatmouse.jpg"));
            this->mouse = false;
        }
    }
}

void myitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/cz.png")));
}

void myitem::setMouse(bool mouse)
{
    this->mouse = mouse;
}

bool myitem::isMouse()
{
    return this->mouse;
}

void myitem::setStart(bool start)
{
    this->start = start;
}

bool myitem::isStart()
{
    return this->start;
}
