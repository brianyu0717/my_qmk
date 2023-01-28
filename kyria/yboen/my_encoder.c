#include "my_encoder.h"

// encoder actions

void encoder_action_paging(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
}

void encoder_action_ms_up_down(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_WH_D);
    } else {
        tap_code(KC_WH_U);
    }
}

void encoder_action_volume(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

void encoder_action_move_desktop(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(G(KC_RIGHT)));
    } else {
        tap_code16(C(G(KC_LEFT)));
    }
}

// utils

void encoder_utils_init(void) {
    encoder_left_mode  = ENC_MODE_VOLUME;
    encoder_right_mode = ENC_MODE_PAGING;
}

encoder_mode_t get_encoder_mode(bool left) {
    if (left) {
        return encoder_left_mode;
    } else {
        return encoder_right_mode;
    }
}

void set_encoder_mode(bool left, encoder_mode_t mode) {
    if (left) {
        encoder_left_mode = mode;
    } else {
        encoder_right_mode = mode;
    }
}

void cycle_encoder_mode(bool left, bool reverse) {
    encoder_mode_t mode = get_encoder_mode(left);
    if (reverse) {
        mode = (mode == 0) ? (_ENC_MODE_LAST - 1) : (mode - 1);
    } else {
        mode = (mode == (_ENC_MODE_LAST - 1)) ? 0 : (mode + 1);
    }
    set_encoder_mode(left, mode);
}

void encoder_action(encoder_mode_t mode, uint8_t clockwise) {
    switch (mode) {
        case ENC_MODE_VOLUME:
            encoder_action_volume(clockwise);
            break;
        case ENC_MODE_MSCROLL_UP_DOWN:
            encoder_action_ms_up_down(clockwise);
            break;
        case ENC_MODE_PAGING:
            encoder_action_paging(clockwise);
            break;
        case ENC_MODE_MV_DESKTOP:
            encoder_action_move_desktop(clockwise);
            break;
        default:
            encoder_action_volume(clockwise);
    }
}
