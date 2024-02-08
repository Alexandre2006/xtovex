#ifndef VEX_SERVICES_H
#define VEX_SERVICES_H

#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

// Callbacks
void dataiq_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);
void dataiq_notify_callback(struct bt_conn *conn, uint8_t err, const void *buf, uint16_t len);

void status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);
void status_write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint16_t flags);

void dataedr_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);
void dataedr_notify_callback(struct bt_conn *conn, uint8_t err, const void *buf, uint16_t len);

void device_status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);
void device_status_write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint16_t flags);

// Setters
void set_dataiq_value(uint8_t *value, uint16_t len);
void set_status_value(uint8_t *value, uint16_t len);
void set_dataedr_value(uint8_t *value, uint16_t len);
void set_device_status_value(uint8_t *value, uint16_t len);

// Getters
uint8_t *get_dataiq_value();
uint8_t *get_status_value();
uint8_t *get_dataedr_value();
uint8_t *get_device_status_value();

// Initialization
int vex_primary_services_init();

#endif