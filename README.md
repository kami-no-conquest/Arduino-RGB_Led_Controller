# Arduino RGB LED Controller (Non-Blocking)

This project demonstrates a non-blocking, event-driven approach to controlling LED brightness using PWM and pushbuttons on Arduino.
Each button controls the brightness of one LED:

- **Short press** → increase brightness
- **Long press** → decrease brightness

The implementation avoids `delay()` entirely and uses `millis()` for debouncing and press-duration detection.


## Features

- Non-blocking button handling using `millis()`
- Software debouncing
- Short-press vs long-press detection
- PWM brightness control
- Responsive input handling


## Hardware Used

- Arduino Uno
- 3 × Pushbuttons
- 3 × LEDs
- Current-limiting resistors(220 ohms)
- Jumper wires
- Breadboard


## How It Works

Each button is handled using a simple state-based approach:
1. The raw button input is sampled each loop cycle
2. Input changes are debounced using timing checks
3. On button press, the press start time is recorded
4. On button release, the press duration is evaluated
5. PWM brightness is adjusted based on short or long press

This approach allows the system to remain responsive without blocking execution.


## Why `millis()` Instead of `delay()`

Using `delay()` blocks the main loop and prevents the system from responding to other inputs or events.

By using `millis()`:
- The loop remains responsive
- Debouncing is more reliable
- The design scales better as complexity increases
- Input handling becomes deterministic


## Project Evolution

### Initial Implementation

The first version of this project used:
- 2 pushbuttons per LED (one for brightening and the other for dimming)
- `delay()`-based timing
- Direct, sequential button checks

While functional, this approach had limitations:
- Blocking delays reduced responsiveness
- Code duplication made scaling difficult
- Button behavior was limited to simple presses

### Refactored Implementation (Current)

The current version was redesigned to:
- use a single pushbutton to both control brigthening and dimming (reducing needed pushbuttons by half)
- Use non-blocking timing with `millis()`
- Implement proper software debouncing
- Detect short vs long button presses
- Reduce blocking behavior and improve responsiveness

The full refactor history is preserved in the Git commit log.


## Possible Future Improvements

- Refactor button handling using arrays or structs
- Generalize input handling into a single update function
- Add EEPROM storage for brightness persistence
- Package the button logic as a reusable module


## License

MIT License
