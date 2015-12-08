package javasample.Views;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javasample.JClip;
import javasample.JDataInterface;
import javasample.JDataSource;
import javasample.JDevice;
import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.JTable;
import javax.swing.JScrollPane;

import Enums.ExportRecordTypeEnum;
import Enums.StreamProtocolEnum;

import javax.swing.border.TitledBorder;

import Utils.Constants;

/**
 * The Class NewExportDlg controls the New Export Dialog functionalities.
 */
@SuppressWarnings("serial")
public class NewExportDlg extends JDialog {

	private JTable _devicesTable;
	private JTable _clipsTable;
	private JTable _exportsTable;
	private DefaultTableModel _devicesModel;	
	private JDevice _devices[];
	private ArrayList<JClip> _clipsAdded;	
	private ArrayList<JClip> _clipsToExport;
	
	int _selectedClipIndex = -1;
	int _exportSelectedIndex = -1;

	/**
	 * Create the dialog.
	 *
	 * @param devicesList
	 *            the devices list
	 * @param system
	 *            the system details
	 */
	public NewExportDlg(JDevice devicesList[], JSystem system) {

		NewExportDlg dlg = this;
		setTitle("New Export");
		setBounds(100, 100, 1136, 498);
		getContentPane().setLayout(null);

		_devices = devicesList;
		_devicesModel = new DefaultTableModel();
		_devicesModel.addColumn("Name");
		
		_clipsToExport = new ArrayList<JClip>();
		_clipsAdded = new ArrayList<JClip>();

		JPanel devicesPanel = new JPanel();
		devicesPanel.setBorder(new TitledBorder(null, "Device List",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		devicesPanel.setBounds(25, 11, 307, 429);
		getContentPane().add(devicesPanel);
		devicesPanel.setLayout(null);
		_devicesTable = new JTable(_devicesModel);
		_devicesTable.setBorder(null);
		_devicesTable
				.setPreferredScrollableViewportSize(new Dimension(100, 120));
		_devicesTable.setFillsViewportHeight(true);
		JScrollPane devicesScrollPane = new JScrollPane(_devicesTable);
		devicesScrollPane.setBounds(24, 26, 262, 380);
		devicesPanel.add(devicesScrollPane);
		devicesScrollPane.setViewportBorder(null);
		_devicesTable.getSelectionModel().addListSelectionListener(
				new ListSelectionListener() {
					@Override
					public void valueChanged(ListSelectionEvent ev) {

						ListSelectionModel lsm = (ListSelectionModel) ev
								.getSource();

						if (lsm.getValueIsAdjusting()) {
							// nothing
						} else {
							//Get the clips available for the selected device and update the clips table
							int rowSelectedInDeviceTable = _devicesTable.getSelectedRow();
							int selectedDevice = _devicesTable.convertRowIndexToModel(rowSelectedInDeviceTable);						
							UpdateClipsTable(selectedDevice);
						}
					}
				});

		DefaultTableModel clipsModel = new DefaultTableModel();
		clipsModel.addColumn("Clip Id");
		clipsModel.addColumn("Type");
		clipsModel.addColumn("Start Time");
		clipsModel.addColumn("End Time");

		JPanel clipsPanel = new JPanel();
		clipsPanel.setBorder(new TitledBorder(null, "Available Clips",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		clipsPanel.setBounds(342, 11, 320, 429);
		getContentPane().add(clipsPanel);
		clipsPanel.setLayout(null);
		_clipsTable = new JTable(clipsModel);
		_clipsTable.setBorder(null);
		_clipsTable.setPreferredScrollableViewportSize(new Dimension(100, 120));
		_clipsTable.setFillsViewportHeight(true);
		
		_clipsTable.getColumn("Clip Id").setPreferredWidth(0);
		_clipsTable.getColumn("Clip Id").setMinWidth(0);
		_clipsTable.getColumn("Clip Id").setWidth(0);
		_clipsTable.getColumn("Clip Id").setMaxWidth(0);
		
		JScrollPane clipsScrollPane = new JScrollPane(_clipsTable);
		clipsScrollPane.setBounds(21, 21, 278, 384);
		clipsPanel.add(clipsScrollPane);
		_clipsTable.getSelectionModel().addListSelectionListener(
				new ListSelectionListener() {

					@Override
					public void valueChanged(ListSelectionEvent ev) {
						ListSelectionModel lsm = (ListSelectionModel) ev
								.getSource();
						if (lsm.getValueIsAdjusting()) {
							// nothing
						} else {
							int slectedClipIndex = _clipsTable.getSelectedRow();
							_selectedClipIndex = _clipsTable.convertRowIndexToModel(slectedClipIndex);
						}

					}
				});

		JButton btnAdd = new JButton("Add >>");
		btnAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(_selectedClipIndex != -1){
					Object clipId = _clipsTable.getModel().getValueAt(_selectedClipIndex, 0);										
					JClip clipToAdd = null;
					for(JClip clip: _clipsAdded){
						if( clip.dataSourceID.equals(clipId.toString())){
							clipToAdd = clip;
							break;
						}
					}
					if(clipToAdd != null){
						_clipsToExport.add(clipToAdd);
						AddClipDlg dialog = new AddClipDlg(clipToAdd, dlg);
						dialog.setModal(true);
						dialog.setVisible(true);
					}
				}				
			}
		});
		btnAdd.setBounds(672, 167, 117, 23);
		getContentPane().add(btnAdd);

		JButton btnRemove = new JButton("<< Remove");
		btnRemove.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				if(_exportSelectedIndex != -1){
					Object clipId = _exportsTable.getModel().getValueAt(_exportSelectedIndex, 0);					
					JClip clipToRemove = null;
					for(JClip clip: _clipsToExport){
						if( clip.dataSourceID.equals(clipId.toString())){
							clipToRemove = clip;
							break;
						}
					}
					if(clipToRemove != null){
						_clipsToExport.remove(clipToRemove);
						((DefaultTableModel)_exportsTable.getModel()).removeRow(_exportSelectedIndex);
					}
				}	
			}
		});
		btnRemove.setBounds(672, 201, 117, 23);
		getContentPane().add(btnRemove);

		DefaultTableModel exportsModel = new DefaultTableModel();
		exportsModel.addColumn("Clip Id");
		exportsModel.addColumn("Type");
		exportsModel.addColumn("Start Time");
		exportsModel.addColumn("End Time");

		JPanel exportsPanel = new JPanel();
		exportsPanel.setBorder(new TitledBorder(null, "Clips to Export",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		exportsPanel.setBounds(799, 11, 296, 394);
		getContentPane().add(exportsPanel);
		exportsPanel.setLayout(null);
		_exportsTable = new JTable(exportsModel);
		_exportsTable.setBorder(null);
		_exportsTable.setPreferredScrollableViewportSize(new Dimension(100, 120));
		_exportsTable.setFillsViewportHeight(true);
		
		_exportsTable.getColumn("Clip Id").setPreferredWidth(0);
		_exportsTable.getColumn("Clip Id").setMinWidth(0);
		_exportsTable.getColumn("Clip Id").setWidth(0);
		_exportsTable.getColumn("Clip Id").setMaxWidth(0);
		
		JScrollPane exportsScrollPane = new JScrollPane(_exportsTable);
		exportsScrollPane.setBounds(22, 23, 252, 349);
		exportsPanel.add(exportsScrollPane);

		_exportsTable.getSelectionModel().addListSelectionListener(
				new ListSelectionListener() {
					@Override
					public void valueChanged(ListSelectionEvent ev) {
						ListSelectionModel lsm = (ListSelectionModel) ev
								.getSource();
						if (lsm.getValueIsAdjusting()) {
							// nothing
						} else {
							int slectedExportIndex = _exportsTable.getSelectedRow();
							_exportSelectedIndex = _exportsTable.convertRowIndexToModel(slectedExportIndex);							
						}

					}
				});
		
		JButton btnExport = new JButton("Export");
		btnExport.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {

				if(_clipsToExport.size() > 0){
					ExportSettingsDlg dialog = new ExportSettingsDlg(_clipsToExport,system);
					dialog.setModal(true);
					dialog.setVisible(true);
				}
				else{
					JOptionPane.showMessageDialog(null,Constants.NO_ITEMS_TO_EXPORT, "Warning" ,JOptionPane.WARNING_MESSAGE, null);
				}
			}
		});
		btnExport.setBounds(863, 417, 89, 23);
		getContentPane().add(btnExport);

		JButton btnCancel = new JButton("Cancel");
		btnCancel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		btnCancel.setBounds(962, 417, 89, 23);
		getContentPane().add(btnCancel);

		UpdateDeviceTable();

	}

	/**
	 * Update device table.
	 */
	private void UpdateDeviceTable() {
		for (JDevice dev : _devices) {
			_devicesModel.addRow(new Object[] { dev.deviceName });
		}
	}

	/**
	 * Update exports table.
	 *
	 * @param selectedDevice
	 *            -the selected device
	 */
	private void UpdateClipsTable(int selectedDevice) {

		JDevice devObj = _devices[selectedDevice];
		JDataSource[] dataSources = devObj.GetDataSources();
		if (dataSources == null) {
			System.out.println("No datasources for the selected device: " + devObj.deviceName);
			return;
		}
		for (JDataSource ds : dataSources) {
			JDataInterface[] dataInterfaces = ds.GetDataInterfaces();

			if (dataInterfaces == null) {
				System.out.println("No datainterfaces available with datasource: "+ ds.name + " for device: " + devObj.deviceName);
				continue;
			}
			JDataSource dsForStreaming = null;
			for (JDataInterface di : dataInterfaces) {				
				if (di.streamProtocol == StreamProtocolEnum.kStreamProtocolRtspRtp.getValue()) {
					dsForStreaming = ds;
					
					JClip[] clips = dsForStreaming.GetClips();
					
					if (clips == null) 
						 continue;
						
					DefaultTableModel model = (DefaultTableModel) _clipsTable.getModel();
					for (JClip clp : clips) {							
						
						boolean alreadyAdded = false;
						for(JClip clipAdded: _clipsAdded){
							if(clipAdded.dataSourceID.equals(clp.dataSourceID)){
								alreadyAdded = true;
								break;
							}
						}
						if(!alreadyAdded){
							_clipsAdded.add(clp);
							model.addRow(new Object[] {		
									clp.dataSourceID,
									ExportRecordTypeEnum.getStringValueFromInt(clp.recordType),
									clp.startTime, 
									clp.endTime 
									});
						}
					}
					
				}
			}

		}

	}

	/**
	 * Update new export table.
	 *
	 * @param startTime
	 *            - the start time
	 * @param endTime
	 *            - the end time
	 */
	public void UpdateNewExportTable(JClip clipToUpdate) {
		DefaultTableModel exportModel = (DefaultTableModel)_exportsTable.getModel();
		exportModel.addRow(new Object[] { clipToUpdate.dataSourceID, ExportRecordTypeEnum.getStringValueFromInt(clipToUpdate.recordType), clipToUpdate.startTime, clipToUpdate.endTime });
	}
}
