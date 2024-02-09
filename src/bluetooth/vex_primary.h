#ifndef VEX_SERVICES_H
#define VEX_SERVICES_H

#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>

// Callbacks
ssize_t dataiq_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);
ssize_t status_write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint8_t flags);

ssize_t dataedr_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);

ssize_t device_status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset);
ssize_t device_status_write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint8_t flags);

void ccc_callback(const struct bt_gatt_attr *attr, uint16_t value);

// Getters
uint8_t *get_dataiq_value();
uint8_t *get_status_value();
uint8_t *get_dataedr_value();
uint8_t *get_device_status();

// Setters
void set_dataiq_value(uint8_t *value);
void set_status_value(uint8_t *value);
void set_dataedr_value(uint8_t *value);
void set_device_status(uint8_t *value);


// Initialization
int vex_primary_services_init();

#endif