#include <stdio.h>
#include <string.h>

///////////////////GetGematria//////////////////////

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
///////////////////GetAtbash//////////////////////
char* GetAtbash(char Tmp []){
    int TmpLen= strlen(Tmp);
    char Ans [TmpLen];
    int i=0, j=0;
    char c;
    while(i<TmpLen){
        c=Tmp[i];
        if((('A'<=c)&&(c<='Z'))||(('a'<=c)&&(c<='z'))){
            if(('a'<=c)&&(c<='z')) {  // Lower case
                c=c-'a';   
                c='z'-c;
                Ans[j]=c;
                j++;
            }
            if(('A'<=c)&&(c<='Z')) {  // Upper case
                c=c-'A';  
                c='Z'-c;
                Ans[j]=c;

                j++;
            }
        }
        i++;
    }
    Ans[j]='\0';
    char * tmp = &Ans[0];
    return tmp;
}
////////////////AppendChars////////////////////////
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
    return Ans;
}

///////////////////main///////////////////////////


int main(){
    char* AppendChars(char Ans [],char Tmp []);
    int i= 0;
    int WordLen=0;
    int TextLen=0;
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
    WordLen = (index-ind+1);
    char* Atbash  = GetAtbash(Word);
     int AtLen= strlen(Atbash);  
    

    int WordValue = GetGematria(Word);
    i=0;
    c='0';
     char Text [1024]={0};
    char txtemp;
    for (int i = 0; i < 1024; i++) {
        scanf("%c", &txtemp);
        if (txtemp == '~') {
            break;
        }
        Text[i] = txtemp;
    }

/////// Gematria check //////
    int checker=0;
    char Tmp [1];
    int l=0,h=0;
    int TmpValue=0;
    char Ans[1000];
    Ans[0] = '\0';
    TextLen=strlen (Text);

       while(h<TextLen){
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
        int size= (h-l+1);
        memcpy(Tmp,&Text[l],size);
        Tmp[size]='\0';
        TmpValue = GetGematria(Tmp);
                    if(TmpValue==WordValue){
                 AppendChars(Ans,Tmp);
                 checker++;
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
    if(checker!=0){
     int AnsLen=strlen (Ans);
       Ans[AnsLen-1]='\0';
      printf("Gematria Sequences: %s\n",Ans);
}  
 else {printf("Gematria Sequences: \n");}
////////////////Atbash check//////////////////////
    checker=0;
    char AtTmp [1]={0};
    l=0,h=0;
    int t=0;
    int Value=0;
    int AtValue=GetGematria(Atbash); 
    char AtAns[1000]={0};
    TextLen=strlen (Text);

    int flag =1;
    while((h<TextLen)||(l<TextLen)){
        AtValue=GetGematria(Atbash); 
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
     while(length<AtLen){
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
                if((('A'<=cc)&&(cc<='Z'))||(('a'<=cc)&&(cc<='z'))){
                    if(Atbash[t]!=cc){
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
                checker++;
            }
            else {
                flag=1;
                r=0;
                t=0;      
                while(r<length){
                    char cc=AtTmp[r];
                    if((('A'<=cc)&&(cc<='Z'))||(('a'<=cc)&&(cc<='z'))){
                
                        if(Atbash[AtLen-t-1]!=cc){
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
    if(checker!=0){
    int AtAnsLen=strlen (AtAns);
    AtAns[AtAnsLen-1]='\0';
    printf("Atbash Sequences: %s\n",AtAns);
 }
  else {printf("Atbash Sequences: \n");}


//////////////////////// Anagram check //////////////////////////////
    char AnTmp [1];
    checker=0;
    l=0,h=0;
    int a,tm=0;
    int AnTmpValue=0;
    int AnWordValue=0;
    int WordCounter[128]={0};
    int TmpCounter[128]={0};
    i=0;
        
    while(Word[i]!='\0'){
        a= Word[i];
        AnWordValue=AnWordValue+a;
        WordCounter[a]= WordCounter[a]+1;
        i++; 
    }

    char AnAns[1000];
    AnAns[0] = '\0';
    TextLen=strlen (Text); // maybe remove
    flag=0;
    char b;

   //  find all the substrings.
   while((h<TextLen)&&(l<TextLen)){
       AnTmpValue=0;
        flag=0;
        i=0;
        while(i<128){
            TmpCounter[i]=0;
            i++;
        }
        i=0;
        while (flag!=1){
            char c= Text[l];
            i=0;
            while(Word[i]!='\0'){
                b=Word[i];
                if(c==b){
                    flag=1;
                    break;
                }
                else i++;
            }
            if((l<TextLen)&&(flag!=1)){
                    l++;
                }
                else break;
            }
           while(h<l){
            h++;
          }
           int size =(h-l+1);
            while(size<WordLen-1){
                h++;
                size=(h-l+1);
            }
            if((h>=TextLen)||(l>=TextLen)){
                    break;
                }
             memcpy(AnTmp,&Text[l],size);  //AnTmp = current substring.
             AnTmp[size]='\0';
             int j=0;
             while(AnTmp[j]!='\0'){
                 tm=AnTmp[j];
                 if(tm!=' '){
                     AnTmpValue=AnTmpValue+tm;
                     TmpCounter[tm]=TmpCounter[tm]+1;
                 }
                 j++;
             }
                if(AnTmpValue==AnWordValue){
                    flag=1;
                    i=0;
                    while(i<128){
                        if(TmpCounter[i]!=WordCounter[i]){
                            flag=0;
                            break;
                        }
                        else{
                            i++;
                        }
                    }    
                    if(flag==1){
                    AppendChars(AnAns,AnTmp);
                     checker++;
                    }
                     l++;
                     h++;
                }
                else{
                    if(AnTmpValue<AnWordValue){
                        if(h<TextLen){
                        h++;
                        }
                        else break;
                    }else{
                      if(AnTmpValue>AnWordValue){
                      if(l<h){
                         l++;
                    }  
                    else{
                        if(l==h){   
                            h++;
                        }
                     }
                    }
                }
        }
          if((h>=TextLen)||(l>=TextLen)){
                    break;
                }
   }
     if(checker!=0){
       int AnAnsLen=strlen (AnAns);
       AnAns[AnAnsLen-1]='\0';
      printf("Anagram Sequences: %s",AnAns);
     }
     else printf("Anagram Sequences: ");

    return 0;
}
////////////////////EndOfFile////////////////////////////