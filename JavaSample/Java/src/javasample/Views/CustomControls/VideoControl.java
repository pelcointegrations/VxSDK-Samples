package javasample.Views.CustomControls;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Panel;

import javasample.JDataSource;
import javasample.JDevice;
import javasample.JMediaControl;
import javasample.Win32;

import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.LineBorder;

import Enums.PanelLocationEnum;
import Enums.StreamProtocolEnum;
import Utils.Logger;
import net.miginfocom.swing.MigLayout;

import java.awt.Component; //property change stuff
import java.util.Date;

/**
 * The Class VideoControl creates a new user control.
 */
@SuppressWarnings("serial")
public class VideoControl extends JPanel{
    
    private Panel _videoPanel;
    private JLabel _lblDevice;
    private JLabel _lblTimeStamp;
    JPanel _unitGroup;
    JPanel _videoStreamPanel;
    private JMediaControl _mediaControl;
    private JDevice _currentlyPlayingDevice;
    private JDataSource _dataSourceForStreaming;
    private int _streamProtocol;
    PanelLocationEnum _location = PanelLocationEnum.Left;
    
    /**
     * Instantiates a new video control.
     */
    public VideoControl() {
            setOpaque(true);
      
        _videoPanel = new Panel();
        _videoPanel.setBackground(Color.DARK_GRAY);

        //Add the label for device name
        _lblDevice = new JLabel("");
        _lblDevice.setAlignmentY(20.0f);
        _videoStreamPanel = new JPanel();
   
       _unitGroup = new JPanel(); //{
        _unitGroup.setOpaque(true);
        _unitGroup.setLayout(new MigLayout("", "[160px,fill][330.00px,grow,fill][150px,fill]", "[289px,grow,fill][]"));
        _videoStreamPanel.setLayout(new MigLayout("", "[376px,grow,fill]", "[245px,grow,fill]"));
        _videoStreamPanel.add(_videoPanel, "cell 0 0,grow");
        _videoPanel.setLayout(new MigLayout("", "[grow]", "[grow]"));
        _unitGroup.add(_videoStreamPanel, "cell 0 0 3 1,alignx left,aligny top");
        _unitGroup.add(_lblDevice, "cell 0 1 3 0,growx,aligny bottom");

        //Put everything together.
        setLayout(new BoxLayout(this, BoxLayout.LINE_AXIS));
        add(_unitGroup);
        _unitGroup.setAlignmentY(TOP_ALIGNMENT);
        
        //Add the label for time stamp
       _lblTimeStamp = new JLabel("");
       _lblTimeStamp.setAlignmentY(Component.BOTTOM_ALIGNMENT);
       _lblTimeStamp.setAlignmentX(Component.RIGHT_ALIGNMENT);
       _unitGroup.add(_lblTimeStamp, "cell 2 1,alignx center,aligny center");
       
       _mediaControl = null;
    }

   
    /* (non-Javadoc)
     * @see javax.swing.JComponent#getMaximumSize()
     */
    public Dimension getMaximumSize() {
        return new Dimension(Integer.MAX_VALUE,
                             getPreferredSize().height);
    }
    
    public boolean IsMediaControlAvailable(){
	    return (_mediaControl != null);
    }
    
    public Panel GetVideoPanel(){    	
    	return _videoPanel;
    }
    
    public void SetLocation(PanelLocationEnum locationVal){
    	_location = locationVal;
    }
    
    public PanelLocationEnum GetLocation(){
    	return _location ;
    }
    
    public void StartStream(JDevice selectedDevice, JDataSource dsForStreaming,int streamProtocol,Date seekTime){
    	
    	if (_mediaControl == null) {
    		_mediaControl = new JMediaControl();
    		_mediaControl.InvokeMediaController(dsForStreaming,streamProtocol);    				
    		System.out.println("Media controller loaded succesfully!!");
    		_mediaControl.SetTimeStampLabelToUpdate(_lblTimeStamp);
    		int windowHandle = Win32.getWindowHandle(_videoPanel);
    		_mediaControl.SetVideoWindow(windowHandle);
    		_mediaControl.SubscribeTimeStampEvents();
    	} else {
    		if (false == _currentlyPlayingDevice.deviceID.equals(selectedDevice.deviceID)) {
    			_mediaControl.Stop();
    			_mediaControl.SetDataSource(dsForStreaming,streamProtocol);
    		}
    	}
    	
    	if (_mediaControl == null) {
    		System.out.println("Error in StartStream: Media control is null.");
    		return;
    	}
    	
    	_dataSourceForStreaming = dsForStreaming;
    	_currentlyPlayingDevice = selectedDevice;
    	_streamProtocol = streamProtocol;
    	
    	String protocol =  StreamProtocolEnum.getStringValueFromInt(_streamProtocol);
    	if (seekTime == null) {
    		
    		Logger.UpdateLog("Live streaming started for " + _dataSourceForStreaming.name + "(Protocol: " + protocol + ")");
    		_mediaControl.Play(_mediaControl.GetSpeed());
    	} else {
    		// Divide by 1000 to exclude milliseconds. Otherwise there might
    		// be an issue casting to int
    		int epochTime = (int) (seekTime.getTime() / 1000);
    		Logger.UpdateLog("Playback streaming started for " + _dataSourceForStreaming.name + "(Protocol: " + protocol + ", Seektime: " + 
    						seekTime.toString() + ")");
    		_mediaControl.Seek(epochTime, _mediaControl.GetSpeed());
    	}
    	
    	
    	setDeviceText(_currentlyPlayingDevice.deviceName);
    }
    public void JumpToLive(){    	
		_mediaControl.GotoLive();
    }
    
    public void Pause(){
    	if (_mediaControl == null) {
			return;
		}
    	_mediaControl.Pause();
    }
    
    public void StopStream() {
		
		if (_mediaControl == null) {
			return;
		}

		// Cleanup mediaControl related things first		
		_mediaControl.Stop();
		_mediaControl.UnSubscribeTimeStampEvents();
		_mediaControl.Delete();
		_mediaControl = null;	
		
		_currentlyPlayingDevice = null;
		_dataSourceForStreaming = null;
		
		_lblTimeStamp.setText("");
		_lblDevice.setText("");
		
		_videoPanel.repaint();
		_videoPanel.revalidate();
	
	}
    
    public void SetSpeed(int speedVal){
    	if (_mediaControl != null) {
			_mediaControl.SetSpeed(speedVal);
		}
    }
    
  /**
   * Select videoStreamPanel.
   */
  public void SelectPanel(){
	  _videoStreamPanel.setBorder(new LineBorder(Color.GREEN, 3)); 
  }
  
  /**
   * Deselect videoStreamPanel.
   */
  public void DeselectPanel(){
	  _videoStreamPanel.setBorder(new LineBorder(Color.GRAY, 1)); 
  }
  
  /**
   * Sets the device text.
   *
   * @param devName - the device text
   */
  public void setDeviceText(String devName){
	  _lblDevice.setText(devName);
  }
  
 
}
