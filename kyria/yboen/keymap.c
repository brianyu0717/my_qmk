#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "my_encoder.h"

#define CGL C(G(KC_LEFT))
#define CGR C(G(KC_RIGHT))
#define UND C(KC_Z)
#define CPY C(KC_C)
#define CUT C(KC_X)
#define PST C(KC_V)
#define K_A MT(MOD_LGUI, KC_A)
#define K_S MT(MOD_LALT, KC_S)
#define K_D MT(MOD_LCTL, KC_D)
#define K_F MT(MOD_LSFT, KC_F)
#define K_J MT(MOD_LSFT, KC_J)
#define K_K MT(MOD_LCTL, KC_K)
#define K_L MT(MOD_LALT, KC_L)
#define K_SCLN MT(MOD_LGUI, KC_SCLN)
#define MO_SYM MO(_SYM)
#define MO_NAV MO(_NAV)
#define MO_FN MO(_FN)
#define K_SPC LT(_FN, KC_SPC)
// kyria only
#define K_ESC MT(MOD_LALT, KC_ESC)
#define TO_NUM TO(_NUMPAD)

#ifdef COMBO_ENABLE
enum combo_events {
    MOUSE_MODE,
    EM_EMAIL,
    MIDDLE_CLICK,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM to_mouse_mode[] = {KC_MINS, KC_QUOT, COMBO_END};
const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM middle_click_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};
combo_t key_combos[] = {
    [MOUSE_MODE] = COMBO_ACTION(to_mouse_mode),
    [EM_EMAIL] = COMBO_ACTION(email_combo),
    [MIDDLE_CLICK] = COMBO_ACTION(middle_click_combo),
};
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case MOUSE_MODE:
            if (pressed) {
                if (IS_LAYER_ON(_QWERTY)) {
                    layer_move(_NAV);
                } else {
                    layer_clear();
                }
            }
            break;
        case EM_EMAIL:
            if (pressed) {
                SEND_STRING("brianyu0717@msn.com");
            }
            break;
        case MIDDLE_CLICK:
            if (pressed) {
                register_code(KC_BTN3);
            } else {
                unregister_code(KC_BTN3);
            }
            break;
    }
}
#endif



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
      K_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_CAPS,
      KC_LCTL, K_A,     K_S,     K_D,     K_F,     KC_G,                                           KC_H,    K_J,     K_K,     K_L,     K_SCLN,  KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TO_NUM,  KC_MEH,     KC_DEL,  KC_INS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 ENC_L,   KC_LGUI, MO_SYM,  K_SPC,   KC_HOME,    KC_END,  KC_SPC,  MO_NAV,  KC_TAB,  ENC_R
    //   ENC_MODE_L,  KC_LGUI, LT(_NAV, KC_ENT),    KC_SPC, LT(_FUNC, KC_HOME),         LT(_SYM, KC_END), KC_BSPC, LT(_NAV, KC_ENT),  KC_TAB, ENC_MODE_R
    ),
    [_SYM] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, XXXXXXX,                                        XXXXXXX, KC_TILD, KC_CIRC, XXXXXXX, KC_DQUO, _______,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                         KC_PLUS, KC_MINS, KC_ASTR, KC_PERC, KC_QUOT, _______,
      _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, _______, _______,    _______, _______, KC_AMPR, KC_EQL,  KC_UNDS, KC_BSLS, KC_PIPE, _______,
                                 _______, _______, _______, KC_ENT , _______,    _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_CAPS, KC_HOME, KC_END,  KC_PGUP, XXXXXXX,                                                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BTN2,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_PGDN, KC_LSFT,    _______, _______,      _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, TO(_QWERTY), KC_BTN1,
                                          _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
    ),
    [_FUNC] = LAYOUT(
      KC_ESC , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, _______, _______, C(G(KC_LEFT)), C(G(KC_RIGHT)), _______,                                      _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, C(KC_X), C(KC_C), C(KC_V), _______,      TO(_RGB), _______,                _______, _______, _______, _______, _______, _______, _______, _______,
                                _______,  C(S(KC_H)), C(A(KC_U)), _______, _______,          _______, _______, _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
      _______, _______, _______, KC_UP, _______, _______,                                           KC_DLR,  KC_7, KC_8, KC_9, KC_PLUS, KC_NLCK,
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                                         KC_CIRC, KC_4, KC_5, KC_6, KC_MINS, KC_SLSH,
      _______, _______, _______, KC_LPRN, KC_RPRN, _______, TO(_QWERTY), _______, _______, KC_DOT , KC_0, KC_1, KC_2, KC_3, KC_ASTR, KC_EQL ,
                                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
    [_RGB] = LAYOUT(
      _______, _______, _______, _______, _______, _______ ,                                           _______, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD ,                                           _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, TO(_QWERTY), _______,   _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______ , _______    , _______,   _______, _______, _______, _______, _______
    ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

//void render_logo(void) {
    // Credit to https://joric.github.io/qle to help generate the code below and method from tessachka's keymap
    // use the "raw" section to generate the numbers array
//    static const char PROGMEM my_logo[] =
        // my_logo_2_bubble_128x24
//        {
//            0,  192, 48,  24, 136, 72, 72,  136, 136, 24, 16,  32,  224, 32, 16, 136, 72,  72, 200, 8, 16, 48,  248, 136, 136, 8, 8,   8,   8, 8, 152, 240, 48,  24,  8,   8,   8,   16,  48,  208, 16,  16,  224, 0, 224, 48,  16, 48, 224, 2,   242, 12, 232, 44,  168, 108, 168, 172, 40,  236, 10, 242, 0, 0, 224, 32,  176, 144, 216, 200, 236, 246, 121, 61,  29, 57, 50, 118, 228, 228, 204, 200, 136, 136, 152, 24, 12, 228, 228, 228, 236, 232, 232, 232, 104, 8,  8,  140, 196, 244, 116, 52, 4,  4,  28, 176, 32, 32, 248, 4, 50, 250, 26, 154, 154, 250, 250, 154, 154, 154, 26, 250, 250, 2,  250, 14, 0, 0,  0,  255, 128, 0,  97, 242, 146, 146, 163, 96, 0,   3,   247, 248, 0,   1,  66, 226, 193, 136, 14, 51, 65, 193, 35, 62, 0,  0,  63, 33, 225, 63, 192, 0,  15, 137, 207, 128, 0,  15, 248, 0,   1,  227, 199, 128, 0,  0,  255, 0,   255, 0,  255, 236, 133, 252, 247, 148, 231, 255, 0,   255, 0,  0,
//            15, 248, 129, 3,  59,  57, 187, 251, 123, 59, 255, 255, 63,  59, 59, 251, 185, 59, 63,  7, 7,  231, 59,  9,   1,   1, 255, 255, 0, 3, 255, 255, 119, 119, 119, 119, 119, 119, 119, 199, 255, 127, 7,   0, 128, 192, 56, 63, 240, 253, 61,  55, 51,  245, 253, 61,  48,  191, 179, 192, 3,  254, 0, 0, 0,   112, 99,  6,   100, 36,  4,   100, 4,   102, 98, 2,  99, 36,  68,  4,   84,  39,  16,  1,   99,  68, 36, 4,   38,  86,  34,  2,   82,  50,  3,   16, 99, 4,   84,  51,  16,  67, 36, 68, 35, 68,  4,  71, 32,  7, 68, 36,  71, 0,   73,  10,  102, 34,  70,  98,  6,  66,  38,  66, 38,  73, 8, 32, 46, 57,  32,  46, 47, 39,  99,  65,  64,  64, 223, 191, 128, 192, 112, 99, 71, 79,  71,  70,  96, 33, 63, 48,  96, 68, 95, 79, 64, 64, 95,  79, 110, 46, 46, 46,  46,  110, 78, 79, 79,  110, 32, 47,  39,  49,  46, 47, 47,  110, 78,  78, 95,  93,  92,  60,  63,  59,  121, 121, 120, 59,  24, 0,
//        };
//    oled_write_raw_P(my_logo, sizeof(my_logo));

    // oled_advance_page(false); // advances the cursor for a few lines past the logo, otherwise we end up drawing on top of it...
//    oled_advance_page(false);
//    oled_advance_page(false);
//    oled_advance_page(false);
//}

void render_layer(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Func\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NumPad\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

void render_leds(void) {
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void render_encoder(encoder_mode_t mode) {
    switch (mode) {
        case ENC_MODE_VOLUME:
            oled_write_P(PSTR("Volume\n"), false);
            break;
        case ENC_MODE_MSCROLL_UP_DOWN:
            oled_write_P(PSTR("MsWheel U/D\n"), false);
            break;
        case ENC_MODE_PAGING:
            oled_write_P(PSTR("Page U/D\n"), false);
            break;
        case ENC_MODE_MV_DESKTOP:
            oled_write_P(PSTR("Desktop L/R\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

//void render_rgb_status(void) {
//    char snum[8];
//    uitoa(rgblight_get_mode(), snum, sizeof(snum));
//    oled_write_P(PSTR("RGB: "), false);
//    oled_write(snum, false);
//}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
//        render_logo();
        render_layer();
        render_leds();
        oled_write_P(PSTR("L-Enc: "), false);
        render_encoder(encoder_left_mode);
        oled_write_P(PSTR("R-Enc: "), false);
        render_encoder(encoder_right_mode);
//        render_rgb_status();
    } else {
        oled_write_P(PSTR("Symbols\n"), false);
        oled_write_P(PSTR("L1 ! @ { }\n"), false);
        oled_write_P(PSTR("L2 # $ ( ) `~\n"), false);
        oled_write_P(PSTR("L3 _ ^ [ ]\n"), false);
        oled_write_P(PSTR("R2 + - * %% \\|\n"), false);
        oled_write_P(PSTR("R3 & =+\n"), false);
    }
    return false;
}
#endif


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
     if (index == 0) {
        encoder_action(get_encoder_mode(true), clockwise);
    }
    else if (index == 1) {
        encoder_action(get_encoder_mode(false), clockwise);
    }
    return false;
}

void matrix_init_user(void) {
    encoder_utils_init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_MODE_L:
            if (record->event.pressed) {
                cycle_encoder_mode(true, false);
            }
            break;
        case ENC_MODE_R:
            if (record->event.pressed) {
                cycle_encoder_mode(false, false);
            }
            break;
    }
    return true;
}
#endif


#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 20, HSV_CORAL} );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(nav_layer);
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _NAV));
    return state;
}
#endif