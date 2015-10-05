#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/// コーヒーを定義する
typedef struct _Coffee {
    float powder;   ///< コーヒー粉
    float water;    ///< 湯
}Coffee;

/// コーヒーの初期値
static const Coffee CoffeeEmpty = {0.0, 0.0};

/// コーヒーの量を取得する
/// @param coffee 量を取得する対象のコーヒー
/// @return 粉と湯の合計値
static float CoffeeGetTotal(Coffee *coffee) {
    return coffee->powder + coffee->water;
}

/// コーヒーの濃度を取得する
/// @param coffee 濃度を取得する対象のコーヒー
/// @param asPercent パーセントとして出力するかどうか
/// @return コーヒーの濃度
static float CoffeeGetConsentration(Coffee *coffee, _Bool asPercent) {
    float consentration = coffee->powder / CoffeeGetTotal(coffee);
    return asPercent ? consentration * 100 : consentration;
}

/// コーヒーにお湯を入れる
/// @param coffee お湯を入れる対象のコーヒー
/// @param quantity お湯の量
static void CoffeeAddWater(Coffee *coffee, float quantity) {
    coffee->water += quantity;
}

/// コーヒーに粉を入れる
/// @param coffee 粉を入れる対象のコーヒー
/// @param quantity 粉の量
static void CoffeeAddPowder(Coffee *coffee, float quantity) {
    coffee->powder += quantity;
}

/// コーヒーを味見する
/// @param coffee 味見をする対象のコーヒー
/// @param quantity 味見する量
static void CoffeeTaste(Coffee *coffee, float quantity) {
    float total = CoffeeGetTotal(coffee);
    coffee->powder -= quantity * coffee->powder / total;
    coffee->water -= quantity * coffee->water / total;
}

/// 改行コードを除去する
/// @param str 改行コードを除去する対象の文字列
static void removeReturnCode(char *str) {
    if (strchr(str, '\n')) {
        str[strlen(str) - 1] = '\0';
    }
}

int main(void){
    // バッファの長さ
    const size_t bufLen = 100;
    // 分割に使用する文字
    const char *splitChar = " ";
    
    // 処理数を取得する
    char linesStr[bufLen];
    fgets(linesStr, sizeof(bufLen), stdin);
    removeReturnCode(linesStr);
    int lines = atoi(linesStr);
    
    // 量の閾値
    const int minQuantity = 1;
    const int maxQuantity = 100;
    
    // コーヒーを生成する
    Coffee coffee = CoffeeEmpty;
    
    for (int idx = 0; idx < lines; idx++) {
        // コーヒー処理用の文字列を取得する
        char actStr[bufLen];
        fgets(actStr, bufLen, stdin);
        removeReturnCode(actStr);
        
        // 行動のタイプ
        enum {
            ADD_WATER    = 1,
            ADD_POWDER   = 2,
            TASTE        = 3
        };
        
        // 処理タイプと量を取得する(処理のタイプと量は空白で分かれている)
        int actType = atoi(strtok(actStr, splitChar));
        int quantity = atoi(strtok(NULL, splitChar));
        if (quantity < minQuantity || maxQuantity < quantity) {
            return EXIT_FAILURE;
        }
        
        // 処理タイプに応じ、指定された量分の処理を行う
        switch (actType) {
            case ADD_WATER:
                CoffeeAddWater(&coffee, quantity);
                break;
            case ADD_POWDER:
                CoffeeAddPowder(&coffee, quantity);
                break;
            case TASTE:
                CoffeeTaste(&coffee, quantity);
                break;
            default:
                return EXIT_FAILURE;
                break;
        }
    }
    
    // 濃度を出力する
    printf("%d", (int)CoffeeGetConsentration(&coffee, true));
    return EXIT_SUCCESS;
}
