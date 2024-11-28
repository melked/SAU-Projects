/**
*
* @author g211210003 Melike Demirtaş melike.demirtas@ogr.sakarya.edu.tr
* @since 03.04.2024
* <p>
* Tüm satır sayısını sayan class
* </p>
*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class LOCSayici {
	 public static int countLOC(File file) {
	        int LOCSayisi = 0;

	        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
	            while ((reader.readLine()) != null) {// her satır için sayacı bir arttır.
	                LOCSayisi++;
	            }
	        } catch (IOException e) {
	            e.printStackTrace();
	        }

	        return LOCSayisi;
	    }
}
