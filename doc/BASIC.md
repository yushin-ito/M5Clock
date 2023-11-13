# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [cl.setPosition(x, y) => void](#clsetpositionx-y--void)
    - [cl.setTextSize(size) => void](#clsettextsizesize--void)
    - [cl.setTextColor(color) => void](#clsettextcolorcolor--void)
    - [cl.setBgColor(color) => void](#clsetbgcolorcolor--void)
    - [cl.init() => void](#clinit--void)
    - [cl.show() => void](#clshow--void)
    - [cl.hide() => void](#clhide--void)
    - [cl.isDrawing() => bool](#clisdrawing--bool)
    - [cl.isChanged() => bool](#clischanged--bool)
    - [cl.syncClock(ssid, password) => void](#clsyncclock--void)
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

Set position of Clock box.

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

### cl.init() => void

Initialize Clock with position.

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

Kind: instance method of `M5Clock`

### cl.show() => void

Show Clock.

Kind: instance method of `M5Clock`

### cl.hide() => void

Hide Clock.

Kind: instance method of `M5Clock`

### cl.isDrawing() => bool

Get if the Clock is drawing.

Kind: instance method of `M5Clock`

### cl.isChanged() => bool

Get if the Clock style is changed.

Kind: instance method of `M5Clock`

### cl.syncClock(ssid, password) => void

Try to get the NTP time over WiFi, and then set the RTC.

|  Param   |     Type     |
| :------: | :----------: |
|   ssid   | const char\* |
| password | const char\* |

Kind: instance method of `M5Clock`

### cl.drawClock() => void

Display Clock.

Kind: instance method of `M5Clock`
