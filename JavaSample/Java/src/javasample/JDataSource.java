package javasample;

/**
 * The Wrapper Class for DataSource interface of SDK.
 */
public class JDataSource {

	private long vxDataSource;
	public String id;
	public String name;
	public String ip;
	public int number;
	public boolean live;

	/**
	 * Checks if is ptz enabled.
	 *
	 * @return true, if successful
	 */
	public native boolean IsPTZEnabled();

	/**
	 * Gets the ptz controller.
	 *
	 * @return the JPTZ controller
	 */
	public native JPTZController GetPTZController();

	/**
	 * Gets the clips.
	 *
	 * @return the JClip[]
	 */
	public native JClip[] GetClips();

	/**
	 * Gets the data interfaces.
	 *
	 * @return the JDataInterface[]
	 */
	public native JDataInterface[] GetDataInterfaces();

	/**
	 * Gets the rtsp endpoint.
	 *
	 * @return the string
	 */
	public native String GetRTSPEndpoint();

	/**
	 * Creates the mjpeg session.
	 *
	 * @return the JDataSession
	 */
	public native JDataSession CreateMJPEGSession();
}
