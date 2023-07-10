typedef struct {
    bool layers[16];
    struct {
        bool ctrl;
        bool opt;
        bool cmd;
        bool shft;
    } osm;
    int8_t macro_recording;
} my_indicators_t;
my_indicators_t my_indicators;

// Desired state of physical LEDs
led_t physical_led_state;

static uint16_t my_indicators_blink_timer;
// Modes:
// - Indicate layer active with solid LEDs: SYM, NAV, UNI
// - Indicate OSM active with medium blink LEDs: ctrl, cmd, shift (no pattern for optio)
// - Indicate recording active with fast blink LEDs: all LEDs
void show_my_indicators(void) {
    led_t leds = physical_led_state;
    int8_t blink_period = my_indicators.macro_recording > 0 ? 100 : 200; // go extra fast when recording a macro
    bool blink_time = timer_elapsed(my_indicators_blink_timer) > blink_period;

    // Show layers unless there is an OSM active, and then blink to indicate OSM active
    if (my_indicators.osm.ctrl || my_indicators.macro_recording) {
        if (blink_time) leds.caps_lock = !leds.caps_lock;
    } else {
        leds.caps_lock = (my_indicators.layers[SYM]) || (my_indicators.layers[NUM]);
    }

    if (my_indicators.osm.cmd || my_indicators.macro_recording) {
        if (blink_time) leds.num_lock = !leds.num_lock;
    } else {
        leds.num_lock = (my_indicators.layers[NAV]) || (my_indicators.layers[NUM]);
    }

    if (my_indicators.osm.shft || my_indicators.macro_recording) {
        if (blink_time) leds.scroll_lock = !leds.scroll_lock;
    } else {
        leds.scroll_lock = (my_indicators.layers[UNI]) || (my_indicators.layers[NUM]);
    }

    // If we blinked, reset the timer
    if (blink_time) my_indicators_blink_timer = timer_read();
    physical_led_state = leds;
    led_update_ports(leds);
}
