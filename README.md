<h1>M5Clock</h1>

<div align="left">
  <img src="https://img.shields.io/badge/version-0.0.1-red.svg">
  <img src="https://img.shields.io/github/actions/workflow/status/yushin-ito/M5Clock/build.yml">
  <img src="https://img.shields.io/github/stars/yushin-ito/M5Clock?color=yellow">
  <img src="https://img.shields.io/github/commit-activity/t/yushin-ito/M5Clock">
  <img src="https://img.shields.io/badge/license-MIT-green">
</div>

<br>

<h2>📝 Overview</h2>
An M5Stack library for displaying clock.

<br>
<br>

<h2>🚀 Features</h2>
<ul>
  <li>Display clock charge</li>
  <li>Customize size and color</li>
</ul>
<br>
<div align="center">
  <img src="https://github.com/yushin-ito/M5Clock/assets/75526539/d14ea0dc-1db0-4f11-bddc-c1acdcd93bfe" width="80%"/>
</div>

<br>

<h2>📦 Installation</h2>
<a href="https://open.vscode.dev/yushin-ito/M5Clock">
  <img src="https://github.com/yushin-ito/M5Clock/assets/75526539/57b2c785-39de-4f98-943d-4a75c5a08bff">
</a>
<br>
<br>
<ol>
  <li>Initialize your Platform IO project</li>

```powershell
platformio init -d . -b m5stack-core-esp32
```

  <li>Install the library and its dependency</li>

```powershell
platformio lib install M5Clock
platformio lib install M5Unified
```

</ol>

<h2>🔧 Usage</h2>

> **Warning**
> This library has been tested only with M5Stack and M5StickC-PLUS.

<br>

```c++
#include <M5Unified.h>
#include <M5Clock.h>

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
```

<p>You can also read the <a href="https://github.com/yushin-ito/M5Clock/blob/main/doc/BASIC.md">module doc</a> for a list of supported calls.</p>

<br>

<h2>👀 Author</h2>
<a href="https://github.com/yushin-ito">Yushin Ito</a>

<br>
<br>

<h2>📜 License</h2>
<a href="https://github.com/yushin-ito/M5Clock/blob/main/LICENSE">MIT License</a>
