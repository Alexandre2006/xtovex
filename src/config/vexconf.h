// NOTE:
// All UUIDs are in little-endian format (reversed order)

// MAC ADDRESS
#define MAC_ADDRESS "A4:34:F1:7F:24:99"

/*
 * Device Info:
 *  - Device UUID: 068708B5-C055-9225-E7F3-D86FDF88A678
 *  - Advertisement Manufacturer Data: 0x067710300059835240004b40001111028fc58300 (20 bytes)
 *  - TX Power: 0x00
 *  - Connectable: true
 *  - Device Local Name: "        "
*/

#define DEVICE_UUID { 0x68, 0x87, 0x08, 0xB5, 0xC0, 0x55, 0x92, 0x25, 0xE7, 0xF3, 0xD8, 0x6F, 0xDF, 0x88, 0xA6, 0x78 }
#define MANUFACTURER_DATA { 0x06, 0x77, 0x10, 0x30, 0x00, 0x59, 0x83, 0x52, 0x40, 0x00, 0x4B, 0x40, 0x00, 0x11, 0x11, 0x02, 0x8F, 0xC5, 0x83, 0x00 }
#define DEVICE_LOCAL_NAME "XToVEX Adapter"

/*
 * Vex Controller Data Service:
 * 
 * Service UUID: 08590F7E-DB05-467E-8757-72F6FAEB13A5
 * - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB13B5 (Data for Vex IQ Hardware)
 *   - Characteristic User Description: "DataIQ"
 *   - Client Characteristic Configuration: 0x01 (1 byte)
 *   - Capability: Read, Notify
 *   - Default Value: 0x0000000000000000000000000000 (14 bytes)
 * - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB13C5 (Unsure of use, seems to always be 0x1900)
 *   - Characteristic User Description: "Status."
 *   - Capability: Write, Read
 *   - Default Value: 0x1900 (2 bytes)
 * - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB1336 (Data for Vex EDR/V5 Hardware)
 *   - Characteristic User Description: "DataEDR"
 *   - Client Characteristic Configuration: 0x01 (1 byte)
 *   - Capability: Read, Notify
 *   - Default Value: 0x0000000000000000000000000000000000000000 (20 bytes)
 * - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB1337 (Unsure of use, seems to have filename when file is selected on V5)
 *   - Characteristic User Description: "DeviceStatus"
 *   - Capability: Write, Read
 *   - Default Value: 0x00000000000000000000000000000000000000000000000000000000 (28 bytes)
 */

#define VEX_CONTROLLER_DATA_SERVICE_UUID 0xA5, 0x13, 0xEB, 0xFA, 0xF6, 0x72, 0x57, 0x87, 0x7E, 0x46, 0x05, 0xDB, 0x7E, 0x0F, 0x59, 0x08

#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_UUID 0xB5, 0x13, 0xEB, 0xFA, 0xF6, 0x72, 0x57, 0x87, 0x7E, 0x46, 0x05, 0xDB, 0x7E, 0x0F, 0x59, 0x08
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_USER_DESCRIPTION "DataIQ"
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_CLIENT_CHARACTERISTIC_CONFIGURATION 0x01
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_IQ_DEFAULT_VALUE {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

#define VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_UUID 0xC5, 0x13, 0xEB, 0xFA, 0xF6, 0x72, 0x57, 0x87, 0x7E, 0x46, 0x05, 0xDB, 0x7E, 0x0F, 0x59, 0x08
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_USER_DESCRIPTION "Status."
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_STATUS_DEFAULT_VALUE {0x19, 0x00}

#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_UUID 0x36, 0x13, 0xEB, 0xFA, 0xF6, 0x72, 0x57, 0x87, 0x7E, 0x46, 0x05, 0xDB, 0x7E, 0x0F, 0x59, 0x08
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_USER_DESCRIPTION "DataEDR"
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_CLIENT_CHARACTERISTIC_CONFIGURATION 0x01
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DATA_EDR_DEFAULT_VALUE {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DEVICE_STATUS_UUID 0x37, 0x13, 0xEB, 0xFA, 0xF6, 0x72, 0x57, 0x87, 0x7E, 0x46, 0x05, 0xDB, 0x7E, 0x0F, 0x59, 0x08
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DEVICE_STATUS_USER_DESCRIPTION "DeviceStatus"
#define VEX_CONTROLLER_DATA_CHARACTERISTIC_DEVICE_STATUS_DEFAULT_VALUE {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

/*
* Vex Controller Serial Service:
* 
* Service UUID: 08590F7E-DB05-467E-8757-72F6FAEB13D5
* - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB1306 (Unsure which serial channel this is for, but Transmit)
*   - Characteristic User Description: "TXData"
*   - Characteristic Presentation Format: 0x01 (1 byte)
*   - Capability: Notify, Indicate, WriteWithoutResponse
*   - Default Value: None
* - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB1316 (Unsure which serial channel this is for, but Transmit)
*   - Characteristic User Description: "TXUser"
*   - Characteristic Presentation Format: 0x01 (1 byte)
*   - Capability: Notify, Indicate, WriteWithoutResponse
*   - Default Value: None
* - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB1326 (Unsure which serial channel this is for, but Receive)
*   - Characteristic User Description: "RXUser"
*   - Characteristic Presentation Format: 0x01 (1 byte)
*   - Capability: Write, Notify, WriteWithoutResponse
*   - Default Value: None
* - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB13E5 (Static Code)
*   - Characteristic User Description: "Code"
*   - Characteristic Presentation Format: 0x0 (1 byte)
*   - Capability: Write, Read, WriteWithoutResponse
*   - Default Value: 0xdeadface (4 bytes)
* - Characteristic UUID: 08590F7E-DB05-467E-8757-72F6FAEB13F5 (Unsure which serial channel this is for, but Receive)
*   - Characteristic User Description: "RXData"
*   - Characteristic Presentation Format: 0x01 (1 byte)
*   - Capability: Write, Notify, WriteWithoutResponse
*   - Default Value: None
*/

#define VEX_CONTROLLER_SERIAL_SERVICE_UUID { 0x08, 0x59, 0x0F, 0x7E, 0xDB, 0x05, 0x46, 0x7E, 0x87, 0x57, 0x72, 0xF6, 0xFA, 0xEB, 0x13, 0xD5 }

#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_TX_DATA_UUID { 0x08, 0x59, 0x0F, 0x7E, 0xDB, 0x05, 0x46, 0x7E, 0x87, 0x57, 0x72, 0xF6, 0xFA, 0xEB, 0x13, 0x06 }
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_TX_DATA_USER_DESCRIPTION "TXData"
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_TX_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION 0x01

#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_TX_USER_UUID { 0x08, 0x59, 0x0F, 0x7E, 0xDB, 0x05, 0x46, 0x7E, 0x87, 0x57, 0x72, 0xF6, 0xFA, 0xEB, 0x13, 0x16 }
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_TX_USER_USER_DESCRIPTION "TXUser"
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_TX_USER_CLIENT_CHARACTERISTIC_CONFIGURATION 0x01

#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_RX_USER_UUID { 0x08, 0x59, 0x0F, 0x7E, 0xDB, 0x05, 0x46, 0x7E, 0x87, 0x57, 0x72, 0xF6, 0xFA, 0xEB, 0x13, 0x26 }
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_RX_USER_USER_DESCRIPTION "RXUser"
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_RX_USER_PRESENTATION_FORMAT 0x01

#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_CODE_UUID { 0x08, 0x59, 0x0F, 0x7E, 0xDB, 0x05, 0x46, 0x7E, 0x87, 0x57, 0x72, 0xF6, 0xFA, 0xEB, 0x13, 0xE5 }
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_CODE_CLIENT_CHARACTERISTIC_CONFIGURATION "Code"
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_CODE_PRESENTATION_FORMAT 0x0
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_CODE_DEFAULT_VALUE 0xdeadface

#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_RX_DATA_UUID { 0x08, 0x59, 0x0F, 0x7E, 0xDB, 0x05, 0x46, 0x7E, 0x87, 0x57, 0x72, 0xF6, 0xFA, 0xEB, 0x13, 0xF5 }
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_RX_DATA_USER_DESCRIPTION "RXData"
#define VEX_CONTROLLER_SERIAL_CHARACTERISTIC_RX_DATA_CLIENT_CHARACTERISTIC_CONFIGURATION 0x01 