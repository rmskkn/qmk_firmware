## How to compile keyboard

All basic preparation steps are described in
<https://docs.qmk.fm/newbs_getting_started>

1. Fetch all modules
```
qmk git-submodules
```

2. Compile
```
bear make SHELL='sh -x' handwired/dactyl_cc:default
```

!!! Don't need to perfrom recompilation with bear, only initial.

3. Flash image
3.1. Activate BOOT mode on the keyboard

3.2. Copy image to disk
```
cp handwired_dactyl_cc_default.uf2 /media/<user>/RPI-RP2
```

4. Debug
HID console
```
qmk console -d 444D:3636
```

