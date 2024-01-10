#include "splashkit.h"
#include "player.h"
#include "power_up.h"


/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

void draw_hud(const player_data& player)
{
    // Draw the background of the HUD
    fill_rectangle(COLOR_GRAY, 50, 50, 350, 100);

    // Draw the player's location
    draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_RED, 80, 100, option_to_screen());

    // Draw the player's score
    draw_text("SCORE: " + to_string(player.score), COLOR_RED, 80, 80, option_to_screen());


     // Draw the fuel gauge
    int fuelWidth = static_cast<int>(200 * player.fuel_pct);
    draw_text("FUEL", COLOR_BEIGE, 100, 160);
    load_bitmap("fuel_empty","bar_white_fill.png");
    draw_bitmap("fuel_empty", 100, 170, option_to_screen());
    load_bitmap("energy","blue_bar_bubbles.png");
    draw_bitmap("energy", 40, 170, option_to_screen());

    // Health Gauge
    draw_text("HEALTH", COLOR_BEIGE, 100, 210);
    load_bitmap("health_empty","bar_white_fill.png");
    draw_bitmap("health_empty", 100, 220, option_to_screen());
    load_bitmap("healthful","purple_bar.png");
    draw_bitmap("healthful", 40, 220, option_to_screen());

    load_bitmap("fuel_full", "orange_bar.png");
    //draw_bitmap("fuel_full", 20, 60, option_part_bmp(0, 0, fuelWidth, bitmap_height("fuel_full")), option_to_screen());

    // Refresh the screen
    refresh_screen();
}

/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 800, 800);
    load_resources();

    player_data player;
    player = new_player();

    //adding power up near the player
    power_up_data power_up = new_power_up(sprite_x(player.player_sprite), sprite_y(player.player_sprite));

    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        update_player(player);
        update_power_up(power_up);

        // Redraw everything
        clear_screen(COLOR_BLACK);

        //draw the hud elements
        draw_hud(player);

        //draw power up
        draw_power_up(power_up);

        // as well as the player who can move
        draw_player(player);
        
        refresh_screen(60);
    }

    return 0;
}
