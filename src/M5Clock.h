#ifndef M5CLOCK_H
#define M5CLOCK_H
#include <WiFi.h>
#include <M5Unified.h>

class M5Clock {
private:
  M5Canvas* canvas;
  bool _drawing;
  bool _changed;
  int32_t _x;
  int32_t _y;
  float _text_size;
  uint32_t _color;
  uint32_t _bg_color;
  char _ntp_server[65] = "ntp.jst.mfeed.ad.jp";
  long _gmt_offset_sec;
  int _daylight_offset_sec;
  m5::rtc_date_t _rtc_date;
  m5::rtc_time_t _rtc_time;
  const char* _wd[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

public:
  M5Clock();
  void setConfig(long gmt_offset_sec, int daylight_offset_sec, const char* ntp_server);
  void setPosition(int32_t x, int32_t y);
  void setTextSize(float size);
  void setColor(uint32_t color);
  void setBgColor(uint32_t color);
  void init(int32_t x, int32_t y);
  void show();
  void hide();
  bool isDrawing();
  bool isChanged();
  void setChanged(bool changed);
  bool syncClock(const char* ssid, const char* password);
  String getTimeStamp();
  void drawClock();
  m5::rtc_date_t getDate();
  m5::rtc_time_t getTime();
};

#endif // M5CLOCK_H

#ifndef CONTEXT_H
#define CONTEXT_H

class Context {
private:
  M5Clock* _cl;

public:
  Context(M5Clock* cl);
  M5Clock* getClock();
};

#endif // CONTEXT_H
