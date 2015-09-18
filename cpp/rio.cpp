#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/// 文字列を分割する
/// @param str 文字列の参照
/// @param sep 分割に使う文字
/// @return 分割後の配列(std::vector)
vector<string> splitStringToVector(const string &str, const char sep) {
    vector<string> vec;
    stringstream sstream(str);
    string buf;
    while (getline(sstream, buf, sep)) {
        vec.push_back(buf);
    }
    return vec;
}

/// ラインを取得する
/// @return 取得したラインの文字列
string readLine() {
    string str;
    getline(cin, str);
    return str;
}

/// コーヒーを定義する
class Coffee {
private:
    /// コーヒーの粉の量
    float _powder;

    /// 湯(水)の量
    float _water;

public:
    /// コンストラクタ
    Coffee() : _powder(0), _water(0) {}

    /// 合計を取得する
    /// @return 粉と水の合計値
    float getTotal() {
        return _powder + _water;
    }

    /// コーヒー粉を入れる
    /// @param powder 粉の量
    void addPowder(float powder) {
        _powder += powder;
    }

    /// 湯(水)を入れる
    /// @param water 湯(水)の量
    void addWater(float water) {
        _water += water;
    }

    /// 濃度を取得する
    /// @param asPercent パーセントとして取得するかどうか。デフォルトはfalse。
    /// @return 濃度
    template <typename T> T getConsentration(bool asPercent = false) {
        float consentration = _powder / getTotal();
        return static_cast<T>(consentration * (asPercent ? 100.0 : 1.0));
    }

    /// 味見をする
    /// @param quantity 味見をするコーヒーの量
    void taste(float quantity) {
        auto total = getTotal();
        _powder -= quantity * _powder / total;
        _water -= quantity * _water / total;
    }
};

int main(void){
    // 行数を取得する
    auto lines = stoi(readLine());
    const auto minLines = 1;
    const auto maxLines = 10;
    if (lines < minLines || maxLines < lines) {
        throw "The lines must be " + to_string(minLines) + "..." + to_string(maxLines) + ".";
    }

    Coffee coffee;

    // 量の閾値を設定する
    const auto minQuantity = 1;
    const auto maxQuantity = 100;

    for (auto line = 0; line < lines; line++) {
        // カラムのタイプを取得する
        enum {
            ACT_TYPE = 0,
            QUANTITY,
            COLUMN_SIZE,
        };
        // 行動のタイプを定義する
        enum {
            ADD_WATER = 1,
            ADD_POWDER = 2,
            TASTE = 3,
        };

        auto actArr = splitStringToVector(readLine(), ' ');
        if (actArr.size() != COLUMN_SIZE) {
            throw "Invalid format of action inputted.";
        }

        auto action = stoi(actArr[ACT_TYPE]);
        auto quantity = stoi(actArr[QUANTITY]);
        if (quantity < minQuantity || maxQuantity < quantity) {
            throw "The quantity must be " + to_string(minQuantity) + "..." + to_string(maxQuantity) + ".";
        }

        switch (action) {
            case ADD_WATER:
                coffee.addWater(quantity);
                break;
            case ADD_POWDER:
                coffee.addPowder(quantity);
                break;
            case TASTE:
                coffee.taste(quantity);
                break;
            default:
                throw "Invalid action type detected. The action type must be 1(add water), 2(add powder), or 3(taste).";
                break;
        }
    }
    cout << coffee.getConsentration<int>(true) << endl;
    return 0;
}
