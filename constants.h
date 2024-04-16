#ifndef CONSTANTS_H
#define CONSTANTS_H

#define APP_STYLE_GLOBAL "color:black; background-color: white;"
#define SCROLL_AREA_STYLE "* {padding-left: 5px; padding-top: 6px;}"

#define HIGHLIGHTED_STYLE "* {background-color: #D3D3D3;}"
#define DEFAULT_MENU_STYLE "* {background-color: white}"

#define TREATMENT_TAB_TEXT "Treatments"
#define TREATMENT_TAB_INDEX 0
#define LOGS_TAB_TEXT "Logs"
#define LOGS_TAB_INDEX 1
#define SETTINGS_TAB_TEXT "Date/time settings"
#define SETTINGS_TAB_INDEX 2
#define MENU_TAB_TEXT "Menu"
#define MENU_TAB_INDEX 3

#define LED_DIAMETER 24
#define LED_FLASH_INTERVAL 420

#define INITIAL_VIEW_TAB_INDEX 3

#define DISCONNECT_ALERT "Alert: EEG terminal(s) disconnected"
#define POWER_ALERT "Alert: insufficient battery"

#define BATTERY_TREATMENT_CAPACITY 3

#define NUM_SAMPLES 314.0 // at intervals of 1/100 in data series
#define INTERVAL_END 3.14
#define TWO_PI 6.28 // needed as a constant because the "regular" interval of sin is 2pi, to control our frequency
#define X_LABEL "Time (Seconds)"
#define Y_LABEL "Sensor Readout (Microvolts)"

#define EPOCH "1970 01 01"

#define ALPHA_MAX 12.0
#define ALPHA_MIN 8.0
#define ALPHA_FREQ_STDEV 1.0 // defining frequency std deviation as 1/4 of its range (roughly 95% accurate assuming normal dist)

#define BETA_FREQ_STDEV 4.25
#define BETA_MAX 40.0
#define BETA_MIN 12.0

#define THETA_FREQ_STDEV 1.0
#define THETA_MAX 8.0
#define THETA_MIN 4.0

#define DELTA_FREQ_STDEV 1.0
#define DELTA_MAX 4.0
#define DELTA_MIN 0.0

#define OFFSET_FREQ_VALUE 5
#define OFFSET_FREQ_STRENGTH 200 // amplitude of offset frequency, in microvolt

#define NUM_OFFSETS 16
#define NUM_FEEDBACK_ROUNDS 4

#define ONE_MINUTE 5 // number of seconds in a Neureset minute, adjustable
#define FIVE_MINUTES_MS 300000
#define NUM_SITES 7
#define TREATMENT_INCREMENT 5 // increment of treatment frequency, in hz

#endif // CONSTANTS_H
