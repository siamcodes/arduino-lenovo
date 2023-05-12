// BluetoothOrders.h

#ifndef _BLUETOOTHORDERS_h
#define _BLUETOOTHORDERS_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define ACTION_MOVE           'A'   //comanda i movimenti della macchina A#speedl#speedr#
#define ACTION_CAR_MODE       'H'   //modalità della macchina.  H#MODE_NONE->ferma
                                    //                          H#MODE_GRAVITY->ferma
                                    //                          H#MODE_ULTRASONIC->evita ostacoli con sonar ed infrared
                                    //                          H#MODE_ULTRASONIC_NOIR->evita ostacoli con sonar senza infrared
                                    //                          H#MODE_TRACKING->tracking con infrared in basso                     
                                    //                          H#MODE_FOLLOW->follow con sonar ed infrared     
#define ACTION_BUZZER         'D'

#define ACTION_ULTRASONIC     'E'
#define ACTION_IRDX           'M'
#define ACTION_IRSX           'N'

#define ACTION_STOP           'B'
#define ACTION_RGB            'C'
#define ACTION_LIGHT_TRACING  'F'
#define ACTION_TRACKING       'G'
#define ACTION_GET_VOLTAGE    'I'
#define ECHO_OK               'J'
#define ACTION_NONE           'K'
#define ACTION_INFRARED_AVOID 'L'


#define MODE_NONE             0
#define MODE_GRAVITY          1
#define MODE_ULTRASONIC       2
#define MODE_ULTRASONIC_NOIR  3
#define MODE_TRACKING         4
#define MODE_FOLLOW           5

#endif
