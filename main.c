#include <stdio.h>
#include <string.h>

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
        c=Text[l];
        printf("c is c= %c",c);
        while((l<TextLen)){
           if(('a'>c)||(c>'z')){
              if (('A'>c)||(c>'Z')){
                l++;
                c=Text[l]; 
                printf("%d",l);
            }
           else break;
         }
         else break;
        }
            if(l>h){
                h=l;
            }
        int size= (h-l+1);
        memcpy(Tmp,&Text[l],size);
        Tmp[size]='\0';
        printf("\n %s \n",Tmp);
        // Tmp=GetClean(Tmp);
        // printf("the clean is =%s" , Tmp);
        TmpValue = GetGematria(Tmp);
        printf("\nTmp is %s  and the value is %d\n",Tmp,TmpValue);
                    if(TmpValue==WordValue){
              //   printf("\n the string is :%s\n",Tmp);
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
             else {if(l==h){
             l++;
             h++;  
             }
             }
        }
        }
       
     }
       int AnsLen=strlen (Ans);
       Ans[AnsLen-1]='\0';
      printf("Ans is:%s ",Ans);
      
    return 0;
}