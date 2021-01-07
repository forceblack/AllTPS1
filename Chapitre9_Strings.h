#ifndef CHAP9_STRING
#define CHAP9_STRING


void Chap9_String(void);
void entreFirstName(void);
void resistorValue(void);
void printColorCode (char inTab[][7], int inSize);
int checkColor (char inTab[][7],int inSize,char *inColor,int *outIndex);
int checkE12(int *E12Value, int E12Size, int resValue);

#endif
