#include <iostream>
#include <vector>
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
using namespace std;
 
int main(void){
    // マスの数を取得する
    string numOfCellsString;
    getline(cin, numOfCellsString);
    auto numOfCells = stoi(numOfCellsString);
    if (numOfCells < 2 || 100 < numOfCells) {
        throw "Invalid numOfCells detected";
    }
    auto goal = numOfCells - 1;
     
    // マスを取得する
    string cellsString;
    getline(cin, cellsString);
    auto cells = splitStringToVector(cellsString, ' ');
    for (auto cell : cells) {
        if (stoi(cell) < -100 || 100 < stoi(cell)) {
            throw "Invalid num detected";
        }
    }
     
    if (numOfCells != cells.size()) {
        throw "numOfCells and size of cells.size not match.";
    }
     
    // 出目数を取得する
    string actsString;
    getline(cin, actsString);
    auto acts = stoi(actsString);
    if (acts < 0 || 100 < acts) {
        throw "Invalid acts detected.";
    }
     
    // 出目の処理を行う
    for (auto act = 0; act < acts; act++) {
        // 出目を取得する
        string numString;
        getline(cin, numString);
        auto num = stoi(numString);
        std::vector<int> moveLog;
         
        bool finished = false;
         
        int times = 0;
        while (true) {
            if (num == goal) {
                finished = true;
                break;
            }else if (num < 1 || goal < num) {
                finished = false;
                break;
            }else{
                auto moves = stoi(cells.at(num));
                if (moves == 0) {
                    finished = false;
                    break;
                }else{
                    num += moves;
                    bool infinity = false;
                    for (auto moved : moveLog) {
                        if (num == moved) {
                            infinity = true;
                            break;
                        }
                    }
                    if (infinity) {
                        finished = false;
                        break;
                    }else{
                        moveLog.push_back(num);
                    }
                }
            }
            times++;
        }
         
        if (finished) {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}

