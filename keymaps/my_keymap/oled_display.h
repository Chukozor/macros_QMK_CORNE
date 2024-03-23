// =============================== OLED DISPLAY ===============================
#ifdef OLED_ENABLE

// // rotate oled
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   return OLED_ROTATION_90;
// }

// Draw to OLED
bool oled_task_user() {
  // Set cursor position
  oled_set_cursor(0,1);

  // // Write text to OLED
  // oled_write("Hello World!", false);

  switch (get_highest_layer(layer_state)){
    case _COLEMAK_FR :
      oled_write("COLEMAK FR   ", false);
      break;
    case _ACCENTS :
      oled_write("ACCENTS      ", false);
      break;
    case _CAPS_LOCK :
      oled_write("CAPS_LOCK    ", false);
      break;
    case _REG_SPE :
      oled_write("SPE_CHAR REG ", false);
      break;
    case _SFT_COLEMAK_FR :
      oled_write("SHIFT        ", false);
      break;
    case _NAV :
      oled_write("NAV          ", false);
      break;
    // case 4 :
    //   oled_write("NUMPAD       ", false);
    //   break;
    case _SPE :
      oled_write("SPE_CHAR RARE", false);
      break;
    case _RGB :
      oled_write("RGB          ", false);
      break;
    case _F_KEYS :
      oled_write("_F_KEYS      ", false);
      break;
    case _LATEX :
      oled_write("_LATEX       ", false);
      break;
    case _MULTIMEDIA :
      oled_write("_MULTIMEDIA  ", false);
      break;
    // case 4 :
    //   oled_write("", false);
    //   break;
  }
  
  return false;
}

#endif
// =============================== END OLED DISPLAY ===============================