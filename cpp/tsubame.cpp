#include <iostream>
using namespace std;
 
int main(){
    // 数字を取得する(文字列として)
    string str;
    getline(cin, str);
    auto num = stoi(str);
     
    // 10〜99以外の場合は例外を投げる
    const auto min = 10;
    const auto max = 99;
    if (num < min || max < num) {
        throw "The number must be " + to_string(min) + " ... " + to_string(max) +".";
    }
     
    // それぞれの桁数を計算する
    // (文字として扱われるため、必ず'0'の文字コードの数値を減算する)
    const auto zero = '0';
    for (auto ch : str) {
        num += ch - zero;
    }
     
    // 数値を出力する
    cout << num << endl;
     
    return 0;
}

