#include <stdio.h>

// fft_func function declarations
int fft_rdft(int nfft, int hopsize, int buffer_length, double* data_in, double* data_out);
int fft_irdft(int nfft, int hopsize, int buffer_length, double* data_in, double* data_out);

// Ooura fft function declarations
void cdft(int, int, double *, int *, double *);
void rdft(int, int, double *, int *, double *);
void ddct(int, int, double *, int *, double *);
void ddst(int, int, double *, int *, double *);
void dfct(int, double *, double *, int *, double *);
void dfst(int, double *, double *, int *, double *);

