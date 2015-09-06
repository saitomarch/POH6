using System;

/// コーヒーを定義する
class Coffee {
    /// コーヒー粉
    private float Powder = 0.0f;
    /// 湯
    private float Water = 0.0f;

    /// 合計を取得する
    /// @return コーヒー粉と湯の合計値
    public float GetTotal() {
        return Powder + Water;
    }

    /// コーヒー粉を入れる
    /// @param quantity コーヒー粉の量
    public void AddPowder(float quantity) {
        Powder += quantity;
    }

    /// 湯を入れる
    /// @param quantity 湯の量
    public void AddWater(float quantity) {
        Water += quantity;
    }

    /// 味見する
    /// @param quantity 味見するコーヒーの量
    public void Taste(float quantity) {
        float total = GetTotal();
        Powder -= quantity * Powder / total;
        Water -= quantity * Water / total;
    }

    /// 濃度を取得する
    /// @param asPercent パーセント形式で取得するかどうか
    /// @return 濃度
    public float GetConsentration(bool asPercent) {
        float consentration = Powder / GetTotal();
        return consentration * (asPercent ? 100.0f : 1.0f);
    }
}

public class Rio {
    public static void Main() {
        // 処理行数を取得する
        var lines = int.Parse(System.Console.ReadLine());
        const int minLines = 1;
        const int maxLines = 10;
        if (lines < minLines || maxLines < lines) {
            throw new Exception("The num of lines must be " + minLines + "..." + maxLines + ".");
        }

        Coffee coffee = new Coffee();

        // 量の最大値・最小値を設定する
        const int minQuantity = 1;
        const int maxQuantity = 100;

        // カラムのタイプ
        const int columnTypeActType = 0;
        const int columnTypeQuantity = 1;
        const int columnSize = 2;

        // 行動のタイプ
        const int actTypeAddWater = 1;
        const int actTypeAddPowder = 2;
        const int actTypeTaste = 3;


        // コーヒーの処理を行う
        for (int idx = 0; idx < lines; idx++) {
            var actString = System.Console.ReadLine();
            var actArr = actString.Split(' ');
            if (actArr.Length != columnSize) {
                throw new Exception("Invalid format of action inputted.");
            }

            int actionType = int.Parse(actArr[columnTypeActType]);
            int quantity = int.Parse(actArr[columnTypeQuantity]);
            if (quantity < minQuantity || maxQuantity < quantity) {
                throw new Exception("The quantity must be " + minQuantity + "..." + maxQuantity + ".");
            }

            switch (actionType) {
                case actTypeAddWater:
                    coffee.AddWater(quantity);
                    break;
                case actTypeAddPowder:
                    coffee.AddPowder(quantity);
                    break;
                case actTypeTaste:
                    coffee.Taste(quantity);
                    break;
                default:
                    throw new Exception("Invalid action type detected. The action type must be 1(add water), 2(add powder), or 3(taste).");
            }
        }

        // 出力する
        System.Console.WriteLine((int)coffee.GetConsentration(true));
    }
}
