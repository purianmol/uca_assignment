#include <float.h>
#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames];
    int last_used[num_frames]; // Timestamp array
    int page_faults = 0;

    // Initialize empty slots
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {
        int page = page_requests[time];
        bool hit = false;

        // TODO 1: Check if 'page' is already in 'frames' (HIT)
        // If found, mark hit = true and update last_used[frame_index] = time.
        for(int i = 0 ; i < num_frames ; i++){
            if(frames[i] == page){
                hit = true;
                last_used[i] = time;
                break;
            }
        }

        // TODO 2: Handle PAGE FAULT if not found
        // - Increment page_faults counter.
        // - Check for an empty slot (frames[i] == -1).
        // - If full, iterate through last_used[] to find the smallest timestamp (LRU).
        // - Replace that frame with 'page' and update its timestamp to 'time'.
        if(!hit){
            page_faults++;
            int frame_index = -1;
            for(int i = 0 ; i < num_frames ; i++){
                if(frames[i] == -1){
                    frame_index = i;
                    break;
                }
            }

            if(frame_index == -1){
                frame_index=0;
                for(int i =1 ; i < num_frames ; i++){
                    if(last_used[i] < last_used[frame_index]){
                        frame_index = i;
                    }
                }
            }   

            frames[frame_index] = page;
            last_used[frame_index] = time;
        }

    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);
    
    simulate_lru(requests, num_requests, 3);
    return 0;
}
