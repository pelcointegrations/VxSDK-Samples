package Utils;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
 


import javasample.Views.DownloadForm;

import javax.swing.SwingWorker;

/**
 * The Class DownloadTask.
 */
public class DownloadTask extends SwingWorker<Void, Void> {

	 /** The Constant BUFFER_SIZE. */
 	private static final int BUFFER_SIZE = 4096;   
	    
    	/** The download url. */
    	private String downloadURL;
	    
    	/** The file name. */
    	private String fileName;
	    
    	/** The file size. */
    	private int fileSize = 0;
	    
    	/** The save directory. */
    	private String saveDirectory;
	    
    	/** The gui. */
    	private DownloadForm gui;
	     
	    /**
    	 * Instantiates a new download task.
    	 *
    	 * @param gui the gui
    	 * @param downloadURL the download url
    	 * @param saveDirectory the save directory
    	 * @param fileName the file name
    	 * @param fileSize the file size
    	 */
    	public DownloadTask(DownloadForm gui, String downloadURL, String saveDirectory, String fileName,int fileSize) {
	        this.gui = gui;
	        this.downloadURL = downloadURL;
	        this.saveDirectory = saveDirectory;
	        this.fileName = fileName;
	        this.fileSize = fileSize;
	    }
	     
	    /**
    	 * Executed in background thread.
    	 *
    	 * @return the void
    	 * @throws Exception the exception
    	 */
	    @Override
	    protected Void doInBackground() throws Exception {
	        try {
	            HttpDownloadUtils util = new HttpDownloadUtils();
	            util.DownloadFile(downloadURL,fileName,fileSize);
	            
	             
	            // set file information on the GUI
	            gui.setFileInfo(util.getFileName(), util.getContentLength());
	             
	            String saveFilePath = saveDirectory + File.separator + util.getFileName() + ".zip";
	 
	            InputStream inputStream = util.getInputStream();
	            // opens an output stream to save into file
	            FileOutputStream outputStream = new FileOutputStream(saveFilePath);
	 
	            byte[] buffer = new byte[BUFFER_SIZE];
	            int bytesRead = -1;
	            long totalBytesRead = 0;
	            int percentCompleted = 0;
	            long fileSize = util.getContentLength() * 1000;
	 
	            while ((bytesRead = inputStream.read(buffer)) != -1) {            	
	            	outputStream.write(buffer, 0, bytesRead);
	                totalBytesRead += bytesRead;
	                percentCompleted = (int) (totalBytesRead * 100 / fileSize);
	                
	                //sometimes it goes above 100, so limit it to 100 to avoid crash
	                if(percentCompleted > 100) percentCompleted = 100;
	                setProgress(percentCompleted);         
	            }
	 
	            outputStream.close();
	 
	            util.disconnect();	            
	            firePropertyChange("status", "downloading", "completed");
	            
	        } catch (IOException ex) {	                    
	            ex.printStackTrace();
	            setProgress(0);
	            cancel(true);          
	        }
	        return null;
	    }
	 
	    /**
    	 * Executed in Swing's event dispatching thread.
    	 */
	    @Override
	    protected void done() {
	        if (!isCancelled()) {
	           
	        }
	    }  
}
