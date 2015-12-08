package javasample.Views;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javasample.JSituation;
import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import Utils.Constants;

import java.awt.SystemColor;

/**
 * The Class AddSituationDlg controls the Add Situation Dialog.
 */
@SuppressWarnings("serial")
public class AddSituationDlg extends JDialog {

	/**
	 * Create the dialog.
	 *
	 * @param system
	 *            the system
	 */
	public AddSituationDlg(JSystem system) {

		setTitle("Add Situation");
		setBounds(100, 100, 397, 377);
		JPanel contentPanel = new JPanel();
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);

		JLabel lblName = new JLabel("Name");
		lblName.setBounds(10, 11, 46, 14);
		contentPanel.add(lblName);

		JLabel lblSourceDeviceId = new JLabel("Source Device Id");
		lblSourceDeviceId.setBounds(10, 46, 98, 14);
		contentPanel.add(lblSourceDeviceId);

		JLabel lblType = new JLabel("Type");
		lblType.setBounds(10, 76, 46, 14);
		contentPanel.add(lblType);

		JTextField txtName = new JTextField();
		txtName.setBounds(119, 8, 97, 20);
		contentPanel.add(txtName);
		txtName.setColumns(10);

		JTextField txtDeviceId = new JTextField();
		txtDeviceId.setBounds(119, 43, 97, 20);
		contentPanel.add(txtDeviceId);
		txtDeviceId.setColumns(10);

		JTextField txtType = new JTextField();
		txtType.setBounds(119, 76, 97, 20);
		contentPanel.add(txtType);
		txtType.setColumns(10);

		JLabel lblAudibleLoopDelay = new JLabel("Audible Loop Delay");
		lblAudibleLoopDelay.setBounds(10, 121, 98, 14);
		contentPanel.add(lblAudibleLoopDelay);

		SpinnerModel loopDelayModel = new SpinnerNumberModel(0, 0, 100, 1);
		JSpinner loopDelaySpinner = new JSpinner(loopDelayModel);

		loopDelaySpinner.setBounds(119, 118, 64, 20);
		contentPanel.add(loopDelaySpinner);

		SpinnerModel playCountModel = new SpinnerNumberModel(0, 0, 100, 1);
		JSpinner playCountSpinner = new JSpinner(playCountModel);

		playCountSpinner.setBounds(118, 157, 64, 20);
		contentPanel.add(playCountSpinner);

		SpinnerModel acknowledgeModel = new SpinnerNumberModel(0, 0, 100, 1);
		JSpinner acknowledgeSpinner = new JSpinner(acknowledgeModel);

		acknowledgeSpinner.setBounds(119, 192, 64, 20);
		contentPanel.add(acknowledgeSpinner);

		SpinnerModel severityModel = new SpinnerNumberModel(1, 1, 10, 1);
		JSpinner severitySpinner = new JSpinner(severityModel);

		severitySpinner.setBounds(119, 223, 64, 20);
		contentPanel.add(severitySpinner);

		SpinnerModel interval_1Model = new SpinnerNumberModel(0, 0, 100, 1);
		JSpinner interval_1Spinner = new JSpinner(interval_1Model);

		interval_1Spinner.setBounds(119, 254, 64, 20);
		contentPanel.add(interval_1Spinner);

		SpinnerModel interval_2Model = new SpinnerNumberModel(0, 0, 100, 1);
		JSpinner interval_2Spinner = new JSpinner(interval_2Model);

		interval_2Spinner.setBounds(213, 254, 64, 20);
		contentPanel.add(interval_2Spinner);

		SpinnerModel interval_3Model = new SpinnerNumberModel(0, 0, 100, 1);
		JSpinner interval_3Spinner = new JSpinner(interval_3Model);

		interval_3Spinner.setBounds(302, 254, 64, 20);
		contentPanel.add(interval_3Spinner);

		JLabel lblAudiblePlayCount = new JLabel("Audible Play Count");
		lblAudiblePlayCount.setBounds(10, 160, 98, 14);
		contentPanel.add(lblAudiblePlayCount);

		JLabel lblAutoAcknowledge = new JLabel("Auto acknowledge");
		lblAutoAcknowledge.setBounds(10, 195, 98, 14);
		contentPanel.add(lblAutoAcknowledge);

		JLabel lblSeverity = new JLabel("Severity");
		lblSeverity.setBounds(10, 226, 46, 14);
		contentPanel.add(lblSeverity);

		JLabel lblSnoozeIntervals = new JLabel("Snooze Intervals");
		lblSnoozeIntervals.setBounds(10, 258, 98, 14);
		contentPanel.add(lblSnoozeIntervals);

		JCheckBox chckbxNotify = new JCheckBox("Notify");
		chckbxNotify.setBounds(269, 11, 97, 23);
		contentPanel.add(chckbxNotify);

		JCheckBox chckbxAckNeeded = new JCheckBox("Ack Needed");
		chckbxAckNeeded.setBounds(269, 42, 97, 23);
		contentPanel.add(chckbxAckNeeded);

		JCheckBox chckbxAudibleNotify = new JCheckBox("Audible Notify");
		chckbxAudibleNotify.setBounds(269, 72, 97, 23);
		contentPanel.add(chckbxAudibleNotify);

		JCheckBox chckbxExpandBanner = new JCheckBox("Expand Banner");
		chckbxExpandBanner.setBounds(269, 98, 128, 23);
		contentPanel.add(chckbxExpandBanner);

		JCheckBox chckbxLog = new JCheckBox("Log");
		chckbxLog.setBounds(269, 121, 97, 23);
		contentPanel.add(chckbxLog);
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setBorder(new LineBorder(SystemColor.controlShadow));
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						dispose();
					}
				});
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
				getRootPane().setDefaultButton(cancelButton);
			}
			{
				JButton addButton = new JButton("Add");
				addButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {

						JSituation situation = new JSituation();						
						situation.name = txtName.getText();
						situation.sourceDeviceId = txtDeviceId.getText();
						situation.situationType = txtType.getText();
						situation.audibleLoopDelay = (int) loopDelaySpinner.getValue();
						situation.audiblePlayCount = (int) playCountSpinner.getValue();
						situation.autoAcknowledge = (int) acknowledgeSpinner.getValue();
						situation.severity = (int) severitySpinner.getValue();
						situation.snoozeIntervals[0] = (int) interval_1Spinner.getValue();
						situation.snoozeIntervals[1] = (int) interval_2Spinner.getValue();
						situation.snoozeIntervals[2] = (int) interval_3Spinner.getValue();
						situation.notify = chckbxNotify.isSelected();
						situation.ackNeeded = chckbxAckNeeded.isSelected();
						situation.audibleNotify = chckbxAudibleNotify.isSelected();
						situation.expandBanner = chckbxExpandBanner.isSelected();
						situation.log = chckbxLog.isSelected();
						if(true == system.AddSituation(situation)){
							JOptionPane.showMessageDialog(null,Constants.SITUATION_ADDED_SUCCESS, "Info" ,JOptionPane.INFORMATION_MESSAGE, null);
						}
						else{
							JOptionPane.showMessageDialog(null,Constants.SITUATION_FAILED_TO_ADD, "Error" ,JOptionPane.ERROR_MESSAGE, null);
						}
						dispose();
					}
				});
				addButton.setActionCommand("Add");
				buttonPane.add(addButton);
			}
		}
	}
}
