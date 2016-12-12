package com.company;
import javax.swing.*;




public class Samotnik{

    private static Samotnik instance = null;
<<<<<<< HEAD
    private Panel panel;
=======
    private Panel can;
>>>>>>> origin/master
    static private JFrame gameFrame;
    private Window window;


    protected Samotnik() {
<<<<<<< HEAD
    }

    static Samotnik getInstance() {
=======

    }

    public static Samotnik getInstance() {
>>>>>>> origin/master
        if(instance == null) {
            instance = new Samotnik();
        }
        return instance;
    }


<<<<<<< HEAD
    void init() {
=======
    public void init() {

>>>>>>> origin/master
        createWindow();
        createGUI();
        setVisibileOfFrame();

    }
<<<<<<< HEAD
    
=======

    private void createGUI() {
        can = new Panel(gameFrame.createImage(500, 500));
        gameFrame.add(can);
        createMenu();
    }



    private void setVisibileOfFrame() {
        window.setVisibleOfFrame();
    }

>>>>>>> origin/master
    private void createWindow() {
        gameFrame = new JFrame();
        gameFrame.addNotify();
        window = new Window(gameFrame);
    }
<<<<<<< HEAD
    
    private void createGUI() {
        panel = new Panel(gameFrame.createImage(500, 500));
        gameFrame.add(panel);
        createMenu();
    }

    private void createMenu() {
        Menu menu = new Menu(panel);
        menu.createMenu();
        gameFrame.setJMenuBar(menu.getMenuBar());
    }
    
    private void setVisibileOfFrame() {
        window.setVisibleOfFrame();
    }
=======

    private void createMenu() {
        Menu menu = new Menu(can);
        menu.createMenu();
        gameFrame.setJMenuBar(menu.getMenuBar());
    }

>>>>>>> origin/master

}
