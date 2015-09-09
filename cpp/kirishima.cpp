#include <iostream>
#include <vector>
#include <array>
#include <sstream>

using namespace std;

/// 文字列を分割する
/// @param str 文字列の参照
/// @param sep 分割に使う文字
/// @return 分割後の配列(std::vector)
vector<string> splitStringToVector(const string &str, char sep) {
    vector<string> vec;
    istringstream sstream(str);
    string buf;
    while (getline(sstream, buf, sep)) {
        vec.push_back(buf);
    }
    return vec;
}

int main(){
    // マスの数を取得する
    string numOfCellsString;
    getline(cin, numOfCellsString);
    const auto numOfCells = stoi(numOfCellsString);
    const auto minNumOfCells = 2;
    const auto maxNumOfCells = 100;
    if (numOfCells < minNumOfCells || maxNumOfCells < numOfCells) {
        throw "The number of cells must be " + to_string(minNumOfCells) + "..." + to_string(maxNumOfCells) + ".";
    }
    auto goal = numOfCells - 1;

    // マスを取得する
    string cellsString;
    getline(cin, cellsString);
    auto tempCells = splitStringToVector(cellsString, ' ');
    if (numOfCells != tempCells.size()) {
        throw "The input value of cells and size of cells do not match.";
    }
    vector<int> cells;
    const auto minCellNum = -100;
    const auto maxCellNum = 100;
    for (int idx = 0; idx < numOfCells; idx++) {
        auto cellNum = stoi(tempCells[idx]);
        if (cellNum < minCellNum || maxCellNum < cellNum) {
            throw "The value of cell must be " + to_string(minCellNum) + "..." + to_string(maxCellNum) + ".";
        }else if((idx == 0 || idx == numOfCells - 1) && cellNum != 0) {
            throw "The value of first cell and/or last cell must be 0.";
        }
        cells.push_back(cellNum);
    }

    // 出目数を取得する
    string actsString;
    getline(cin, actsString);
    auto acts = stoi(actsString);
    const auto minActs = 0;
    const auto maxActs = 100;
    if (acts < minActs || maxActs < acts) {
        throw "The number of acts must be " + to_string(minActs) + "..." + to_string(maxActs) + ".";
    }

    // 出目の最小値と最大値
    const auto minActNum = 1;
    const auto maxActNum = 100;
    // 出目の処理を行う
    for (auto act = 0; act < acts; act++) {
        // 出目を取得する
        string numString;
        getline(cin, numString);

        auto num = stoi(numString);
        if (num < minActNum || maxActNum < num) {
            throw "The value of act must be " + to_string(minActNum) + "..." + to_string(maxActNum) + ".";
        }

        std::vector<int> moveLog;

        enum Status {
            CURRENT = 0,
            FINISHED,
            DEAD,
        };

        auto status = CURRENT;

        while (status == CURRENT) {
            if (num == goal) {
                // ゴールに到達した場合
                status = FINISHED;
            }else if (num < 1 || goal < num) {
                // スタート地点に戻ったり、ゴールを越えてしまった場合
                status = DEAD;
            }else{
                // それ以外
                auto moves = cells[num];
                if (moves == 0) {
                    // これ以上進めない場合
                    status = DEAD;
                }else{
                    // それ以外の場合。前に行ったことのあるマスなら無限ループに陥っているとみなしてゲームオーバーとする
                    num += moves;
                    for (auto moved : moveLog) {
                        if (num == moved) {
                            status = DEAD;
                            break;
                        }
                    }
                    if (status != DEAD) {
                        moveLog.push_back(num);
                    }
                }
            }
        }

        cout << (status == FINISHED ? "Yes" : "No") << endl;
    }
    return 0;
}
