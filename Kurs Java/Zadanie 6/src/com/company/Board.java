package com.company;

/**
 * author @pater
 */
public class Board {


    private int BoardType;
    private int Board[][];

    public void setCheckersCount(int checkersCount) {
        CheckersCount = checkersCount;
    }

    private int CheckersCount;


    public Board() {
        BoardType = Panel.BoardTypes.BRITISH;
    }


    public int[][] getBoard() {
        return Board;
    }

    public int getCheckersCount() {
        return CheckersCount;
    }

    public void setBoardType(int boardType) {
        BoardType = boardType;
    }

    private void fillRestOfTable() {

        standardVersionOfTable();

        if(BoardIsBritish()){
            System.out.println(BoardType);
            BritishVersionOfTable();
        }


    }

    public void createBoard() {
        Board = new int[20][20];
        fillTable0();
        fillRestOfTable();
    }

    private void BritishVersionOfTable() {
                Board[11][11] = 0;
                Board[11][7] = 0;
                Board[7][7] = 0;
                Board[7][11] = 0;
        CheckersCount = 33;
    }

    private void standardVersionOfTable() {
        for (int i = 6; i < 13; i++) {
            for (int j = 6; j < 13; j++) {
                Board[i][j] = 2;


                Board[6][6] = 0;
                Board[6][7] = 0;
                Board[6][11] = 0;
                Board[6][12] = 0;
                Board[7][6] = 0;
                Board[7][12] = 0;
                Board[12][7] = 0;
                Board[12][6] = 0;
                Board[12][12] = 0;
                Board[12][11] = 0;
                Board[11][6] = 0;
                Board[11][12] = 0;
                Board[11][11] = 2;
                Board[9][9] = 1;
                CheckersCount = 37;
            }
        }


    }


    private void fillTable0() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                Board[i][j] = 0;
            }
        }
    }

    private boolean BoardIsBritish() {
        return BoardType == Panel.BoardTypes.BRITISH;
    }


}
