/*
参数值：
    输入文件名
返回值：
    返回文件中的行数，以回车为行分隔符。
*/
unsigned int CountLines(char* FileName){
  int lineNum=0;
  char t;
  freopen(FileName,"r",stdin);

  while(scanf("%c",&t)!=EOF)     //整行读，好像无法判断空行，蛋疼，一个一个读可能会略慢。
    if(t=='\n') lineNum++;

  return lineNum;
  }
/*
参数值：
    输入文件名
返回值：
    返回文件中的单词数（针对英文文件，以空格为词分割单位）
*/
unsigned int CountEnglishWords(char* FileName){
  int lineNum=0;
  char t[256];
  freopen(FileName,"r",stdin);

  while(scanf("%s",t)!=EOF)
     lineNum++;

  return lineNum;
  }
/*
作用：
		把源文件中的空行去掉，结果保存在目标文件名制定的文件中。
参数值：
    源文件名和目标文件名
返回值：
    空行数
*/
unsigned int DelBlankLines(char* srcFileName,char* desFileName){
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

void TestTxtTools(void);
