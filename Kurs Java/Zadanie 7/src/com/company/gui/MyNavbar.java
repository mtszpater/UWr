package com.company.gui;

import com.company.events.NavbarListener;
import javax.swing.*;

/**
 * author @pater
 */
class MyNavbar extends JMenuBar {
    private static final String WINDOW = "window";
    private static final String METAL = "metal";
    private JMenu menu;
    private JRadioButtonMenuItem menuItem;
    private ButtonGroup buttonsGroups;
    private JFrame frame;

    MyNavbar(JFrame frame) {
        super();
        this.frame = frame;
        createEditMenu();
    }
    
    private void createEditMenu() {
        menu = new JMenu("Settings");
        createChangeLookAndFeelMenu();
    }

    private void createChangeLookAndFeelMenu() {
        buttonsGroups = new ButtonGroup();
        createWindowButton();
        createGTKButton();
        createMetalButton();
        add(menu);
    }

    private void createWindowButton() {
        menuItem = new JRadioButtonMenuItem("Nimbus");
        menuItem.setActionCommand(WINDOW);
        addListenerAndAddToMenu();
    }
    
    private void createGTKButton() {
        menuItem = new JRadioButtonMenuItem("System");
        addListenerAndAddToMenu();
    }

    private void createMetalButton() {
        menuItem = new JRadioButtonMenuItem("Metal");
        menuItem.setActionCommand(METAL);
        addListenerAndAddToMenu();
    }

    private void addListenerAndAddToMenu() {
        menuItem.addActionListener(new NavbarListener(frame));
        buttonsGroups.add(menuItem);

        menu.add(menuItem);
    }
    
}


