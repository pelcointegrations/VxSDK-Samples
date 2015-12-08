package javasample.Views;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.util.ArrayList;

import javasample.JExport;
import javasample.Views.CustomControls.JFilePicker;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JProgressBar;
import javax.swing.JTextField;

import Utils.DownloadTask;

/**
 * The Class DownloadForm controls the Download Export dialog.
 */
@SuppressWarnings("serial")
public class DownloadForm extends JDialog implements PropertyChangeListener {

	private JFilePicker filePicker = new JFilePicker("Save in directory: ",
			"Browse...");
	private JButton buttonDownload = new JButton("Start Download");
	private JLabel labelFileName = new JLabel("File name: ");
	private JTextField fieldFileName = new JTextField(20);
	private JLabel labelFileSize = new JLabel("File size (Kb): ");
	private JTextField fieldFileSize = new JTextField(20);
	private JLabel labelProgress = new JLabel("Progress:");
	private JProgressBar progressBar = new JProgressBar(0, 100);
	private ArrayList<JExport> exportsForDownload = null;
	private int currentDownloadIndex = -1;

	/**
	 * Create the frame.
	 *
	 * @param exportsToDowload
	 *            - the exports to dowload
	 */
	public DownloadForm(ArrayList<JExport> exportsToDowload) {

		exportsForDownload = exportsToDowload;
		// set up layout
		setLayout(new GridBagLayout());
		setTitle("Download Export(s)");
		GridBagConstraints constraints = new GridBagConstraints();
		constraints.anchor = GridBagConstraints.WEST;
		constraints.insets = new Insets(5, 5, 5, 5);

		// set up components
		filePicker.setMode(JFilePicker.MODE_SAVE);
		filePicker.getFileChooser().setFileSelectionMode(
				JFileChooser.DIRECTORIES_ONLY);

		buttonDownload.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent event) {
				buttonDownloadActionPerformed(event);
			}
		});

		fieldFileName.setEditable(false);
		fieldFileSize.setEditable(false);

		progressBar.setPreferredSize(new Dimension(200, 30));
		progressBar.setStringPainted(true);

		// add components to the frame
		constraints.gridx = 0;
		constraints.gridy = 0;
		// add(labelURL, constraints);

		constraints.gridx = 1;
		constraints.fill = GridBagConstraints.HORIZONTAL;
		constraints.weightx = 1.0;
		// add(fieldURL, constraints);

		constraints.gridx = 0;
		constraints.gridy = 1;
		constraints.weightx = 0.0;
		constraints.gridwidth = 2;
		constraints.fill = GridBagConstraints.NONE;
		add(filePicker, constraints);

		constraints.gridy = 2;
		constraints.anchor = GridBagConstraints.CENTER;
		add(buttonDownload, constraints);

		constraints.gridx = 0;
		constraints.gridy = 3;
		constraints.gridwidth = 1;
		constraints.anchor = GridBagConstraints.WEST;
		add(labelFileName, constraints);

		constraints.gridx = 1;
		add(fieldFileName, constraints);

		constraints.gridy = 4;
		constraints.gridx = 0;
		add(labelFileSize, constraints);

		constraints.gridx = 1;
		add(fieldFileSize, constraints);

		constraints.gridx = 0;
		constraints.gridy = 5;
		constraints.gridwidth = 1;
		constraints.anchor = GridBagConstraints.WEST;
		add(labelProgress, constraints);

		constraints.gridx = 1;
		constraints.weightx = 1.0;
		constraints.fill = GridBagConstraints.HORIZONTAL;
		add(progressBar, constraints);

		pack();
		setLocationRelativeTo(null); // center on screen

	}

	/**
	 * Button download action performed.
	 *
	 * @param event
	 *            the event
	 */
	private void buttonDownloadActionPerformed(ActionEvent event) {

		String saveDir = filePicker.getSelectedFilePath();

		if (saveDir.equals("")) {
			JOptionPane.showMessageDialog(this,
					"Please choose a directory save file!", "Error",
					JOptionPane.ERROR_MESSAGE);
			return;
		}

		currentDownloadIndex = 0;
		DownloadFile(currentDownloadIndex, exportsForDownload);
	}

	/**
	 * Download file.
	 *
	 * @param indexToDownload
	 *            - the index to download
	 * @param exportsArray
	 *            - the exports array
	 */
	private void DownloadFile(int indexToDownload,
			ArrayList<JExport> exportsArray) {

		String downloadURL = "";
		String fileName = "";
		int fileSize = 0;

		downloadURL = exportsArray.get(indexToDownload).datauri;
		fileName = exportsArray.get(indexToDownload).name;
		fileSize = exportsArray.get(indexToDownload).fileSizeKb;

		try {
			progressBar.setValue(0);

			DownloadTask task = new DownloadTask(this, downloadURL,
					filePicker.getSelectedFilePath(), fileName, fileSize);
			task.addPropertyChangeListener(this);
			task.execute();
		} catch (Exception ex) {
			JOptionPane.showMessageDialog(this, "Error executing upload task: "
					+ ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
		}

	}

	/**
	 * Sets the file info.
	 *
	 * @param name
	 *            - the file name
	 * @param size
	 *            - the file size
	 */
	public void setFileInfo(String name, int size) {
		fieldFileName.setText(name);
		fieldFileSize.setText(String.valueOf(size));
	}

	/**
	 * Update the progress bar's state whenever the progress of download
	 * changes.
	 *
	 * @param evt
	 *            - the property change event
	 */
	@Override
	public void propertyChange(PropertyChangeEvent evt) {
		if (evt.getPropertyName().equals("progress")) {
			int progress = (Integer) evt.getNewValue();
			progressBar.setValue(progress);
		} else if (evt.getPropertyName().equals("status")) {
			if (evt.getNewValue().equals("completed")) {
				currentDownloadIndex++;
				// Means more files available for download
				if (currentDownloadIndex > exportsForDownload.size()) {
					DownloadFile(currentDownloadIndex, exportsForDownload);
				}
				// Finished downloading selected exports
				else {
					System.out.println("No more exports to download..");
				}
			}
		}
	}

}
