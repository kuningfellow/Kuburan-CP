#include<windows.h>
#include<stdio.h>
 
int main() {
  HANDLE clip;
  if (OpenClipboard(NULL)) 
    clip = GetClipboardData(CF_TEXT);
  else
    return 1;
  unsigned int i = 0;
  while (((char*)clip)[i] != 0) {
    if (((char*)clip)[i] != '\r') {
      printf("%c", ((char*)clip)[i]);
    }
    i++;
  }
  CloseClipboard();
  return 0;
}