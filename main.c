#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *__findType(char *data, int start, int end){
    if(end == 1 && data[0] == '.')
        return "string";
    int i = start;
    while(i < end){
        if(data[i] == '.'){
            char *res = __findType(data, i+1, end);
            if(strcmp(res, "int") == 0){
                return "double";
            }else
                return "string";
        }else if(isdigit(data[i])==0)
            return "string";
        i++;
    }
    return "int";
}

char *findType(char *data){
    int n = (int)strlen(data);
    return __findType(data, 0, n);
}

int main() {
    char data[50];
    scanf("%50s",data);
    while(1){
        if(strcmp(data,"exit")==0)
            break;
        printf("%s\n", findType(data));
        scanf("%50s",data);
    }
    return 0;
}
