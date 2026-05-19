#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t SDA = 4;
static const uint8_t SCL = 26;

static const uint8_t SS   = 5;
static const uint8_t MOSI = 23;
static const uint8_t MISO = 25;
static const uint8_t SCK  = 19;

static const uint8_t A0  = 36;
static const uint8_t A3  = 39;
static const uint8_t A4  = 32;
static const uint8_t A5  = 33;
static const uint8_t A6  = 34;
static const uint8_t A7  = 35;
static const uint8_t A10 = 4;
static const uint8_t A11 = 0;
static const uint8_t A12 = 2;
static const uint8_t A13 = 15;
static const uint8_t A14 = 13;
static const uint8_t A15 = 12;
static const uint8_t A16 = 14;
static const uint8_t A17 = 27;
static const uint8_t A18 = 25;
static const uint8_t A19 = 26;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

// Buttons — active HIGH (external pull-down resistors)
// "SN" on board silkscreen = SVN = GPIO 39 (input-only)
#define UP_BTN  34
#define DW_BTN  33
#define L_BTN   39
#define R_BTN   32
#define SEL_BTN      17
#define START_BTN    14
#define A_BTN        35
#define B_BTN        13
#define RESET_BTN    12
#define SETTINGS_BTN 16

#define HAS_BTN   1
#define BTN_ALIAS "\"Select\""
#define BTN_PIN   SEL_BTN
#define BTN_ACT   HIGH

// No microphone
#define PIN_CLK      -1
#define I2S_SCLK_PIN -1
#define I2S_DATA_PIN -1
#define PIN_DATA     -1

// No RGB LED
#define RGB_LED -1

// No speaker
#define BCLK -1
#define WCLK -1
#define DOUT -1

// I2C — only GPIO 4 and 26 are free after TFT + buttons
#define GROVE_SDA 4
#define GROVE_SCL 26

// BadUSB / GPS
#define BAD_TX GROVE_SDA
#define BAD_RX GROVE_SCL
#define SERIAL_TX     1
#define SERIAL_RX     3
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// IR / RF TX — GPIO 5 (only free output-capable pin besides 2 and 15)
// IR_TX_PINS / IR_RX_PINS / RF_TX_PINS / RF_RX_PINS defined in .ini (require shell quoting)
#define TXLED   5
#define LED_ON  HIGH
#define LED_OFF LOW

// No free pins for a dedicated peripheral SPI bus after TFT + 10 buttons
#define SPI_SCK_PIN  -1
#define SPI_MOSI_PIN -1
#define SPI_MISO_PIN -1
#define SPI_SS_PIN   -1

// CC1101 / NRF24 / W5500 — not connected (no free SPI pins)
#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN  -1
#define CC1101_SS_PIN    -1
#define CC1101_MOSI_PIN  SPI_MOSI_PIN
#define CC1101_SCK_PIN   SPI_SCK_PIN
#define CC1101_MISO_PIN  SPI_MISO_PIN

#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN    -1
#define NRF24_SS_PIN    -1
#define NRF24_MOSI_PIN  SPI_MOSI_PIN
#define NRF24_SCK_PIN   SPI_SCK_PIN
#define NRF24_MISO_PIN  SPI_MISO_PIN

#define USE_W5500_VIA_SPI
#define W5500_SS_PIN    -1
#define W5500_MOSI_PIN  SPI_MOSI_PIN
#define W5500_SCK_PIN   SPI_SCK_PIN
#define W5500_MISO_PIN  SPI_MISO_PIN
#define W5500_INT_PIN   -1

// Font sizes
#define FP 1
#define FM 2
#define FG 3

// Screen
#define HAS_SCREEN 1
#define ROTATION   1
#define BACKLIGHT  27
#define MINBRIGHT  10

// TFT_eSPI — ILI9341 (240x320)
#define USER_SETUP_LOADED 1
#define ILI9341_DRIVER    1
#define TFT_HEIGHT        320
#define TFT_WIDTH         240
#define TFT_MISO          25
#define TFT_MOSI          23
#define TFT_SCLK          19
#define TFT_CS            22
#define TFT_DC            21
#define TFT_RST           18
#define TFT_BL            27
#define TFT_BACKLIGHT_ON  HIGH
#define SMOOTH_FONT       1

#define SPI_FREQUENCY       40000000
#define SPI_READ_FREQUENCY  16000000
#define SPI_TOUCH_FREQUENCY 2500000

// No touch screen
#define HAS_TOUCH 0
#define TOUCH_CS  -1

// No SD card
#define SDCARD_CS   -1
#define SDCARD_SCK  -1
#define SDCARD_MISO -1
#define SDCARD_MOSI -1

// Backlight PWM
#define TFT_BRIGHT_CHANNEL 0
#define TFT_BRIGHT_Bits    8
#define TFT_BRIGHT_FREQ    5000

#endif /* Pins_Arduino_h */
