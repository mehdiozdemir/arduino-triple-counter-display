# Triple 7-Segment Counter with Speed Control

An Arduino-based counter project featuring three 7-segment displays, dual potentiometer controls for speed and direction, counting from 0-999.

## 🛠️ Components Used

- 1x Arduino Uno
- 3x 7-segment displays
- 3x CD4511 BCD to 7-segment decoders
- 2x Potentiometers
- Resistors (220Ω)
- Jumper Wires
- 1x Breadboard

## 📋 Features

- Triple 7-segment display (000-999 range)
- Adjustable counting speed via potentiometer
- Direction control (up/down) via potentiometer
- BCD encoding for display control
- Continuous loop counting
- Serial monitoring for debugging

## 🎮 Pin Configuration

### Display Control
- First Display (segment1): pins 2, 3, 4, 5
- Second Display (segment2): pins 6, 7, 8, 9
- Third Display (segment3): pins 10, 11, 12, 13

### Input Controls
- Speed Potentiometer: A0
- Direction Potentiometer: A1

## 📺 Circuit Diagram

![Brilliant Hango](https://github.com/user-attachments/assets/1757518a-3d91-4e00-8841-6680db0b3645)


## 💡 Usage

1. Power up the Arduino board
2. Adjust left potentiometer to control counting speed
3. Adjust right potentiometer to control counting direction:
   - Left half: Count down (999 to 000)
   - Right half: Count up (000 to 999)
4. Monitor values through Serial port (9600 baud)

## ⚡ How It Works

1. **Direction Control**
   - Potentiometer reading < 512: Count down
   - Potentiometer reading > 512: Count up

2. **Speed Control**
   - Maps potentiometer value (0-1023) to delay (0-255ms)

3. **Display System**
   - Three 7-segment displays using BCD encoding
   - Updates continuously based on counter value

## ⚠️ Important Notes

- Ensure correct BCD decoder connections
- Verify potentiometer wiring
- Use appropriate current-limiting resistors
- Counter loops between 000-999

## 🔧 Assembly Instructions

1. **Display Setup**
   - Connect 7-segment displays via BCD decoders
   - Wire segment control pins correctly
   - Add current-limiting resistors

2. **Control Setup**
   - Wire potentiometers to analog pins
   - Verify ground connections
   - Check power supply stability

## 🔍 Troubleshooting

| Problem | Possible Solution |
|---------|------------------|
| Displays show wrong numbers | Check BCD connections |
| Counter not responding | Verify potentiometer connections |
| Erratic counting | Clean potentiometer contacts |
| Uneven display brightness | Check resistor values |

## 🔄 Version History

- v1.0 (Initial Release)
  - Triple display counter
  - Speed and direction control
  - Serial monitoring

 ## 📝 License

This project is licensed under the MIT License
