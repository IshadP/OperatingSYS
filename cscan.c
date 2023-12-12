#include <stdio.h>

int main() {
    int t = 200;
    int rq[] = {82, 170, 43, 140, 24, 16, 190};
    int curr = 50;

    // For Forward Direction
    int goBackward = 0;
    int lsttrkbck = 0;
    int lsttrkfor = curr;
    for (int i = 0; i < sizeof(rq) / sizeof(rq[0]); i++) {
        int track = rq[i];
        if (track < curr) {
            goBackward = 1;
            lsttrkfor = t - 1;
            if (lsttrkbck < track) {
                lsttrkbck = track;
            }
        }
        if (!goBackward) {
            if (lsttrkfor < track)
                lsttrkfor = track;
        }
    }

    int no_of_track_movement = lsttrkfor - curr;
    if (goBackward)
        no_of_track_movement += t - 1 - lsttrkbck;

    printf("No of Track Movement: %d\n", no_of_track_movement);

    return 0;
}
