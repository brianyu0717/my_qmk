#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    ENC_MODE_VOLUME = 0,
    ENC_MODE_MV_DESKTOP,
    ENC_MODE_PAGING,
    ENC_MODE_MSCROLL_UP_DOWN,
    _ENC_MODE_LAST  // Do not use, except for looping through enum values
} encoder_mode_t;

encoder_mode_t encoder_left_mode;
encoder_mode_t encoder_right_mode;

// encoder actions

void encoder_action_paging(uint8_t clockwise);

void encoder_action_ms_up_down(uint8_t clockwise);

void encoder_action_volume(uint8_t clockwise);

void encoder_action_move_desktop(uint8_t clockwise);

// utils

void encoder_utils_init(void);

encoder_mode_t get_encoder_mode(bool left);

void set_encoder_mode(bool left, encoder_mode_t mode);

void cycle_encoder_mode(bool left, bool reverse);

void encoder_action(encoder_mode_t mode, uint8_t clockwise);
