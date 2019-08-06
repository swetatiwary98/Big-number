#include<stdio.h>
#include<string.h>
void sum(char[], char[]);
void sub(char[],char[]);
void mul(char[],char[]);

char *strrev(char *str) {
  char c, *front, *back;

  if(!str || !*str)
      return str;
    
  for(front=str, back=str+strlen(str)-1; front < back; front++,back--){
      c=*front;
      *front=*back;
      *back=c;
    }

  return str;
}

int main(void) {

   printf("|-------Menu-------| \n");
   printf("| 1. Addition      | \n");
   printf("| 2. Substraction  | \n");
   printf("| 3. Multiplication| \n");
   printf("|------------------| \n"); 

  char Num1[100], Num2[100], Ans[100];
  int choice;

  printf("Enter 1st no \n");
  scanf("%s",Num1);
  printf("Enter 2nd no \n");
  scanf("%s",Num2);

   printf("Enter your choice \n");
   scanf("%d",&choice);

   switch(choice) {
     case 1: sum(Num1, Num2); break;
     case 2: sub(Num1, Num2); break;
     case 3: mul(Num1, Num2); break;
     default: printf("Wrong choise\n");
   }
}


void mul(char s1[], char s2[]) {

  //Declaration of variables 
  int i,j,n1 = strlen(s1), 
    n2 = strlen(s2);
  char ans[250]="";
    
  //Reversing the strings
  strrev(s1); strrev(s2);

  for(i=0; i<n2; i++) {
    int d2=s2[i]-'0';
    int carry=0;

    for(j=0; j<n1; j++) {
      int d1=s1[j]-'0';

      int temp=(ans[i+j]-'0');
      if(temp<0) temp =0;

      int cur=d1*d2+temp+carry;

      ans[i+j]=cur%10+'0';
      carry=cur/10;
    }
    ans[i+n1]=carry+'0';
  } 

  //Reverse the answer to get the actual answer 
  strrev(ans);

  //Print the answer
  printf("ans %s",ans);
}

void sub(char s1[], char s2[]) {

  //Declaration of variables 
  char ans[200]="";
  int i,carry=0, change=0;
  
  //Swaping if s2 > s1 or value of s2 > s1 
  //and setting change = 1
  if(strlen(s2)>strlen(s1)) {
    char temp[100];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
    change=1;
  }
  if(strlen(s2)==strlen(s1)) {
    for(i=0; i<strlen(s1);i++) {
      if(s2[i]-'0' > s1[i]-'0') {
        char temp[100];
        strcpy(temp,s1);
        strcpy(s1,s2);
        strcpy(s2,temp);
        change=1;
        break;
      }
    }
  }

  //Calculating the difference b/w the length
  int n1 = strlen(s1),
  n2 = strlen(s2);
  int diff = n1-n2;

  //Substracting from the end 
  for (i=n2-1; i>=0; i--) {

    int sub = ((s1[i+diff]-'0') -(s2[i]-'0') - carry);

    //when sub is less than 0 i.e we need to carry from the previous number
    if (sub < 0) {
      sub = sub+10;
      carry = 1;
    } else {
       carry = 0;
    }

    //Concatination of string
    char t[1] = ""; t[0]=(sub + '0');
    strcat(ans,t);
    }

  //For remaining part of the String  
  for (i=diff-1; i>=0; i--) {
    int sub = ((s1[i]-'0') - carry);
    if (i>0 || sub>0) {
      char t[1] = ""; t[0]=(sub+'0');
      strcat(ans,t);}
    carry = 0;
    } 

  //Reverse the answer to get the actual answer
  strrev(ans);

  //change=1 append '-' to ans string
  if(change) {
    char save[200]="";
    strcpy(save,ans);
    for(i=0; i<strlen(save); i++)
      ans[i+1]=save[i];
    ans[0]='-';
  }

  //Print the answer
  printf("sub %s",ans);
}

void sum(char s1[], char s2[]) {
  
  //Declaration of variables 
  char ans[200] = "";
  int i, carry = 0;
  
  //Swaping Both strings as we want s2 to be larger
  if(strlen(s1)>strlen(s2)) {
    char temp[100];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
  }

  //Calculating the difference b/w the length
  int n1 = strlen(s1);
  int n2 = strlen(s2);

  //Reversing the strings
  strrev(s1); 
  strrev(s2);

  //Converting each char of string to a int and performing adding with help of carry
  for (i=0; i<n1; i++) {
    int sum = ((s1[i]-'0')+(s2[i]-'0')+carry);

    //Temporary array
    char t[1] = ""; 
    t[0]=(sum%10 + '0');
    
    //Concatination of string
    strcat(ans,t);
    carry = sum/10;
  }

  //For the remaning elements in String
  for (int i=n1; i<n2; i++) {
    int sum = ((s2[i]-'0')+carry);
    char t[1] = ""; t[0]=(sum%10 + '0');
    strcat(ans,t);
    carry = sum/10;
  }

  //If any carry remains add it the ans string
  if (carry) {
   char t[1] = ""; t[0]=(carry + '0');
   strcat(ans,t);
  }
  
  //Reverse the answer to get the actual answer
  strrev(ans);
  
  //Print the answer
  printf("Answer : %s ",ans);
}
