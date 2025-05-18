led_config_t g_led_config = { {
  // Key Matrix to LED Index --- The physical keypad only uses 6 LEDs, placed evenly under the 9 keys. 
  { 0, 1, 2 },
  { 3, 4, 5 },
  { NO_LED, NO_LED, NO_LED }
}, {
  // LED Index to Physical Position (x, y)
  {   0,  0 },   // LED 0 under (0,0)
  { 112,  0 },   // LED 1 under (0,1)
  { 224,  0 },   // LED 2 under (0,2)
  {   0, 32 },   // LED 3 under (1,0)
  { 112, 32 },   // LED 4 under (1,1)
  { 224, 32 }    // LED 5 under (1,2)
}, {
  // LED Index to Flag -- "4" flags the LEDs as key backlights
  4, 4, 4, 4, 4, 4
} };
