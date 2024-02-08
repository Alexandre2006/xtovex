#ifndef USB_SERIAL_H
#define USB_SERIAL_H

#include <zephyr/drivers/uart.h>
#include <zephyr/sys/ring_buffer.h>
#include <zephyr/logging/log.h>

#define RING_BUF_SIZE 1024

extern uint8_t ring_buffer[RING_BUF_SIZE];
extern struct ring_buf ringbuf;
extern bool rx_throttled;

void interrupt_handler(const struct device *dev, void *user_data);
void usb_setup(const struct device *dev);

#endif