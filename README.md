SDL_input
=========

A SDL based input library for dynamic mapping.

Therefore, instead of thinking input as key presses or mouse movements,
you think of them as signals, such as, `is_jumping` or `up_strength`.

How it works
------------
You define one or more `Profile`s. These can be enabled and disabled at will.
Each profile contains one or more `Binding`s. These bindings have a type and a source.

The type can be one of:
* onoff - binary, is the key/mouse button currently pressed
* toggle - binary, toggles on each key press/mouse button press
* absolute value - increments/decrements according to movement
* relative value - represents how much movement has happened since last update

The binding sources can be key presses, mouse button clicks, mouse axises, joystick and gamepad.

