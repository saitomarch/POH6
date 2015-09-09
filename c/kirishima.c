#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/// 改行コードを除去する
/// @param str 改行コードを除去する対象の文字列
static void removeReturnCode(char *str) {
    if (strchr(str, '\n')) {
        str[strlen(str) - 1] = '\n';
    }
}

/// 文字列を元に整数型の配列を生成する
/// @param str 文字列
/// @param arr 対象の配列へのポインタ
/// @param size 配列のサイズ
static void separateStringToArray(const char *str, int *arr, size_t size) {
    char *tempStr = (char *)calloc(sizeof(char), BUFFER_SIZE);
    const char *sepStr = " ";
    strncpy(tempStr, str, strlen(str) + 1);
    for (int count = 0; count < size; count++) {
        const char *word = strtok(count == 0 ? tempStr : NULL, sepStr);
        arr[count] = atoi(word);
    }
    free(tempStr);
}

int main(void){
    // マスの数を取得する
    char str[BUFFER_SIZE];
    fgets(str, BUFFER_SIZE, stdin);
    removeReturnCode(str);
    const int numOfCells = atoi(str);
    const int goal = numOfCells - 1;
    const int minCells = 2;
    const int maxCells = 100;
    if (numOfCells < minCells || maxCells < numOfCells) {
        return EXIT_FAILURE;
    }

    // マスを生成する
    fgets(str, BUFFER_SIZE, stdin);
    removeReturnCode(str);
    int cells[numOfCells];
    separateStringToArray(str, cells, numOfCells);
    const int minCellNum = -100;
    const int maxCellNum = 100;
    for (int idx = 0; idx < numOfCells; idx++) {
        if ( ( (idx == 0 || idx == (numOfCells - 1) ) && cells[idx] != 0) ||
            (cells[idx] < minCellNum || maxCellNum < cells[idx]) ) {
            return EXIT_FAILURE;
        }
    }

    // 出目の回数を取得する
    fgets(str, BUFFER_SIZE, stdin);
    removeReturnCode(str);
    const int acts = atoi(str);
    const int minActs = 1;
    const int maxActs = 100;
    if (acts < minActs || maxActs < acts) {
        return EXIT_FAILURE;
    }

    const int minActNum = 1;
    const int maxActNum = 100;

    // 出目を回し、結果を出力する
    for (int count = 0; count < acts; count++) {
        fgets(str, BUFFER_SIZE, stdin);
        removeReturnCode(str);
        int num = atoi(str);
        if (num < minActNum || maxActNum < num) {
            return EXIT_FAILURE;
        }

        // 移動ログ(無限ループ判定に使用する)
        int moveLog[BUFFER_SIZE] = {0};
        enum Status {
            CURRENT = 0,
            FINISHED,
            DEAD,
        };
        enum Status status = CURRENT;

        while (status == CURRENT) {
            if (num == goal) {
                // ゴールについた場合
                status = FINISHED;
            }else if (num < 1 || goal < num) {
                // ゴールを越えた、あるいはスタート地点に戻ったりした場合
                status = DEAD;
            }else{
                // それ以外
                int moves = cells[num];
                if (moves == 0) {
                    // これ以上動けない場合
                    status = DEAD;
                }else{
                    num += moves;
                    int idx;
                    for (idx = 0; idx < BUFFER_SIZE && moveLog[idx] != 0 && status != DEAD; idx++) {
                        if (num == moveLog[idx]) {
                            // 過去に行ったことのあるマスだった場合は無限ループに陥ったとみなしてゲームオーバー
                            status = DEAD;
                        }
                    }
                    if (status != DEAD) {
                        moveLog[idx] = num;
                    }
                }
            }
        }

        puts (status == FINISHED ? "Yes" : "No");
    }

    return EXIT_SUCCESS;
}
