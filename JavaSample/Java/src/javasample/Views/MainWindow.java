package javasample.Views;

import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Enumeration;

import javasample.JDataInterface;
import javasample.JDataSource;
import javasample.JDevice;
import javasample.JExport;
import javasample.JPTZController;
import javasample.JSystem;
import javasample.Views.CustomControls.VideoControl;

import javax.swing.AbstractButton;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JComponent;
import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JSpinner;
import javax.swing.JSplitPane;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.ListSelectionModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.UIManager;
import javax.swing.border.BevelBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.text.DefaultFormatter;

import net.miginfocom.swing.MigLayout;
import Enums.DeviceStateEnum;
import Enums.DeviceTypeEnum;
import Enums.PanelLocationEnum;
import Enums.StreamProtocolEnum;
import Utils.Constants;
import Utils.Logger;

/**
 * The Class MainWindow controls the functionalities of Main window dialog.
 */
public class MainWindow {

	private JFrame frmJavaVxsdkSample;
	private JSystem _system;
	private JDevice[] _devices;
	private ArrayList<JComponent> _playerControls;
	private JMenu _exportsMenu;
	private JMenu _eventsMenu;
	private JMenu _situationsMenu;
	private JMenu _ptzMenu;
	private JMenu _protocolMenu;
	private ButtonGroup _streamprotocolsBtnGroup;
	private JTable _devicesTable;
	private int _selectedDevice = -1;
	private JPTZController _ptzController;
	private JScrollPane _statusPanel;
	private boolean isStatusDisplayed = false;// to check if the ststus panel is displayed
	private JTextArea _logTxtArea;	
	private PanelLocationEnum _selectedPanel = PanelLocationEnum.Left;
	private VideoControl _videoLeft;
	private VideoControl _videoRight;

	/**
	 * Launch the application.
	 *
	 * @param args
	 *            the arguments
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {

				try {
					// Change default Java UI look and feel to OS specific theme
					UIManager.setLookAndFeel(UIManager
							.getSystemLookAndFeelClassName());
				} catch (Exception ex) {
					ex.printStackTrace();
				}

				try {

					// Check whether 32bit or 64bit JVM
					String archModel = System
							.getProperty("sun.arch.data.model");
					boolean isDebug = java.lang.management.ManagementFactory
							.getRuntimeMXBean().getInputArguments().toString()
							.indexOf("jdwp") >= 0;
					String debugConst = "";

					String libPath = "libs/";
					if (archModel.equals("32")) {

						if (isDebug) {
							System.out.println("Runs in 32 bit, debug mode..");
							libPath = "libs/x86/Debug/";
							debugConst = "d";
						} else {
							System.out
									.println("Runs in 32 bit, release mode..");
							libPath = "libs/x86/Release/";
						}
					} else if (archModel.equals("64")) {
						if (isDebug) {
							System.out.println("Runs in 64 bit, debug mode..");
							libPath = "libs/x64/Debug/";
							debugConst = "d";
						} else {
							System.out
									.println("Runs in 64 bit, release mode..");
							libPath = "libs/x64/Release/";
						}
					}

					System.out.println("Loading GStreamer libraries..");
					Utils.Helper.loadGSTBinaries(libPath);

					System.out.println("Loading JNI and dependent libraries..");
					System.loadLibrary(libPath + "cpprest120" + debugConst + "_2_6");
					System.loadLibrary(libPath + "VxSdk" + debugConst);
					System.loadLibrary(libPath + "MediaController" + debugConst);
					System.loadLibrary(libPath + "CPPJni");

					System.out.println("Invoking MainWindow..");
					MainWindow window = new MainWindow();
					window.frmJavaVxsdkSample.setVisible(true);

				} catch (Exception e) {
					e.printStackTrace();
				}
				catch (UnsatisfiedLinkError error){
					JOptionPane.showMessageDialog(null,
							"Unable to load dependent libraries. "
							+ "\nJava sample depends on loading CPPJni.dll and its dependent libraries. "
							+ "\nPlease make sure those libraries are available inside 'libs' folder. "
							+ "\n\n Error Message: " + error.getMessage(), "Error",
							JOptionPane.ERROR_MESSAGE, null);
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainWindow() {
		_playerControls = new ArrayList<JComponent>();
		initialize();		
		EnableDisablePlayerButtons(false);
		EnableDisableMenuControls(false, _exportsMenu, _eventsMenu,
				_situationsMenu, _ptzMenu, _protocolMenu);
		_videoLeft.SelectPanel();
		_videoRight.DeselectPanel();

	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmJavaVxsdkSample = new JFrame();
		frmJavaVxsdkSample.setPreferredSize(new Dimension(1290, 460));
		frmJavaVxsdkSample.setMinimumSize(new Dimension(1250, 460));
		frmJavaVxsdkSample.getContentPane().setSize(new Dimension(1290, 460));
		frmJavaVxsdkSample.getContentPane().setPreferredSize(
				new Dimension(1290, 460));
		frmJavaVxsdkSample.setTitle("Java VxSDK Sample");
		frmJavaVxsdkSample.setBounds(100, 100, 1290, 460);
		frmJavaVxsdkSample.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JMenuBar menuBar = new JMenuBar();
		frmJavaVxsdkSample.setJMenuBar(menuBar);

		JMenu mnFile = new JMenu("File");
		menuBar.add(mnFile);
		JMenuItem mntmConnect = new JMenuItem("Connect");
		mntmConnect.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {

				_system = new JSystem();
				LoginDlg dialog = new LoginDlg(_system);
				dialog.setModal(true);
				dialog.setVisible(true);

				if (_system.isConnected == true) {					
					Logger.UpdateLog("Connected to: " + _system.ip);
					EnableDisableMenuControls(true, _exportsMenu, _eventsMenu,
							_situationsMenu, _protocolMenu);
					_devices = _system.GetDevices();

					if (_devices != null) {					   
						Logger.UpdateLog(String.format(Constants.DEVICES_COLLECTED, _devices.length));
						DefaultTableModel model = (DefaultTableModel) _devicesTable.getModel();
						for (JDevice dev : _devices) {
							_devicesTable.setVisible(true);
							model.addRow(new Object[] {
									dev.deviceName,
									dev.deviceIP,
									DeviceStateEnum.getStringValueFromInt(dev.deviceState),
									DeviceTypeEnum.getStringValueFromInt(dev.deviceType) });
						}
					}
					else{
						Logger.UpdateLog(String.format(Constants.DEVICES_COLLECTED, 0));
					}
				} else {
					Logger.UpdateLog("Connection failed: " + _system.ip);
				}
			}
		});
		mnFile.add(mntmConnect);

		JMenuItem mntmExit = new JMenuItem("Exit");
		mntmExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frmJavaVxsdkSample.dispose();
			}
		});
		
		JMenuItem mntmShowLog = new JMenuItem("Show Log");
		mntmShowLog.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				isStatusDisplayed = !isStatusDisplayed;
				DisplayStatusDetails();
				
				if(isStatusDisplayed) {
					mntmShowLog.setText("Hide Log");
				}
				else {
					mntmShowLog.setText("Show Log");				
				}
			}
		});
		mnFile.add(mntmShowLog);
		mnFile.add(mntmExit);

		JMenu mnExports = new JMenu("Exports");
		menuBar.add(mnExports);
		_exportsMenu = mnExports;

		JMenuItem mntmExportManager = new JMenuItem("Export Manager");
		mntmExportManager.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {

				JExport exports[] = _system.GetExports();
				if (exports != null) {					
					ExportDlg dialog = new ExportDlg(_system);
					dialog.ShowExportDetails(exports, _devices);
					dialog.setVisible(true);
				} else {
					Logger.UpdateLog(String.format(Constants.EXPORTS_COLLECTED, 0));
				}
			}
		});
		mnExports.add(mntmExportManager);

		JMenu mnEvents = new JMenu("Events");
		menuBar.add(mnEvents);
		_eventsMenu = mnEvents;

		JCheckBoxMenuItem chckbxmntmSubscribeToSystem = new JCheckBoxMenuItem("Subscribe to System Events");
		chckbxmntmSubscribeToSystem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				if (chckbxmntmSubscribeToSystem.isSelected()) {
					if(true == _system.SubscribeEvents()){
						Logger.UpdateLog(Constants.EVENT_SUBSCRIPTION_SUCCESS);
					}
					else{
						Logger.UpdateLog(Constants.EVENT_SUBSCRIPTION_FAILURE);
					}
				} else {
					if(true == _system.UnsubscribeEvents()){
						Logger.UpdateLog(Constants.EVENT_UNSUBSCRIPTION_SUCCESS);
					}
					else{
						Logger.UpdateLog(Constants.EVENT_UNSUBSCRIPTION_FAILURE);
					}
				}
			}
		});
		mnEvents.add(chckbxmntmSubscribeToSystem);

		JMenuItem mntmInsertEvent = new JMenuItem("Insert System Event");
		mntmInsertEvent.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				AddEventDlg dialog = new AddEventDlg(_system);
				dialog.setModal(true);
				dialog.setVisible(true);
			}
		});
		mnEvents.add(mntmInsertEvent);

		JMenu mnSituations = new JMenu("Situations");
		menuBar.add(mnSituations);
		_situationsMenu = mnSituations;

		JMenuItem mntmSituationMngr = new JMenuItem("Situation Manager");
		mntmSituationMngr.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SituationManagerDlg dialog = new SituationManagerDlg(_system);				
				dialog.setVisible(true);

			}
		});
		mnSituations.add(mntmSituationMngr);

		JMenu mnPtz = new JMenu("PTZ");
		menuBar.add(mnPtz);
		_ptzMenu = mnPtz;

		JMenuItem mntmShowPtzControls = new JMenuItem("Show PTZ Controls");
		mntmShowPtzControls.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				PTZControlDlg dialog = new PTZControlDlg(_ptzController);
				dialog.setModal(true);
				dialog.setVisible(true);
			}
		});
		mnPtz.add(mntmShowPtzControls);

		JMenu mnStreams = new JMenu("Streams");
		menuBar.add(mnStreams);
		_protocolMenu = mnStreams;

		JMenu mnStreamProtocol = new JMenu("Stream Protocol");
		mnStreams.add(mnStreamProtocol);

		JRadioButtonMenuItem rdbtnmntmRtsp = new JRadioButtonMenuItem("RTSP");
		rdbtnmntmRtsp.setSelected(true);
		mnStreamProtocol.add(rdbtnmntmRtsp);

		JRadioButtonMenuItem rdbtnmntmMjpeg = new JRadioButtonMenuItem("MJPEG");
		mnStreamProtocol.add(rdbtnmntmMjpeg);

		_streamprotocolsBtnGroup = new ButtonGroup();
		_streamprotocolsBtnGroup.add(rdbtnmntmRtsp);
		_streamprotocolsBtnGroup.add(rdbtnmntmMjpeg);

		DefaultTableModel model = new DefaultTableModel();
		model.addColumn("Name");
		model.addColumn("IP");
		model.addColumn("State");
		model.addColumn("Type");

		_devicesTable = new JTable(model);
		_devicesTable.setPreferredScrollableViewportSize(new Dimension(600, 120));
		_devicesTable.setFillsViewportHeight(true);
		JScrollPane scrollPane = new JScrollPane(_devicesTable);
		scrollPane.setBounds(0, 0, 763, 384);

		_devicesTable.getSelectionModel().addListSelectionListener(
				new ListSelectionListener() {

					@Override
					public void valueChanged(ListSelectionEvent ev) {
						ListSelectionModel lsm = (ListSelectionModel) ev
								.getSource();
						if (lsm.getValueIsAdjusting()) {
							// Do nothing
						} else {
							int selectedRow = _devicesTable.getSelectedRow();
							_selectedDevice = _devicesTable
									.convertRowIndexToModel(selectedRow);
							EnableDisablePlayerButtons(true);
						}

					}
				});

		_devicesTable.setVisible(false);

		_videoLeft = new VideoControl();
		_videoRight = new VideoControl();
		
		_videoLeft.SetLocation(PanelLocationEnum.Left);
		_videoLeft.GetVideoPanel().addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				_selectedPanel = PanelLocationEnum.Left;
				_videoLeft.SelectPanel();
				_videoRight.DeselectPanel();
			}
		});
		
		frmJavaVxsdkSample.getContentPane().setLayout(
				new MigLayout("", "[1290px,grow 10000]", "[470.00px,grow 10000,fill][10,bottom]"));
		
		
		_videoRight.SetLocation(PanelLocationEnum.Right);
		_videoRight.GetVideoPanel().addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				_selectedPanel = PanelLocationEnum.Right;
				_videoRight.SelectPanel();
				_videoLeft.DeselectPanel();
			}
		});
		
		JPanel videoControlPanel = new JPanel();
		videoControlPanel.setBorder(null);
		frmJavaVxsdkSample.getContentPane().add(videoControlPanel, "cell 0 0");
		videoControlPanel.setLayout(new MigLayout("", "[131.00px][695.00][108.00][380.00,grow][310.00][-39.00][][760.00,grow]", "[332px,grow 10000][13.00][]"));
		videoControlPanel.add(_videoLeft, "cell 0 0 8 1,grow");
		videoControlPanel.add(_videoRight, "cell 0 0 8 1,grow");

		JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
				scrollPane, videoControlPanel);
		splitPane.setResizeWeight(0.5);
		splitPane.setMinimumSize(new Dimension(200, 200));
		frmJavaVxsdkSample.getContentPane().add(splitPane, "cell 0 0,grow");

		JPanel buttonPanel = new JPanel();

		JButton btnJumpToLive = new JButton("Live");
		btnJumpToLive.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				VideoControl selectedControl = GetSelectedControl();
				if(false == selectedControl.IsMediaControlAvailable()){
					StartStream(null);
				}					
				selectedControl.JumpToLive();	
			}
		});
		
		buttonPanel.add(btnJumpToLive);
		videoControlPanel.add(buttonPanel, "cell 3 2 2 1,alignx center,aligny top");

		JButton btnSeek = new JButton("Seek");
		btnSeek.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Calendar cal = Calendar.getInstance();
				cal.add(Calendar.DATE, -1);				
				StartStream(cal.getTime());
			}
		});
		buttonPanel.add(btnSeek);

		JButton btnPause = new JButton("Pause");
		btnPause.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				VideoControl selectedControl = GetSelectedControl();
				if(selectedControl.IsMediaControlAvailable()){
					selectedControl.Pause();
				}
			}
		});
		btnPause.setBounds(916, 361, 71, 23);
		buttonPanel.add(btnPause);

		JButton btnPlay = new JButton("Play");
		btnPlay.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				StartStream(null);
			}
		});
		buttonPanel.add(btnPlay);

		JButton btnStop = new JButton("Stop");
		btnStop.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				VideoControl selectedControl = GetSelectedControl();
				if(selectedControl.IsMediaControlAvailable()){
					selectedControl.StopStream();
				}
			}
		});
		buttonPanel.add(btnStop);

		JLabel lblSpeed = new JLabel("Speed");
		lblSpeed.setBounds(1175, 364, 30, 14);
		buttonPanel.add(lblSpeed);

		JSpinner speedSelect = new JSpinner();
		speedSelect.setModel(new SpinnerNumberModel(new Integer(1), null, null,
				new Integer(1)));
		speedSelect.setBounds(1213, 364, 41, 20);

		JComponent comp = speedSelect.getEditor();
		speedSelect.addChangeListener(new ChangeListener() {
			@Override
			public void stateChanged(ChangeEvent e) {
				
				VideoControl selectedControl = GetSelectedControl();
				if(selectedControl.IsMediaControlAvailable()){
					selectedControl.SetSpeed((int) speedSelect.getValue());
				}
			}
		});

		buttonPanel.add(speedSelect);

		_playerControls.add(btnJumpToLive);
		_playerControls.add(btnSeek);
		_playerControls.add(btnPlay);
		_playerControls.add(btnPause);
		_playerControls.add(btnStop);
		_playerControls.add(speedSelect);
		
		JFormattedTextField field = (JFormattedTextField) comp.getComponent(0);
		DefaultFormatter formatter = (DefaultFormatter) field.getFormatter();
		formatter.setCommitsOnValidEdit(true);

		_logTxtArea = new JTextArea("");
		_logTxtArea.setEditable(false);
		
		_statusPanel = new JScrollPane(_logTxtArea);		
		_statusPanel.setMinimumSize(new Dimension(100, 100));
		_statusPanel.setBorder(new BevelBorder(BevelBorder.LOWERED));
		_statusPanel.setOpaque(true);
		
		Logger.SetLoggingArea(_logTxtArea); //Set the TextArea instance to Helper class
	}

	/**
	 * Get the selected video control.
	 */
	private VideoControl GetSelectedControl() {		
		if(_selectedPanel.getValue() == PanelLocationEnum.Left.getValue()){
			return _videoLeft;
		}
		return _videoRight;
	}
	
	/**
	 * Start streaming video.
	 *
	 * @param seekTime
	 *            - the seek time
	 */
	private void StartStream(Date seekTime) {

		if (_selectedDevice != -1) {
			JDevice devObj = _devices[_selectedDevice];
			if (devObj == null)
				return;

			JDataSource[] dataSources = devObj.GetDataSources();
			if (dataSources == null) {
				System.out.println("Datasources returned null for "+ devObj.deviceName);
				return;
			}
			
			if (dataSources.length == 0) {
				System.out.println("No datasources available for "+ devObj.deviceName);
				return;
			}
			
			JDataSource dsForStreaming = null;

			for (JDataSource ds : dataSources) {
				// Get the available datainterfaces for this datasource
				JDataInterface[] dataInterfaces = ds.GetDataInterfaces();

				if (dataInterfaces == null) {					
					continue;
				}
				// Iterate through datainterfaces and if it has RTSP or MJPEG
				// protocol, then this DS can be used for streaming
				int selectedProtocol = GetSelectedStreamProtocol(_streamprotocolsBtnGroup);
				
				for (JDataInterface di : dataInterfaces) {					
					if (di.streamProtocol == selectedProtocol) {
						dsForStreaming = ds;
						break;
					}
				}
			}
			if (dsForStreaming == null) {
				System.out.println("No datainterfaces available for selected protocol.");
				return;
			}
			if (dsForStreaming.IsPTZEnabled()) {
				_ptzController = dsForStreaming.GetPTZController();
				EnableDisableMenuControls(true, _ptzMenu);
			} else {
				EnableDisableMenuControls(false, _ptzMenu);
			}
			
			VideoControl selectedControl = GetSelectedControl();
			selectedControl.StartStream(devObj, dsForStreaming, GetSelectedStreamProtocol(_streamprotocolsBtnGroup), seekTime);
		}
	}	

	/**
	 * Enable / Disable player buttons.
	 *
	 * @param enable
	 *            - the enable/disable value
	 */
	private void EnableDisablePlayerButtons(boolean enable) {
		for (JComponent comp : _playerControls) {
			comp.setEnabled(enable);
		}
	}

	/**
	 * Enable /Disable menu controls.
	 *
	 * @param enable
	 *            - the enable/disable value
	 * @param menuControls
	 *            - the specified menu controls for enable/disable
	 */
	private void EnableDisableMenuControls(boolean enable,
			JMenu... menuControls) {
		for (JMenu menu : menuControls) {
			menu.setEnabled(enable);
		}
	}

	/**
	 * Gets the selected protocol for streaming.
	 *
	 * @param buttonGroup
	 *            - the button group for selection of streaming protocol
	 * @return int - the selected protocol
	 */
	private int GetSelectedStreamProtocol(ButtonGroup buttonGroup) {
		int selectedProtocol = StreamProtocolEnum.kStreamProtocolRtspRtp.getValue();
		for (Enumeration<AbstractButton> buttons = buttonGroup.getElements(); buttons
				.hasMoreElements();) {
			AbstractButton button = buttons.nextElement();

			if (button.isSelected()) {
				String btnText = button.getText();
				if (btnText.equals("MJPEG")) {
					selectedProtocol = StreamProtocolEnum.kStreamProtocolMjpegPull.getValue();
				}
			}
		}
		return selectedProtocol;
	}

	/**
	 * Display status details panel.
	 */
	private void DisplayStatusDetails() {
		if (isStatusDisplayed) {
			
			int height =frmJavaVxsdkSample.getHeight();
			frmJavaVxsdkSample.setBounds(100,100,1290, height+90);
			
			frmJavaVxsdkSample.getContentPane().add(_statusPanel,
					"cell 0 1,alignx left,growx");	
			
		} else {
			int height =frmJavaVxsdkSample.getHeight();
			frmJavaVxsdkSample.getContentPane().remove(_statusPanel);
			frmJavaVxsdkSample.setBounds(100,100,1290, height-90);
		}
	}

}
