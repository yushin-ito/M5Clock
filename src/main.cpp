#include <M5Unified.h>
#include <M5Clock.h>
#include <WiFi.h>

const char* ssid = "ssid";
const char* password = "password";

M5Clock cl;

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  M5.Display.setRotation(1);
  cl.init(0, 0);
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed()) {
    if (cl.isDrawing()) {
      cl.hide();
    }
    else {
      cl.show();
    }
  }


  if (M5.BtnB.wasPressed()) {
    cl.syncClock(ssid, password);
  }

  delay(100);
}