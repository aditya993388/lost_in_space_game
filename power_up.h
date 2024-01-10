#ifndef POWER_UP_H
#define POWER_UP_H

#include "splashkit.h"

enum power_up_kind
{
    SHIELD,
    POWER,
    POTION,
    FUEL,
    DROPS,
    DIAMOND,
    STAR,
    CASH,
    NOS,
    LEVEL,
    BULLET,
    COIN,
    BATTERY,
    HEART,
    MUSCLE,
    TIME
};

struct power_up_data
{
    power_up_kind kind;
    sprite power_up_sprite;
};

power_up_data new_power_up(double x, double y);

bitmap power_up_bitmap(power_up_kind kind);

void draw_power_up(const power_up_data& power_up);

void update_power_up(power_up_data& power_up);

#endif 
