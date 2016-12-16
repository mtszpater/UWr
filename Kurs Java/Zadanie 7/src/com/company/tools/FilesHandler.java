package com.company.tools;

import java.io.*;
import java.util.ArrayList;

/**
 * author @pater
 */
public class FilesHandler implements Serializable {
    static final long serialVersionUID = -7588980448693010399L;
    private ArrayList <String> listOfFramesTitles = new ArrayList<>();
    private String activeTitleOfFrame;
    private String activeFrameEditorContent;
    private static FilesHandler instance = null;
    
    private FilesHandler() {}
    public static FilesHandler getInstance() {
        if(instance == null) {
            instance = new FilesHandler();
        }
        return instance;
    }
    
    public String getTitleOfActiveFrame(){
        return activeTitleOfFrame;
    }

    public String getContentOfActiveFrame(){
        return activeFrameEditorContent;
    }

    public ArrayList<String> getListOfFramesTitles() {
        return listOfFramesTitles;
    }
    
    public void addFramesToList(String frameTitle ){
        listOfFramesTitles.add(frameTitle);
    }
    
    public void deleteFramesFromList(String frameTitle){
        listOfFramesTitles.remove(frameTitle);
    }
    
    public void setActiveFrame(String frameTitle, String editorContent)
    {
        activeTitleOfFrame = frameTitle;
        activeFrameEditorContent = editorContent;
    }
    
    boolean isOpen(String filename) {
        for (String listOfFramesTitle : listOfFramesTitles) {
            if (listOfFramesTitle.compareTo(filename) == 0) {
                return true;
            }
        }
        return false;
    }
}
