#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * URL参数解析器
 * 输入：包含http/https超链接的字符串
 * 输出：解析出所有的key-value键值对，每行显示一个
 */

int parse_url(const char* url) {
    int err = 0;

    // TODO: 在这里添加你的代码
    // I AM NOT DONE
    const char* query = strchr(url, '?');
    if (query == NULL) {
        printf("URL中没有查询参数\n");
        goto exit;
    }
    query++; // 跳过 '?'
    char* query_copy = strdup(query);
    if (query_copy == NULL) {
        perror("内存分配失败");
        err = 1;
        goto exit;
    }
    char* token = strtok(query_copy, "&");
    while (token != NULL) {
        char* equal_sign = strchr(token, '=');
        if (equal_sign != NULL) {
            *equal_sign = '\0'; // 将key和value分开
            char* key = token;
            char* value = equal_sign + 1;
            printf("%s: %s\n", key, value);
        } else {
            printf("无效的参数: %s\n", token);
        }
        token = strtok(NULL, "&");
    }
    free(query_copy);

exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}