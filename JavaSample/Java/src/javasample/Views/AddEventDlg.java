package javasample.Views;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Hashtable;
import java.util.TimeZone;

import javasample.JNewEvent;
import javasample.JSituation;
import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerDateModel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;

/**
 * The Class AddEventDlg controls the Add New Event Dialog.
 */
@SuppressWarnings("serial")
public class AddEventDlg extends JDialog {


	private String[] _situationTypes;
	private String[] _srcDeviceId;

	/**
	 * Create the dialog.
	 *
	 * @param system
	 *            the system
	 */
	public AddEventDlg(JSystem system) {

		setTitle("Add New Event");
		setBounds(100, 100, 410, 381);
		getContentPane().setLayout(new BorderLayout());
		JPanel contentPanel = new JPanel();
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);

		JLabel lblGeneratorDeviceId = new JLabel("Generator Device Id");
		lblGeneratorDeviceId.setBounds(10, 25, 108, 23);
		contentPanel.add(lblGeneratorDeviceId);

		JTextField txtDeviceId = new JTextField();
		txtDeviceId.setBounds(154, 26, 228, 20);
		contentPanel.add(txtDeviceId);
		txtDeviceId.setColumns(10);

		JLabel lblSituationType = new JLabel("Situation Type");
		lblSituationType.setBounds(10, 56, 108, 23);
		contentPanel.add(lblSituationType);

		JSituation[] situations = system.GetSituations();
		if (situations != null) {
			_situationTypes = new String[situations.length];
			_srcDeviceId = new String[situations.length];
			for (int i = 0; i < situations.length; i++) {
				_situationTypes[i] = situations[i].situationType;
				_srcDeviceId[i] = situations[i].sourceDeviceId;
			}
		}
		JComboBox<String> cmbSituationType = new JComboBox<String>(_situationTypes);
		cmbSituationType.setBounds(154, 57, 228, 20);
		contentPanel.add(cmbSituationType);

		JLabel lblSourceDeviceId = new JLabel("Source Device Id");
		lblSourceDeviceId.setBounds(10, 88, 108, 23);
		contentPanel.add(lblSourceDeviceId);

		JComboBox<String> cmbSrcDevId = new JComboBox<String>(_srcDeviceId);
		cmbSrcDevId.setBounds(154, 89, 228, 20);
		contentPanel.add(cmbSrcDevId);

		JLabel lblEventTime = new JLabel("Event Time");
		lblEventTime.setBounds(10, 122, 108, 23);
		contentPanel.add(lblEventTime);

		JSpinner eventTimeSpinner = new JSpinner(new SpinnerDateModel());
		eventTimeSpinner.setBounds(154, 123, 228, 20);
		JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(
				eventTimeSpinner, "yyyy-MM-dd HH:mm:ss");
		eventTimeSpinner.setEditor(dateEditor);
		Date date = new Date();
		eventTimeSpinner.setValue(date);
		contentPanel.add(eventTimeSpinner);

		JLabel lblName = new JLabel("Name");
		lblName.setHorizontalAlignment(SwingConstants.CENTER);
		lblName.setBounds(154, 164, 86, 23);
		contentPanel.add(lblName);

		JLabel lblValue = new JLabel("Value");
		lblValue.setHorizontalAlignment(SwingConstants.CENTER);
		lblValue.setBounds(262, 164, 86, 23);
		contentPanel.add(lblValue);

		JLabel lblCustomProperties = new JLabel("Custom Properties");
		lblCustomProperties.setBounds(10, 159, 108, 32);
		contentPanel.add(lblCustomProperties);

		JTextField txtPropertyName_1 = new JTextField();
		txtPropertyName_1.setBounds(154, 188, 86, 20);
		contentPanel.add(txtPropertyName_1);
		txtPropertyName_1.setColumns(10);

		JTextField txtPropertyName_2 = new JTextField();
		txtPropertyName_2.setBounds(154, 219, 86, 20);
		contentPanel.add(txtPropertyName_2);
		txtPropertyName_2.setColumns(10);

		JTextField txtPropertyName_3 = new JTextField();
		txtPropertyName_3.setBounds(154, 250, 86, 20);
		contentPanel.add(txtPropertyName_3);
		txtPropertyName_3.setColumns(10);

		JTextField txtPropertyValue_1 = new JTextField();
		txtPropertyValue_1.setBounds(262, 188, 86, 20);
		contentPanel.add(txtPropertyValue_1);
		txtPropertyValue_1.setColumns(10);

		JTextField txtPropertyValue_2 = new JTextField();
		txtPropertyValue_2.setBounds(262, 219, 86, 20);
		contentPanel.add(txtPropertyValue_2);
		txtPropertyValue_2.setColumns(10);

		JTextField txtPropertyValue_3 = new JTextField();
		txtPropertyValue_3.setBounds(262, 250, 86, 20);
		contentPanel.add(txtPropertyValue_3);
		txtPropertyValue_3.setColumns(10);

		JButton btnAdd = new JButton("Add");
		btnAdd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				boolean insertStatus;
				JNewEvent newEvent = new JNewEvent();
				newEvent.generatorDeviceId = txtDeviceId.getText();
				newEvent.situationType = cmbSituationType.getSelectedItem()
						.toString();
				newEvent.sourceDeviceId = cmbSrcDevId.getSelectedItem()
						.toString();

				DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss");
				df.setTimeZone(TimeZone.getTimeZone("UTC"));
				Date evTime = (Date) eventTimeSpinner.getValue();
				String eventTime = df.format(evTime);
				newEvent.eventTime = eventTime;

				Hashtable<String, String> properties = new Hashtable<String, String>();
				properties.put(txtPropertyName_1.getText(),
						txtPropertyValue_1.getText());
				properties.put(txtPropertyName_2.getText(),
						txtPropertyValue_2.getText());
				properties.put(txtPropertyName_3.getText(),
						txtPropertyValue_3.getText());
				insertStatus = system.InsertNewEvent(newEvent, properties);// Inserts
																			// the
																			// new
																			// event
				if (insertStatus) {
					System.out.println("New Event Inserted");
				} else {
					System.out.println("New Event not Inserted");
				}
			}
		});
		btnAdd.setBounds(286, 308, 89, 23);
		contentPanel.add(btnAdd);

		JButton btnCancel = new JButton("Cancel");
		btnCancel.setBounds(186, 308, 89, 23);
		contentPanel.add(btnCancel);
	}
}
