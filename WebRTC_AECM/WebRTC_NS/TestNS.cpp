#include <stdio.h>
#include "noise_suppression.h"
#include "noise_suppression_x.h"

#define FRAMESIZE 160
int main(int argc, char** argv)
{
	FILE *fpinput, *fpoutput;
	int samples = 8000;
	int status;
	NsHandle *nsHandle;
	short audioframe[FRAMESIZE];
	short outframe[FRAMESIZE];

	status = WebRtcNs_Create(&nsHandle);
	if (status != 0)
	{
		printf("Create Failure\n");
		return -1;
	}

	status = WebRtcNs_Init(nsHandle, samples);
	if (status != 0)
	{
		printf("Init Failure\n");
		return -1;
	}
	status = WebRtcNs_set_policy(nsHandle, 2);
	if (status != 0)
	{
		printf("set_policy Failure\n");
		return -1;
	}
	fpinput = fopen("test1.pcm", "rb");
	fpoutput = fopen("test2.pcm", "wb");
	memset(outframe, 0, sizeof(outframe));
	while (!feof(fpinput))
	{
		fread(audioframe, sizeof(short), FRAMESIZE, fpinput);
		status = WebRtcNs_Process(nsHandle, audioframe, NULL, outframe, NULL);
		if (status != 0)
		{
			printf("WebRtcNs_Process Failure\n");
			return -1;
		}
		status = WebRtcNs_Process(nsHandle, audioframe+80, NULL, outframe+80, NULL);
		if (status != 0)
		{
			printf("WebRtcNs_Process Failure\n");
			return -1;
		}
		fwrite(outframe, sizeof(short), FRAMESIZE, fpoutput);
	}

	fclose(fpinput);
	fclose(fpoutput);
	status = WebRtcNs_Free(nsHandle);
	if (status != 0)
	{
		printf("WebRtcNs_Free Failure\n");
		return -1;
	}
	printf("Finish\n");
	getchar();
	return 0;
}