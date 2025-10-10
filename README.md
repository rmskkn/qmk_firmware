## How to compile keyboard

All basic preparation steps are described in
<https://docs.qmk.fm/newbs_getting_started>

1. Fetch all modules
```
qmk git-submodule
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
cp handwired_dactyl_cc_default.uf2 /media/$(whoami)/RPI-RP2
```

4. Debug
HID console
```
qmk console -d 444D:3636
```

### For QMK debug console need to install hid-raw libs:
```
sudo apt install -y libhidapi-hidraw0 libusb-dev`
pip3 uninstall hid
pip3 install hid==1.0.4
```

### Also, we need to add hidraw udev rules:
1. echo 'KERNEL=="hidraw*", SUBSYSTEM=="hidraw", MODE="0666", TAG+="uaccess", TAG+="udev-acl"' | sudo tee /etc/udev/rules.d/92-qmk.rules
2. sudo udevadm control --reload-rules
3. sudo udevadm trigger
