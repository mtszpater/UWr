package com.company.tools;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * author @pater
 */
public class MyReader {
    private final String filename;

    public MyReader(String filename) {
        this.filename = filename;
    }

    public String getContentFromFile() {
        String line;
        String content = "";

        try {
            FileReader fileReader = new FileReader(Constans.SRC_COM_COMPANY_FILES + filename);

            BufferedReader bufferedReader = new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                content += line + System.getProperty("line.separator");
            }

            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println("Unable to open file '" );
        }
        catch(IOException ex) {
            System.out.println("Error reading file '");
        }
        return content;
    }
}
