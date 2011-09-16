/**
 * Reads value assigned to specified user in configuration file
 * @param user Username
 * @param buffer Output buffer for serial number
 * @param size Buffer size
 * @return 0 on success or -1 on failure
 */
int get_serial(const char* user, char* buffer, unsigned int size);

/**
 * Checks whether a USB device with specified serial number is connected
 * @param serial Serial number
 * @return Check result
 */
int check_serial(const char* serial);
