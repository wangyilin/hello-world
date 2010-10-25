#include "TxtTools.h"
#include <stdio.h>

#define MAX_LINE 1000 /* you can use define here, but const int in c++ is better*/

int CountLines(char* FileName){ 
	int lineNum=0;
	char line[MAX_LINE];
	FILE* fh;

	fh = fopen(FileName,"r");
	if(fh == NULL) /* judge fh must followed fopen, it's a RULE!! */
	{
		fprintf(stderr, "open file %s fail\n",FileName); /* output message to stderr */
		return -1;
	}

	while(fgets(line,MAX_LINE,fh)!=NULL) /* it's code snippet common used, you need remember it to read every line from a file */
	{
		fputs(line,stdout); /*or use printf("%s",line);*/
		lineNum++;
	}
	fclose(fh);
	return lineNum;
}


int CountEnglishWords(char* FileName){
  
 }


int DelBlankLines(char* srcFileName,char* desFileName){
  char L[256];
    int B_Num=0,Lend,i;
    freopen(srcFileName,"r",stdin);    //文件必须以换行符结尾，不然会出错。
    freopen(desFileName,"w",stdout);
    while(scanf("%c",&L[0])!=EOF){
       Lend=0;
       while (L[Lend]!='\n'){
         Lend++;
         scanf("%c",&L[Lend]);
       }
       for(i=0;i<Lend;i++)
         if(L[i]!=' ')break;
       if (i==Lend) B_Num++;
       else
         for(i=0;i<=Lend;i++)printf("%c",L[i]);
    }
    return B_Num;
}


void TestTxtTools(void)
{
	char * FileName = "test.txt";
	unsigned int numLines;
	unsigned int numWords;
	numLines = CountLines(FileName);
	printf("%d",numLines);
	
	/*numWords = CountEnglishWords(FileName);
	printf("%u %u\n",numLines,numWords);*/
}