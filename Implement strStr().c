int strStr(char* haystack, char* needle) {
    int i = 0;
    char* h = haystack, * n = needle, *temp;
    if(haystack == NULL) return -1;
    if(*haystack == '\0' && *needle == '\0') return 0;
    if(*haystack == '\0' && *needle != '\0') return -1;
    while(*h != '\0' && *n != '\0') {
        while(*n != *h && *h != '\0') {
            h++;
            i++;
        }
        if(*h == '\0') return -1;
        if(*h == *n) temp = h + 1;                  //"temp" is important!  
        while(*h == *n && *h != '\0' && *n != '\0') {
            h++;
            n++;
        }
        if(*n == '\0') return i;
        if(*h == '\0' && *n != '\0') return -1;
        n = needle;
        i++;
        h = temp;
    }
}