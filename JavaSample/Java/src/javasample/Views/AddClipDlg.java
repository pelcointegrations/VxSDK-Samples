package javasample.Views;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import javasample.JClip;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerDateModel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;

/**
 * The Class AddClipDlg controls the Add clip dialog.
 */
@SuppressWarnings("serial")
public class AddClipDlg extends JDialog {

	private NewExportDlg _parent;

	/**
	 * Create the dialog.
	 *
	 * @param startTime
	 *            - the start time of selected clip.
	 * @param endTime
	 *            - the end time of selected clip.
	 * @param parent
	 *            - the parent
	 */
	public AddClipDlg(JClip clipToAdd, NewExportDlg parent) {
		setTitle("Add Clip");
		_parent = parent;
		setBounds(100, 100, 329, 204);
		JPanel contentPanel = new JPanel();
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);

		JSpinner startDateSpinner = new JSpinner(new SpinnerDateModel());
		startDateSpinner.setBounds(123, 25, 145, 20);
		JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(
				startDateSpinner, "yyyy-MM-dd HH:mm:ss");
		startDateSpinner.setEditor(dateEditor);
		SimpleDateFormat sdf = new SimpleDateFormat(
				"yyyy-MM-dd'T'HH:mm:ss.SSSZ");
		Date date = null;
		try {

			date = sdf.parse(clipToAdd.startTime.replaceAll("Z$", "+0000"));

		} catch (ParseException e1) {
			e1.printStackTrace();
		}
		contentPanel.setLayout(null);

		startDateSpinner.setValue(date);
		contentPanel.add(startDateSpinner);

		JSpinner endDateSpinner = new JSpinner(new SpinnerDateModel());
		endDateSpinner.setBounds(123, 68, 145, 20);
		JSpinner.DateEditor endDateEditor = new JSpinner.DateEditor(
				endDateSpinner, "yyyy-MM-dd HH:mm:ss");
		endDateSpinner.setEditor(endDateEditor);

		Date endDate = null;
		try {
			endDate = sdf.parse(clipToAdd.endTime.replaceAll("Z$", "+0000"));
		} catch (ParseException e1) {
			e1.printStackTrace();
		}
		contentPanel.setLayout(null);

		endDateSpinner.setValue(endDate);
		contentPanel.add(endDateSpinner);

		JLabel lblStartTime = new JLabel("Start Time");
		lblStartTime.setBounds(42, 25, 119, 20);
		contentPanel.add(lblStartTime);

		JLabel lblEndTime = new JLabel("End Time");
		lblEndTime.setBounds(42, 71, 46, 14);
		contentPanel.add(lblEndTime);

		JButton btnAdd = new JButton("Add");
		btnAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {

				DateFormat df = new SimpleDateFormat(
						"yyyy-MM-dd'T'HH:mm:ss.SSSZ");// sets time format
				df.setTimeZone(TimeZone.getTimeZone("UTC"));// sets time zone
				Date startDate = (Date) startDateSpinner.getValue();
				Date endDate = (Date) endDateSpinner.getValue();
				String startDateValue = df.format(startDate);
				String endDateValue = df.format(endDate);
				
				clipToAdd.startTime = startDateValue;
				clipToAdd.endTime = endDateValue;
				
				_parent.UpdateNewExportTable(clipToAdd);
				dispose();

			}
		});
		btnAdd.setBounds(100, 117, 79, 23);
		contentPanel.add(btnAdd);

		JButton btnCancel = new JButton("Cancel");
		btnCancel.setBounds(189, 117, 79, 23);
		contentPanel.add(btnCancel);

	}

}
