#include <stdio.h>
#include <string.h>

FILE *scrFileNameP,*desFileNameP;
char scrFileName[100],desFileName[100],Line[10000];
int sectionNum;

void init(){
  while(scrFileNameP==NULL){
    printf("please input filename\n");
    scanf("%s",scrFileName);
    scrFileNameP=fopen(scrFileName,"r");
  }
  strcpy(desFileName,"caption.txt");
  desFileNameP=fopen(desFileName,"w");



}
//--------------------------------------------------------------------------------
bool findSection(){
  for (int i=0;i<strlen(Line);i++)
    if (int(Line[i])==-75 && int(Line[i+1]==-38)){
      if (i+5<strlen(Line))
        if (int(Line[i+4]==-69) && int(Line[i+5])==-40 )
          return true;

      if (i+7<strlen(Line))
        if (int(Line[i+6]==-69) && int(Line[i+7])==-40 )
          return true;

      if (i+9<strlen(Line))
         if (int(Line[i+8]==-69) && int(Line[i+9])==-40 )
           return true;
    }
  return false;
}
//--------------------------------------------------------------------------------
void makeStr(int num){
  if (num<10){
    strcpy(desFileName,"section");
    desFileName[7]=char(num+'0');
    desFileName[8]='\0';
    strcat(desFileName,".txt");
  }
  else{
    strcpy(desFileName,"section");
    desFileName[7]=char(num/10+'0');
    desFileName[8]=char(num%10+'0');
    desFileName[9]='\0';
    strcat(desFileName,".txt");
  }
}
//--------------------------------------------------------------------------------
void print(){

  sectionNum=0;
  while(fscanf(scrFileNameP,"%s",Line)!=EOF){
    if (findSection()) {
          fclose(desFileNameP);
          sectionNum++;

          makeStr(sectionNum);

          desFileNameP=fopen(desFileName,"w");
        }

    fprintf(desFileNameP,"%s\n",Line);
  }

  fclose(scrFileNameP);
  fclose(desFileNameP);

}
//---------------------------------------------------------------------------------
int main()
{

  init();
  print();

}
