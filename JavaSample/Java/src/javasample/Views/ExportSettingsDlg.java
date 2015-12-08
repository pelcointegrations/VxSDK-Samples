package javasample.Views;

import java.awt.BorderLayout;

import javasample.JClip;
import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.JComboBox;
import javax.swing.JTextField;

import Utils.Constants;
import Utils.Logger;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.ArrayList;

/**
 * The Class ExportSettingsDlg controls the Export Setting dialog.
 */
@SuppressWarnings("serial")
public class ExportSettingsDlg extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField txtName;
	private JTextField txtPassword;

	/**
	 * Create the dialog.
	 *
	 * @param _clipsToExport
	 *            - the clips selected to export
	 * @param system
	 *            - the system object
	 */
	public ExportSettingsDlg(ArrayList<JClip> _clipsToExport, JSystem system) {
		setTitle("Export Settings");
		setBounds(100, 100, 301, 290);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);

		JPanel formatPanel = new JPanel();
		formatPanel.setBorder(new TitledBorder(null, "Export Format",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		formatPanel.setBounds(20, 25, 250, 55);
		contentPanel.add(formatPanel);

		String[] exportFormats = { "MkvZip", "MP4" };
		formatPanel.setLayout(null);
		JComboBox comboBox = new JComboBox(exportFormats);
		comboBox.setBounds(25, 21, 198, 20);
		formatPanel.add(comboBox);

		JPanel namePanel = new JPanel();
		namePanel.setBorder(new TitledBorder(null, "Export Name",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		namePanel.setBounds(20, 85, 250, 55);
		contentPanel.add(namePanel);
		namePanel.setLayout(null);

		txtName = new JTextField();
		txtName.setBounds(27, 21, 200, 20);
		namePanel.add(txtName);
		txtName.setColumns(10);

		JPanel passwordPanel = new JPanel();
		passwordPanel.setBorder(new TitledBorder(null, "Export Password",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		passwordPanel.setBounds(20, 145, 250, 55);
		contentPanel.add(passwordPanel);
		passwordPanel.setLayout(null);

		txtPassword = new JTextField();
		txtPassword.setBounds(28, 21, 198, 20);
		passwordPanel.add(txtPassword);
		txtPassword.setColumns(10);
		
				JButton btnCancel = new JButton("Cancel");
				btnCancel.setBounds(205, 211, 65, 23);
				contentPanel.add(btnCancel);
				btnCancel.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent ev) {
						dispose();
					}
				});
		
				JButton btnAdd = new JButton("Create");
				btnAdd.setBounds(125, 211, 74, 23);
				contentPanel.add(btnAdd);
				btnAdd.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent ev) {
						String format = comboBox.getSelectedItem().toString();
						String name = txtName.getText();
						String password = txtPassword.getText();
						JClip[] clipsToExportArr = new JClip[_clipsToExport.size()];
						for(int i=0; i<_clipsToExport.size(); i++){
							clipsToExportArr[i] = _clipsToExport.get(i);
						}
						system.CreateExport(clipsToExportArr, format, name, password);// creates the new export
						JOptionPane.showMessageDialog(null, Constants.EXPORT_SUCCESS,"Info" ,JOptionPane.INFORMATION_MESSAGE, null);
						Logger.UpdateLog(Constants.EXPORT_SUCCESS);
						dispose();
					}
				});

	}
}
