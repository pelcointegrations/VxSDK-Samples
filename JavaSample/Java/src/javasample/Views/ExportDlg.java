package javasample.Views;

import java.awt.Dimension;
import java.awt.Font;

import javasample.JDevice;
import javasample.JExport;
import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.table.DefaultTableModel;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JTable;

import Enums.ExportStatusEnum;

import javax.swing.border.TitledBorder;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;

import Utils.Constants;

/**
 * The Class ExportDlg controls export Dialog functionalities.
 */
@SuppressWarnings("serial")
public class ExportDlg extends JFrame implements TableModelListener {

	private JTable _exportsTable;
	private DefaultTableModel _exportsTableModel;
	private JExport _exportsList[] = null;
	private JDevice _devicesList[] = null;
	private ArrayList<JExport> _selectedExports = new ArrayList<JExport>();

	/**
	 * Create the dialog.
	 *
	 * @param system
	 *            - the system object
	 */
	public ExportDlg(JSystem system) {

		setTitle("Export Manager");
		setBounds(100, 100, 721, 494);
		getContentPane().setLayout(null);

		JPanel panel = new JPanel();
		panel.setBorder(new TitledBorder(null, "", TitledBorder.LEADING,
				TitledBorder.TOP, null, null));
		panel.setBounds(563, 11, 128, 429);
		getContentPane().add(panel);
		panel.setLayout(null);

		JButton btnDownload = new JButton("Download...");
		btnDownload.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnDownload.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				if (_selectedExports.size() > 0) {
					DownloadForm downloadForm = new DownloadForm(
							_selectedExports);
					downloadForm.setModal(true);
					downloadForm.setVisible(true);
				} else {
					JOptionPane.showMessageDialog(panel,
							"No files selected for download.", "Error",
							JOptionPane.ERROR_MESSAGE, null);
				}
			}
		});
		btnDownload.setBounds(10, 11, 106, 23);
		panel.add(btnDownload);

		JButton btnDelete = new JButton("Delete");
		btnDelete.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {				
				boolean isExportDeleted;
				if(_selectedExports.size() > 0){
					int choice = JOptionPane.showConfirmDialog(null,
		                    "Are you sure you want to delete selected export(s)?", "Delete Export", JOptionPane.YES_NO_OPTION);
		            if (choice == JOptionPane.YES_OPTION){		            	
		            	for(JExport exp: _selectedExports){
							isExportDeleted = system.DeleteExport(exp);							
							if(isExportDeleted){
								System.out.println(exp.name +  " deleted succesfully.");															
							}
							else{
								System.out.println("Failed to delete " + exp.name);
							}
						}		            	
		            }				
				}
				else{
					JOptionPane.showMessageDialog(panel, String.format(Constants.NO_ITEMS_TO_DELETE, "an export"),"Warning" ,JOptionPane.WARNING_MESSAGE, null);   
				}
			}
		});
		btnDelete.setBounds(10, 45, 106, 23);
		panel.add(btnDelete);

		JButton btnNewExport = new JButton("New Export...");
		btnNewExport.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnNewExport.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				NewExportDlg exportframe = new NewExportDlg(_devicesList, system);
				exportframe.setModal(true);
				exportframe.setVisible(true);
			}
		});
		btnNewExport.setBounds(10, 395, 106, 23);
		panel.add(btnNewExport);

		_exportsTableModel = new DefaultTableModel();
		_exportsTableModel.addColumn("");
		_exportsTableModel.addColumn("Name");
		_exportsTableModel.addColumn("Created On");
		_exportsTableModel.addColumn("Created By");
		_exportsTableModel.addColumn("File size");
		_exportsTableModel.addColumn("Status");
		_exportsTable = new JTable(_exportsTableModel) {
			/*
			 * @Override public Class getColumnClass(int column) { return
			 * getValueAt(0, column).getClass(); }
			 */
			@SuppressWarnings("unchecked")
			@Override
			public Class getColumnClass(int column) {
				switch (column) {
				case 0:
					return Boolean.class;
				case 1:
					return String.class;
				case 2:
					return String.class;
				case 3:
					return String.class;
				case 4:
					return Integer.class;
				case 5:
					return String.class;
				default:
					return Boolean.class;
				}
			}
		};
		_exportsTable.setBorder(new TitledBorder(null, "", TitledBorder.LEADING,
				TitledBorder.TOP, null, null));
		_exportsTable.setPreferredScrollableViewportSize(new Dimension(300, 120));
		_exportsTable.setFillsViewportHeight(true);
		JScrollPane scrollPane = new JScrollPane(_exportsTable);
		getContentPane().add(scrollPane);

		scrollPane.setBounds(22, 11, 531, 429);
		_exportsTable.getModel().addTableModelListener(this);

	}

	/**
	 * Show export details.
	 *
	 * @param exports
	 *            - the exports list
	 * @param devices
	 *            - the devices list
	 */
	public void ShowExportDetails(JExport exports[], JDevice devices[]) {
		_exportsList = exports;
		_devicesList = devices;
		for (JExport exp : exports) {
			_exportsTableModel.addRow(new Object[] { false, exp.name,
					exp.initiated, exp.owner, exp.fileSizeKb,
					ExportStatusEnum.getStringValueFromInt(exp.status) });
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see javax.swing.event.TableModelListener#tableChanged(javax.swing.event.
	 * TableModelEvent)
	 */
	@Override
	public void tableChanged(TableModelEvent e) {

		_selectedExports.clear();

		DefaultTableModel m = (DefaultTableModel) _exportsTable.getModel();
		for (int i = 0; i < _exportsTable.getModel().getRowCount(); i++) {
			Boolean selected = (Boolean) m.getValueAt(i, 0);
			if (selected) {
				_selectedExports.add(_exportsList[i]);
			}
		}
	}
}
