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
       printf("%s\n" ,Atbash);
     int AtLen= strlen(Atbash);  
       int RevLen =5;
   

   char rev1[RevLen];

    int WordValue = GetGematria(Word);
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
      printf("Ans is:%s ",Ans);
}  
 else {printf("gematria is:");}
////////////////Atbash check//////////////////////
    checker=0;
    char AtTmp [1];
    l=0,h=0;
    int t=0;
    int Value=0;
    int AtValue=GetGematria(Atbash); // need to check
    char AtAns[1000];
    TextLen=strlen (Text);

    int flag =1;
    while((h<TextLen)||(l<TextLen)){
        AtValue=GetGematria(Atbash); // need to check
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
            printf("\nTmp is %s  and the value is %d\n",AtTmp ,Value);
        if(Value==AtValue){
                        printf("\nvalues are sameeee!! is %d  and the atbash value is %d\n",Value,AtValue);
            int r=0;
            t=0;
            flag=1;
            while(r<length){
                char cc=AtTmp[r];
                if(('A'<=cc)&&(cc<='Z')||('a'<=cc)&&(cc<='z')){
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
                    if(('A'<=cc)&&(cc<='Z')||('a'<=cc)&&(cc<='z')){
                
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
    printf("AtAns is:%s ",AtAns);
 }
  else {printf("Atbash is:");}


//////////////////////// Anagram check //////////////////////////////
    char AnTmp [1];
    checker=0;
    l=0,h=0;
    int a;
    int AnTmpValue=0;
    int AnWordValue=0;
    int WordCounter[128]={0};
    int TmpCounter[128]={0};
    i=0;
        printf("Word is %d",Word[3]);
        
    while(Word[i]!='\0'){
        a= Word[i];
        printf("\n Word %d",a); 
        WordCounter[a]= WordCounter[a]+1;
        printf(" WCounter %d  ",WordCounter[a]);
        i++; 
    }

    char AnAns[1000];
    AnAns[0] = '\0';
    TextLen=strlen (Text); // maybe remove
    flag=0;

   //  find all the substrings.
       while((h<TextLen)||(l<TextLen)){
           flag=0;
             i=0;
        // check if the i' char is in the original word.
    while(flag==0){
        c=Text[l];    
       while(i<WordLen-1){
           if(c==Text[i]){
               flag=1;
               break;
           }
           else i++;
       } 
       if((flag==0)||(l<TextLen)){  l++; }  // maybe remove.
         else break;
                      printf("print cheack1 ");

    }
    
    if(l>=h){ 
        h=l;
    }
              printf("print cheack22 ");

        // int size= (h-l+1);  //size of the current substring.
        // while(size<WordLen){ // increase the size of the substring to the size of the Word.
        //     h++;
        // }
        // size= (h-l+1);
        // memcpy(AnTmp,&Text[l],size);  //AnTmp = current substring.
        // AnTmp[size]='\0';
        // printf("\n %s \n",AnTmp);
        // int j=0;
        // int charSum=0;
        // while(j<size){
        //     if(AnTmp[j]!=' '){
        //         a=AnTmp[j];
        //     AnTmpValue=AnTmpValue+a;   
        //     TmpCounter[a]= TmpCounter[a]+1;
        //     }
        //     j++;
        // }
        //              printf("print chea3rck ");

        //             if(AnTmpValue==AnWordValue){
        //                 flag=1;
        //                 // check if the 2 countingSort arrays are same.
        //              for(i=0;i<128;i++){
        //                  if(TmpCounter[i]!=WordCounter[i]){
        //                      flag=0;
        //                      break;
        //                  }
        //              }
        //             if(flag=1){
        //             AppendChars(AnAns,AnTmp);
        //                 checker++;
        //             }
        //             l++;
                    
        //             }  
        //  else{
        //     if(AnTmpValue<AnWordValue){
        //          h++;
        // }   
        // else if(AnTmpValue>AnWordValue){
        //      if(l<h){
        //   l++;
        //      }
        //      else {if(l==h){
        //      l++;
        //      h++;  
        //      }
        //      }
        // }
        // }
       
     }
     if(checker!=0){
       int AnAnsLen=strlen (AnAns);
       AnAns[AnAnsLen-1]='\0';
      printf("AnAns is:%s ",AnAns);
     }
printf("done");

    return 0;
}
//////////////////////////////////////////////////////