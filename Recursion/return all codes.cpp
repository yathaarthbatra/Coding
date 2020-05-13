int getCodes(string input, string output[10000]) {
   if(input[0]=='\0')
   {
       output[0]="";
       return 1;
   }
    
    string smalloutput1[10000];
    string smalloutput2[10000];
    
    int n=input[0]-'0';
    int size1=getCodes(input.substr(1),smalloutput1);
    int size2=0;
    
    
    if(((input[0]-'1'+1)*10+(input[1]-'1'+1))>=10&&((input[0]-'1'+1)*10+(input[1]-'1'+1))<=26)
    {
         size2=getCodes(input.substr(2),smalloutput2);
    }
    
    int row=0;
    for(int i=0;i<size1;i++)
    {
        char ch=(input[0]-'0'+'a'-1);
        output[row]=ch+smalloutput1[i];
        row++;
    }
    
    for(int i=0;i<size2;i++)
    {
        char ch=((input[0]-'1'+1)*10+(input[1]-'1'+1))+'a'-1;
        output[row]=ch+smalloutput2[i];
        row++;
    }
    
    return row;
    
}
