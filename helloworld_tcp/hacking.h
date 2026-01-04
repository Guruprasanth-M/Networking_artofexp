//Page_no:238
//Dumps	raw	memory in hex	byte and printable split format
void dump(const unsigned char *data_buffer, const unsigned int length) {
    unsigned char byte;
    unsigned int i, j;

    for (i = 0; i < length; i++) {
        byte = data_buffer[i];
        printf("%02x ", byte);  // Display byte in hex

        // End of line (16 bytes) or last byte
        if (((i % 16) == 15) || (i == length - 1)) {
            // Pad spaces if line not full
            for (j = 0; j < 15 - (i % 16); j++) {
                printf("   ");
            }

            // Separator
            printf(" | ");

            // Print ASCII characters
            for (j = (i - (i % 16)); j <= i; j++) {
                byte = data_buffer[j];
                if ((byte > 31) && (byte < 127)) // Printable ASCII
                    printf("%c", byte);
                else
                    printf(".");
            }

            printf("\n"); // End of dump line
        }
    }
}
