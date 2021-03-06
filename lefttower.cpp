#include "lefttower.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QLineF>
#include<QGraphicsScene>
#include<QTimer>
#include"arrow.h"
#include"scene.h"
#include"luffy2.h"
#include"zoro2.h"
#include"bread2.h"
#include"curry2.h"
#include"din2.h"
#include"bo2.h"
#include"totoro2.h"
#include"lulumi2.h"

LeftTower::LeftTower(QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    hp = 25;
    bar = new QProgressBar();
    bar->setValue(hp/25*100);
    bar->show();
    // Create points vector
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3) << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // Scale points
    int SCALE_FACTOR = 90;
    for(size_t i=0,n=points.size();i<n;++i )
        points[i] *= SCALE_FACTOR;

    // Create the QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->QAbstractGraphicsShapeItem::setPen(QPen(Qt::transparent));

    //Move the polygon
    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+175,y()+85);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());


    QTimer * timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer1->start(900);
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(blood()));
    timer2->start(1000);

    damagedsound = new QMediaPlayer();
    damagedsound->setMedia(QUrl("qrc:/sound/snd/Punch.mp3"));
    damagedsound->setVolume(50);

    destroyedsound = new QMediaPlayer();
    destroyedsound->setMedia(QUrl("qrc:/sound/snd/destroy.mp3"));
    destroyedsound->setVolume(500);

    swordsound = new QMediaPlayer();
    swordsound->setMedia(QUrl("qrc:/sound/snd/sword.mp3"));
    swordsound->setVolume(250);

}

double LeftTower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void LeftTower::attack()
{
    Arrow * arrow = new Arrow();
    arrow->setPos(x()+175,y()+80);

    QLineF ln(QPointF(x()+175,y()+80),QPointF(attack_destn.x()+50,attack_destn.y()+50));
    int angle = ln.angle();

    arrow->setRotation(-angle);
    this->scene()->addItem(arrow);

}

void LeftTower::acquire_target()
{
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if(colliding_items.size()<=4)
    {
        has_target = false;
        return;
    }

    double closest_dist = 500;
    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Luffy2 * luffy = dynamic_cast<Luffy2 *>(colliding_items[i]);
        {
            if(luffy)
            {   double this_dist = distanceTo(luffy);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Totoro2 * totoro = dynamic_cast<Totoro2 *>(colliding_items[i]);
        {
            if(totoro)
            {
                double this_dist = distanceTo(totoro);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Zoro2 * zoro2 = dynamic_cast<Zoro2 *>(colliding_items[i]);
        {
            if(zoro2)
            {
                double this_dist = distanceTo(zoro2);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Bread2 * bread2 = dynamic_cast<Bread2 *>(colliding_items[i]);
        {
            if(bread2)
            {
                double this_dist = distanceTo(bread2);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Curry2 * curry2 = dynamic_cast<Curry2 *>(colliding_items[i]);
        {
            if(curry2)
            {
                double this_dist = distanceTo(curry2);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Din2 * din2 = dynamic_cast<Din2 *>(colliding_items[i]);
        {
            if(din2)
            {
                double this_dist = distanceTo(din2);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Bo2 * bo2 = dynamic_cast<Bo2 *>(colliding_items[i]);
        {
            if(bo2)
            {
                double this_dist = distanceTo(bo2);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();

    for(size_t i =0, n = colliding_items.size(); i<n ; ++i)
    {
        Lulumi2 * lulumi2 = dynamic_cast<Lulumi2 *>(colliding_items[i]);
        {
            if(lulumi2)
            {
                double this_dist = distanceTo(lulumi2);
                if(this_dist<closest_dist)
                {
                    closest_dist = this_dist;
                    closest_pos = colliding_items[i]->pos();
                    has_target = true;
                }
            }
        }
    }
    attack_destn = closest_pos;
    attack();
}\

void LeftTower::blood()
{
    QList<QGraphicsItem *> reaching_items = this->collidingItems();
    if(reaching_items.size()<=1)
    {
        damaged = false;
        return;
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Luffy2 * luffy = dynamic_cast<Luffy2 *>(reaching_items[i]);
        if(luffy)
        {
            hp -= 3;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Zoro2 * zoro2 = dynamic_cast<Zoro2 *>(reaching_items[i]);
        if(zoro2)
        {
             hp -= 3;
             bar->setValue(hp*4);
             swordsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Bread2 * bread2 = dynamic_cast<Bread2 *>(reaching_items[i]);
        if(bread2)
        {
            hp -= 4;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Curry2 * curry2 = dynamic_cast<Curry2 *>(reaching_items[i]);
        if(curry2)
        {
            hp -= 4;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Din2 * din2 = dynamic_cast<Din2 *>(reaching_items[i]);
        if(din2)
        {
            hp -= 2;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Totoro2 * totoro = dynamic_cast<Totoro2 *>(reaching_items[i]);
        if(totoro)
        {
            hp -= 5;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    for(size_t i = 0, n = reaching_items.size(); i<n; ++i)
    {
        Lulumi2 * lulumi2 = dynamic_cast<Lulumi2 *>(reaching_items[i]);
        if(lulumi2)
        {
            hp -= 4;
            bar->setValue(hp*4);
            damagedsound->play();
        }
    }

    if(hp<=0)
    {
        destroyedsound->play();
        bar->setValue(hp*4);
        scene()->removeItem(this);
        delete this;
        return;
    }
}

