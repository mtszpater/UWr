package com.company.tools;


import java.sql.Timestamp;

/**
 * author @pater
 */
public class FilenameCreator {
    private String filename;

    public FilenameCreator(String filename) {
        this.filename = filename;
    }

    public boolean checkFileName() {
        try {
            checkFileLength();
        } 
        catch (Exception e) {
            System.err.println(e.getMessage());
            return false;
        }
        return true;
    }

    private void checkFileLength() throws Exception {
        if(filename.length() < 4)
            throw new Exception("Za krótka nazwa pliku");
        generateFilename();
    }

    private void generateFilename(){
        Timestamp timestamp = new Timestamp(System.currentTimeMillis());
        filename = filename + "_" + timestamp.getTime();
    }
    
    public String getFilename() {
        return filename;
    }
}
