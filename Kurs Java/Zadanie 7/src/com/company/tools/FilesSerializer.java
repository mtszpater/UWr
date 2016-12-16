package com.company.tools;

import java.io.*;

/**
 * author @pater
 */
public class FilesSerializer {
    private static final String PATH = Constans.SRC_COM_COMPANY_FILES + "fileshandler.ser";

    public void saveFilesHandler() {
        FilesHandler filesHandler = FilesHandler.getInstance();
        
        try {
            FileOutputStream fileOut = new FileOutputStream(PATH);
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(filesHandler);
            out.close();
            fileOut.close();
            System.out.printf("Serialized data is saved in "+PATH);
        }
        catch(IOException i) {
            i.printStackTrace();
        }

    }
    
    public FilesHandler restorePreviousFilesHandler() {
        try {
            return readFromFileToFilesHandler();
        }
        catch(IOException i) {
            i.printStackTrace();
        }
        catch(ClassNotFoundException c) {
            System.out.println("filesHandler class not found");
            c.printStackTrace();
        }
        
        return null;
    }

    private FilesHandler readFromFileToFilesHandler() throws IOException, ClassNotFoundException {
        FileInputStream fileIn = new FileInputStream(PATH);
        ObjectInputStream in = new ObjectInputStream(fileIn);
        FilesHandler filesHandler = (FilesHandler) in.readObject();
        in.close();
        fileIn.close();
        
        return filesHandler;
    }
}
