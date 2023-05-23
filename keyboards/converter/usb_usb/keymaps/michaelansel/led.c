typedef struct {
    bool layers[16];
    struct {
        bool ctrl;
        bool opt;
        bool cmd;
        bool shft;
    } osm;
} my_indicators_t;
my_indicators_t my_indicators;

// Desired state of physical LEDs
led_t physical_led_state;

static uint16_t my_indicators_blink_timer;
void show_my_indicators(void) {
    led_t leds = physical_led_state;
    bool blink_time = timer_elapsed(my_indicators_blink_timer) > 200;

    // Show layers unless there is an OSM active, and then blink to indicate OSM active
    if (my_indicators.osm.ctrl) {
        if (blink_time) leds.caps_lock = !leds.caps_lock;
    } else {
        leds.caps_lock = (my_indicators.layers[SYM]);
    }

    if (my_indicators.osm.cmd) {
        if (blink_time) leds.num_lock = !leds.num_lock;
    } else {
        leds.num_lock = (my_indicators.layers[NAV]);
    }

    if (my_indicators.osm.shft) {
        if (blink_time) leds.scroll_lock = !leds.scroll_lock;
    } else {
        leds.scroll_lock = (my_indicators.layers[UNI]);
    }

    // If we blinked, reset the timer
    if (blink_time) my_indicators_blink_timer = timer_read();
    physical_led_state = leds;
    led_update_ports(leds);
}
