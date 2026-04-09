#include <stdio.h>

int main() {
    char source[] = "Hello, World! This is a test string for my_strcpy function.\n";
    char destination[101];
    
    int idx = 0;
    for(; source[idx] != '\0'; idx++) {
        destination[idx] = source[idx];
    }
    destination[idx] = '\0'; // 添加字符串结束符

    printf("拷贝后的字符串: %s", destination);
    
    return 0;
}