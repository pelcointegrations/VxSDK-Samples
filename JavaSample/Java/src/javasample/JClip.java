package javasample;

/**
 * The Wrapper Class for clip interface of SDK.
 */
public class JClip {

	@SuppressWarnings("unused")
	private long vxClip;
	public int recordType;
	public String startTime;
	public String endTime;
	public String dataSourceID;

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	public String toString() {
		return "[" + recordType + "," + startTime + "," + endTime + "]";
	}

}
