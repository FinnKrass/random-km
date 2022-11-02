
//This section for me is in a seperate .c file than my keymap along with my other
//functions, you should do this too

__attribute__((weak)) bool process_record_kb(uint16_t keycode, keyrecord_t *record) { return true; }

uint16_t tap_taplong_timer;
// tap_taplong feature
inline void tap_taplong(uint16_t kc1, uint16_t kc2, keyrecord_t *record) {
  if (record->event.pressed) {
    tap_taplong_timer = timer_read();
  } else {
    if (timer_elapsed(tap_taplong_timer) > TAPPING_TERM) {
      tap_code16(kc2);
    } else {
      tap_code16(kc1);
    }
  }
}

// ^ This is not my function, I found it in the repo from ericgebhart
// Include "#define TAPPING_TERM 175" in your config.h with 175 being
// in milliseconds
// This is the section in my keymap.c, ofc enumerate keycode n then yeah happy days

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_keymap(keycode, record)) return false;
  switch (keycode) {

    case KC_CCCV:
      tap_taplong(LCTL(KC_C), LCTL(KC_V), record);       //the first kc will be tap, the second will be hold
      break;
    }
    return true;
}
