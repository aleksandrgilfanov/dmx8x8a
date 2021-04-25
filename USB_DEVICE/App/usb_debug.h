#ifndef USB_DEBUG_H
#define USB_DEBUG_H

#include <stdint.h>

void usb_printf(char *fmt, ...);
void usb_dump(uint8_t *src_packet, uint16_t len, uint16_t channel);

#endif		/* USB_DEBUG_H */
