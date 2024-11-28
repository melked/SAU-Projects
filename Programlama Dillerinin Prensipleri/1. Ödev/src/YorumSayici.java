/**
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 03.04.2024
* <p>
* Yorum sayan sınıf
* </p>
*/
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class YorumSayici {

    public static int countComments(File file) {
        int commentLines = 0;
        boolean inJavaDoc = false;

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();

                if (line.startsWith("/**")) { // Eğer javadoc varsa saymıyorum.
                    inJavaDoc = true;
                    continue;
                }

                if (inJavaDoc && line.endsWith("*/")) { 
                    inJavaDoc = false;
                    continue;
                }

                if (line.startsWith("/*") && !line.startsWith("/**") && !line.endsWith("*/")) { 
                	commentLines++;
                    inJavaDoc = true;
                    continue;
                }

                if (inJavaDoc) { // JavaDoc içerisindeyse devem ediyorum.
                	continue;
                }

                // Satır içindeki // ifadesini araıyorum ve bulunan her // ifadesi için sayacı arttırıyorum.
                int index = line.indexOf("//");
                while (index != -1) {
                    commentLines++;
                    index = line.indexOf("//", index + 1);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return commentLines;//en son yorum sayısının döndürüyorum.
    }
}
