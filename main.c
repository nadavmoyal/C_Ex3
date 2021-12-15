#include <stdio.h>
#include <string.h>

void GetClean(char str[]) {
    int i=0,TotalValue=0,StrSize =0;
    char c ='0';
    StrSize = strlen(str);
    int j= StrSize-1;
    while(i<=StrSize){
        c=str[i];
        if(('a'<=c)||(c<='z')||('A'<=c)||(c<='Z')){ 
         break;
        }  
        else{
            i++;
        }
    }
      while(j>=0){
        c=str[j];
        if(('a'<=c)||(c<='z')||('A'<=c)||(c<='Z')){ 
         break;
        }  
        else{
            j--;
        }
    }
    char CleanStr [j-i+1];
    memcpy(CleanStr,&str[i],j-i+1);  
    CleanStr[j-i+1]='\0';   
    int p=0;
    while(p<=j-i+1){
      str[p] = CleanStr[p];  
      p++;
    }
}

int GetGematria(char str[]) {
    int i=0,TotalValue=0,StrSize =0;
    char c ='0';
    StrSize = strlen(str);
    while(i<=StrSize){
        c=str[i];
        if(('a'<=c)&&(c<='z')){ //Lower case 
            c=( c -'a')+1;
        }  
        else{
             if(('A'<=c)&&(c<='Z')){ //Upper case 
            c=( c-'A')+1;
           }  
           else{
            c=0;
        }  
        }
        
        TotalValue = TotalValue + c ;
        i=i+1;               
    }
    return TotalValue;
}

char* AppendChars(char Ans [],char Tmp []){
    int i =0; 
    char c;
    int TmpLen = strlen(Tmp);
    while (i<=TmpLen){
        c = Tmp[i];
        strncat(Ans, &c, 1);
        i=i+1;
    }
    // Ans[i]='~';
    // Ans[i+1]='\0';
    c='~';
    strncat(Ans, &c, 1);
    c='\0';
    strncat(Ans, &c, 1);
    printf("Ans iterr    %s ",Ans);
    return Ans;
}



int main(){
    // get a word 
    char* AppendChars(char Ans [],char Tmp []);
    int i= 0;
    int WordLen=0;
    int TextLen=0;
    char TextTemp[1024]; // maybe 1024 ..
    char c='0';
    char WordTemp[30];
    fgets(WordTemp,30, stdin);  
    WordLen = strlen (WordTemp);
    while(i<=WordLen){
        c=WordTemp[i];
        if((c==' ')||(c=='\n')||(c=='\t')){
            break;
        }
        i=i+1;
    }
     char Word [i];
     strncpy(Word,&WordTemp[0],i);
     Word [i] ='\0';
     printf("%s\n" , Word);
     int WordValue = GetGematria(Word);
     printf("is      %d\n" , WordValue);

    i=0;
    c='0';
    fgets(TextTemp,1024, stdin);
    TextLen = strlen (TextTemp);
    while(i<=TextLen){
        c=TextTemp[i];
        if(c=='~'){
            break;
        }
        i=i+1;
    }
    char Text [i];
     strncpy(Text,&TextTemp[0],i);
     Text [i] ='\0';
     printf("%s", Text);
    char Tmp [1];
    int l=0,h=0;
    int TmpValue=0;
    char Ans[1000];
     TextLen=strlen (Text);
     printf(" is      %d\n" , TextLen);
     while(h<TextLen){
       int size= (h-l);
        printf("\n %d ",(size));
        memcpy(Tmp,&Text[l],size+1);
        Tmp[size+1]='\0';
        printf("\n %s \n",Tmp);
        GetClean(Tmp);
        printf("the clean is =%s" , Tmp);
        while(Text[l]!=Tmp[0]){l++;}
        TmpValue = GetGematria(Tmp);
        printf("\nTmp is %s  and the value is %d\n",Tmp,TmpValue);
                    if(TmpValue==WordValue){
                 printf("\n the string is :%s\n",Tmp);
                 AppendChars(Ans,Tmp);
                    l++;
                    h++;
        }  else{
            if(TmpValue<WordValue){
                 h++;
        }   
        else if(TmpValue>WordValue){
             if(l<h){
             l++;
             }
             else if(l==h){
             l++;
             h++;  
             }
        }
        }
       
     }
     // printf("Ans is     %s ",Ans);

    return 0;
}