//usr/bin/g++ -std=c++11 $0 -o ~/bin/CP ; [ "$1" == "-r" ] && rm ~/bin/CP ; exit

#include<string>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<chrono>
using namespace std;

const char *reset = "\033[0m";
#define black "\033[0;30m"
#define BLACK "\033[1;30m"
#define red "\033[0;31m"
#define RED "\033[1;31m"
#define green "\033[0;32m"
#define GREEN "\033[1;32m"
#define yellow "\033[0;33m"
#define YELLOW "\033[1;33m"
#define blue "\033[0;34m"
#define BLUE "\033[1;34m"
#define magenta "\033[0;35m"
#define MAGENTA "\033[1;35m"
#define cyan "\033[0;36m"
#define CYAN "\033[1;36m"
#define white "\033[0;37m"
#define WHITE "\033[1;37m"

char str[50005];
char *arg;
string GPP = "g++ -std=c++11";
string cpp = "";
string exe = "";
string tmpile = "..cpp";
#ifdef __linux__
string cls = "clear";
#elif _WIN32 || _WIN64
string cls = "cls";
#endif
int compiled = 0;

void transpile() {
  FILE * in = fopen(arg, "r");
  FILE * out = fopen(tmpile.c_str(), "w");
  while (fgets(str, 50000, in)) {
    if (strcmp(str, "#define DEBUG(...)\n") == 0) {
      fprintf(out, "#define DEBUG(...) {printf(\"%s\");__VA_ARGS__ printf(\"%s\");}\n", green, reset);
    } else {
      fprintf(out, "%s", str);
    }
  }
  fclose(in);
  fclose(out);
}
#ifdef __linux__
int compile(int m = 0) {
  system(("[ -e \"" + exe + "\" ] && rm \"" + exe + "\"").c_str());
  compiled = 0;
  transpile();
  int ret = system((
    GPP + " \"" + tmpile + "\" -o \"" + exe + "\"" +
    (m?"":" && echo -e \\\e[1m\\\e[32mCOMPILATION SUCCESSFUL")
  ).c_str());
  if (ret == 0) compiled = 1;
  if (ret || !m) scanf("%[^\n]", str), getchar();
  return ret;
}
void run(string args = "", int m = 0) {
  if (m == 1 && compile(1)) return;
  auto start = std::chrono::high_resolution_clock::now();
  system((
    "\"" + exe + "\"" + args + " || echo -e \\\e[1m\\\e[31mRUNTIME ERROR"
  ).c_str());
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  fflush(stdout);
  cout << reset << "Runtime: " << green << elapsed.count() << reset << " s\n";
  scanf("%[^\n]", str), getchar();
}
void paste() {
  system("xclip -o > IN");
}
#elif _WIN32 || _WIN64
int compile(int m = 0) {
  system(("IF EXIST \"" + exe + "\" ( del \"" + exe + ".exe\" )").c_str());
  compiled = 0;
  transpile();
  int ret = system((
    GPP + " \"" + tmpile + "\" -o \"" + exe + "\"" +
    (m?"":" && echo \e[1m\e[32mCOMPILATION SUCCESSFUL")
  ).c_str());
  if (ret == 0) compiled = 1;
  if (ret || !m) scanf("%[^\n]", str), getchar();
  return ret;
}
void run(string args = "", int m = 0) {
  if (m == 1 && compile(1)) return;
  auto start = std::chrono::high_resolution_clock::now();
  system((
    "\"" + exe + "\"" + args + " || echo \e[1m\e[31mRUNTIME ERROR"
  ).c_str());
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  fflush(stdout);
  cout << reset << "Runtime: " << green << elapsed.count() << reset << " s\n";
  scanf("%[^\n]", str), getchar();
}
#include<windows.h>
void paste() {
  FILE * inFile = fopen("IN", "w");
  HANDLE clip;
  if (OpenClipboard(NULL)) {
    clip = GetClipboardData(CF_TEXT);
    unsigned int i = 0;
    while (((char*)clip)[i] != 0) {
      if (((char*)clip)[i] != '\r') {
        fprintf(inFile, "%c", ((char*)clip)[i]);
      }
      i++;
    }
    CloseClipboard();
  }
  fclose(inFile);
}
#endif
bool init(char *argv) {
  arg = argv;
  for (int i = 0; argv[i] != '\0'; i++) {
    if (argv[i] == '\"') cpp += "\\";
    else if (argv[i] == '\\') cpp += "\\";
    cpp += argv[i];
  }
  if (cpp.length() < 4 || cpp.substr(cpp.length() - 4) != ".cpp") return false;
#ifdef __linux__
  if (cpp[0] != '/') exe = "./";
#endif
  exe += cpp.substr(0, cpp.length() - 4);
  return true;
}

int main(int argc, char *argv[]) {
  if (argc == 1 || !init(argv[1])) {
    printf("Please provide a cpp file\n");
  } else if (argc == 2) {
    compile(1);
    system(cls.c_str());
    while (1 < 2) {
      printf("%s[%s%s%s]\n", reset, YELLOW, argv[1], reset);
      printf("%s1%s:exe ", compiled?GREEN:"", reset);
      printf("%s2%s:IN ", compiled?GREEN:"", reset);
      printf("%s3%s:IN+OUT ", compiled?GREEN:"", reset);
      printf("%sp%saste ", GREEN, reset);
      printf("%sc%sompile ", GREEN, reset);
      printf("%sq%suit ", GREEN, reset);
      str[0] = '2';
      str[1] = '\0';
      scanf("%[^\n]", str), getchar();
      if (!strcmp(str, "1")) run();
      else if (!strcmp(str, "2")) run(" < IN");
      else if (!strcmp(str, "3")) run(" < IN > OUT");
      else if (!strcmp(str, "p")) paste();
      else if (!strcmp(str, "P")) {
        paste();
        run(" < IN");
      } else if (!strcmp(str, "c")) compile();
      else if (!strcmp(str, "C")) run(" < IN", 1);
      else if (!strcmp(str, "q")) {
#ifdef __linux__
        system(("rm " + tmpile).c_str());
#elif _WIN32 || _WIN64
        system(("del " + tmpile).c_str());
#endif
        break;
      }
      system(cls.c_str());
    }
  } else if (argc == 3) {
    for (int i = 0; argv[2][i] != '\0'; i++) {
      system(cls.c_str());
      printf("%s[%s%s%s]\n", reset, YELLOW, argv[1], reset);
      if (argv[2][i] == 'c') {
        compile();
      } else if (argv[2][i] == 'r') {
        run();
      } else if (argv[2][i] == 'R') {
        run("", 1);
      } else if (argv[2][i] == 'i') {
        run(" < IN");
      } else if (argv[2][i] == 'I') {
        run(" < IN", 1);
      } else if (argv[2][i] == 'h' || argv[2][i] == 'H') {
        printf("usage:\nc -> compile\nr -> run\nR -> compile and run\ni -> run with IN\nI -> compile and run with IN\nh -> show help\nNote: commands can be combined\n");
      } else {
        printf("Invalid usage %c\n", argv[2][i]);
        break;
      }
#ifdef __linux__
      system(("rm " + tmpile).c_str());
#elif _WIN32 || _WIN64
      system(("del " + tmpile).c_str());
#endif
    }
  } else {
    printf("Invalid parameter count\n");
  }
  return 0;
}
