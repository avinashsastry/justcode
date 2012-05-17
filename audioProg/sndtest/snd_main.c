#include <stdio.h>
#include <sndfile.h>
#include <stdlib.h>
#include "fft_func.h"
#include <math.h>

#define BUFFER_LENGTH 1024
#define FFT_LENGTH 1024
#define FFT_SQRT 32

void process_data(double *data_in, double* data_out, int readcount, int channels);

int main(void)
{
  double data_in[BUFFER_LENGTH];
  double data_out[BUFFER_LENGTH];

  SNDFILE *infile;
  SNDFILE *outfile;
  SF_INFO sfinfo;
  int readcount;
  const char *infilename="in.wav";
  const char *outfilename="out.wav";
  
  if(!(infile = sf_open(infilename, SFM_READ, &sfinfo)))
  {
    printf("ERROR:Unable to open file %s\n", infilename);
    puts(sf_strerror(NULL));
    return -1;
  }

if(!(outfile = sf_open(outfilename, SFM_WRITE, &sfinfo)))
  {
    printf("ERROR:Unable to open file %s\n", outfilename);
    puts(sf_strerror(NULL));
    return -1;
  }

 while ((readcount = sf_read_double(infile, data_in, BUFFER_LENGTH)))
 {
   process_data(data_in, data_out, readcount, sfinfo.channels);
   sf_write_double(outfile, data_out, readcount);
 }

 sf_close(infile);
 sf_close(outfile);
 return 0;
}

void process_data(double *data_in, double *data_out, int readcount, int channels)
{
    int i =0;
    int *ip;                // Working space for rdft()
    double *w;              // Cos/Sin tables 
    double fft_out[BUFFER_LENGTH];

    ip = (int*) malloc(sizeof(int)*(FFT_SQRT+2));
    w = (double*) malloc(sizeof(double)*(BUFFER_LENGTH*5/4));
    ip[0] = 0;
    double err_sum_sq = 0;

    // mono file only
    if (channels == 1) {
        fft_rdft(BUFFER_LENGTH/2, BUFFER_LENGTH/4, BUFFER_LENGTH, data_in, fft_out);     
        fft_irdft(BUFFER_LENGTH/2, BUFFER_LENGTH/2, BUFFER_LENGTH, fft_out, data_out);
    }
    else {
        printf("ERROR: Only mono files will work");
    }
}
