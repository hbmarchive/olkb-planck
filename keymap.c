/* Copyright 2015-2023 Jack Humbert
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

enum my_layers {
  BASE_LAYER,
  SYM_LAYER,
  NAV_LAYER,
  FUNC_LAYER,
  SCUT_LAYER
};

enum my_keycodes {
    M_ESCQ = SAFE_RANGE,
    M_ESCW,
    M_ESCV,
    M_ECSL,
    M_EQLR,
    M_ALTT
};

// Stores state of M_ALTT macro - true if we are currently tabbing between
// windows.
static bool m_altt_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE_LAYER] = LAYOUT_planck_grid(
    KC_Q,            KC_W,           KC_F,           KC_P,           KC_B,    LCTL(KC_TAB),        M_ALTT,            KC_J,    KC_L,     KC_U,     KC_Y,    KC_BSPC,
    KC_A,            KC_R,           KC_S,           KC_T,           KC_G,    KC_ESC,              M_ECSL,            KC_M,    KC_N,     KC_E,     KC_I,    KC_O,
    KC_Z,            KC_X,           KC_C,           KC_D,           KC_V,    LSFT(LCTL(KC_SPC)),  LSFT(LCTL(KC_C)),  KC_K,    KC_H,     KC_COMM,  KC_DOT,  OSL(SCUT_LAYER),
    TO(FUNC_LAYER),  OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  KC_SPC,  OSM(MOD_LSFT),       OSL(SYM_LAYER),    KC_ENT,  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT
  ),

  [SYM_LAYER] = LAYOUT_planck_grid(
    KC_EXLM,         LSFT(KC_2),     LSFT(KC_3),  KC_DLR,   KC_PERC,  KC_TRNS,         KC_TRNS,        KC_CIRC,  KC_AMPR,        KC_ASTR,        KC_UNDS,  KC_PLUS,
    KC_ESC,          LSFT(KC_NUBS),  KC_LBRC,     KC_LCBR,  KC_LPRN,  KC_TRNS,         KC_TRNS,        KC_COLN,  LSFT(KC_QUOT),  LSFT(KC_BSLS),  KC_MINS,  KC_EQL,
    TO(FUNC_LAYER),  KC_NUBS,        KC_RBRC,     KC_RCBR,  KC_RPRN,  KC_TRNS,         KC_TRNS,        KC_SCLN,  KC_QUOT,        KC_BSLS,        KC_GRV,   OSL(SCUT_LAYER),
    KC_TRNS,         KC_TRNS,        KC_TRNS,     KC_TRNS,  KC_TRNS,  TO(BASE_LAYER),  TO(NAV_LAYER),  KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,  KC_TRNS
  ),

  [NAV_LAYER]          = LAYOUT_planck_grid(
    KC_1,              KC_2,          KC_3,                 KC_4,                 KC_5,     KC_TRNS,         KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_TAB,            LCTL(KC_TAB),  M_ALTT,               KC_BTN1,              KC_BTN2,  KC_TRNS,         KC_TRNS,  KC_WH_U,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
    TO(FUNC_LAYER),    LCTL(LGUI(KC_LEFT)),  LCTL(LGUI(KC_RGHT)), LSFT(LCTL(KC_BTN1)),  M_ESCV,   KC_TRNS,         KC_TRNS,  KC_WH_D,  KC_HOME,  KC_PGDN,  KC_PGUP,  OSL(SCUT_LAYER),
    KC_TRNS,           KC_TRNS,       KC_TRNS,              KC_TRNS,              KC_TRNS,  TO(BASE_LAYER),  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
                       ),

  [FUNC_LAYER] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_MNXT,  KC_TRNS,         KC_TRNS,        KC_VOLU,  KC_BRIU,  KC_ASTR,  KC_NO,    KC_PLUS,
    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_MPLY,  KC_TRNS,         KC_TRNS,        KC_VOLD,  KC_BRID,  KC_NO,    KC_MINS,  KC_EQL,
    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MPRV,  KC_TRNS,         KC_TRNS,        KC_MUTE,  KC_NO,    KC_COMM,  KC_DOT,   OSL(SCUT_LAYER),
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(BASE_LAYER),  TO(SYM_LAYER),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [SCUT_LAYER] = LAYOUT_planck_grid(
    M_ESCQ,   M_ESCW,      LCTL(KC_F),  LSFT(LCTL(KC_SPC)),  LCTL(KC_B),  KC_TRNS,         KC_TRNS,  KC_NO,       KC_NO,             KC_NO,       KC_NO,       KC_DEL,
    KC_TAB,   HYPR(KC_1),  HYPR(KC_2),  HYPR(KC_3),          HYPR(KC_G),  KC_TRNS,         KC_TRNS,  HYPR(KC_M),  HYPR(KC_4),        HYPR(KC_5),  HYPR(KC_6),  KC_INS,
    KC_CAPS,  LCTL(KC_X),  LCTL(KC_C),  LSFT(LCTL(KC_C)),    LCTL(KC_V),  KC_TRNS,         KC_TRNS,  HYPR(KC_K),  LSFT(LCTL(KC_1)),  KC_NO,       M_EQLR,      KC_SLSH,
    KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,             KC_TRNS,     TO(BASE_LAYER),  KC_NO,    KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode != M_ALTT && m_altt_pressed) {
    unregister_code(KC_LALT);
    m_altt_pressed = false;
  }
  switch (keycode) {
    case M_ALTT:
      if (record->event.pressed) {
        if (!m_altt_pressed) {
          register_code(KC_LALT);
          m_altt_pressed = true;
        }
        tap_code(KC_TAB);
      }
      break;
    case M_ESCQ:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":q!"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCW:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":wq"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_EQLR:
      if (record->event.pressed) {
        SEND_STRING("=> ");
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCV:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_V)SS_UP(X_LSFT));
      }
      break;
    case M_ECSL:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_SCLN)SS_UP(X_LSFT));
        SEND_STRING(SS_TAP(X_SLSH));
      }
      break;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Return to the base layer if space, enter or a function key is pressed.
    case KC_SPC:
    case KC_ENT:
    case KC_F1 ... KC_F12:
      if (!record->event.pressed) { layer_move(BASE_LAYER); }
      break;
    // Cancel caps lock if escape is pressed.
    case KC_ESC:
      if (host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
      break;
    // Return to the nav layer if symbols in the func layer have been pressed.
    case KC_ASTR:
    case KC_PLUS:
    case KC_MINS:
    case KC_EQL:
    case KC_DOT:
    case KC_SLSH:
      if (!record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NAV_LAYER);
        }
      }
      break;
  }
}
