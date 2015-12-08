package javasample;

/**
 * The Wrapper Class for Device interface of SDK.
 */
public class JDevice {
	
	private long vxDevice;
	public String deviceName;  
    public String deviceIP;
    public String deviceModel;
    public String deviceVersion;
    public String deviceID;
    public boolean deviceCommissioned;
    public boolean deviceLicenseRequired;
    public String devicePassword;
    public boolean devicePelcoHardware;
    public String deviceSerial;
    public String deviceUsername;  
    public String deviceVendor;
    public String deviceVirtualIp;
    public int deviceState;
    public int deviceType;
      
    /**
     * Gets the data sources.
     *
     * @return the j data source[]
     */
    public native JDataSource[] GetDataSources();
    
    /**
     * Gets the device handle.
     *
     * @return the device handle
     */
    public native long GetDeviceHandle();
    
    /* (non-Javadoc)
     * @see java.lang.Object#toString()
     */
    public String toString() {   
    	 return "[" + deviceName+ ","+ deviceIP + "," + deviceModel +"]";   
    }

}
