package com.company.events;

import com.company.tools.*;

import javax.swing.*;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;

public class InternalCaretListener implements CaretListener {
    private String title;
    private JEditorPane editorPane;
    
    public InternalCaretListener(String title, JEditorPane editorPane) {
        this.title = title;
        this.editorPane = editorPane;
    }

    @Override
    public void caretUpdate(CaretEvent e) {
        FilesHandler filesHandler = FilesHandler.getInstance();
        filesHandler.setActiveFrame(title, editorPane.getText());
    }
}
