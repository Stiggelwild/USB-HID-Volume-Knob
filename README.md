![1](https://user-images.githubusercontent.com/82065607/114857176-41fceb80-9de8-11eb-8298-961016332502.png)

# USB-HID-Volume-Knob
In this Project I built a volume knob that controls your pc directly instead of your audio output

Editors note: I don't advise anyone to use a small case like mine because you can screw up very easily in confined spaces like this

# Hardware Used:
- Seeeduino Xiao / pro micro
- usb cable
- pc
- small can (sold as empty makeup container)
- Knob (in my case a 3D printed adaptor from a bottle cap to D-Shaft)
- Rotary encoder
- Wires
- Soldering Iron 
- Kapton Tape


# Software Used:
- Arduino IDE
    - HID-Project.h
- Fusion 360

# Wiring diagram:
<img width="283" alt="Bildschirmfoto 2021-04-15 um 13 49 23" src="https://user-images.githubusercontent.com/82065607/114864662-8e005e00-9df1-11eb-8424-1b598b5e9dd0.png">

- Black  → Ground
- Green  → Button → D2
- Purple → out A  → D3
- Blue   → out B  → D4

# Special Thanks to:
- Niko Hood for his [HID Library](https://github.com/NicoHood/HID)
- [This Video](https://www.youtube.com/watch?v=V1txmR8GXzE) that taught me everything I need to know about rotary encoders


