// Wrapper for the Ooura FFT library

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "fft_func.h"

// rfft() - Calls Ooura's rdft
int fft_rdft(int nfft, int hopsize, int buffer_length, double* data_in, double* data_out) {
    
    // Initialize variables
    int i = 0;              // Counter
    int *ip;                 // Working space for rdft()
    double *w;              // Cos/Sin tables 
    double *frame_buf;      // Buffer for frames

    // Initialize cursors - pointers for navigation in buffer
    double* frame_start;
    double* data_start;

    // allocate memory
    ip = (int*) malloc(sizeof(int)*((int)pow(nfft, 0.5)+2));
    w = (double*) malloc(sizeof(double)*(nfft*5/4));
    frame_buf = (double*) malloc(sizeof(double)*nfft);

    // A step that is needed by Ooura rdft
    // initilizes the cos/sin tables
    ip[0] = 0; 
        
    frame_start = data_in;
    data_start = data_out;

    while ((frame_start + nfft) <= (data_in + buffer_length)) {
        printf("Processing RFFT...");
        // Copy from data_in to frame
        // Because rdft() is in-place
        memcpy(frame_buf, frame_start, sizeof(double)*nfft);

        // Get rfft of frame
        rdft(nfft, 1, frame_buf, ip, w);
        
        // scale amplitude
        for (i = 0; i < nfft; i++) {
            frame_buf[i] *= 2.0/nfft;
        }

        // Write to data_out        
        memcpy(data_start, frame_buf, sizeof(double)*nfft);          

        // Advance the pointers
        frame_start += hopsize;
        data_start += nfft;
    }

    // Free up memory
    if (ip) free(ip);
    if (w) free(w);
    if (frame_buf) free(frame_buf);
}  

int fft_irdft(int nfft, int hopsize, int buffer_length, double* data_in, double* data_out) {
    // Initialize variables
    int i = 0;              // Counter
    int *ip;                 // Working space for rdft()
    double *w;              // Cos/Sin tables 
    double *frame_buf;      // Buffer for frames

    // Initialize cursors - pointers for navigation in buffer
    double* frame_start;
    double* data_start;

    // allocate memory
    ip = (int*) malloc(sizeof(int)*((int)pow(nfft, 0.5)+2));
    w = (double*) malloc(sizeof(double)*(nfft*5/4));
    frame_buf = (double*) malloc(sizeof(double)*nfft);

    // A step that is needed by Ooura rdft
    // initilizes the cos/sin tables
    ip[0] = 0; 
        
    frame_start = data_in;
    data_start = data_out;

    while ((frame_start + nfft) <= (data_in + buffer_length)) {
        printf("Taking IFFT...\n");
        // copy frame to frame_buf
        memcpy(frame_buf, frame_start, sizeof(double)*nfft);
        
        // Take ifft
        rdft(nfft, -1, frame_buf, ip, w);

        // copy this to data_out
        memcpy(data_start, frame_buf, sizeof(double)*nfft);
        
        // Advance the pointers
        frame_start += nfft;
        data_start += hopsize;
    }
    
    // Free up memory
    if (ip) free(ip);
    if (w) free(w);
    if (frame_buf) free(frame_buf);
}
