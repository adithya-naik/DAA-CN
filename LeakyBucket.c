#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Ensure this header is included for sleep() function

#define NOF_PACKETS 10

// Function to generate random values (already defined in stdlib.h, no need to redefine it)
int generate_random(int a) {
    int rn = (rand() % 10) % a;
    return rn == 0 ? 1 : rn;
}

int main() {
    int packet_sz[NOF_PACKETS], i, clk, b_size, o_rate, p_sz_rm = 0, p_sz, p_time, op;
    
    // Generate random packet sizes
    for (i = 0; i < NOF_PACKETS; ++i) {
        packet_sz[i] = generate_random(6) * 10;
    }

    // Display generated packet sizes
    for (i = 0; i < NOF_PACKETS; ++i) {
        printf("\npacket[%d]:%d bytes\t", i, packet_sz[i]);
    }

    // User input for output rate and bucket size
    printf("\nEnter the Output rate: ");
    scanf("%d", &o_rate);
    printf("Enter the Bucket Size: ");
    scanf("%d", &b_size);

    // Processing each packet
    for (i = 0; i < NOF_PACKETS; ++i) {
        if ((packet_sz[i] + p_sz_rm) > b_size) {
            if (packet_sz[i] > b_size) {
                // If incoming packet size is greater than bucket size, reject it
                printf("\n\nIncoming packet size (%d bytes) is Greater than bucket capacity (%d bytes) - PACKET REJECTED", packet_sz[i], b_size);
            } else {
                // If bucket capacity exceeded, reject packet
                printf("\n\nBucket capacity exceeded - PACKETS REJECTED!!");
            }
        } else {
            // Add the packet to the remaining size
            p_sz_rm += packet_sz[i];
            printf("\n\nIncoming Packet size: %d", packet_sz[i]);
            printf("\nBytes remaining to Transmit: %d", p_sz_rm);

            // Generate random transmission time
            p_time = generate_random(4) * 10;
            printf("\nTime left for transmission: %d units", p_time);

            // Simulate the transmission process
            for (clk = 10; clk <= p_time; clk += 10) {
                sleep(1);  // Pause for 1 second

                if (p_sz_rm) {
                    if (p_sz_rm <= o_rate) {
                        // If remaining packet size is less than or equal to output rate, transmit all
                        op = p_sz_rm;
                        p_sz_rm = 0;
                    } else {
                        // Else transmit as much as the output rate
                        op = o_rate;
                        p_sz_rm -= o_rate;
                    }

                    // Display packet transmission status
                    printf("\nPacket of size %d Transmitted", op);
                    printf(" ---- Bytes Remaining to Transmit: %d", p_sz_rm);
                } else {
                    // If no packets are left to transmit
                    printf("\nTime left for transmission: %d units", p_time - clk);
                    printf("\nNo packets to transmit!!");
                }
            }
        }
    }
    return 0;
}


/*


packet[0]:30 bytes	
packet[1]:10 bytes	
packet[2]:10 bytes	
packet[3]:50 bytes	
packet[4]:30 bytes	
packet[5]:50 bytes	
packet[6]:10 bytes	
packet[7]:20 bytes	
packet[8]:30 bytes	
packet[9]:10 bytes	
Enter the Output rate: 40
Enter the Bucket Size: 100


Incoming Packet size: 30
Bytes remaining to Transmit: 30
Time left for transmission: 20 units
Packet of size 30 Transmitted ---- Bytes Remaining to Transmit: 0
Time left for transmission: 0 units
No packets to transmit!!

Incoming Packet size: 10
Bytes remaining to Transmit: 10
Time left for transmission: 30 units
Packet of size 10 Transmitted ---- Bytes Remaining to Transmit: 0
Time left for transmission: 10 units
No packets to transmit!!
Time left for transmission: 0 units
No packets to transmit!!

Incoming Packet size: 10
Bytes remaining to Transmit: 10
Time left for transmission: 10 units
Packet of size 10 Transmitted ---- Bytes Remaining to Transmit: 0

Incoming Packet size: 50
Bytes remaining to Transmit: 50
Time left for transmission: 10 units
Packet of size 40 Transmitted ---- Bytes Remaining to Transmit: 10

Incoming Packet size: 30
Bytes remaining to Transmit: 40
Time left for transmission: 30 units
Packet of size 40 Transmitted ---- Bytes Remaining to Transmit: 0
Time left for transmission: 10 units
No packets to transmit!!
Time left for transmission: 0 units
No packets to transmit!!

Incoming Packet size: 50
Bytes remaining to Transmit: 50
Time left for transmission: 20 units
Packet of size 40 Transmitted ---- Bytes Remaining to Transmit: 10
Packet of size 10 Transmitted ---- Bytes Remaining to Transmit: 0

Incoming Packet size: 10
Bytes remaining to Transmit: 10
Time left for transmission: 10 units
Packet of size 10 Transmitted ---- Bytes Remaining to Transmit: 0

Incoming Packet size: 20
Bytes remaining to Transmit: 20
Time left for transmission: 20 units
Packet of size 20 Transmitted ---- Bytes Remaining to Transmit: 0
Time left for transmission: 0 units
No packets to transmit!!

Incoming Packet size: 30
Bytes remaining to Transmit: 30
Time left for transmission: 20 units
Packet of size 30 Transmitted ---- Bytes Remaining to Transmit: 0
Time left for transmission: 0 units
No packets to transmit!!

Incoming Packet size: 10
Bytes remaining to Transmit: 10
Time left for transmission: 20 units
Packet of size 10 Transmitted ---- Bytes Remaining to Transmit: 0
Time left for transmission: 0 units
No packets to transmit!!

*/
