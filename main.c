#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp, *fp_out;
	unsigned char in[2];
	float out[2];

	fp = fopen("fm_sdr", "r");
	fp_out = fopen("fm_sdr_fp", "w+");

	while(fread(in, 1, 2, fp)){
		out[0] = in[0];
		out[1] = in [1];

		out[0] = (out[0] - 127)*(1.0/128);
		out[1] = (out[1] - 127)*(1.0/128);

		fwrite(out, sizeof(float), 2, fp_out);
	}

	return 1;
}
