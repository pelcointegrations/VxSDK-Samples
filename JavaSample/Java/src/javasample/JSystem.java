package javasample;

import java.util.Hashtable;

import Utils.Logger;

/**
 * The Wrapper Class for System interface of SDK.
 */
public class JSystem {

	public String username;
	public String password;
	public String ip;
	public boolean isConnected;

	/**
	 * method to connect to the system.
	 *
	 * @param username
	 *            - the username
	 * @param password
	 *            - the password
	 * @param ip
	 *            - the ip
	 * @return true, if successful
	 */
	public native boolean Connect(String username, String password, String ip);

	/**
	 * Gets the devices.
	 *
	 * @return the JDevice[]
	 */
	public native JDevice[] GetDevices();

	/**
	 * Gets the exports.
	 *
	 * @return the JExport[]
	 */
	public native JExport[] GetExports();

	/**
	 * Creates the export.
	 *
	 * @param clp
	 *            - the clp for export
	 * @param format
	 *            - the export format
	 * @param name
	 *            - the export name
	 * @param password
	 *            - the exportpassword
	 */
	public native void CreateExport(JClip[] clp, String format, String name,
			String password);

	/**
	 * Delete export.
	 *
	 * @param export
	 *            - the export to delete
	 * @return true, if successful
	 */
	public native boolean DeleteExport(JExport export);

	/**
	 * Gets the situations.
	 *
	 * @return the JSituation[]
	 */
	public native JSituation[] GetSituations();

	/**
	 * Insert new event.
	 *
	 * @param newEvent
	 *            - the new event to insert
	 * @param prop
	 *            - the properties of event
	 * @return true, if successful
	 */
	public native boolean InsertNewEvent(JNewEvent newEvent, Hashtable prop);

	/**
	 * Subscribe events.
	 *
	 * @return true, if successful
	 */
	public native boolean SubscribeEvents();

	/**
	 * Unsubscribe events.
	 *
	 * @return true, if successful
	 */
	public native boolean UnsubscribeEvents();

	/**
	 * Delete situation.
	 *
	 * @param situation
	 *            - the situation to delete
	 * @return true, if successful
	 */
	public native boolean DeleteSituation(JSituation situation);

	/**
	 * Adds the situation.
	 *
	 * @param situation
	 *            - the situation to add
	 */
	public native boolean AddSituation(JSituation situation);

	/**
	 * Events callback.
	 *
	 * @param eventsData
	 *            - the events data
	 */
	public void EventsCallBack(JEvent eventDetails) {
		if(eventDetails != null){		
			String eventData= "Device ID:"+eventDetails.generatorDeviceId + 
					",Situation Type:"+ eventDetails.situationType +
					",Time:"+eventDetails.time+
					",Severity:"+eventDetails.severity;
			Logger.UpdateLog(eventData);
		}
	}
}
