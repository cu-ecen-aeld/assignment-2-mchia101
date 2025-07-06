#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    // Open syslog for logging
    openlog("writer", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writer program started");

    // Check for correct number of arguments
    if(argc != 3) {
        // fprintf(stderr, "Usage: %s <filename> <string>\n", argv[0]);
        syslog(LOG_ERR, "Usage: %s <filename> <string>\n", argv[0]);
        return 1;
    }

    // Open in create/append mode with read/write
    FILE *file = fopen(argv[1], "a+"); 
    if(file == NULL) {
        perror("Error opening file");
        syslog(LOG_ERR, "Error opening file: %s", argv[1]);
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    if(fprintf(file, "%s", argv[2]) < 0) {
        syslog(LOG_ERR, "Error writing to file: %s", argv[1]);
        fclose(file);
        return 1;
    }
    fclose(file);
    syslog(LOG_DEBUG, "Successfully wrote to file: %s", argv[1]);

    return 0;
}