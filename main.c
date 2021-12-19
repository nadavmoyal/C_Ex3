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
///////////////////////////////////////////////////
char* GetReverse(char * Tmp){
    int TmpLen= strlen(Tmp);
    char src [TmpLen] ;
    strcpy(src,Tmp);
    char Revrese [TmpLen];
    int i=0;
    while(i<TmpLen){
        Revrese[i]=src[TmpLen-i-1];
        i++;
    }
    Revrese[i]='\0';
    printf("\n this is reverse : %s\n",Revrese);
    char * var = &Revrese[0];
    return var;
}
///////////////////////////////////////////////////
char* GetAtbash(char Tmp []){
    int TmpLen= strlen(Tmp);
    char Ans [TmpLen];
    int i=0, j=0;
    char c;
    while(i<TmpLen){
        c=Tmp[i];
        if(('A'<=c)&&(c<='Z')||('a'<=c)&&(c<='z')){
            if(('a'<=c)&&(c<='z')) {  // Lower case
                c=c-'a';   //maybe we need to use int and after that to do casting
                c='z'-c;
                Ans[j]=c;
                j++;
            }
            if(('A'<=c)&&(c<='Z')) {  // Upper case
                c=c-'A';   //maybe we need to use int and after that to do casting
                c='Z'-c;
                Ans[j]=c;

                j++;
            }
        }
        i++;
    }
    Ans[j]='\0';
    printf("\n this is ans: %s\n",Ans);
    char * tmp = &Ans[0];
    return tmp;
}
///////////////////////////////////////////////////
char* AppendChars(char Ans [],char Tmp []){
    int i =0; 
    char c;
    int TmpLen = strlen(Tmp);
    while (i<=TmpLen){
        c = Tmp[i];
        strncat(Ans, &c, 1);
        i=i+1;
    }
    c='~';
    strncat(Ans, &c, 1);
    c='\0';
    strncat(Ans, &c, 1);
    printf("Ans iterr %s",Ans);
    return Ans;
}

///////////////////////////////////////////////////


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
    while(i<WordLen){
        c=WordTemp[i];
        if((c==' ')||(c=='\n')||(c=='\t')){
            break;
        }
        i=i+1;
    }
    int ind=0;
    int index=i;
    while((ind<i)){
        c=WordTemp[ind];
        if(('a'>c)||(c>'z')){
            if (('A'>c)||(c>'Z')){
                ind++;
            }
            else break;
        }
        else break;
    }
    while((index>0)){
        c=WordTemp[index];
        if(('a'>c)||(c>'z')){
            if (('A'>c)||(c>'Z')){
                index--;
            }
            else break;
        }
        else break;
    }

    char Word [index-ind+1];
    strncpy(Word,&WordTemp[ind],index-ind+1);
    Word [index-ind+1] ='\0';
    printf("%s\n" , Word);
    char* Atbash  = GetAtbash(Word);
    char* Rev = GetReverse(Atbash);
    int RevLen= strlen(Rev);
    printf("%s\n" ,Atbash);
    printf("%s\n" , Rev);

    char rev1[RevLen];
    char at1[RevLen];
    strncpy(at1,&Atbash[0],RevLen);
    strncpy(rev1,&Rev[0],RevLen);
      for(int i=0;i<RevLen;i++){
          char ch = at1[i];
        printf("%c\n" , ch);
      }
       printf("hatatazizilel\n" );
          for(int i=0;i<RevLen;i++){
          char ch= rev1[i];
        printf("%c\n" , ch);
      }


    printf("this is the length of rev:%d",RevLen);
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
    Ans[0] = '\0';
    TextLen=strlen (Text);

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

///////////////////////////////////////////////////

    char AtTmp [1];
    l=0,h=0;
    int t=0;
    int Value=0;
    int AtValue=GetGematria(at1); // need to check
    char AtAns[1000];
    TextLen=strlen (Text);

    // printf(" is      %d\n" , TextLen);
    int flag =1;
    while((h<TextLen)||(l<TextLen)){
        c=Text[l];
        while((l<TextLen)){
            if(('a'>c)||(c>'z')){
                if (('A'>c)||(c>'Z')){
                    l++;
                    c=Text[l];
                }
                else break;
            }
            else break;
        }
        if(l>h){
            h=l;
        }

        int length= (h-l+1);
        while(length<RevLen){
            if(h<TextLen){
                h++;
            }
            length=h-l+1;
        }

        memcpy(AtTmp,&Text[l],length);
        AtTmp[length]='\0';
        Value =GetGematria(AtTmp);
        if(Value==AtValue){
            int r=0;
            t=0;
            flag=1;
            while(r<length){
                char cc=AtTmp[r];
                if(('A'<=cc)&&(cc<='Z')||('a'<=cc)&&(cc<='z')){
                    if(at1[t]!=cc){
                        flag=0;
                        break;
                    }
                    else {
                        r++;
                        t++;
                    }
                }else{
                    r++;
                }
            }
            if(flag==1){
                AppendChars(AtAns,AtTmp);
            }
            else {
                flag=1;
                r=0;
                t=0;  
                    
                while(r<length){
     
                    char cc=AtTmp[r];
                    if(('A'<=cc)&&(cc<='Z')||('a'<=cc)&&(cc<='z')){
                
                        if(rev1[t]!=cc){
                            flag=0;
                            break;
                        }
                        else {
                            r++;
                            t++;
                        }
                    }else{
                        r++;
                    }
                }
                if(flag==1){
                    AppendChars(AtAns,AtTmp);
                }
                
            }
                     l++;
                    
        }  else{
            if(Value<AtValue){
                h++;
                if(h>=TextLen){
                    break;
                }
            }
            else if(Value>AtValue){
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
    int AtAnsLen=strlen (AtAns);
    AtAns[AnsLen-1]='\0';
    printf("AtAns is:%s ",AtAns);

    return 0;
}
//////////////////