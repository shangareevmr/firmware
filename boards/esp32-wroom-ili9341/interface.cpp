#include "core/powerSave.h"
#include <interface.h>

void _setup_gpio() {
    bruceConfig.colorInverted = 0;
    bruceConfigPins.rotation = ROTATION;
    // All buttons use external pull-down resistors (active HIGH).
    // GPIO 34, 35, 39 are input-only — INPUT is the only valid mode for them.
    pinMode(UP_BTN,      INPUT);
    pinMode(DW_BTN,      INPUT);
    pinMode(L_BTN,       INPUT);
    pinMode(R_BTN,       INPUT);
    pinMode(SEL_BTN,     INPUT);
    pinMode(START_BTN,   INPUT);
    pinMode(A_BTN,       INPUT);
    pinMode(B_BTN,       INPUT);
    pinMode(RESET_BTN,   INPUT);
    pinMode(SETTINGS_BTN, INPUT);
}

void _post_setup_gpio() {
    pinMode(TFT_BL, OUTPUT);
    ledcAttach(TFT_BL, TFT_BRIGHT_FREQ, TFT_BRIGHT_Bits);
    ledcWrite(TFT_BL, 255);
}

int getBattery() { return 0; }

void _setBrightness(uint8_t brightval) {
    int dutyCycle = (brightval == 100) ? 255 : ((brightval * 255) / 100);
    ledcWrite(TFT_BL, dutyCycle);
}

void InputHandler(void) {
    static unsigned long tm = millis();
    if (!(millis() - tm > 150 || LongPress)) return;

    // Buttons are active HIGH (pulled-down, press connects to 3.3 V)
    bool u    = digitalRead(UP_BTN)       == HIGH;
    bool d    = digitalRead(DW_BTN)       == HIGH;
    bool l    = digitalRead(L_BTN)        == HIGH;
    bool r    = digitalRead(R_BTN)        == HIGH;
    bool sel  = digitalRead(SEL_BTN)      == HIGH;  // SELECT   → confirm
    bool st   = digitalRead(START_BTN)    == HIGH;  // START    → back/escape
    bool a    = digitalRead(A_BTN)        == HIGH;  // A        → confirm
    bool b    = digitalRead(B_BTN)        == HIGH;  // B        → back/escape
    bool sett = digitalRead(SETTINGS_BTN) == HIGH;  // SETTINGS → escape to settings

    if (u || d || l || r || sel || st || a || b || sett) {
        tm = millis();
        if (!wakeUpScreen()) AnyKeyPress = true;
        else return;
    }

    if (u)              UpPress   = true;
    if (d)              DownPress = true;
    if (l)              PrevPress = true;
    if (r)              NextPress = true;
    if (sel || a)       SelPress  = true;
    if (st || b || sett) EscPress = true;
}

void powerOff() {
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_0, LOW);
    esp_deep_sleep_start();
}

void checkReboot() {
    if (digitalRead(RESET_BTN) == HIGH) {
        delay(50);
        if (digitalRead(RESET_BTN) == HIGH) ESP.restart();
    }
}
