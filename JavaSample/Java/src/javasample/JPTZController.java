package javasample;

/**
 * The Wrapper Class for PTZ Controller interface of SDK.
 */
public class JPTZController {

	private long vxPTZController;

	/**
	 * Continuous move.
	 *
	 * @param speedX
	 *            - the speed x
	 * @param speedY
	 *            - the speed y
	 * @param zoomDirection
	 *            - the zoom direction
	 * @return true, if successful
	 */
	public native boolean ContinuousMove(int speedX, int speedY,
			int zoomDirection);

	/**
	 * Trigger preset value.
	 *
	 * @param presetToTrigger
	 *            - the preset to trigger
	 * @return true, if successful
	 */
	public native boolean TriggerPreset(JPreset presetToTrigger);

	/**
	 * Trigger pattrn value.
	 *
	 * @param patternToTrigger
	 *            - the pattern to trigger
	 * @return true, if successful
	 */
	public native boolean TriggerPattrn(JPattern patternToTrigger);

	/**
	 * PTZ stop.
	 */
	public native void PTZStop();

	/**
	 * Continuous focus.
	 *
	 * @param focusDirection
	 *            - the focus direction
	 * @return true, if successful
	 */
	public native boolean ContinuousFocus(int focusDirection);

	/**
	 * Continuous iris.
	 *
	 * @param irisDirection
	 *            - the iris direction
	 * @return true, if successful
	 */
	public native boolean ContinuousIris(int irisDirection);

	/**
	 * Gets the presets.
	 *
	 * @return the JPreset[]
	 */
	public native JPreset[] GetPresets();

	/**
	 * Gets the patterns.
	 *
	 * @return the JPattern[]
	 */
	public native JPattern[] GetPatterns();

	/**
	 * Absolute pan.
	 *
	 * @param x
	 *            - the x value
	 * @return true, if successful
	 */
	public native boolean AbsolutePan(int x);

	/**
	 * Absolute tilt.
	 *
	 * @param y
	 *            - the y value
	 * @return true, if successful
	 */
	public native boolean AbsoluteTilt(int y);

	/**
	 * Absolute zoom.
	 *
	 * @param z
	 *            - the z value
	 * @return true, if successful
	 */
	public native boolean AbsoluteZoom(int z);

	/**
	 * Absolute move.
	 *
	 * @param x
	 *            - the x value
	 * @param y
	 *            - the y value
	 * @return true, if successful
	 */
	public native boolean AbsoluteMove(int x, int y);

	/**
	 * Absolute move.
	 *
	 * @param x
	 *            - the x value
	 * @param y
	 *            - the y value
	 * @param z
	 *            - the z value
	 * @return true, if successful
	 */
	public native boolean AbsoluteMove(int x, int y, int z);

	/**
	 * Gets the x.
	 *
	 * @return the x value
	 */
	public native int GetX();

	/**
	 * Gets the y.
	 *
	 * @return the y value
	 */
	public native int GetY();

	/**
	 * Gets the z.
	 *
	 * @return the z value
	 */
	public native int GetZ();

	/**
	 * Relative move.
	 *
	 * @param x
	 *            - the x value
	 * @param y
	 *            - the y value
	 * @param z
	 *            - the z value
	 * @return true, if successful
	 */
	public native boolean RelativeMove(int x, int y, int z);
}
