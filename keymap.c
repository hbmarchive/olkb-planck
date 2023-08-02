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
  FUNC_LAYER
};

enum my_tap_dances {
  TD_Z_CAPS,
  TD_X_CUT,
  TD_C_COPY,
  TD_V_PASTE,
  TD_F_PGDN,
  TD_B_PGUP,
  TD_LBRC_GLB,
  TD_RBRC_GRB
};

enum my_keycodes {
  BACKLIT = SAFE_RANGE,
  M_LAUNCHER1,
  M_LAUNCHER2,
  M_LAUNCHER3,
  M_LAUNCHER4,
  M_1PASSWD,
  M_DSKN,
  M_DSKP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE_LAYER] = LAYOUT_planck_grid(
    KC_Q,            KC_W,           TD(TD_F_PGDN),  KC_P,           TD(TD_B_PGUP),   KC_NO,          KC_NO,    KC_J,            KC_L,          KC_U,          KC_Y,          KC_BSPC,
    KC_A,            LGUI_T(KC_R),   LALT_T(KC_S),   LCTL_T(KC_T),   KC_G,            KC_ESC,         KC_COLN,  KC_M,            RCTL_T(KC_N),  RALT_T(KC_E),  RGUI_T(KC_I),  KC_O,
    TD(TD_Z_CAPS),   TD(TD_X_CUT),   TD(TD_C_COPY),  KC_D,           TD(TD_V_PASTE),  M_1PASSWD, KC_NO,  KC_K,            KC_H,          KC_COMM,       KC_DOT,        KC_SLSH,
    TO(FUNC_LAYER),  OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),   ALL_T(KC_SPC),  KC_ENT,   OSL(SYM_LAYER),  M_LAUNCHER1,   M_LAUNCHER2,   M_LAUNCHER3,   M_LAUNCHER4
  ),

  [SYM_LAYER] = LAYOUT_planck_grid(
    KC_TAB,   KC_DQUO,  LSFT(KC_3),       KC_DLR,   KC_PERC,         KC_TRNS,  KC_TRNS,  KC_CIRC,        KC_AMPR,  KC_ASTR,  KC_UNDS,  KC_PLUS,
    KC_ESC,   KC_PIPE,  TD(TD_LBRC_GLB),  KC_LCBR,  KC_LPRN,         KC_TRNS,  KC_TRNS,  KC_COLN,        KC_AT,    KC_TILD,  KC_MINS,  KC_EQL,
    KC_NO,    KC_NUBS,  TD(TD_RBRC_GRB),  KC_RCBR,  KC_RPRN,         KC_TRNS,  KC_TRNS,  KC_SCLN,        KC_QUOT,  KC_HASH,  KC_GRV,   KC_EXLM,
    KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,  TO(BASE_LAYER),  KC_TRNS,  KC_TRNS,  TO(NAV_LAYER),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [NAV_LAYER] = LAYOUT_planck_grid(
    KC_1,          KC_2,          KC_3,          KC_4,     KC_5,            KC_TRNS,  KC_TRNS,  KC_6,    KC_7,     KC_8,     KC_9,     KC_0,
    LCTL(KC_TAB),  LALT(KC_TAB),  LGUI(KC_TAB),  KC_BTN1,  KC_BTN2,         KC_TRNS,  KC_TRNS,  KC_DEL,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
    KC_TRNS,       KC_TRNS,       M_DSKP,        M_DSKN,   LSFT(KC_V),      KC_TRNS,  KC_TRNS,  KC_INS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,  TO(BASE_LAYER),  KC_TRNS,  KC_TRNS,  KC_NO,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [FUNC_LAYER] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_MNXT,         KC_TRNS,  KC_TRNS,  KC_VOLU,        KC_BRIU,  KC_ASTR,  KC_NO,    KC_PLUS,
    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_MPLY,         KC_TRNS,  KC_TRNS,  KC_VOLD,        KC_BRID,  KC_NO,    KC_MINS,  KC_EQL,
    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MPRV,         KC_TRNS,  KC_TRNS,  KC_MUTE,        KC_NO,    KC_COMM,  KC_DOT,   KC_SLSH,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(BASE_LAYER),  KC_TRNS,  KC_TRNS,  TO(SYM_LAYER),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  )
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Z, twice for Caps Lock
    [TD_Z_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_CAPS),
    // Tap once for X, twice for Ctrl-X
    [TD_X_CUT] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_CUT),
    // Tap once for C, twice for Ctrl-C
    [TD_C_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COPY),
    // Tap once for V, twice for Ctrl-V
    [TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_PSTE),
    // Tap once for F, twice for Ctrl-F
    [TD_F_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_F, LCTL(KC_F)),
    // Tap once for B, twice for Ctrl-B
    [TD_B_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_B, LCTL(KC_B)),
    // Tap once for [, twice for GUI-[ (ChromeOS prev desk)
    [TD_LBRC_GLB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),
    // Tap once for ], twice for GUI-] (ChromeOS next desk)
    [TD_RBRC_GRB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    // Return to the base later after fn keys, space or enter have been pressed
    case KC_F1 ... KC_F12:
    case KC_SPC:
    case KC_ENT:
      if (record->event.pressed) {
        layer_move(BASE_LAYER);
      }
      break;
    // Return to num layer if symbol keys in the func layer have been pressed
    case KC_ASTR:
    case KC_PLUS:
    case KC_MINS:
    case KC_EQL:
    case KC_DOT:
    case KC_SLSH:
      if (record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NAV_LAYER);
        }
      }
      break;
    // Respond to launcher keys
    case M_LAUNCHER1:
    case M_LAUNCHER2:
    case M_LAUNCHER3:
    case M_LAUNCHER4:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        switch (keycode) {
          case M_LAUNCHER1: SEND_STRING("1"); break;
          case M_LAUNCHER2: SEND_STRING("2"); break;
          case M_LAUNCHER3: SEND_STRING("3"); break;
          case M_LAUNCHER4: SEND_STRING("4"); break;
        }
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LALT)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT));
      }
      break;
    // Respond to 1Password macro
    case M_1PASSWD:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL));
        SEND_STRING(SS_TAP(X_SPACE));
        SEND_STRING(SS_UP(X_LCTL)SS_UP(X_LSFT));
      }
      break;
    // Respond to next desktop macro
    case M_DSKN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_RIGHT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
    // Respond to previous desktop macro
    case M_DSKP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_LEFT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
  }
  return true;
}
