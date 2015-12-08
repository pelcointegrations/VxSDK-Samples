package javasample;

import java.awt.Component;

/**
 * The Wrapper Class to communicate with Win32 native APIs.
 */
public class Win32 {

	/**
	 * Gets the window handle.
	 *
	 * @param c
	 *            - the component
	 * @return the window handle
	 */
	public static native int getWindowHandle(Component c);
}
