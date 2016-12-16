package com.company.gui;

/**
 * author @pater
 */


import com.company.events.MyWindowListener;

import javax.swing.*;
import java.awt.*;


public class Gui extends JFrame{
    private JToolBar toolBar;
    private JDesktopPane desktop;
    
    private Gui() {
        super("Title");
        setWindowDimension();
        addDesktopPane();
        addToolBar();
        addMenuBar();
        addWindowListener(new MyWindowListener(desktop));
    }

    private void setWindowDimension() {
        int inset = 50;
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        setBounds(inset, inset, screenSize.width  - inset*2, screenSize.height - inset*2);
    }

    private void addDesktopPane() {
        desktop = new JDesktopPane();
        getContentPane().add(desktop);
    }
    
    private void addToolBar() {
        toolBar = new MyToolBar(desktop);
        getContentPane().add(toolBar, BorderLayout.NORTH);
    }

    private void addMenuBar() {
        setJMenuBar(new MyNavbar(this));
    }
    
    public static void createAndShowGUI() {
        JFrame.setDefaultLookAndFeelDecorated(true);
        Gui frame = new Gui();
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
