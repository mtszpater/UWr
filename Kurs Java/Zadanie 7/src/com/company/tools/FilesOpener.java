package com.company.tools;

import java.io.File;

/**
 * author @pater
 */
public class FilesOpener {
    private File folder = new File(Constans.SRC_COM_COMPANY_FILES);
    private File[] listOfFiles = folder.listFiles();
    private int count = 1;
    private FilesHandler filesHandler = FilesHandler.getInstance();
    
    public Object[] getListOfFilesName() {

        countOfFiles();
        Object[] possibilities = new Object[count];

        for (File listOfFile : listOfFiles) {
            if (isCorrect(listOfFile)) {
                possibilities[count - 1] = listOfFile.getName();
                --count;
            }
        }
        return possibilities;
    }

    private void countOfFiles() {
        for (File listOfFile : listOfFiles) {
            if (isCorrect(listOfFile)) {
                ++count;
            }
        }
    }

    private boolean isCorrect(File listOfFile) {
        return isFile(listOfFile) && !isSerializableFile(listOfFile) && !isOpen(listOfFile) && !isNull(listOfFile) && !isDS_STORE(listOfFile);
    }

    private boolean isNull(File file) {
        return file.getName().compareTo("null") == 0;
    }
    
    private boolean isDS_STORE(File file){
        return file.getName().compareTo(".DS_Store") == 0;
    }

    private boolean isFile(File file) {
        return file.isFile();
    }

    private boolean isSerializableFile(File file) {
        return file.getName().contains(".ser");
    }

    private boolean isOpen(File file) {
        return filesHandler.isOpen(file.getName());
    }
}
