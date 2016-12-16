package com.company.events;

import com.company.tools.*;

import javax.swing.*;
import javax.swing.event.InternalFrameEvent;
import javax.swing.event.InternalFrameListener;

/**
 * author @pater
 */
public class InternalListener implements InternalFrameListener {
    
    private JEditorPane editorPane;
    private FilesHandler filesHandler;

    public InternalListener(JEditorPane editorPane) {
        this.editorPane = editorPane;
        filesHandler = FilesHandler.getInstance();
    }

    @Override
    public void internalFrameOpened(InternalFrameEvent e) {
        filesHandler.addFramesToList(e.getInternalFrame().getTitle());
        filesHandler.setActiveFrame(e.getInternalFrame().getTitle(), editorPane.getText());
    }

    @Override
    public void internalFrameClosing(InternalFrameEvent e) {
        int reply = JOptionPane.showConfirmDialog(null, "Czy przed zamknieciem pliku chcesz go zapisac?", "Utrata danych", JOptionPane.YES_NO_OPTION);
        if (reply == JOptionPane.YES_OPTION)
        {
            FileSaver.save(editorPane.getText(), e.getInternalFrame().getTitle() );
        }
    }

    @Override
    public void internalFrameClosed(InternalFrameEvent e) {
        JInternalFrame frame = e.getInternalFrame();
        filesHandler.deleteFramesFromList(frame.getTitle());
    }

    @Override
    public void internalFrameIconified(InternalFrameEvent e) {
    }

    @Override
    public void internalFrameDeiconified(InternalFrameEvent e) {
    }

    @Override
    public void internalFrameActivated(InternalFrameEvent e) {
        JInternalFrame frame = e.getInternalFrame();
        filesHandler.setActiveFrame(frame.getTitle(), editorPane.getText());
    }

    @Override
    public void internalFrameDeactivated(InternalFrameEvent e) {
    }
}

