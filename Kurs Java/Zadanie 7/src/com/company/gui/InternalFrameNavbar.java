package com.company.gui;

import javax.swing.*;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.text.DefaultEditorKit;
import javax.swing.undo.CannotRedoException;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.UndoManager;
import java.awt.event.ActionEvent;

/**
 * author @pater
 */
class InternalFrameNavbar extends JMenuBar {

    private UndoAction undoAction;
    private RedoAction redoAction;
    private UndoManager undo = new UndoManager();
    private JMenu menu;

    InternalFrameNavbar(JEditorPane editorPane) {
        super();
        createEditMenu();

        editorPane.getDocument().addUndoableEditListener(new MyUndoableEditListener());
    }

    private void createEditMenu() {
        menu = new JMenu("Edit");

        createUndoButton();
        createRedoButton();
        menu.addSeparator();
        createCutButton();
        createCopyButton();
        createPasteButton();

        add (menu);
    }
    
    private void createUndoButton() {
        undoAction = new UndoAction();
        menu.add(undoAction);
    }
    
    private void createRedoButton() {
        redoAction = new RedoAction();
        menu.add(redoAction);
    }

    private void createCutButton() {
        Action cutAction = new DefaultEditorKit.CutAction();
        cutAction.putValue(Action.NAME, "Cut");
        menu.add(cutAction);
    }

    private void createCopyButton() {
        Action copyAction = new DefaultEditorKit.CopyAction();
        copyAction.putValue(Action.NAME, "Copy");
        menu.add(copyAction);
    }
    
    private void createPasteButton() {
        Action pasteAction = new DefaultEditorKit.PasteAction();
        pasteAction.putValue(Action.NAME, "Paste");
        menu.add(pasteAction);
    }

    private class UndoAction extends AbstractAction {
        UndoAction() {
            super("Undo");
            setEnabled(false);
        }

        public void actionPerformed(ActionEvent e) {
            try {
                undo.undo();
            } catch (CannotUndoException ex) {
                System.out.println("Unable to undo: " + ex);
                ex.printStackTrace();
            }
            updateUndoState();
            redoAction.updateRedoState();
        }

        void updateUndoState() {
            if (undo.canUndo()) {
                setEnabled(true);
                putValue(Action.NAME, undo.getUndoPresentationName());
            } else {
                setEnabled(false);
                putValue(Action.NAME, "Undo");
            }
        }
    }

    private class RedoAction extends AbstractAction {
        RedoAction() {
            super("Redo");
            setEnabled(false);
        }

        public void actionPerformed(ActionEvent e) {
            try {
                undo.redo();
            } catch (CannotRedoException ex) {
                System.out.println("Unable to redo: " + ex);
                ex.printStackTrace();
            }
            updateRedoState();
            undoAction.updateUndoState();
        }
        
        void updateRedoState() {
            if (undo.canRedo()) {
                setEnabled(true);
                putValue(Action.NAME, undo.getRedoPresentationName());
            } else {
                setEnabled(false);
                putValue(Action.NAME, "Redo");
            }
        }
    }
    
    private class MyUndoableEditListener implements UndoableEditListener {
        public void undoableEditHappened(UndoableEditEvent e) {
            undo.addEdit(e.getEdit());
            undoAction.updateUndoState();
            redoAction.updateRedoState();
        }
    }

}


