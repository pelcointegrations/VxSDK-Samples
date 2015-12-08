package javasample;

/**
 * The Wrapper Class for Situation interface of SDK.
 */
public class JSituation {

	@SuppressWarnings("unused")
	private long vxSituation;
	public String situationType;
	public String sourceDeviceId;
	public int severity;
	public String[] notificationIds;
	public int[] snoozeIntervals = new int[3];
	public int audiblePlayCount;
	public int audibleLoopDelay;
	public int autoAcknowledge;
	public boolean audibleNotify;
	public boolean ackNeeded;
	public boolean expandBanner;
	public boolean log;
	public boolean notify;
	public String name;

}
