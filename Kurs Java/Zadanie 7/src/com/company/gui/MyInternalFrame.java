
package com.company.gui;

import com.company.events.InternalCaretListener;
import com.company.events.InternalListener;

import javax.swing.*;
import java.awt.*;


public class MyInternalFrame extends JInternalFrame {
    private static int openFrameCount = 0;
    private static final int xOffset = 30;
    private static final int yOffset = 30;
    private JEditorPane editorPane;
    private String content;
    private String title;

    public MyInternalFrame(String title, String content) {
        super(title, true, true, true, true);
        this.content = content;
        this.title = title;
        init();
    }

    public MyInternalFrame(String title) {
        super(title, true, true, true, true);
        this.content = "";
        this.title = title;
        init();
    }

    private void init() {
        ++openFrameCount;
        setSize(300,300);

        addEditorScrollPane();
        addMenuBar();
        addListener();

        setLocation(xOffset*openFrameCount, yOffset*openFrameCount);
        setVisible(true);
    }
    
    private void addEditorScrollPane() {
        editorPane = new JEditorPane();
        editorPane.setText(content);
        editorPane.addCaretListener(new InternalCaretListener(title, editorPane));
        
        JScrollPane editorScrollPane = new JScrollPane(editorPane);
        setPropertyOfEditorScrollPane(editorScrollPane);
        add(editorScrollPane);
    }
    
    private void setPropertyOfEditorScrollPane(JScrollPane editorScrollPane) {
        editorScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        editorScrollPane.setPreferredSize(new Dimension(150, 145));
        editorScrollPane.setMinimumSize(new Dimension(10, 10));
    }
    
    private void addMenuBar() {
        setJMenuBar(new InternalFrameNavbar(editorPane));
    }

    private void addListener() {
        addInternalFrameListener(new InternalListener(editorPane));
    }
}



