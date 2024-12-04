## Reform - Ortho Keyboard

![Reform Ortho](https://i.redd.it/teckwqi8zt871.png)

A replacement keyboard for the MNT Reform that fits both the [laptop](https://shop.mntre.com/products/mnt-reform) and [standalone keyboard](https://shop.mntre.com/products/mnt-reform-usb-keyboard-standalone).

PCB designed and maintained by: Sebastiaan Swinkels ([C44Supra](https://github.com/C44Supra)), [BeanBoards.io](https://www.beanboards.io) for [OLKB](https://www.olkb.com)

For default ortho layout, build with:
```
make beanboards/reform:default
```

For ortho layout with 1.5U center column, build with
```
make beanboards/reform:center15u
```

## Bootloader and flashing

By default, this board can be put into flashing mode by pressing `lower` + `raise` + `esc`. Alternatively, flashing mode can be intiated by double pressing the physical DFU button on the PCB, or by pressing and holding the `BS` button prior to connecting the USB cable.

Once in flashing (DFU) mode, you can drag and drop the UF2 firmware onto the drive called `RPI-RP2`. Once the flashing process is complete, the drive will disappear and the keyboard will reboot itself with the new firmware.

Note: the menu that the original reform boards come with hasn't been implemented yet.