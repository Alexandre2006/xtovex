#include <zephyr/types.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/services/dis.h>

#include "config/vexconf.h"
#include "usb/usb_serial.h"
#include "bluetooth/vex_primary.h"

static const struct bt_data advertisement_data[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA_BYTES(BT_DATA_MANUFACTURER_DATA, { 0x06, 0x77, 0x10, 0x30, 0x00, 0x59, 0x83, 0x52, 0x40, 0x00, 0x4B, 0x40, 0x00, 0x11, 0x11, 0x02, 0x8F, 0xC5, 0x83, 0x00 }),
	BT_DATA_BYTES(BT_DATA_UUID128_ALL, {VEX_CONTROLLER_DATA_SERVICE_UUID}),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL,
				  BT_UUID_16_ENCODE(BT_UUID_DIS_VAL))};

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err)
	{
		printk("Connection failed (err 0x%02x)\n", err);
	}
	else
	{
		printk("Connected\n");
	}
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	printk("Disconnected (reason 0x%02x)\n", reason);
}

static void identity_resolved(struct bt_conn *conn, const bt_addr_le_t *rpa,
							  const bt_addr_le_t *identity)
{
	char addr[BT_ADDR_LE_STR_LEN];
	bt_addr_le_to_str(identity, addr, sizeof(addr));
	printk("Identity resolved %s\n", addr);
}

static void le_param_req(struct bt_conn *conn, struct bt_le_conn_param *param)
{
	printk("LE conn param req: int (0x%04x, 0x%04x) lat %d to %d\n",
		   param->interval_min, param->interval_max,
		   param->latency, param->timeout);
}

static void le_param_updated(struct bt_conn *conn, uint16_t interval,
							 uint16_t latency, uint16_t timeout)
{
	printk("LE conn param updated: int 0x%04x lat 0x%04x to 0x%04x\n",
		   interval, latency, timeout);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = connected,
	.disconnected = disconnected,
	.identity_resolved = identity_resolved,
	.le_param_req = le_param_req,
	.le_param_updated = le_param_updated,
};

static void bt_ready(void)
{
	int err;

	printk("Bluetooth initialized\n");

	// Register primary service
	err = vex_primary_services_init();

	if (err)
	{
		printk("Primary service init failed (err %d)\n", err);
		return;
	}

	err = bt_le_adv_start(BT_LE_ADV_CONN_NAME, advertisement_data, ARRAY_SIZE(advertisement_data), NULL, 0);
	if (err)
	{
		printk("Advertising failed to start (err %d)\n", err);
		return;
	}

	printk("Advertising successfully started\n");
}

int main(void)
{
	/*
	 * USB Device Configuration
	 */
	const struct device *dev;

    dev = DEVICE_DT_GET_ONE(zephyr_cdc_acm_uart);
    usb_setup(dev);

	/*
	 * Bluetooth Device Configuration
	 */
	int err;

	// Set MAC Address
	bt_addr_le_t addr;
	err = bt_addr_le_from_str(MAC_ADDRESS, "public", &addr);
	if (err) {
		printk("Invalid BT address (err %d)\n", err);
	}

	err = bt_ctlr_set_public_addr(addr.a.val);

	if (err)
	{
		printk("Bluetooth set public address failed (err %d)\n", err);
		return 0;
	}

	// Enable Bluetooth
	err = bt_enable(NULL);
	if (err)
	{
		printk("Bluetooth init failed (err %d)\n", err);
		return 0;
	}

	bt_ready();

	// while (1)
	// {
	// 	k_sleep(K_SECONDS(1));
	// }
	// return 0;

	while (true) {
		// Get current value
		uint8_t *val = get_dataiq_value();

		// Increment value
		*val += 1;

		// Set new value
		set_dataiq_value(val);

		// Wait
		k_sleep(K_MSEC(10));
	}
}