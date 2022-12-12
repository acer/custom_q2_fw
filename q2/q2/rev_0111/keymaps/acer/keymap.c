/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define EECONFIG_RGB_MATRIX (uint32_t *)28

enum layers{
    _0_MAC_BASE,
    _1_WIN_BASE,
    _2_MAC_MOD,
    _3_WIN_MOD,
    _4_FNS,
    _5_NUMPAD,
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    SIELP,
    PROTN,
    ACW,
    WORKE
};

#define KC_WAVE S(KC_GRV)   
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

// Key override
// ALT + ESC(keycap label) = ALT + ` (easier to windows from the same program on macos)
// const key_override_t esc_to_grv_key_override = ko_make_basic(MOD_MASK_ALT, KC_TAB, LCMD(KC_GRV));
// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
//    &esc_to_grv_key_override,
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_ESC):
        case LT(3, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0_MAC_BASE] = LAYOUT_ansi_67(
        KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        LT(2, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,           KC_UP,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                            MO(_4_FNS), KC_MPLY, TG(_5_NUMPAD),           KC_LEFT,  KC_DOWN, KC_RGHT),

    [_1_WIN_BASE] = LAYOUT_ansi_67(
        KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_MUTE,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,          KC_DEL,
        LT(3, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_HOME,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,            KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                            MO(_4_FNS), KC_MPLY, TG(_5_NUMPAD),       KC_LEFT, KC_DOWN, KC_RGHT),

    [_2_MAC_MOD] = LAYOUT_ansi_67(
        KC_WAVE,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_VOLD,  KC_VOLU,   KC_TRNS,          KC_TRNS,
        RGB_TOG,    RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
        KC_TRNS,    RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,             KC_CAPS,          KC_TRNS,
        KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_CAPS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_3_WIN_MOD] = LAYOUT_ansi_67(
        KC_WAVE,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE, KC_VOLD,  KC_VOLU,   KC_TRNS,          KC_TRNS,
        RGB_TOG,    RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
        KC_TRNS,    RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,             KC_CAPS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_CAPS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_4_FNS] = LAYOUT_ansi_67(
        KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    KC_TRNS,          KC_TRNS,
        RGB_TOG, RGB_MOD, WORKE, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, PROTN, KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
        KC_TRNS, ACW,SIELP, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_5_NUMPAD] = LAYOUT_ansi_67(
        KC_WAVE,  S(KC_1), S(KC_2),  S(KC_3), S(KC_4), S(KC_5), S(KC_6), KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,          KC_Q,    KC_UP,    KC_E,    KC_R,    S(KC_7), S(KC_8), KC_4,    KC_5,    KC_6,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_TRNS,         KC_LEFT, KC_DOWN,  KC_RGHT, KC_F,    KC_G,    KC_H,    KC_1,    KC_2,    KC_3,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSPO,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_0,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSPC,           KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_0,                               KC_TRNS, KC_TRNS,  TO(_0_MAC_BASE), KC_TRNS, KC_TRNS, KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case SIELP:
            if (record->event.pressed) {
                SEND_STRING("");;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key      
        case PROTN:
            if (record->event.pressed) {
                SEND_STRING("");;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key    
        case ACW:
            if (record->event.pressed) {
                SEND_STRING("");;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key    
        case WORKE:
            if (record->event.pressed) {
                SEND_STRING("");;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key   
        default:
            return true;  // Process all other keycodes normally
    }

      // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            if (IS_LAYER_ON(_2_MAC_MOD)){
                tap_code_delay(KC_BRIU, 10);
            } else {
                tap_code_delay(KC_VOLU, 10);   
            }

        } else {
            if (IS_LAYER_ON(_2_MAC_MOD)){
                tap_code_delay(KC_BRID, 10);
            } else {
                tap_code_delay(KC_VOLD, 10);   
            }
        }
    }
    return true;
}
#endif

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
    rgb_matrix_sethsv(12,255,159);
    debug_enable=true;
    debug_keyboard=true;
}
