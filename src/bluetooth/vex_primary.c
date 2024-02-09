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
ssize_t dataiq_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset)
{
    // Log Activity
    printk("dataiq_read_callback called\n");

    // Write data to buffer
    memcpy(buf, dataiq_value, sizeof(dataiq_value));

    // Return length
    return sizeof(dataiq_value);
}

ssize_t status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset)
{
    // Log data
    printk("status_read_callback called\n");

    // Write data to buffer
    memcpy(buf, status_value, sizeof(status_value));

    // Return length
    return sizeof(status_value);
}
ssize_t status_write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
    // Log data
    printk("status_write_callback called\n");

    // Save data
    memcpy(status_value, buf, sizeof(status_value));

    // Return length
    return sizeof(status_value);
}

ssize_t dataedr_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset)
{
    // Log data
    printk("dataedr_read_callback called\n");

    // Write data to buffer
    memcpy(buf, dataedr_value, sizeof(dataedr_value));

    // Return length
    return sizeof(dataedr_value);
}

ssize_t device_status_read_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, void *buf, uint16_t len, uint16_t offset)
{
    // Log data
    printk("device_status_read_callback called\n");

    // Write data to buffer
    memcpy(buf, device_status, sizeof(device_status));

    // Return length
    return sizeof(device_status);
}
ssize_t device_status_write_callback(struct bt_conn *conn, const struct bt_gatt_attr *attr, const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
    // Log data
    printk("device_status_write_callback called\n");

    // Save data
    memcpy(device_status, buf, sizeof(device_status));

    // Return length
    return sizeof(device_status);
}

// Initialization
static struct bt_gatt_attr primary_service_attrs[] = {
    BT_GATT_PRIMARY_SERVICE(&primary_service_uuid.uuid),

    // Data IQ Characteristic
    BT_GATT_CHARACTERISTIC(&dataiq_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY, BT_GATT_PERM_READ, dataiq_read_callback, NULL, dataiq_value),
    BT_GATT_DESCRIPTOR(&dataiq_uuid.uuid, BT_GATT_PERM_READ, NULL, dataiq_value, sizeof(dataiq_value)),
    BT_GATT_CCC(ccc_callback, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

    // Status Characteristic
    BT_GATT_CHARACTERISTIC(&status_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, status_read_callback, status_write_callback, status_value),
    BT_GATT_DESCRIPTOR(&status_uuid.uuid, BT_GATT_PERM_READ, NULL, status_value, sizeof(status_value)),

    // Data EDR Characteristic
    BT_GATT_CHARACTERISTIC(&dataedr_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_NOTIFY, BT_GATT_PERM_READ, dataedr_read_callback, NULL, dataedr_value),
    BT_GATT_DESCRIPTOR(&dataedr_uuid.uuid, BT_GATT_PERM_READ, NULL, dataedr_value, sizeof(dataedr_value)),
    BT_GATT_CCC(ccc_callback, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE),

    // Device Status Characteristic
    BT_GATT_CHARACTERISTIC(&device_status_uuid.uuid, BT_GATT_CHRC_READ | BT_GATT_CHRC_WRITE, BT_GATT_PERM_READ | BT_GATT_PERM_WRITE, device_status_read_callback, device_status_write_callback, device_status),
    BT_GATT_DESCRIPTOR(&device_status_uuid.uuid, BT_GATT_PERM_READ, NULL, device_status, sizeof(device_status)),
};

// CCC Values
uint16_t dataiq_ccc_value = 0;
uint16_t dataedr_ccc_value = 0;

// CCC Callback
void ccc_callback(const struct bt_gatt_attr *attr, uint16_t value)
{
    // Log data
    printk("ccc_callback called\n");

    // Check which characteristic this CCC belongs to
    if (attr == &primary_service_attrs[4])
    {
        dataiq_ccc_value = value;

        // Log data
        printk("dataiq_ccc_value: %d\n", dataiq_ccc_value);
    }
    else if (attr == &primary_service_attrs[11])
    {
        dataedr_ccc_value = value;

        // Log data
        printk("dataedr_ccc_value: %d\n", dataedr_ccc_value);
    }
    else
    {
        printk("Unknown CCC\n");
    }
}

static struct bt_gatt_service primary_service = BT_GATT_SERVICE(primary_service_attrs);

int vex_primary_services_init()
{
    return bt_gatt_service_register(&primary_service);
}

// Getters
uint8_t *get_dataiq_value()
{
    return dataiq_value;
}
uint8_t *get_status_value()
{
    return status_value;
}
uint8_t *get_dataedr_value()
{
    return dataedr_value;
}
uint8_t *get_device_status()
{
    return device_status;
}

// Setters
void set_dataiq_value(uint8_t *value)
{
    // Set data
    memcpy(dataiq_value, value, sizeof(dataiq_value));

    // Notify clients
    if (dataiq_ccc_value == BT_GATT_CCC_NOTIFY)
    {
        bt_gatt_notify(NULL, &primary_service_attrs[1], dataiq_value, sizeof(dataiq_value));
    }
}
void set_status_value(uint8_t *value)
{
    memcpy(status_value, value, sizeof(status_value));
}

void set_dataedr_value(uint8_t *value)
{
    // Set data
    memcpy(dataedr_value, value, sizeof(dataedr_value));

    // Notify clients
    if (dataedr_ccc_value == BT_GATT_CCC_NOTIFY)
    {
        bt_gatt_notify(NULL, &primary_service_attrs[6], dataedr_value, sizeof(dataedr_value));
    }
}
void set_device_status(uint8_t *value)
{
    memcpy(device_status, value, sizeof(device_status));
}
