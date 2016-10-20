#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <signal.h>

#define TRIESMAX 5
#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1 /* POSIX compliant source */
#define FALSE 0
#define TRUE 1
#define FLAG 0x7e
#define A_TR 0x03
#define A_RT 0x01
#define C_SET 0x03
#define C_UA 0x07
#define RECEIVER 0
#define TRANSMITTER 1
#define SUPERVISIONPACKAGE 5

struct linkLayer {
    char port[20];
    int baudRate;
    unsigned int sequenceNumber;
    unsigned int timeout;
    unsigned int numTransmissions;

    char frame[CONTROLPACKAGESIZE]; //MAX_SIZE not defined
}

void handleAlarm();
int sendMessage(int fd, char* message);
int receiveMessage(int fd, char* message);
int llopen(int fd, int connectionMode);