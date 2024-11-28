/**
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 03.04.2024
* <p>
* Yorum sayısı sayan class
* </p>
*/
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class SatirSayici {

    public static int countCodeLines(File file) {
        int satirSayisi = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            boolean inYorum = false;
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
          
                if (!inYorum && !line.isEmpty() && !line.startsWith("//") && !line.startsWith("/*")) {// eğer satırda kos varsa yani yorum satırı değilse veya boşuk değilse o satırda kod vardır.
                    satirSayisi++;
                }
     
                if (!inYorum && line.startsWith("/*")) {
                    inYorum = true;
                    continue; // Yorum satırını saymıyorum.
                }
                
                if (inYorum && line.endsWith("*/")) {
                    inYorum = false;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return satirSayisi;
    }
}
