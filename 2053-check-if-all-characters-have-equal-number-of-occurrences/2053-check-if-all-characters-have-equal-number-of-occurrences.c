bool areOccurrencesEqual(char* s) {
    int a[26]={0};
    char* ptr=s;
    //printf("%c",*ptr);
    while(*ptr)
    {
       printf("%c",*ptr);
       a[*ptr -'a']++; 
       ptr++;
      
    }
    int val=a[s[0]-'a'];
    for(int i=0;i<26;i++)
    {
        if(a[i] && a[i]!=val)
        {
            return false;
        }
    }
    return true;

    
}