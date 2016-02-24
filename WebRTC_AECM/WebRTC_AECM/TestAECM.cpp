#include <stdio.h>
#include "echo_control_mobile.h"
int main(int argc, char** argv)
{
	void *AecmInst;
	printf("create -- %d\n", WebRtcAecm_Create(&AecmInst));
	printf("init -- %d\n", WebRtcAecm_Init(AecmInst, 8000));
	AecmConfig config;
	config.cngMode = AecmTrue;
	config.echoMode = 4;

	printf("config -- %d\n", WebRtcAecm_set_config(AecmInst, config));

	FILE *fp = fopen("aec_near.pcm", "rb");   //输入
	FILE *fps = fopen("aec_far.pcm", "rb");
	FILE *outfp = fopen("out23.pcm", "wb");  //输出
	if (fp == NULL) {
		printf("empty file,please check the file name\n");
		return -1;
	}
	short readBuf[160];
	short refBuf[160];
	short outBuf[160];
	//fread(readBuf, 2, 160, fps);
	while (!feof(fp) && !feof(fps)) {
		fread(readBuf, 2, 160, fp);
		fread(refBuf, 2, 160, fps);

		//参考音频
		printf("buffput------%d", WebRtcAecm_BufferFarend(AecmInst, refBuf, 160));

		//处理
		printf("process-----%d\n", WebRtcAecm_Process(AecmInst, readBuf, readBuf, outBuf, 160, 10));
		fwrite(outBuf, 2, 160, outfp);
		// memcpy(refBuf,readBuf,320);
	}
	printf("--------------end the process--------");
	getchar();
	fclose(fp);
	fclose(outfp);
	return 0;
	return 0;
}