//pass1

            #include<stdio.h>
	    #include<string.h>
	    #include<math.h>
	     struct SYMTAB
	       {
		 char symbol[30];
		 char address[30];
	       }s[100];
              int scount=0;
              int hextodecimal(char achex[])      
              { 
                int len,i,temp;
                int dec=0;
                len=strlen(achex);                
                for(i=0;i<len;i++)
                {
                  switch(achex[i])
                   {
                    case '0' :temp=0;
                              break;
                    case '1' :temp=1;
                              break; 
                    case '2' :temp=2;
                              break;
                    case '3' :temp=3;
                              break;
                    case '4' :temp=4;
                              break;
                    case '5' :temp=5;
                              break;
                    case '6' :temp=6;
                              break;
                    case '7' :temp=7;
                              break;
                    case '8' :temp=8;
                              break;
                    case '9' :temp=9;
                              break;
                    case 'A':
                    case 'a' :temp=10;
                              break;
                    case'B':
                    case'b' :temp=11;
                              break;
                    case 'C':
                    case 'c' :temp=12;
                              break; 
                    case 'D':
                    case 'd' :temp=13;
                              break; 
                    case 'E':
                    case 'e' :temp=14;
                              break;
                   case 'F':
                   case 'f' :temp=15;
                              break; 
                 }
            dec=dec+temp*pow(16,len-i-1);
            }
             return dec;
             }

	    void passone()
	      { 
	      char label[30],opcode[30],operand[30],address[30];
	      char loc[30];
	      int flag,j;
	      int startaddress,locctr=0,i;
	      FILE *fp,*f1;
	      fp=fopen("input.c","r");
              f1=fopen("intermediate.txt","w");
	      fscanf(fp,"%s%s%s",label,opcode,operand);
	      while(!feof(fp))
	       {
		  if(strcmp(opcode,"START")==0)
		    {
		        startaddress=atoi(operand);
		        locctr=hextodecimal(operand);
		        fprintf(f1,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		        fscanf(fp,"%s%s%s",label,opcode,operand);
		   }
	       if(strcmp(label,"**")!=0)
		 {
		    strcpy(s[scount].symbol,label);
		    sprintf(address,"%x",locctr);
		    strcpy(s[scount++].address,address);
		 }
	      fprintf(f1,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);

	      if(strcmp(opcode,"word")==0)
		{
		  locctr+=3;
		}
	      else if(strcmp(opcode,"RESW")==0)
		{
		  locctr+=atoi(operand)*3;
		}
	      else if(strcmp(opcode,"RESB")==0)
		{
		  locctr+=atoi(operand);
	        }
	      else if(strcmp(opcode,"BYTE")==0)
		{
		 locctr+=strlen(operand);
		}
	      else
		{
		  locctr+=3;
		}
	    fscanf(fp,"%s%s%s",label,opcode,operand);
	    }
            fprintf(f1,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
	    fclose(f1);
	    fclose(fp);
	    printf("symbol table \n");

	    for(i=0;i<scount;i++)  
	     {
	       printf("%s\t%s\n",s[i].symbol,s[i].address);
	     }
	    printf("intermediate code of assembler\n");
	    f1=fopen("intermediate.txt","r");
	    fscanf(f1,"%s%s%s%s\n",loc,label,opcode,operand);
	    while(!feof(f1))
	      { 
		 printf("%s\t%s\t%s\t%s\n",loc,label,opcode,operand);
		 fscanf(f1,"%s%s%s%s",loc,label,opcode,operand);
	      }
	      fclose(f1);
	    }
	   void main()
	    {
	      passone();
	    }

 INPUT
COPY   START  1000
**     LDA    NUM1
**     LDS    NUM2
LOOP   ADD    NUM2
**     DEC    NUM1
**     JNZ    LOOP
NUM1   BYTE   05
NUM2   RESW   2
**     END    
OUTPUT
   symbol table 
   LOOP	1006
   NUM1	100f
   NUM2	1011
   intermediate code of assembler
   1000	COPY	START	1000
   1000	**	LDA	NUM1
   1003	**	LDS	NUM2
   1006	LOOP	ADD	NUM2
   1009	**	DEC	NUM1
   100c	**	JNZ	LOOP
   100f	NUM1	BYTE	05
   1011	NUM2	RESW	2
   1017	**	END	2           
                

