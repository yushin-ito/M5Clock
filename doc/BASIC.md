# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [cl.setPosition(x, y) => void](#clsetpositionx-y--void)
    - [cl.setTextSize(size) => void](#clsettextsizesize--void)
    - [cl.setTextColor(color) => void](#clsettextcolorcolor--void)
    - [cl.setBgColor(color) => void](#clsetbgcolorcolor--void)
    - [cl.init(x, y) => void](#clinitx-y--void)
    - [cl.show() => void](#clshow--void)
    - [cl.hide() => void](#clhide--void)
    - [cl.isDrawing() => bool](#clisdrawing--bool)
    - [cl.isChanged() => bool](#clischanged--bool)
    - [cl.syncClock(ssid, password) => void](#clsyncclock--void)
    - [cl.getTimeStamp() => String](#clgettimestamp--string)
    - [cl.drawClock() => void](#cldrawclock--void)

## Instance Basics

### Create a instance

Include the `M5Clock.h` and `M5Unified`

```c++
#include <M5Unified.h>
#include <M5Clock.h>
```

Then Instanciate

```c++
M5Clock cl;
```

Your instance is now ready.

## Functions Basic

Call the fuctions using the created instance.

### cl.setPosition(x, y) => void

Set position of clock box.

Kind: instance method of `M5Clock`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

### cl.setTextSize(size) => void

Set text size.

Kind: instance method of `M5Clock`

| Param | Type  |
| :---: | :---: |
| size  | float |

### cl.setTextColor(color) => void

Set text color.

Kind: instance method of `M5Clock`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### cl.setBgColor(color) => void

Set bg color of Clock box.

Kind: instance method of `M5Clock`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### cl.init(x, y) => void

Initialize clock with position.

Kind: instance method of `M5Clock`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

### cl.show() => void

Show clock.

Kind: instance method of `M5Clock`

### cl.hide() => void

Hide clock.

Kind: instance method of `M5Clock`

### cl.isDrawing() => bool

Get if the clock is drawing.

Kind: instance method of `M5Clock`

### cl.isChanged() => bool

Get if the clock style is changed.

Kind: instance method of `M5Clock`

### cl.syncClock(ssid, password) => void

Try to get the NTP time over WiFi, and then set the RTC.

Kind: instance method of `M5Clock`

|  Param   |     Type     |
| :------: | :----------: |
|   ssid   | const char\* |
| password | const char\* |

### cl.getTimeStamp() => String

Get time by timestamp.

Kind: instance method of `M5Clock`

### cl.drawClock() => void

Display clock.

Kind: instance method of `M5Clock`
