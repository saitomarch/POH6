import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    private enum GameStatus {
        CURRENT,
        FINISHED,
        DEAD,
    }

    public static void main(String[] args) throws Exception {
        // マスの数を取得する
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int numOfCells = Integer.parseInt(br.readLine());
        final int goal = numOfCells - 1;
        final int minNumOfCells = 2;
        final int maxNumOfCells = 100;
        if (numOfCells < minNumOfCells || maxNumOfCells < numOfCells) {
            throw new RuntimeException("The number of cells must be " + minNumOfCells + "..." + maxNumOfCells + ".");
        }

        // マスを生成する
        String[] cellsString = br.readLine().split(" ");
        if (cellsString.length != numOfCells) {
            throw new RuntimeException("The value of number of cells and cells length do not match.");
        }
        int[] cells = new int[numOfCells];
        final int minCellNum = -100;
        final int maxCellNum = 100;
        for (int idx = 0; idx < numOfCells; idx++) {
            int cellNum =  Integer.parseInt(cellsString[idx]);
            if (cellNum < minCellNum || maxCellNum < cellNum) {
                throw new RuntimeException("The value of cell must be " + minCellNum + "..." + maxCellNum + ".");
            }else if((idx == 0 || idx == numOfCells - 1) && cellNum != 0) {
                throw new RuntimeException("The value of first cell and/or last cell must be 0.");
            }
            cells[idx] = cellNum;
        }

        // 出目数を出力する
        final int acts = Integer.parseInt(br.readLine());
        final int minActs = 0;
        final int maxActs = 100;
        if (acts < minActs || maxActs < acts) {
            throw new RuntimeException("The number of acts must be " + minActs + "..." + maxActs + ".");
        }

        // 出目の最小値と最大値
        final int minActNum = 1;
        final int maxActNum = 100;

        // 出目の処理を行う
        for (int act = 0; act < acts; act++) {
            // 出目を取得する
            int num = Integer.parseInt(br.readLine());
            if (num < minActNum || maxActNum < num) {
                throw new RuntimeException("The value of act must be " + minActNum + "..." + maxActNum + ".");
            }

            ArrayList<Integer> moveLog = new ArrayList<Integer>();
            GameStatus status = GameStatus.CURRENT;

            while (status == GameStatus.CURRENT) {
                if (num == goal) {
                    // ゴールに到達した場合
                    status = GameStatus.FINISHED;
                }else if(num < 1 || goal < num) {
                    // スタート地点に戻ったり、ゴールを越えてしまった場合
                    status = GameStatus.DEAD;
                }else{
                    // それ以外
                    int moves = cells[num];
                    if (moves == 0) {
                        // これ以上進めない場合
                        status = GameStatus.DEAD;
                    }else{
                        // それ以外の場合、前に行ったことのあるマスならゲームオーバー
                        num += moves;
                        for (int moved : moveLog) {
                            if (num == moved) {
                                status = GameStatus.DEAD;
                                break;
                            }
                        }
                        if (status != GameStatus.DEAD) {
                            moveLog.add(num);
                        }
                    }
                }
            }
            System.out.println(status == GameStatus.FINISHED ? "Yes" : "No");
        }
    }
}
