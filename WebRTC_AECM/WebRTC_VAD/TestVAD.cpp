#include <stdio.h>
#include "webrtc_vad.h"

#define FRAMESIZE 160
int main(int argc, char** argv)
{
	FILE *fpInput, *fpOutput;
	VadInst * handle;
	int status;
	int fs = 8000;
	short audioFrame[FRAMESIZE];
	handle = NULL;
	status = WebRtcVad_Create(&handle);
	if (status != 0)
	{
		printf("Create is error \n");
		return -1;
	}
	status = WebRtcVad_Init(handle);
	if (status != 0)
	{
		printf("Init is error\n");
		return -1;
	}
	fpInput = fopen("test.pcm", "rb");
	fpOutput = fopen("test1.txt", "wb");
	if (fpInput == NULL)
	{
		printf("open file failure\n");
		return -1;
	}

	status = WebRtcVad_set_mode(handle, 2);
	if (status != 0)
	{
		printf("set mode is error\n");
		return -1;
	}
	while (!feof(fpInput))
	{
		fread(audioFrame, sizeof(short), FRAMESIZE, fpInput);
		status = WebRtcVad_Process(handle, fs, audioFrame, FRAMESIZE);
		if (status == -1)
		{
			printf("WebRtcVad_Process is error\n");
			return -1;
		}
		else if (status == 1)
		{
			printf("Active Voice\n");
			
		}
		else
		{
			printf("Non-active Voice\n");
		}
		fprintf(fpOutput, "%2d", status);
	}
	fclose(fpInput);
	fclose(fpOutput);
	status = WebRtcVad_Free(handle);
	if (status != 0)
	{
		printf("Free is failure\n");
		return -1;
	}
	printf("Finished \n");
	getchar();
	return 0;
}