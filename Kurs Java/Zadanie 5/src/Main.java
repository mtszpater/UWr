import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;



class MazeCell {


    int[][] maze;
    int width;
    int height;
    int x;
    int y;



    public MazeCell(int width, int height) {

        this.width = width;
        this.height = height;
        this.maze = new int[height][width];
        this.x = generateRandomVariable(height);
        this.y = generateRandomVariable(width);

        generateMaze();

    }

    public void generateMaze() {

        initialize();

        setStartingCell();

        recursion(x,y);
    }

    private int generateRandomVariable(int height) {
        Random rand = new Random();

        int r = rand.nextInt(height);
        while (r % 2 == 0) {
            r = rand.nextInt(height);
        }
        return r;
    }

    private void setStartingCell() {
        maze[x][y] = 0;
    }

    private void initialize() {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                maze[i][j] = 1;
    }

    public void recursion(int r, int c) {

        Integer[] randDirs = generateRandomDirections();

        for (int i = 0; i < randDirs.length; i++) {
            switch(randDirs[i]){
                case 1: // Up
                    if (IsBiggerThan2(r))
                        continue;
                    if (maze[r - 2][c] != 0) {
                        maze[r-2][c] = 0;
                        maze[r-1][c] = 0;
                        recursion(r - 2, c);
                    }
                    break;
                case 2: // Right
                    if (cDontLeaveWidthArray(c))
                        continue;
                    if (maze[r][c + 2] != 0) {
                        maze[r][c + 2] = 0;
                        maze[r][c + 1] = 0;
                        recursion(r, c + 2);
                    }
                    break;
                case 3: // Down
                    if (rDontLeaveHeightArray(r))
                        continue;
                    if (maze[r + 2][c] != 0) {
                        maze[r+2][c] = 0;
                        maze[r+1][c] = 0;
                        recursion(r + 2, c);
                    }
                    break;
                case 4: // Left
                    if (IsBiggerThan2(c))
                        continue;
                    if (maze[r][c - 2] != 0) {
                        maze[r][c - 2] = 0;
                        maze[r][c - 1] = 0;
                        recursion(r, c - 2);
                    }
                    break;
            }
        }

    }

    private boolean IsBiggerThan2(int c) {
        return c - 2 <= 0;
    }

    private boolean rDontLeaveHeightArray(int r) {
        return r + 2 >= height - 1;
    }

    private boolean cDontLeaveWidthArray(int c) {
        return c + 2 >= width - 1;
    }

    public Integer[] generateRandomDirections() {
        ArrayList<Integer> randoms = new ArrayList<Integer>();

        for (int i = 0; i < 4; i++)
            randoms.add(i + 1);
        Collections.shuffle(randoms);

        return randoms.toArray(new Integer[4]);
    }


    public void displayMaze(){
        for( int i = 0; i < width-1; ++i) {
            for (int j = 0; j < height-1; ++j) {
                System.out.print(maze[i][j]);
            }
            System.out.print("\n");
        }
    }

    public int[][] getMaze() {
        return maze;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }
}


    public class Main {


    public static void main(String[] args) {


        MazeCell mz = new MazeCell(30, 30);

        mz.displayMaze();


        new MojeOkno(mz.getMaze(), mz.getWidth(), mz.getHeight());


    }


}