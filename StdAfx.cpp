// stdafx.cpp : source file that includes just the standard includes
//	RegTool.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

void WriteConf(char *src)
{
	FILE *fp = fopen(".\\config.txt", "w");

	if(fp != NULL)
	{
		fprintf(fp, "%s", src);
		fclose(fp);
	}
}

void GetConf(char* name, char* val)
{
	char szTmp[300] = {0};
	FILE *fp = fopen(".\\config.txt", "r");

	if(fp != NULL)
	{
		while(fgets(szTmp, 200, fp))
		{
			if(strncmp(szTmp, name, strlen(name)) == 0)
			{
				sprintf(val, "%s", szTmp+strlen(name)+1);
				break;
			}

			memset(szTmp, 0x00, sizeof(szTmp));
		}
		fclose(fp);
	}

	if(val[strlen(val)-1] == '\n')
	{
		val[strlen(val)-1] = '\0';
	}
}