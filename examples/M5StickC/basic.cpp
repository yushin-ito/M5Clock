#include <M5Unified.h>
#include <M5Battery.h>

M5Battery bat;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);
    bat.setCusor(M5.Display.width() / 2, M5.Display.height() / 2);
    bat.setSize(3);
}

void loop() {
    M5.update();
    bat.showBattery();
    bat.updateBattery();
}