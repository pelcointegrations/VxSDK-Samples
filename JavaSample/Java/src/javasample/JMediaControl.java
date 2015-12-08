package javasample;

import javax.swing.JLabel;

/**
 * The Class JMediaControl.
 */
public class JMediaControl {

	
	/** The time stamp lbl. */
	private JLabel timeStampLbl = null;
    
    /** The current speed. */
    private int currentSpeed = 1;
    
	/** The media control handle. */
	private long mediaControlHandle;
	
	private long mediaControJniHandle;
	
	/**
	 * Invoke media controller.
	 *
	 * @param dataSource the data source
	 * @param streamProtocol the stream protocol
	 * @return true, if successful
	 */
	public native boolean InvokeMediaController(JDataSource dataSource, int streamProtocol);
	
	/**
	 * Sets the data source.
	 *
	 * @param ds the ds
	 * @param streamProtocol the stream protocol
	 * @return true, if successful
	 */
	public native boolean SetDataSource(JDataSource ds, int streamProtocol);
	
	/**
	 * Sets the video window.
	 *
	 * @param windowHandle the window handle
	 */
	public native void SetVideoWindow(long windowHandle);	
	
	/**
	 * Subscribe time stamp events.
	 */
	/*
	 * In JNI, "TimeStampCallback" method in JMediaControl class will be used for sending events
	 * */
	public native void SubscribeTimeStampEvents();
	
	/**
	 * Un subscribe time stamp events.
	 */
	public native void UnSubscribeTimeStampEvents();
	
	/**
	 * Play.
	 *
	 * @param speed the speed
	 */
	public native void Play(int speed);
	
	/**
	 * Pause.
	 */
	public native void Pause();
	
	/**
	 * Stop.
	 */
	public native void Stop();
	
	/**
	 * Goto live.
	 */
	public native void GotoLive();
	
	/**
	 * Seek.
	 *
	 * @param time the time
	 * @param speed the speed
	 */
	public native void Seek(int time, int speed);
	
	/**
	 * Delete.
	 */
	public native void Delete();
	
	/**
	 * Time stamp callback.
	 *
	 * @param timeStampData the time stamp data
	 */
	public void TimeStampCallback(String timeStampData){
		if(timeStampLbl != null){
			timeStampLbl.setText(timeStampData);
		}
	}

	/**
	 * Sets the time stamp label to update.
	 *
	 * @param lbl the lbl
	 */
	public void SetTimeStampLabelToUpdate(JLabel lbl){
		timeStampLbl = lbl;
	}
	
	/**
	 * Sets the speed.
	 *
	 * @param speed the speed
	 */
	public void SetSpeed(int speed){
		currentSpeed = speed;
	}
	
	/**
	 * Gets the speed.
	 *
	 * @return the int
	 */
	public int GetSpeed(){
		return currentSpeed;
	}
};
