package javasample.Views;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javasample.JSituation;
import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;
import javax.swing.border.TitledBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;

import Utils.Constants;

/**
 * The Class SituationManagerDlg controls the Situation manager functionalities.
 */
@SuppressWarnings("serial")
public class SituationManagerDlg extends JFrame {

	private JTable _situationTable;
	private DefaultTableModel _situationModel;
	private int _selectedSituation = -1;

	/**
	 * Create the dialog.
	 *
	 * @param system
	 *            - the system object
	 */
	public SituationManagerDlg(JSystem system) {

		JSituation[] situations = system.GetSituations();// Get all available situations from system															
		setTitle("Situation Manager");
		setBounds(100, 100, 721, 494);
		getContentPane().setLayout(null);

		JPanel panel = new JPanel();
		panel.setBorder(new TitledBorder(null, "", TitledBorder.LEADING,
				TitledBorder.TOP, null, null));
		panel.setBounds(563, 11, 128, 429);
		getContentPane().add(panel);
		panel.setLayout(null);

		JButton btnViewDetails = new JButton("View Details..");
		btnViewDetails.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnViewDetails.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				
				if(_selectedSituation == -1){
					JOptionPane.showMessageDialog(panel,
							"Please select a situation for viewing the details.", "Warning",
							JOptionPane.WARNING_MESSAGE, null);
				}
				else{
					SituationDetailsDlg dialog = new SituationDetailsDlg();
					dialog.UpdateSituationDetails(situations[_selectedSituation]);
					dialog.setModal(true);
					dialog.setVisible(true);
				}

			}
		});
		btnViewDetails.setBounds(10, 11, 106, 23);
		panel.add(btnViewDetails);

		JButton btnDelete = new JButton("Delete");
		btnDelete.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				
				if(_selectedSituation == -1){
					JOptionPane.showMessageDialog(panel,
							String.format(Constants.NO_ITEMS_TO_DELETE, "a situation"), "Warning",
							JOptionPane.WARNING_MESSAGE, null);
				}
				else{
					int choice = JOptionPane.showConfirmDialog(null,
							String.format(Constants.CONFIRM_DELETE, "situation"), "Confirm Delete", JOptionPane.YES_NO_OPTION);
		            if (choice == JOptionPane.YES_OPTION){
		            	boolean deletionStatus = system.DeleteSituation(situations[_selectedSituation]);
						if(deletionStatus){
							System.out.println(situations[_selectedSituation].situationType +  " deleted succesfully.");
							_situationModel.removeRow(_selectedSituation);
						}
						else{
							System.out.println("Failed to delete " + situations[_selectedSituation].name);
						}
		            }
				}
			}
		});
		btnDelete.setBounds(10, 45, 106, 23);
		panel.add(btnDelete);

		JButton btnAddNewSituation = new JButton("Add New..");
		btnAddNewSituation.setFont(new Font("Tahoma", Font.PLAIN, 11));
		btnAddNewSituation.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				AddSituationDlg dialog = new AddSituationDlg(system);
				dialog.setModal(true);
				dialog.setVisible(true);
			}
		});
		btnAddNewSituation.setBounds(10, 395, 106, 23);
		panel.add(btnAddNewSituation);

		_situationModel = new DefaultTableModel();
		_situationModel.addColumn("Type");
		_situationModel.addColumn("Severity");
		_situationModel.addColumn("Source Device ID");

		_situationTable = new JTable(_situationModel);
		_situationTable.setBorder(new TitledBorder(null, "",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		_situationTable.setPreferredScrollableViewportSize(new Dimension(300,
				120));
		_situationTable.setFillsViewportHeight(true);
		JScrollPane scrollPane = new JScrollPane(_situationTable);
		getContentPane().add(scrollPane);

		scrollPane.setBounds(22, 11, 531, 429);
		_situationTable.getSelectionModel().addListSelectionListener(
				new ListSelectionListener() {
					@Override
					public void valueChanged(ListSelectionEvent ev) {
						ListSelectionModel lsm = (ListSelectionModel) ev.getSource();
						if (lsm.getValueIsAdjusting()) {
							// nothing
						} else {
							int selectedRow = _situationTable.getSelectedRow();
							_selectedSituation = _situationTable.convertRowIndexToModel(selectedRow);

						}
					}
				});
		ShowSituationDetails(situations);
	}

	/**
	 * Show situation details.
	 *
	 * @param situations
	 *            - the available situations
	 */
	private void ShowSituationDetails(JSituation[] situations) {

		if (situations != null) {
			for (JSituation stn : situations) {
				_situationModel.addRow(new Object[] { stn.situationType,
						stn.severity, stn.sourceDeviceId });
			}
		}
	}


}
