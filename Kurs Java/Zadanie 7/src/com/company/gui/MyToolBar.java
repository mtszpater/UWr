package com.company.gui;

import com.company.events.ToolBarListener;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.net.URL;

/**
 * author @pater
 */
class MyToolBar extends JToolBar  {
    static final private String SAVE = "save";
    static final private String WRITE = "write";
    static final private String NEW = "new";
    private JDesktopPane desktop;
    private JButton button;

    MyToolBar(JDesktopPane desktop) {
        super();
        this.desktop = desktop;
        addButtons();
    }

    private void addButtons() {
        makeNavigationButton(SAVE, "Save file", "Save");
        makeNavigationButton(WRITE, "Write on console", "Write");
        makeNavigationButton(NEW, "Create new file", "New file");
    }

    private void makeNavigationButton(String actionCommand, String toolTipText, String altText) {
        button = new JButton();
        
        String imgLocation = createImageLocation(actionCommand);
        URL imageURL = Gui.class.getResource(imgLocation);
        
        button.setActionCommand(actionCommand);
        button.setToolTipText(toolTipText);
        
        addListeners();

        if (doNotFindIMG(imageURL)) {
            button.setIcon(new ImageIcon(imageURL, altText));
        } else {
            button.setText(altText);
            System.err.println("Resource not found: " + imgLocation);
        }
        add(button);
    }
    private String createImageLocation(String actionCommand) {
        return "../res/" + actionCommand + ".png";
    }

    private void addListeners() {
        ActionListener actionListener = new ToolBarListener(desktop);
        button.addActionListener(actionListener);
    }
    
    private boolean doNotFindIMG(URL imageURL) {
        return imageURL != null;
    }
}
