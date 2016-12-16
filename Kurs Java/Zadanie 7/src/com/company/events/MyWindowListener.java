package com.company.events;

import com.company.tools.*;
import com.company.gui.MyInternalFrame;

import javax.swing.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.ArrayList;

/**
 * author @pater
 */
public class MyWindowListener implements WindowListener {

    private final JDesktopPane desktop;
    private FilesHandler filesHandler;

    public MyWindowListener(JDesktopPane desktop) {
        this.desktop = desktop;
    }

    @Override
    public void windowOpened(WindowEvent e) {
        FilesSerializer filesSerializer = new FilesSerializer();
        filesHandler = filesSerializer.restorePreviousFilesHandler();
        restoreLatestFrames();
    }

    private void restoreLatestFrames() {
        ArrayList<String> list = filesHandler.getListOfFramesTitles();
        list.forEach(this::createFrame);
    }

    private void createFrame(String title) {
        MyReader myReader = new MyReader(title);
        String content = myReader.getContentFromFile();
        MyInternalFrame frame = new MyInternalFrame(title, content);
        desktop.add(frame);
    }
    
    @Override
    public void windowClosing(WindowEvent e) {
        serializeCurrentFilesHandler();
    }

    private void serializeCurrentFilesHandler() {
        FilesSerializer filesSerializer = new FilesSerializer();
        filesSerializer.saveFilesHandler();
    }

    @Override
    public void windowClosed(WindowEvent e) {

    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }
    
}
