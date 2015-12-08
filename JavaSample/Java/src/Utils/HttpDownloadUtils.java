package Utils;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Base64;

import javax.net.ssl.HostnameVerifier;
import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLSession;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;

// TODO: Auto-generated Javadoc
/**
 * The Class HttpDownloadUtils.
 */
public class HttpDownloadUtils {

	/** The http conn. */
	private HttpsURLConnection httpConn;
	 
    /** hold input stream of HttpURLConnection. */
    private InputStream inputStream;
 
    /** The file name. */
    private String fileName;
    
    /** The content length. */
    private int contentLength;
    
    /**
     * Download file.
     *
     * @param fileURL the file url
     * @param fileName the file name
     * @param fileSize the file size
     * @throws IOException Signals that an I/O exception has occurred.
     */
    public void DownloadFile(String fileURL,String fileName, int fileSize) throws IOException {
    	
    	this.fileName = fileName;
    	this.contentLength = fileSize;
    	
    	// Create a new trust manager that trust all certificates
		TrustManager[] trustAllCerts = new TrustManager[]{
		    new X509TrustManager() {
		        public java.security.cert.X509Certificate[] getAcceptedIssuers() {
		            return null;
		        }
		        public void checkClientTrusted(
		            java.security.cert.X509Certificate[] certs, String authType) {
		        }
		        public void checkServerTrusted(
		            java.security.cert.X509Certificate[] certs, String authType) {
		        }
		    }
		};

		// Activate the new trust manager
		try {
		    SSLContext sc = SSLContext.getInstance("SSL");
		    sc.init(null, trustAllCerts, new java.security.SecureRandom());
		    HttpsURLConnection.setDefaultSSLSocketFactory(sc.getSocketFactory());
		} catch (Exception e) {
			
		}
    	
		
		
        URL url = new URL(fileURL);
        httpConn = (HttpsURLConnection) url.openConnection();
        
        httpConn.setHostnameVerifier(new HostnameVerifier()
        {
            public boolean verify(String hostname, SSLSession session)
            {	              
                return true;	               
            }
        });
        
        //TODO: Need to base64 encode
        String userName = "admin";
        String userNameEncoded = Base64.getEncoder().encodeToString(userName.getBytes());
        
        String password = "admin123";
        String passwordEncoded = Base64.getEncoder().encodeToString(password.getBytes());
        
        
        httpConn.setRequestProperty("X-Serenity-User",userNameEncoded);
        httpConn.setRequestProperty("X-Serenity-Password",passwordEncoded);
        
        int responseCode = httpConn.getResponseCode();
 
        // always check HTTP response code first
        if (responseCode == HttpURLConnection.HTTP_OK) {
            String disposition = httpConn.getHeaderField("Content-Disposition");
            String contentType = httpConn.getContentType();            
          
 
            // output for debugging purpose only
            System.out.println("Content-Type = " + contentType);
            System.out.println("Content-Disposition = " + disposition);
            System.out.println("Content-Length = " + contentLength);
            System.out.println("fileName = " + fileName);
 
            // opens input stream from the HTTP connection
            inputStream = httpConn.getInputStream();           
        } else {
            throw new IOException(
                    "No file to download. Server replied HTTP code: "
                            + responseCode);
        }
    }
 
    /**
     * Disconnect.
     *
     * @throws IOException Signals that an I/O exception has occurred.
     */
    public void disconnect() throws IOException {
        inputStream.close();
        httpConn.disconnect();
    }
	
    /**
     * Gets the file name.
     *
     * @return the file name
     */
    public String getFileName() {
        return this.fileName;
    }
 
    /**
     * Gets the content length.
     *
     * @return the content length
     */
    public int getContentLength() {
        return this.contentLength;
    }
 
    /**
     * Gets the input stream.
     *
     * @return the input stream
     */
    public InputStream getInputStream() {
        return this.inputStream;
    }
}
