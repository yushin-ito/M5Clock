#include "M5Clock.h"

static TaskHandle_t drawTaskHandle;

Context::Context(M5Clock* cl) { _cl = cl; }

M5Clock* Context::getClock() { return _cl; }

static void drawLoop(void* args) {
    Context* ctx = reinterpret_cast<Context*>(args);
    M5Clock* cl = ctx->getClock();

    while (cl->isDrawing() || cl->isChanged()) {
        if (cl->isDrawing()) {
            cl->drawClock();
        }
        if (cl->isChanged()) {
            M5.Display.clear();
            cl->setChanged(false);
        }
        vTaskDelay(1);
    }
    vTaskDelete(NULL);
}

M5Clock::M5Clock() {
    canvas = new M5Canvas(&M5.Lcd);
    _drawing = false;
    _changed = false;
    _x = 0;
    _y = 0;
    _text_size = 1.0;
    _gmt_offset_sec = 9 * 3600;
    _daylight_offset_sec = 0;
    _color = canvas->color888(255, 255, 255);
    _bg_color = canvas->color888(0, 0, 0);
}

void M5Clock::setConfig(long gmt_offset_sec, int daylight_offset_sec, const char* ntp_server) {
    _gmt_offset_sec = gmt_offset_sec;
    _daylight_offset_sec = daylight_offset_sec;
    memcpy(_ntp_server, ntp_server, 64);
}

void M5Clock::setPosition(int32_t x, int32_t y) {
    _x = x;
    _y = y;
    _changed = true;
}

void M5Clock::setTextSize(float size) {
    _text_size = size;
    _changed = true;
}

void M5Clock::setColor(uint32_t color) {
    _color = color;
    _changed = true;
}

void M5Clock::setBgColor(uint32_t color) {
    _bg_color = color;
    _changed = true;
}

void M5Clock::init(int32_t x, int32_t y) {
    _x = x;
    _y = y;

    if (!M5.Rtc.isEnabled()) return;

    show();
}

void M5Clock::show() {
    Context* ctx = new Context(this);

    if (_drawing) return;
    _drawing = true;

    xTaskCreateUniversal(drawLoop,
        "drawLoop",
        2048,
        ctx,
        1,
        &drawTaskHandle,
        APP_CPU_NUM);
}

void M5Clock::hide() {
    _drawing = false;
    _changed = true;
}

bool M5Clock::isDrawing() {
    return _drawing;
}

bool M5Clock::isChanged() {
    return _changed;
}

void M5Clock::setChanged(bool changed) {
    _changed = changed;
}

bool M5Clock::syncClock(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED) {
        configTime(_gmt_offset_sec, _daylight_offset_sec, _ntp_server);

        struct tm _time_info;
        if (getLocalTime(&_time_info)) {
            m5::rtc_time_t rtc_time;
            Serial.println(_time_info.tm_hour);
            rtc_time.hours = _time_info.tm_hour;
            rtc_time.minutes = _time_info.tm_min;
            rtc_time.seconds = _time_info.tm_sec;
            M5.Rtc.setTime(&rtc_time);

            m5::rtc_date_t rtc_date;
            rtc_date.weekDay = _time_info.tm_wday;
            rtc_date.month = _time_info.tm_mon + 1;
            rtc_date.date = _time_info.tm_mday;
            rtc_date.year = _time_info.tm_year + 1900;
            M5.Rtc.setDate(&rtc_date);
        }
    }

    return true;
}

String M5Clock::getTimeStamp() {
    char timestamp[126];
    sprintf(timestamp, "%04d/%02d/%02d %02d:%02d", _rtc_date.year,
        _rtc_date.month, _rtc_date.date, _rtc_time.hours,
        _rtc_time.minutes, _rtc_time.seconds);
    return String(timestamp);
}

void M5Clock::drawClock() {
    M5.Rtc.getTime(&_rtc_time);
    M5.Rtc.getDate(&_rtc_date);

    int32_t _sprite_width = M5.Display.width();
    int32_t _sprite_height = M5.Display.fontHeight(&Font7) * _text_size + M5.Display.fontHeight(&Font7) * _text_size * 0.3;

    canvas->createSprite(_sprite_width, _sprite_height);

    canvas->setTextWrap(false);
    canvas->setTextColor(_color);

    canvas->setCursor(0, 0);
    canvas->setFont(&Font7);

    canvas->setTextSize(_text_size);
    canvas->printf("%02d:%02d", _rtc_time.hours, _rtc_time.minutes);

    canvas->setTextSize(_text_size * 0.3);
    canvas->printf(" : %02d\n", _rtc_time.seconds);

    canvas->setCursor(0, M5.Display.fontHeight(&Font7));
    canvas->setFont(&Font2);

    canvas->setTextSize(_text_size);
    canvas->printf("%04d.%02d.%02d %s\n", _rtc_date.year,
        _rtc_date.month, _rtc_date.date,
        _wd[_rtc_date.weekDay]);

    canvas->pushSprite(&M5.Display, _x, _y);

    canvas->deleteSprite();
}

m5::rtc_date_t M5Clock::getDate() {
    M5.Rtc.getDate(&_rtc_date);
    return _rtc_date;
}

m5::rtc_time_t M5Clock::getTime() {
    M5.Rtc.getTime(&_rtc_time);
    return _rtc_time;
}