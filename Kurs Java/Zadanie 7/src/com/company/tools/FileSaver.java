package com.company.tools;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * author @pater
 */
public class FileSaver {

    
    public static void save(String content, String filename) {
        try {
            File file = new File(Constans.SRC_COM_COMPANY_FILES + filename);
            FileWriter writer = new FileWriter(file);
            writer.write(content);
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}
