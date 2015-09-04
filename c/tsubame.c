#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // 文字列を入力する
    const size_t charSize = 100;
    char str[charSize];
    fgets(str, charSize, stdin);
    
    // 改行コードを除去する(のちの処理で問題となるため)
    if (strchr(str, '\n') != NULL) {
        str[strlen(str) - 1] = '\0';
    }
    
    // 数値が10〜99の場合は異常終了させる
    int num = atoi(str);
    
    const int min = 10;
    const int max = 99;
    
    if (num < min || max < num) {
        return EXIT_FAILURE;
    }
    
    // 桁の長さを取得して、それぞれの桁の数値を加算させる
    // それぞれの数字は文字であるため、数値にするための処理が必要
    int len = strlen(str);
    char zero = '0';
    
    for (int idx = 0; idx < len; idx++) {
        num += str[idx] - zero;
    }
    
    // 合計値を出力する
    printf("%d", num);
    return EXIT_SUCCESS;
}

