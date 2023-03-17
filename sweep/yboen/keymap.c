#include QMK_KEYBOARD_H

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

enum layer_number {
  _QWERTY = 0,
  _SYM,
  _NAV,
  _FN
};
// left and right are flipped, right hand is reflected left to right
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( 
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,
    K_A,     K_S,     K_D,     K_F,     KC_G,            KC_H,    K_J,   K_K,     K_L,     K_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,
                              MO_SYM,  K_SPC,           KC_SPC,  MO_NAV
  ),
  [_SYM] = LAYOUT( 
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, XXXXXXX,         XXXXXXX, KC_TILD, KC_CIRC, XXXXXXX, KC_DQUO,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV ,         KC_PLUS, KC_MINS, KC_ASTR, KC_PERC, KC_QUOT,
    XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,         KC_AMPR, KC_EQL,  KC_UNDS, KC_BSLS, KC_PIPE,
                               _______, _______,         _______, _______ 
  ),
  [_NAV] = LAYOUT( 
    KC_1, 	 KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
    KC_CAPS, KC_HOME, KC_END,  KC_PGUP, XXXXXXX,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
    KC_LGUI, KC_LALT, KC_LCTL, KC_PGDN, KC_LSFT,         XXXXXXX, KC_ESC,  KC_TAB,  KC_INS,  KC_DEL,
                               _______, KC_ENT ,         _______, _______
  ),
  [_FN] = LAYOUT( 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    XXXXXXX, XXXXXXX, CGL,     CGR,     KC_VOLU,         XXXXXXX, XXXXXXX, KC_MUTE, KC_F11,  KC_F12,
    UND,     CUT,     CPY,     PST,     KC_VOLD,         XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,
                               _______, _______,         _______, _______
  )
};

#ifdef COMBO_ENABLE
enum combo_events {
    PEM_EMAIL,
    WEM_EMAIL,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM pem_email_combo[] = {KC_E, KC_R, KC_M, COMBO_END};
const uint16_t PROGMEM wem_email_combo[] = {KC_W, KC_E, KC_M, COMBO_END};
combo_t key_combos[] = {
    [PEM_EMAIL] = COMBO_ACTION(pem_email_combo),
    [WEM_EMAIL] = COMBO_ACTION(wem_email_combo)
};
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case PEM_EMAIL:
            if (pressed) {
                SEND_STRING("brianyu0717@msn.com");
            }
            break;
        case WEM_EMAIL:
            if (pressed) {
                SEND_STRING("brian.yu@troweprice.com");
            }
            break;
    }
}
#endif
