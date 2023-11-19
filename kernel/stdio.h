void printChar(const char c) 
{
    static int offset = 0;
    volatile char* video_memory = (char*)0xb8000;
    video_memory[offset * 2] = c;
    offset++;
}

void print(const char *str) {
    while (*str != '\0') {
        printChar(*str);
        str++;
    }
}