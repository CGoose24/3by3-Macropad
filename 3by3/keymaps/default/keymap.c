// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "config_led.h"


enum custom_keycodes
{
    CLIP = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
        
    BASIC DIAGRAM -- parentheses () represent microcontroller pin of each row/column

         COL1 COL2 COL3
          (2) (14) (16)
        +----+----+----+
     R1 | Q1 | Q2 | Q3 |   <- (7)
        +----+----+----+
     R2 | Q4 | Q5 | Q6 |   <- (8)
        +----+----+----+
     R3 | Q7 | Q8 | Q9 |   <- (9)
        +----+----+----+

    KEY FUNCTIONALITY DIAGRAM
        ┌──────┬────────────┬────────┐              ┌──────┬────────┬────────┐              
        │ Clip │     A      │    B   │              │ BOOT │  Val↑  │  Val↓  │
        ├──────┼────────────┼────────┤    hold      ├──────┼────────┼────────┤
        │ Prev │ Pause/Play │  Next  │  ------->    │ LED↑ │ ON/OFF │  LED↓  │
        ├──────┼────────────┼────────┤  (SWITCH)    ├──────┼────────┼────────┤ 
        │   7  │     8      │ SWITCH │              │ Hue↑ │  Hue↓  │ *null* │ 
        └──────┴────────────┴────────┘              └──────┴────────┴────────┘
     */

    [0] = LAYOUT(
        CLIP,   KC_P1,   KC_P2, 
        KC_MEDIA_PREV_TRACK,   KC_MEDIA_PLAY_PAUSE,   KC_MEDIA_NEXT_TRACK,
        KC_P7,   KC_P8,  MO(1)
    ),
    
    [1] = LAYOUT(
        QK_BOOT,   RM_VALD,   RM_VALU, 
        RM_PREV,   RM_TOGG,   RM_NEXT, 
        RM_HUED,   RM_HUEU,   KC_NO
    )
    
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CLIP:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_F10);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_F10);
            }
            return false;
    }
    return true;
}

