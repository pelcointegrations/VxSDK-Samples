package javasample.Views.CustomControls;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;




// TODO: Auto-generated Javadoc
/**
 * The Class JFilePicker.
 */
@SuppressWarnings("serial")
public class JFilePicker extends JPanel {
	
	/** The text field label. */
	private String textFieldLabel;
    
    /** The button label. */
    private String buttonLabel;
     
    /** The label. */
    private JLabel label;
    
    /** The text field. */
    private JTextField textField;
    
    /** The button. */
    private JButton button;
     
    /** The file chooser. */
    private JFileChooser fileChooser;
     
    /** The mode. */
    private int mode;
    
    /** The Constant MODE_OPEN. */
    public static final int MODE_OPEN = 1;
    
    /** The Constant MODE_SAVE. */
    public static final int MODE_SAVE = 2;
     
    /**
     * Instantiates a new j file picker.
     *
     * @param textFieldLabel the text field label
     * @param buttonLabel the button label
     */
    public JFilePicker(String textFieldLabel, String buttonLabel) {
        this.textFieldLabel = textFieldLabel;
        this.buttonLabel = buttonLabel;
         
        fileChooser = new JFileChooser();
         
        setLayout(new FlowLayout(FlowLayout.CENTER, 5, 5));
 
        // creates the GUI
        label = new JLabel(textFieldLabel);
         
        textField = new JTextField(30);
        button = new JButton(buttonLabel);
         
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent evt) {
                buttonActionPerformed(evt);            
            }
        });
         
        add(label);
        add(textField);
        add(button);
         
    }
     
    /**
     * Button action performed.
     *
     * @param evt the evt
     */
    private void buttonActionPerformed(ActionEvent evt) {
        if (mode == MODE_OPEN) {
            if (fileChooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
                textField.setText(fileChooser.getSelectedFile().getAbsolutePath());
            }
        } else if (mode == MODE_SAVE) {
            if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
                textField.setText(fileChooser.getSelectedFile().getAbsolutePath());
            }
        }
    }
 
    /**
     * Adds the file type filter.
     *
     * @param extension the extension
     * @param description the description
     */
    public void addFileTypeFilter(String extension, String description) {
        FileTypeFilter filter = new FileTypeFilter(extension, description);
        fileChooser.addChoosableFileFilter(filter);
    }
     
    /**
     * Sets the mode.
     *
     * @param mode the new mode
     */
    public void setMode(int mode) {
        this.mode = mode;
    }
     
    /**
     * Gets the selected file path.
     *
     * @return the selected file path
     */
    public String getSelectedFilePath() {
        return textField.getText();
    }
     
    /**
     * Gets the file chooser.
     *
     * @return the file chooser
     */
    public JFileChooser getFileChooser() {
        return this.fileChooser;
    }

}
