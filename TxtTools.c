#include "TxtTools.h"
#include <stdio.h>

#define MAX_LINE 1000 /* you can use define here, but const int in c++ is better*/
#define MAX_WORD 100

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
   int wordNum=0;
   char word[MAX_WORD];
   FILE *fp;

   fp = fopen(FileName,"r");
   if(fp == NULL){
     fprintf(stderr,"open file %s fail\n",FileName);
     return -1;
   }
   while(fscanf(fp,"%s",word)!=-1){
     wordNum++;
   }
   fclose(fp);
   return wordNum;
  
 }


int DelBlankLines(char* srcFileName,char* desFileName){
  int lineNum=0;
  char line[MAX_LINE];
  FILE *fpRead,*fpWrite;

  fpRead = fopen(srcFileName,"r");
  fpWrite = fopen(desFileName,"w");
  if (fpRead == NULL){
    fprintf(stderr,"open file %s fail\n",srcFileName);
    return -1;
  }
  while(fgets(line,MAX_LINE,fpRead)!=NULL){
    if (line[0]!='\n') {
      lineNum++;
      fputs(line,fpWrite);
    }
  }
  fclose(fpWrite);
  fclose(fpRead);
  return lineNum;

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