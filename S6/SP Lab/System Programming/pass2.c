//Pass2


  #include<stdio.h>
  #include<string.h>
  #include<math.h>
 struct OBJCOD
{
   char mne[10];
   char address[30];
}o[100];
   int ocount=0;
   int hextodecimal(char achex[])
  {
    int len,i,temp;
    int dec=0;
    len=strlen(achex);
    for(i=0;i<len;i++)
  {  
    switch(achex[i])
    {
       case '0': temp=0;
                 break;
       case '1': temp=1;
                 break;
       case '2': temp=2;
                 break;
       case '3': temp=3;
                 break;
       case '4': temp=4;
                 break;
       case '5' :temp=5;      
                 break;
       case '6' :temp=6;
                 break;
       case '7': temp=7;
                 break;
       case '8': temp=8;
                 break;
       case '9': temp=9;
                 break;
       case 'A':
       case 'a': temp=10;
                 break;
       case 'B':
       case 'b': temp=11;
                 break;
       case 'C':
       case 'c': temp=12;
                 break;
       case 'D':
       case 'd': temp=13;
                 break;
       case 'E':
       case 'e': temp=14;
                 break;
       case 'F':
       case 'f': temp=15;
                 break;
    }
  dec=dec+temp*pow(16,len-i-1);
 }
   return dec;
 }
   void secondpass()
  {
    char label[30],opcode[30],operand[30],address[30],loc[30],prgmname[30];
    char opc[30],mnemo[30],prgmName[30],sym[30],addr[30],byte[30];
    char startaddress[30];
    int flag,temp,length;
    int locctr,i;
    FILE *fp,*f1,*f2;
    fp=fopen("intermediate.txt","r");
    fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
    while(!feof(fp))
      {
          if(strcmp(opcode,"START")==0)
                {
                        strcpy(prgmname,label);
                        strcpy(startaddress,operand);
                        locctr=hextodecimal(operand);
                        strcpy(prgmName,label);
                }
                  else
                  {
                      if(strcmp(opcode,"RESW")==0)
               {
                    fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
                    locctr=locctr+atoi(operand)*3;
                    continue;
               }
                    else if(strcmp(opcode,"RESB")==0)
           {
                fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
                locctr=locctr+atoi(operand);
                continue;
           }
           else if(strcmp(opcode,"WORD")==0)
           {
                strcpy(o[ocount].mne,"00");
                strcpy(o[ocount].address,"000");
                strcat(o[ocount++].address,operand);
                locctr=locctr+3;
           }
            else if(strcmp(opcode,"BYTE")==0)
            {
                strcpy(o[ocount].mne,"");
                strcpy(o[ocount].address,"");
                for(i=0;operand[i]!='\0';i++)
              {
                 temp=operand[i];
                 sprintf(byte,"%x",temp);
                 strcat(o[ocount].address,byte);
               }
                ocount++;
                locctr=locctr+strlen(operand);
             }
 
           else  
            {
               f1=fopen("opcode.txt","r");
               fscanf(f1,"%s%s",opc,mnemo);
               while(!feof(f1))
              {
                 if(strcmp(opcode,opc)==0)
                   {
                     strcpy(o[ocount].mne,mnemo);
                     break;
               }
              fscanf(f1,"%s%s",opc,mnemo);
            }

              fclose(f1);
              f2=fopen("symtab.txt","r");
              fscanf(f2,"%s%s",sym,addr);
               while(!feof(f2))
               {
                  if(strcmp(operand,sym)==0)
                    {
                      strcpy(o[ocount++].address,addr);  
                      break;
                    }
               fscanf(f2,"%s%s",sym,addr);
               }
                 fclose(f2);
                 locctr=locctr+3;
            }
          }
            fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
             }
               fclose(fp);
               //Record Format
               length=locctr-hextodecimal(startaddress);
               fp=fopen("record.txt","w");
               fprintf(fp,"H^%s^00%s^0000%x",prgmname,startaddress,length);
               fprintf(fp,"\nT^%s^%x",startaddress,length);
               for(i=0;i<ocount;i++)
           {
               fprintf(fp,"^%s%s",o[i].mne,o[i].address);
               
            }
               fprintf(fp,"\nE^00%s",startaddress);
               }
          void main()
       {
           secondpass();
       }
              






              /*INPUT
		COPY	START	1000
		**	LDA	NUM1
		**      LDS	NUM2
		LOOP	ADD	NUM2
		**	DEC	NUM1
		**	JNZ	LOOP
		NUM1	BYTE	05
		NUM2	RESW	2
		**	END
		*/
		/*INTERMEDIATE
		1000	COPY	START	1000
		1000	**	LDA	NUM1
		1003	**	LDS	NUM2
		1006	LOOP	ADD	NUM2
		1009	**	DEC	NUM1
		100c	**	JNZ	LOOP
		100f	NUM1	BYTE	05
		1011	NUM2	RESW	2
		1017	**	END	2
		*/
      /*OUTPUT
      H^COPY^001000^00001a
      T^1000^1a^100F^80100F^3035
      E^001000
      */
              





             
           

