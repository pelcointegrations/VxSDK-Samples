package javasample.Views;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javasample.JSituation;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;

/**
 * The Class SituationDetailsDlg controls the Situation Details Dialog
 */
@SuppressWarnings("serial")
public class SituationDetailsDlg extends JDialog {

	private JTable _situationDetailsTable;
	private DefaultTableModel _situationDetailsModel;

	/**
	 * Create the dialog.
	 */
	public SituationDetailsDlg() {

		setTitle("Situation Details");
		setBounds(100, 100, 520, 395);

		_situationDetailsModel = new DefaultTableModel();
		_situationDetailsModel.addColumn("Name");
		_situationDetailsModel.addColumn("Value");

		getContentPane().setLayout(null);

		_situationDetailsTable = new JTable(_situationDetailsModel);
		_situationDetailsTable.setBorder(new TitledBorder(null, "",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		_situationDetailsTable.setPreferredScrollableViewportSize(new Dimension(
				300, 120));
		_situationDetailsTable.setFillsViewportHeight(true);
		JScrollPane scrollPane = new JScrollPane(_situationDetailsTable);
		getContentPane().add(scrollPane);

		scrollPane.setBounds(10, 5, 484, 306);

		JButton btnClose = new JButton("Close");
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		btnClose.setBounds(403, 322, 91, 23);
		getContentPane().add(btnClose);

	}

	/**
	 * Update situation details.
	 *
	 * @param stn
	 *            - the selected situation
	 */
	public void UpdateSituationDetails(JSituation stn) {

		String snoozeIntervals = "";
		int snoozeIntervalSize = (stn.snoozeIntervals).length;
		String notificationIDs = "";
		int notificationIDsSize = (stn.notificationIds).length;
		
		
		
		if ((stn.notificationIds).length > 0) {
			for (int i = 0; i < notificationIDsSize-1; i++) {
				notificationIDs = notificationIDs + stn.notificationIds[i]+",";
			}
			notificationIDs = notificationIDs
					+ stn.notificationIds[notificationIDsSize-1];
			_situationDetailsModel.addRow(new Object[] { "Notification Ids",
					notificationIDs });
		} else {
			_situationDetailsModel
					.addRow(new Object[] { "Notification Ids", "" });
		}
		if ((stn.snoozeIntervals).length > 0) {
			for (int i = 0; i < snoozeIntervalSize-1; i++) {
				snoozeIntervals = snoozeIntervals
						+ String.valueOf(stn.snoozeIntervals[i]+",");
			}
			snoozeIntervals = snoozeIntervals
					+ String.valueOf(stn.snoozeIntervals[snoozeIntervalSize-1]);
			_situationDetailsModel.addRow(new Object[] { "Snooze Intervals",
					snoozeIntervals });
		} else {
			_situationDetailsModel
					.addRow(new Object[] { "Snooze Intervals", "" });
		}
		_situationDetailsModel
				.addRow(new Object[] { "Severity", stn.severity });
		_situationDetailsModel.addRow(new Object[] { "Audible play count",
				stn.audiblePlayCount });
		_situationDetailsModel.addRow(new Object[] { "Audible loop delay",
				stn.audibleLoopDelay });
		_situationDetailsModel.addRow(new Object[] { "Auto acknowledge",
				stn.autoAcknowledge });
		_situationDetailsModel.addRow(new Object[] {
				"Use audible notification", stn.audibleNotify });
		_situationDetailsModel.addRow(new Object[] { "Is ack needed",
				stn.ackNeeded });
		_situationDetailsModel.addRow(new Object[] { "Should expand banner",
				stn.expandBanner });
		_situationDetailsModel.addRow(new Object[] { "Should log", stn.log });
		_situationDetailsModel.addRow(new Object[] { "Should notify",
				stn.notify });
		_situationDetailsModel.addRow(new Object[] { "Name", stn.name });
		_situationDetailsModel.addRow(new Object[] { "Source Device Id",
				stn.sourceDeviceId });
		_situationDetailsModel
				.addRow(new Object[] { "Type", stn.situationType });
	}

}
