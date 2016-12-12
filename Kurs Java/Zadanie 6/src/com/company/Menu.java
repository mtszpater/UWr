package com.company;

<<<<<<< HEAD
import com.company.events.ActionManager;
import com.company.events.Actions;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

=======
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
>>>>>>> origin/master

/**
 * author @pater
 */
<<<<<<< HEAD
class Menu  implements ActionListener  {
    
    private JMenuBar menuBar;
    private JMenu menu;
    private JMenuItem menuItem;
    private Panel panel;
    private ButtonGroup group;



    void createMenu() {
        createNavBar();
        createGameBar();
        createSettingBar();
        createHelpBar();
    }
    
    private void createNavBar() {
        menuBar = new JMenuBar();
    }
    
    private void createGameBar() {
        createNavMenu("Gra");
        createGameButtons();
    }
    
    private void createNavMenu(String Title) {
        menu = new JMenu(Title);
        menuBar.add(menu);
    }

    private void createGameButtons() {
        createMenuItem("Nowa gra",  Actions.NEW_GAME);
        addSeparator();
        createMenuItem("Koniec",    Actions.END_GAME);
        createMenuItem("Zatrzymaj", Actions.PAUSE_GAME);
    }
    private void createMenuItem(String text, String actionCommand) {

        menuItem = new JMenuItem(text);
        menuItem.addActionListener(this);
        menuItem.setActionCommand(actionCommand);
        menu.add(menuItem);

    }
    
=======
public class Menu  implements ActionListener {

    private final Samotnik samotnik;
    JMenuBar menuBar;
    JMenu menu;
    JMenuItem menuItem;
    Panel can;
    ButtonGroup group;



    public void createMenu( ) {
        createNavBar();
        createGameBar();
        createMoveBar();
        createSettingBar();
        createHelpBar();
    }

    private void createHelpBar() {
        aligningMenuToRight();
        createNavMenu("Pomoc", KeyEvent.VK_C);
        createHelpButtons();
    }

    private void createSettingBar() {

        createNavMenu("Ustawienia", KeyEvent.VK_G);
        createVersionGroup();
        createPawnsColorGroup();
        createBackgroundColorGroup();
    }

    private void createMoveBar() {
        createNavMenu("Ruchy", KeyEvent.VK_G);
        createMoveButtons();
    }
    private void createGameBar() {
        createNavMenu("Gra" , KeyEvent.VK_G);
        createGameButtons();
    }

    private void createHelpButtons() {
        createMenuItem("O Grze", Actions.ABOUT_GAME.toString(), KeyEvent.VK_ENTER);
        addSeparator();
        createMenuItem("O Aplikacji",Actions.ABOUT_APPLICATION.toString(),KeyEvent.VK_D);
    }

    private void createMoveButtons() {
        createMenuItem("Wybierz punkt", Actions.CHOOSE_POINT,     KeyEvent.VK_D);
        addSeparator();
        createMenuItem("Skocz w gore",  Actions.GO_UP  ,          KeyEvent.VK_D);
        createMenuItem("Skocz w dol",   Actions.GO_DOWN   ,       KeyEvent.VK_D);
        createMenuItem("Skocz w lewo",  Actions.GO_LEFT ,         KeyEvent.VK_D);
        createMenuItem("Skocz w prawo", Actions.GO_RIGHT  ,       KeyEvent.VK_D);
    }


    private void createGameButtons() {
        createMenuItem("Nowa gra",  Actions.NEW_GAME,      KeyEvent.VK_4);
        addSeparator();
        createMenuItem("Koniec",    Actions.END_GAME,      KeyEvent.VK_3);
    }

>>>>>>> origin/master
    private void addSeparator() {
        menu.addSeparator();
    }

<<<<<<< HEAD
    private void createSettingBar() {

        createNavMenu("Ustawienia");
        createVersionGroup();
        createPawnsColorGroup();
        createBackgroundColorGroup();
    }

    private void createVersionGroup() {
        createNewButtonsGroup();
        createRadioButton(group, "Wersja 1", Actions.SET_GAME_1);
        makeButtonSelected();
        createRadioButton(group, "Wersja 2", Actions.SET_GAME_2);
    }

    private void createRadioButton(ButtonGroup group, String text, String setGame1) {
        menuItem = new JRadioButtonMenuItem(text);
        menuItem.addActionListener(this);
        menuItem.setActionCommand(setGame1);
        group.add(menuItem);
        menu.add(menuItem);
    }

    private void createNewButtonsGroup() {
        group = new ButtonGroup();
    }
    
    private void createPawnsColorGroup() {
        addSeparator();
        createNewButtonsGroup();
        createRadioButton(group, "Czerwone piony", Actions.SET_TO_BLACK);
        makeButtonSelected();
        createRadioButton(group, "Zielone piony", Actions.SET_TO_GREEN);
=======
    private void createMenuItem(String text, String actionCommand, int Key) {

        menuItem = new JMenuItem(text);
        menuItem.addActionListener(this);
        menuItem.setActionCommand(actionCommand);
        menuItem.setMnemonic(Key);

        menu.add(menuItem);

    }

    private void createNavMenu(String Title, int Key) {
        menu = new JMenu(Title);
        menu.setMnemonic(Key);
        menuBar.add(menu);
    }

    private void createRadioButton(ButtonGroup group, String text, String setGame1, int vkR) {
        menuItem = new JRadioButtonMenuItem(text);
        menuItem.addActionListener(this);
        menuItem.setActionCommand(setGame1);
        menuItem.setMnemonic(vkR);
        group.add(menuItem);
        menu.add(menuItem);

    }
    private void aligningMenuToRight() {
        menuBar.add(Box.createHorizontalGlue());
    }

    public void createNavBar() {
        menuBar = new JMenuBar();
    }

    public Menu(Panel can) {
        this.can = can;
        this.samotnik = Samotnik.getInstance();
    }


    public JMenuBar getMenuBar() {
        return menuBar;
    }

    private void createBackgroundColorGroup() {
        addSeparator();
        createNewButtonsGroup();
        createRadioButton(group, "Czerwone tło", Actions.SET_BACKGROUND_TO_BLACK, KeyEvent.VK_R);
        makeButtonSelected();
        createRadioButton(group, "Zielone tło", Actions.SET_BACKGROUND_TO_GREEN, KeyEvent.VK_O);
>>>>>>> origin/master
    }

    private void makeButtonSelected() {
        menuItem.setSelected(true);
    }
<<<<<<< HEAD
    
    private void createBackgroundColorGroup() {
        addSeparator();
        createNewButtonsGroup();
        createRadioButton(group, "Czerwone tło", Actions.SET_BACKGROUND_TO_BLACK);
        makeButtonSelected();
        createRadioButton(group, "Zielone tło", Actions.SET_BACKGROUND_TO_GREEN);
    }
    
    private void createHelpBar() {
        aligningMenuToRight();
        createNavMenu("Pomoc");
        createHelpButtons();
    }

    private void aligningMenuToRight() {
        menuBar.add(Box.createHorizontalGlue());
    }
    
    private void createHelpButtons() {
        createMenuItem("O Grze", Actions.ABOUT_GAME);
        addSeparator();
        createMenuItem("O Aplikacji", Actions.ABOUT_APPLICATION);
    }
    
    Menu(Panel can) {
        this.panel = can;
    }
    
    JMenuBar getMenuBar() {
        return menuBar;
    }
    
    public void actionPerformed(ActionEvent e) {
        String i = e.getActionCommand();
        ActionManager am = new ActionManager(panel);
        am.reaction(i);
=======

    private void createPawnsColorGroup() {
        addSeparator();
        createNewButtonsGroup();
        createRadioButton(group, "Czerwone piony", Actions.SET_TO_BLACK, KeyEvent.VK_R);
        makeButtonSelected();
        createRadioButton(group, "Zielone piony", Actions.SET_TO_GREEN, KeyEvent.VK_O);
    }

    private void createVersionGroup() {
        createNewButtonsGroup();
        createRadioButton(group, "Wersja 1", Actions.SET_GAME_1, KeyEvent.VK_R);
        makeButtonSelected();
        createRadioButton(group, "Wersja 2", Actions.SET_GAME_2, KeyEvent.VK_O);
    }

    private void createNewButtonsGroup() {
        group = new ButtonGroup();
    }

    public void actionPerformed(ActionEvent e) {
        String i = e.getActionCommand();
        System.out.println(e.paramString());
        can.whatToDo(i);
>>>>>>> origin/master
    }
}
