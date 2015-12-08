
package javasample.Views;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javasample.JSystem;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.TitledBorder;

import Utils.Constants;
import Utils.Logger;

/**
 * The Class LoginDlg controls the Login Dialog.
 */
@SuppressWarnings("serial")
public class LoginDlg extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField txtIP;
	private JTextField txtPassword;
	private JTextField txtUserName;

	
	/**
	 * Create the dialog.
	 *
	 * @param sys - the system object
	 */
	public LoginDlg(JSystem system) {
		setTitle("Login");
		setBounds(100, 100, 286, 174);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new TitledBorder(null, "", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		JLabel lblUsername = new JLabel("Username:");
		lblUsername.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblUsername.setHorizontalAlignment(SwingConstants.RIGHT);
		lblUsername.setBounds(10, 49, 78, 14);
		contentPanel.add(lblUsername);
		
		
		JLabel lblPassword = new JLabel("Password:");
		lblPassword.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblPassword.setHorizontalAlignment(SwingConstants.RIGHT);
		lblPassword.setBounds(20, 74, 66, 14);
		contentPanel.add(lblPassword);
		
		JLabel lblIp = new JLabel("IP:");
		lblIp.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblIp.setHorizontalAlignment(SwingConstants.RIGHT);
		lblIp.setBounds(40, 23, 46, 14);
		contentPanel.add(lblIp);
		
		txtIP = new JTextField();
		txtIP.setText(Constants.DEFAULT_IP);
		txtIP.setBounds(119, 20, 127, 20);
		contentPanel.add(txtIP);
		txtIP.setColumns(10);
		
		txtPassword = new JTextField();
		txtPassword.setText(Constants.DEFAULT_PASSWORD);
		txtPassword.setColumns(10);
		txtPassword.setBounds(119, 71, 127, 20);
		contentPanel.add(txtPassword);
		
		txtUserName = new JTextField();
		txtUserName.setText(Constants.DEFAULT_USER);
		txtUserName.setColumns(10);
		txtUserName.setBounds(119, 46, 127, 20);
		contentPanel.add(txtUserName);
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("OK");
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {						
						boolean connected = false;
						
						if(!txtIP.getText().isEmpty() && 
						   !txtUserName.getText().isEmpty() && 
						   !txtPassword.getText().isEmpty() ){							
							
							system.username = txtUserName.getText();
							system.password = txtPassword.getText();
							system.ip = txtIP.getText();
							connected = system.Connect(txtUserName.getText(), txtPassword.getText(), txtIP.getText());							
							if(connected){
								system.isConnected = true;
								Logger.UpdateLog(Constants.LOGIN_SUCCESS);
								dispose();								
							}
							else{
								system.isConnected = false;
								Logger.UpdateLog(Constants.LOGIN_FAILURE);
								dispose();
							}
						}
						else{
							System.out.println("All fields are mandatory!!");
						}
					}
				});
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						 dispose();
					}
				});
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
			}
		}
	}
}
