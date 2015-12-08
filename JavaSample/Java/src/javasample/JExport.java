package javasample;

/**
 * The Wrapper Class for Export interface of SDK.
 */
public class JExport {

	@SuppressWarnings("unused")
	private long vxExport;
	public String completed;
	public String id;
	public String initiated;
	public String name;
	public String owner;
	public String datauri;
	public float percentComplete;
	public boolean isProtected;
	public int exportClipSize;
	public int secondsRemaining;
	public int fileSizeKb;
	public int format;
	public int status;

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return "[" + name + "," + status + "]";
	}

}