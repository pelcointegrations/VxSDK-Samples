package Utils;

import javax.swing.JTextArea;

/**
 * The Logs the event details in the text area.
 */
public class Logger {

	public static JTextArea _logArea = null;

	/**
	 * Sets the event text to update.
	 *
	 * @param txtArea
	 *            - the text area
	 */
	public static void SetLoggingArea(JTextArea txtArea) {
		_logArea = txtArea;
	}

	/**
	 * Update log.
	 *
	 * @param str
	 *            - the event data to update
	 */
	public static void UpdateLog(String str) {
		if(_logArea != null){
			if(!_logArea.getText().equals("")) //For first line, no need of newLine character
				_logArea.append("\n");
			_logArea.append(str);
		}
	}

}
