#pragma once

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 250

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 10000
  #define OLED_SCROLL_TIMEOUT 1000
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

#define RGBLIGHT_LAYERS

//current features disabled to save space
#define DISABLE_LEADER
#define NO_ACTION_ONESHOT

//less than 8 layers is used so can enable this to save space
#define LAYER_STATE_8BIT