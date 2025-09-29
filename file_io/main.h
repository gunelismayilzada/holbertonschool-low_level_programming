#ifndef MAIN_H
#define MAIN_H
 
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
/* Function Prototypes */
/* Include any function prototypes you create here, e.g.: */
/* int main(int argc, char *argv[]); */

/* If you need _putchar for other tasks, include it here: */
/* int _putchar(char c); */

#endif /* MAIN_H */