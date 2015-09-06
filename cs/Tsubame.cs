using System;

public class Tsubame {
    public static void Main(){
        // 文字列を取得し、整数に変換する
        var line = System.Console.ReadLine();
        int num = int.Parse(line);

        // 不正な値なら、例外を投げる
        const int minNum = 10;
        const int maxNum = 99;
        if (num < minNum || maxNum < num) {
            throw new Exception("The number must be " + minNum + "..." + maxNum + ".");
        }

        // それぞれの桁の数値を加算させる
        // 数字は文字コードとしての値となるため、補正が必要。
        const char zero = '0';
        foreach (var ch in line) {
            num += ch - zero;
        }

        // 出力する
        System.Console.WriteLine(num);
    }
}
