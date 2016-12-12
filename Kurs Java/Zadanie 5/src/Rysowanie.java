

/*
    Copyright (c) November 2010 by PaweĹ‚ Rzechonek
    Aplikacja okienkowa AWT - prezentuje moĹĽliwoĹ›ci klasy Canvas
    w przechwytywaniu zdarzeĹ„ od myszy i od klawiatury.
    Aby przechwytywaÄ‡ zdarzenia od klawiatury trzeba najpierw wywoĹ‚aÄ‡ metodÄ™
    setFocusable(true) na obiekcie Canvas.
*/

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

class MojeOkno extends Frame
{
    private final int[][] maze;
    private final int width;
    private final int height;
    private Color kolor = Color.BLACK;

    private WindowListener frameList = new WindowAdapter()
    {
        @Override
        public void windowClosing (WindowEvent ev)
        {
            MojeOkno.this.dispose();
        }
    };


    private ActionListener generateAction = new ActionListener()
    {
        @Override
        public void actionPerformed (ActionEvent ev)
        {
            Graphics gr = plotno.getGraphics();

            gr.setColor(Color.RED);

        }
    };


    private MouseListener mouseList = new MouseAdapter()
    {
        @Override
        public void mouseClicked(MouseEvent ev)
        {
            Graphics gr = plotno.getGraphics();
            gr.setColor(Color.RED);

            makeMaze();


        }
    };

    private int scale_y(int i) {
        return i/height;
    }




    public void makeMaze()
    {


        plotno.getGraphics().setColor(Color.RED);
        for( int z = 0; z < width-1; ++z) {
            for (int j = 0; j < height-1; ++j) {
                System.out.println(scale_x(400)+ ", " + j*10);
                if(maze[z][j] == 1) plotno.getGraphics().fillRect(z*scale_x(400),j*scale_y(400), scale_x(400), scale_y(400));
            }
        }




    }


    public void ludzik()
    {

    }
    private KeyListener keyList = new KeyAdapter()
    {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
                case KeyEvent.VK_R: // klawisz 'R'
                    kolor = Color.RED;
                    break;
                case KeyEvent.VK_G: // klawisz 'G'
                    kolor = Color.GREEN;
                    break;
                case KeyEvent.VK_B: // klawisz 'B'
                    kolor = Color.BLUE;
                    break;
                default: // inne klawisze
                    kolor = Color.BLACK;
                    break;
            }
        }
    };
    private BufferedImage img = null;
    {
        try { img = ImageIO.read(new File("1480018138_Santa.png")); }
        catch (IOException e) { }
    }

    private Canvas plotno = new Canvas() {
        @Override
        public void paint(Graphics gr) {

            super.paint(gr);



        }
    };
    private Button button = new Button("generate");



    private int scale_x(int x){

        return x/width;
    }


    public MojeOkno(int[][] maze, int width, int height) {

        super("kolorowe kwadraty");

        this.maze = maze;
        this.width = width;
        this.height = height;
        setSize(400, 400);
        add(plotno, BorderLayout.CENTER);
        plotno.addKeyListener(keyList);
        plotno.addMouseListener(mouseList);
        plotno.setFocusable(true);
        button.addActionListener(generateAction);

        plotno.requestFocus();

        addWindowListener(frameList);

        setVisible(true);


    }



    public class ImageCanvas extends Canvas {

        private BufferedImage img;

        public ImageCanvas() {
            try {
                img = ImageIO.read(new File("1480018138_Santa.png"));
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }

        @Override
        public Dimension getPreferredSize() {
            return img == null ? new Dimension(200, 200) : new Dimension(img.getWidth(), img.getHeight());
        }

        @Override
        public void paint(Graphics g) {
            super.paint(g);
            if (img != null) {
                int x = (getWidth() - img.getWidth()) / 2;
                int y = (getHeight() - img.getHeight()) / 2;
                g.drawImage(img, x, y, this);
            }
        }

    }


}


