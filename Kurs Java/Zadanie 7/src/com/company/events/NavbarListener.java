package com.company.events;

import com.company.tools.Constans;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * author @pater
 */
public class NavbarListener implements ActionListener {
    private final JFrame frame;

    public NavbarListener(JFrame frame) {
        this.frame = frame;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();
        
        if(cmd.equals(Constans.WINDOW))
            changeStyleToNimbus();
        else if(cmd.equals(Constans.METAL))
            changeStyleToMetal();
        else
            changeStyleToDefault();
        
        updateComponents();
    }

    private void changeStyleToNimbus() {
        try {
            UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e) {
            e.printStackTrace();
        }
    }

    private void changeStyleToMetal() {
        try {
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e) {
            e.printStackTrace();
        }
    }

    private void changeStyleToDefault() {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException e) {
            e.printStackTrace();
        }
    }

    private void updateComponents() {
        SwingUtilities.updateComponentTreeUI(frame);
    }
}
