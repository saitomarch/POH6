using System;
using System.Collections.Generic;

public class Kirishima {
    private enum GameStatus {
        Current,
        Finished,
        Dead,
    }

    public static void Main() {
        // マスの数を取得する
        int numOfCells = int.Parse(System.Console.ReadLine());
        int goal = numOfCells - 1;
        const int minNumOfCells = 2;
        const int maxNumOfCells = 100;
        if (numOfCells < minNumOfCells || maxNumOfCells < numOfCells) {
            throw new Exception("The number of cells must be " + minNumOfCells + "..." + maxNumOfCells + ".");
        }

        // マスを生成する
        var cellsString = System.Console.ReadLine().Split(' ');
        if (cellsString.Length != numOfCells) {
            throw new Exception("The value of number of cells and cells length do not match.");
        }
        var cells = new int[numOfCells];
        const int minCellNum = -100;
        const int maxCellNum = 100;

        for (int idx = 0; idx < numOfCells; idx++) {
            var cellNum = int.Parse(cellsString[idx]);
            if (cellNum < minCellNum || maxCellNum < cellNum) {
                throw new Exception("The value of cell must be " + minCellNum + "..." + maxCellNum + ".");
            }else if((idx == 0 || idx == numOfCells - 1) && cellNum != 0) {
                throw new Exception("The value of first cell and/or last cell must be 0.");
            }
            cells[idx] = cellNum;
        }

        // 出目数を出力する
        int acts = int.Parse(System.Console.ReadLine());
        const int minActs = 0;
        const int maxActs = 100;
        if (acts < minActs || maxActs < acts) {
            throw new Exception("The number of acts must be " + minActs + "..." + maxActs + ".");
        }

        // 出目の最小値と最大値
        const int minActNum = 1;
        const int maxActNum = 100;

        // 出目の処理を行う
        for (int act = 0; act < acts; act++) {
            // 出目を取得する
            var num = int.Parse(System.Console.ReadLine());
            if (num < minActNum || maxActNum < num) {
                throw new Exception("The value of act must be " + minActNum + "..." + maxActNum + ".");
            }

            var moveLog = new List<int>();
            bool finished = false;
            GameStatus status = GameStatus.Current;

            while (status == GameStatus.Current) {
                if (num == goal) {
                    // ゴールに到達した場合
                    status = GameStatus.Finished;
                }else if(num < 1 || goal < num) {
                    // スタート地点に戻ったり、ゴールを越えてしまった場合
                    status = GameStatus.Dead;
                }else{
                    // それ以外
                    int moves = cells[num];
                    if (moves == 0) {
                        // これ以上進めない場合
                        status = GameStatus.Dead;
                    }else{
                        // それ以外の場合、前に行ったことのあるマスならゲームオーバー
                        num += moves;
                        foreach (var moved in moveLog) {
                            if (num == moved) {
                                status = GameStatus.Dead;
                                break;
                            }
                        }
                        if (status != GameStatus.Dead) {
                            moveLog.Add(num);
                        }
                    }
                }
            }
            System.Console.WriteLine(status == GameStatus.Finished ? "Yes" : "No");
        }
    }
}
