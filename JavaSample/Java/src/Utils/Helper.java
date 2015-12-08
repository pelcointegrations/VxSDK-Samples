package Utils;

import java.io.File;
import java.util.ArrayList;

// TODO: Auto-generated Javadoc
/**
 * The Class Helper.
 */
public class Helper {
	
	/**
	 * Load available dlls.
	 *
	 * @param dllsToLoad the dlls to load
	 * @return the array list
	 */
	private static ArrayList<String> LoadAvailableDlls(ArrayList<String> dllsToLoad){
		ArrayList<String> loadedDlls = new ArrayList<String>();
		for(String obj: dllsToLoad){
			try{				
	        	System.loadLibrary(obj.toString());	        	
	        	loadedDlls.add(obj);
			}
			catch(UnsatisfiedLinkError error){				
				
			}
			catch (Exception e){
				System.out.println(e.getMessage() + ":" + obj.toString());

			}
		}
		return loadedDlls;
	}
	
	/**
	 * Load gst binaries.
	 *
	 * @param rootPath the root path
	 */
	public static void loadGSTBinaries(String rootPath){
			
		//GStreamer libraries are available inside libs folder		
		String binPath = rootPath + "bin/";
		String libPath =  rootPath + "lib/";			    
		
		File[] binFiles = new File(binPath).listFiles();
		File[] libFiles = new File(libPath + "gstreamer-1.0/").listFiles();
		
		ArrayList<String> allDlls = new ArrayList<String>();
		
		try {
			/*First we need to load all the dlls inside the bin folder.
			 * Some of them are dependent on others, since files will be taken in alphabetical order,
			 * we can't make sure the dependent libraries are loaded or so.
			 * 
			 * So take all the files into an array and recursively load all the libraries until dependent libraries are
			 * loaded
			 * */
			for(File file : binFiles){
				String fileName = file.getName();			
				String fileNameWithOutExt = fileName.replaceFirst("[.][^.]+$", "");
				allDlls.add(binPath + fileNameWithOutExt); //Get all the files without extension in an arraylist
			}		
			
			while(allDlls.size() > 0){
				ArrayList<String> loadedOnes = LoadAvailableDlls(allDlls); //Load the dlls available in this list
				//The loadedOnes array contains libraries that are loaded. So filter the actual dlls based on this and 
				//load remaining libraries until the list is empty.
				if(loadedOnes.size() > 0){				
					for(String obj: loadedOnes){
						allDlls.remove(obj);
					}
				}
				else if(loadedOnes.size() == 0){
					System.out.println("Following dlls failed to load.Possibility of error during streaming!!");
					for(String obj: allDlls){
						System.out.println(obj);
					}
					allDlls.clear();
					break;
				}
			}
			
			/*
			 * Once libraries in bin folder are loaded, we need to load the libraries inside lib folder
			 * Apply similar kind of logic as said above 
			 * 
			 * */
			for(File file : libFiles){			
				String fileName = file.getName();			
				String fileNameWithOutExt = fileName.replaceFirst("[.][^.]+$", "");
				allDlls.add(libPath + "gstreamer-1.0/" + fileNameWithOutExt);
			}	
				
			while(allDlls.size() > 0){
				ArrayList<String> loadedOnes = LoadAvailableDlls(allDlls);
				if(loadedOnes.size() > 0){				
					for(String obj: loadedOnes){
						allDlls.remove(obj);
					}
				}
				else if(loadedOnes.size() == 0){
					System.out.println("Following libraries failed to load. Possibility of error during streaming!!");
					for(String obj: allDlls){
						System.out.println(obj);
					}
					allDlls.clear();
					break;
				}
			}
		} catch (Exception e) {			
			System.out.println("Failed to load GStreamer libraries!");
		}
	}
}
