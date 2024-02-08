#include "vex_primary.h"
#include "../config/vexconf.h"

// UUIDs
static struct bt_uuid_128 primary_service_uuid = BT_UUID_INIT_128(VEX_CONTROLLER_DATA_SERVICE_UUID);
static struct bt_uuid_128 dataiq_uuid = BT_UUID_INIT_128(VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_UUID);
static struct bt_uuid_128 status_uuid = BT_UUID_INIT_128(VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_UUID);
static struct bt_uuid_128 dataedr_uuid = BT_UUID_INIT_128(VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_UUID);
static struct bt_uuid_128 device_status_uuid = BT_UUID_INIT_128(VEX_CONTROLLER_DATA_CHARACTERISTIC_DEVICE_STATUS_UUID);

// Characteristic User Descriptions
static const char dataiq_user_description[] = VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_USER_DESCRIPTION;
static const char status_user_description[] = VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_USER_DESCRIPTION;
static const char dataedr_user_description[] = VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_USER_DESCRIPTION;
static const char device_status_user_description[] = VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_USER_DESCRIPTION;

// Values
uint8_t dataiq_value[14] = VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_DEFAULT_VALUE;
uint8_t status_value[2] = VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_DEFAULT_VALUE;
uint8_t dataedr_value[20] = VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_DEFAULT_VALUE;
uint8_t device_status[28] = VEX_CONTROLLER_DATA_CHARACTERISTIC_DEVICE_STATUS_DEFAULT_VALUE;

// Callbacks
void dataiq_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset) {
    // Log data
    printk("dataiq_read_callback called");
}
void dataiq_notify_callback(struct bt_conn * conn, uint8_t err, const void * buf, uint16_t len)
{    // Log data
    printk("dataiq_notify_callback called");
}

void status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset) {
    // Log data
    printk("status_read_callback called");
}
void status_write_callback(struct bt_conn * conn, const struct bt_gatt_attr * attr, const void * buf, uint16_t len, uint16_t offset, uint16_t flags)
{    // Log data
    printk("status_write_callback called");
}

void dataedr_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset) {
    // Log data
    printk("dataedr_read_callback called");
}
void dataedr_notify_callback(struct bt_conn *conn, uint8_t err, const void *buf, uint16_t len) {
    // Log data
    printk("dataedr_notify_callback called");
}

void device_status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset) {
    // Log data
    printk("device_status_read_callback called");
}
void device_status_write_callback(struct bt_conn * conn, const struct bt_gatt_attr * attr, const void * buf, uint16_t len, uint16_t offset, uint16_t flags){
    // Log data
    printk("device_status_write_callback called");
}

// Setters
void set_dataiq_value(uint8_t * value, uint16_t len){
    memcpy(dataiq_value, value, sizeof(dataiq_value));
}
void set_status_value(uint8_t *value, uint16_t len) {
    memcpy(status_value, value, sizeof(status_value));
}
void set_dataedr_value(uint8_t *value, uint16_t len) {
    memcpy(dataedr_value, value, sizeof(dataedr_value));
}
void set_device_status(uint8_t *value, uint16_t len) {
    memcpy(device_status, value, sizeof(device_status));
}

// Getters
uint8_t *get_dataiq_value() {
    return dataiq_value;
}
uint8_t *get_status_value() {
    return status_value;
}
uint8_t *get_dataedr_value() {
    return dataedr_value;
}
uint8_t *get_device_status() {
    return device_status;
}

// Initialization
static struct bt_gatt_attr primary_service_attrs[] = {
    BT_GATT_PRIMARY_SERVICE(&primary_service_uuid.uuid),

    // Data IQ Characteristic
    BT_GATT_CHARACTERISTIC(&dataiq_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY, BT_GATT_PERM_READ, dataiq_read_callback, NULL, dataiq_value),
    BT_GATT_DESCRIPTOR(&dataiq_uuid.uuid, BT_GATT_PERM_READ, NULL, dataiq_value, sizeof(dataiq_value)),

    // Status Characteristic
    BT_GATT_CHARACTERISTIC(&status_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, status_read_callback, status_write_callback, status_value),
    BT_GATT_DESCRIPTOR(&status_uuid.uuid, BT_GATT_PERM_READ, NULL, status_value, sizeof(status_value)),

    // Data EDR Characteristic
    BT_GATT_CHARACTERISTIC(&dataedr_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY, BT_GATT_PERM_READ, dataedr_read_callback, NULL, dataedr_value),
    BT_GATT_DESCRIPTOR(&dataedr_uuid.uuid, BT_GATT_PERM_READ, NULL, dataedr_value, sizeof(dataedr_value)),

    // Device Status Characteristic
    BT_GATT_CHARACTERISTIC(&device_status_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, device_status_read_callback, device_status_write_callback, device_status),
    BT_GATT_DESCRIPTOR(&device_status_uuid.uuid, BT_GATT_PERM_READ, NULL, device_status, sizeof(device_status)),
};

static struct bt_gatt_service primary_service = BT_GATT_SERVICE(primary_service_attrs);

int vex_primary_services_init() {
    return bt_gatt_service_register(&primary_service);
}