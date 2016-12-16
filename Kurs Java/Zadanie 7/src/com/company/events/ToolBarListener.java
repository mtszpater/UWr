package com.company.events;

import com.company.tools.*;
import com.company.gui.MyInternalFrame;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * author @pater
 */
public class ToolBarListener implements ActionListener {
    private JDesktopPane desktop;

    public ToolBarListener(JDesktopPane desktop) {
        this.desktop = desktop;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();

        if (Constans.NEW.equals(cmd)) {
            actionNewFile();
        }
        else if (Constans.WRITE.equals(cmd)) {
            createFrameWithContent();
        }
        else if (Constans.SAVE.equals(cmd)) {
            actionSave();
        }
    }

    private void actionNewFile() {
        String fileName = showInputDialogAndGetResult();
        checkFileNameAndCreateFrame(fileName);
    }

    private String showInputDialogAndGetResult() {
        return (String) JOptionPane.showInputDialog(desktop, "Podaj nazwę pliku", "Nazwa pliku", JOptionPane.PLAIN_MESSAGE, null, null, "Bez tytulu");
    }
    
    private void checkFileNameAndCreateFrame(String filename) {
        FilenameCreator filenameCreator = new FilenameCreator(filename);

        if(filenameCreator.checkFileName()) {
            createFrame(filenameCreator.getFilename());
        }
    }

    private void createFrame(String title) {
        MyInternalFrame frame = new MyInternalFrame(title);
        desktop.add(frame);
    }
    
    private void createFrameWithContent() {
        String filename = showOptionDialogAndGetResult();
        
        if( filename != null) {
            String content = getContentFromFile(filename);
            MyInternalFrame frame = new MyInternalFrame(filename, content);
            desktop.add(frame);
        }
    }
    
    private String showOptionDialogAndGetResult() {
        Object[] possibilities = getFilesList();
        return (String) JOptionPane.showInputDialog(desktop, "Wybierz plik z listy", "Otwórz plik", JOptionPane.PLAIN_MESSAGE, null, possibilities, "Brak");
    }

    private Object[] getFilesList() {
        FilesOpener filesOpener = new FilesOpener();
        return filesOpener.getListOfFilesName();
    }

    private String getContentFromFile(String filename) {
        MyReader myReader = new MyReader(filename);
        return myReader.getContentFromFile();
    }

    private void actionSave() {
        FilesHandler filesHandler = FilesHandler.getInstance();
        FileSaver.save(filesHandler.getContentOfActiveFrame(), filesHandler.getTitleOfActiveFrame());
    }
    
    
}
