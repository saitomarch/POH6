import java.io.BufferedReader;
import java.io.InputStreamReader;

/// コーヒーを定義する
class Coffee {
    /// コーヒー粉
    private float _powder = 0.0f;
    /// 湯
    private float _water = 0.0f;

    /// 合計を取得する
    /// @return コーヒー粉と湯の合計値
    public float getTotal() {
        return _powder + _water;
    }

    /// コーヒー粉を入れる
    /// @param quantity コーヒー粉の量
    public void addPowder(float quantity) {
        _powder += quantity;
    }

    /// 湯を入れる
    /// @param quantity 湯の量
    public void addWater(float quantity) {
        _water += quantity;
    }

    /// 味見する
    /// @param quantity 味見するコーヒーの量
    public void taste(float quantity) {
        float total = getTotal();
        _powder -= quantity * _powder / total;
        _water -= quantity * _water / total;
    }

    /// 濃度を取得する
    /// @param asPercent パーセント形式で取得するかどうか
    /// @return 濃度
    float getConsentration(boolean asPercent) {
        float consentration = _powder / getTotal();
        return consentration * (asPercent ? 100.0f : 1.0f);
    }
}

// 注意: paizaオンラインハッカソンでテストする場合はRioをMainに変更してください。
public class Rio {
    public static void main(String[] args) throws Exception {
        // 文字列を取得し、整数に変換する
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int lines = Integer.parseInt(line);

        final int minLines = 1;
        final int maxLines = 10;
        if (lines < minLines || maxLines < lines) {
            throw new RuntimeException("The num of lines must be " + minLines + "..." + maxLines + ".");
        }

        Coffee coffee = new Coffee();

        // 量の最大値・最小値を設定する
        final int minQuantity = 1;
        final int maxQuantity = 100;

        // カラムのタイプ
        final int columnTypeActType = 0;
        final int columnTypeQuantity = 1;
        final int columnSize = 2;

        // 行動のタイプ
        final int actTypeAddWater = 1;
        final int actTypeAddPowder = 2;
        final int actTypeTaste = 3;

        // コーヒーの処理を行う
        for (int idx = 0; idx < lines; idx++) {
            String actString = br.readLine();
            String[] actArr = actString.split(" ");
            if (actArr.length != columnSize) {
                throw new RuntimeException("Invalid format of action inputted.");
            }

            int actionType = Integer.parseInt(actArr[columnTypeActType]);
            int quantity = Integer.parseInt(actArr[columnTypeQuantity]);
            if (quantity < minQuantity || maxQuantity < quantity) {
                throw new RuntimeException("The quantity must be " + minQuantity + "..." + maxQuantity + ".");
            }

            switch (actionType) {
                case actTypeAddWater:
                    coffee.addWater(quantity);
                    break;
                case actTypeAddPowder:
                    coffee.addPowder(quantity);
                    break;
                case actTypeTaste:
                    coffee.taste(quantity);
                    break;
                default:
                    throw new RuntimeException("Invalid action type detected. The action type must be 1(add water), 2(add powder), or 3(taste).");
            }
        }
        System.out.println((int)coffee.getConsentration(true));
    }
}
