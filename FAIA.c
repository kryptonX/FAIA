#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
       #include <conio.h>
#elif __APPLE__ || __linux__
       #include <unistd.h>
#endif

#define READ "r"
#define WRITE "w"

int isformatted(char *floc);

const char database[] = {
                              'a', 'b', 'c','d',
                              'e', 'f', 'g', 'h',
                              'i', 'j', 'k', 'l', 
                              'm', 'n', 'o', 'p',
                              'q', 'r', 's', 't',
                              'u', 'v', 'w', 'x',
                              'y', 'z', '1', '2',
                              '3', '4', '5', '6',
                              '7', '8', '9', '@', '&',
};

int main(int argc, char *argv[]) {
    int index;
    if (argc < 2)    
       printf("passkrypt: no input files\n");
    else if (isformatted(argv[1])) {       
        
             FILE *input = fopen(argv[1], READ);                   
             char *ehandle = strcat(argv[1], ".aia");
             FILE *output = fopen(ehandle, WRITE);             
             char buffer;
             while ((buffer = fgetc(input)) != (EOF)) 
                   if (buffer == '\n')
                      fputc('\n', output);
                   else if (buffer == ' ')
                        fputc(' ', output);
                   else {
                        buffer = tolower(buffer);                       
                        for (index = 0; index < sizeof(database) - 2; index++)
                            if (buffer == database[index])
                               fputc((database[index + 2]), output);
                   }
            fclose(input);
            fclose(output);
        
   }
    return 0;   
}

int isformatted(char *floc) { 
    char handle;   
    FILE *target = fopen(floc, "r");
    short result = 0;
    
    if (target == NULL)
       printf("error: cannot open file.\n");
    else {         
         while (1) {
               handle = fgetc(target);
               if (handle != EOF) {
                  result = 1;
                  break;
               } else break;
         }
    }
    fclose(target);
    return result;
}
