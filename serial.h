/**
 * Reads a serial number assigned to the user from the configuration file
 * @param user   User name
 * @param buffer Output buffer for a serial number
 * @param size   Buffer size
 * @return       0 on success, -1 on failure
 */
int get_serial(const char* user, char* buffer, unsigned int size);

/**
 * Checks whether a USB device with the specified serial number is connected
 * @param serial Serial number
 * @return       1 if connected, otherwise 0
 */
int check_serial(const char* serial);
