#include <stdio.h>
#include "gain_control.h"
#define FRAMESIZE 160

int main(int argc, char** argv)
{
	FILE *fpInput, *fpOutput;
	void *handle;
	int status;
	int maxLevel = 255;
	int minLevel = 0;
	int fs = 8000;
	short audioframe[FRAMESIZE];
	short outputframe[FRAMESIZE];
	int inMicLevel  = 50/*(maxLevel - minLevel) >> 1*/;
	int outMicLevel = 0;
	WebRtcAgc_config_t config;
	WebRtc_UWord8 saturationWarning = 0;
	config.compressionGaindB = 9;
	config.limiterEnable = kAgcFalse;
	config.targetLevelDbfs = 3;

	status = WebRtcAgc_Create(&handle);
	if (status != 0)
	{
		printf("Create Failure\n");
		return -1;
	}
	status = WebRtcAgc_Init(handle, minLevel, maxLevel, kAgcModeAdaptiveDigital, fs);
	//WebRtcAgc_VirtualMic
	if (status != 0)
	{
		printf("Init Failure\n");
		return -1;
	}
	status = WebRtcAgc_set_config(handle, config);
	if (status != 0)
	{
		printf("Set_config Failure\n");
		return -1;
	}
	fpInput = fopen("test.pcm", "rb");
	fpOutput = fopen("test1.pcm", "wb");
	//WebRtcSpl_AnalysisQMF
	while (!feof(fpInput))
	{
		fread(audioframe, sizeof(short), FRAMESIZE, fpInput);
		status = WebRtcAgc_Process(handle, audioframe, NULL, FRAMESIZE, outputframe, NULL, inMicLevel, &outMicLevel, 0, &saturationWarning);
		if (status != 0)
		{
			printf("WebRtcAgc_Process is error\n");
			return -1;
		}
		//inMicLevel = outMicLevel;
		fwrite(outputframe, sizeof(short), FRAMESIZE, fpOutput);
	}
	fclose(fpInput);
	fclose(fpOutput);
	status = WebRtcAgc_Free(handle);
	if (status != 0)
	{
		printf("WebRtcAgc_Free Failure\n");
		return -1;
	}
	printf("Finish\n");
	getchar();
	return 0;
}