#include "splashkit.h"
#include "power_up.h"

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    power_up_kind kind = static_cast<power_up_kind>(rnd(6));
    result.kind = kind;
    result.power_up_sprite = create_sprite(power_up_bitmap(kind));
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    return result;
}

bitmap power_up_bitmap(power_up_kind kind)
{
    switch (kind)
    {
    case SHIELD:
        return bitmap_named("shield");
    case POWER:
        return bitmap_named("power");
    case POTION:
        return bitmap_named("potion");
    case FUEL:
        return bitmap_named("fuel");
    case DROPS:
        return bitmap_named("drops");
    case DIAMOND:
        return bitmap_named("diamond");
    case STAR:
        return bitmap_named("star");
    case CASH:
        return bitmap_named("cash");
    case NOS:
        return bitmap_named("nos");
    case LEVEL:
        return bitmap_named("level");
    case BULLET:
        return bitmap_named("bullet");
    case COIN:
        return bitmap_named("coin");
    case BATTERY:
        return bitmap_named("battery");
    case HEART:
        return bitmap_named("heart");
    case MUSCLE:
        return bitmap_named("muscle");
    case TIME:
        return bitmap_named("time");
    }
    return nullptr;
}

void draw_power_up(const power_up_data& power_up)
{
    draw_sprite(power_up.power_up_sprite);
}

void update_power_up(power_up_data& power_up)
{
    update_sprite(power_up.power_up_sprite);
}
