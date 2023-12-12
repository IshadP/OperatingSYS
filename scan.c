#include <stdio.h>

int main() {
    int t = 200;
    int requestq[] = {82, 170, 43, 140, 24, 16, 190};
    int curr = 50;


    int goBackward = 0;
    int lastTrackBackward = curr;
    int lastTrackForward = curr;
    for (int i = 0; i < sizeof(requestq) / sizeof(requestq[0]); i++) {
        int track = requestq[i];
        if (track < curr) {
            goBackward = 1;
            lastTrackForward =t - 1;
            if (track < lastTrackBackward) {
                lastTrackBackward = track;
            }
        }
        if (!goBackward) {
            if (lastTrackForward < track) {
                lastTrackForward = track;
            }
        }
    }

    int no_of_track_movement = lastTrackForward - curr;
    if (goBackward) {
        no_of_track_movement += lastTrackForward - lastTrackBackward;
    }

    printf("No of Track Movement: %d\n", no_of_track_movement);

    return 0;
}