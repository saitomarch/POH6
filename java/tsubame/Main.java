import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        // 文字列を取得し、整数に変換する
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int num = Integer.parseInt(line);

        // 不正な値なら、例外を投げる
        final int minNum = 10;
        final int maxNum = 99;
        if (num < minNum || maxNum < num) {
            throw new RuntimeException("The numbe must be " + minNum + "..." + maxNum + ".");
        }

        // それぞれの桁の数値を加算させる
        // 数字は文字コードとしての値となるため、補正が必要。
        final char zero = '0';
        for (int idx = 0; idx < line.length(); idx++) {
            num += line.charAt(idx) - zero;
        }

        // 出力する
        System.out.println(num);
    }
}
