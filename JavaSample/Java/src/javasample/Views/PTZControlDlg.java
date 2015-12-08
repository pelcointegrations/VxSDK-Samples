package javasample.Views;

import java.awt.BorderLayout;

import javasample.JPTZController;
import javasample.JPattern;
import javasample.JPreset;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.JComboBox;

import Enums.FocusDirection;
import Enums.IrisDirection;
import Enums.ZoomDirection;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 * The Class PTZControlDlg controls the PTZ control dialog functionalities.
 */
@SuppressWarnings("serial")
public class PTZControlDlg extends JDialog {
	
	private boolean _ptzStatus = false;
	private String[] _presetValues = null;
	private String[] _patternValues = null;

	/**
	 * Create the dialog.
	 *
	 * @param ptzController
	 *            the ptz controller object
	 */
	public PTZControlDlg(JPTZController ptzController) {

		setTitle("PTZ Window");
		setBounds(100, 100, 333, 522);
		getContentPane().setLayout(new BorderLayout());
		JPanel contentPanel = new JPanel();
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);

		if (ptzController == null) {
			System.out.println("ptzController NULL");
		}
		JPreset[] presets = ptzController.GetPresets();
		JPattern[] patterns = ptzController.GetPatterns();

		int i = 0;
		if (presets != null) {
			_presetValues = new String[presets.length];			
			for (JPreset preset : presets) {
				_presetValues[i] = preset.name;
				i++;
			}
		} else {
			_presetValues = new String[1];
			_presetValues[0] = "";
		}
		if (patterns != null) {
			_patternValues = new String[patterns.length];
			i = 0;
			for (JPattern pattern : patterns) {
				_patternValues[i] = pattern.name;
				i++;
			}
		} else {
			_patternValues = new String[1];
			_patternValues[0] = "";
		}

		JButton btnUl = new JButton("UL");
		btnUl.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(-100, 100,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnUl.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnUl.setBounds(10, 11, 47, 25);
		contentPanel.add(btnUl);

		JButton btnU = new JButton("U");
		btnU.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent ev) {
				_ptzStatus = ptzController.ContinuousMove(0, 100,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnU.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnU.setBounds(60, 11, 47, 25);
		contentPanel.add(btnU);

		JButton btnUr = new JButton("UR");
		btnUr.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(100, 100,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnUr.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnUr.setBounds(110, 11, 47, 25);
		contentPanel.add(btnUr);

		JButton btnL = new JButton("L");
		btnL.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(-100, 0,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnL.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnL.setBounds(10, 40, 47, 25);
		contentPanel.add(btnL);

		JButton btnR = new JButton("R");
		btnR.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(100, 0,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnR.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnR.setBounds(110, 40, 47, 25);
		contentPanel.add(btnR);

		JButton btnDl = new JButton("DL");
		btnDl.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(-100, -100,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnDl.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnDl.setBounds(10, 70, 47, 25);
		contentPanel.add(btnDl);

		JButton btnD = new JButton("D");
		btnD.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(0, -100,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnD.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnD.setBounds(60, 70, 47, 25);
		contentPanel.add(btnD);

		JButton btnDr = new JButton("DR");
		btnDr.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(100, -100,
						ZoomDirection.kNone.getValue());
				ShowPTZStatus(_ptzStatus, btnDr.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btnDr.setBounds(110, 70, 47, 25);
		contentPanel.add(btnDr);

		JPanel presetsPanel = new JPanel();
		presetsPanel.setBorder(new TitledBorder(null, "Presets",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		presetsPanel.setBounds(10, 106, 296, 82);
		contentPanel.add(presetsPanel);
		presetsPanel.setLayout(null);


		JComboBox<String> cmbPresets = new JComboBox<String>(_presetValues);

		cmbPresets.setBounds(29, 21, 257, 20);
		presetsPanel.add(cmbPresets);

		JButton btnTrigger_Preset = new JButton("Trigger");
		btnTrigger_Preset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ev) {
				int selectedPreset = cmbPresets.getSelectedIndex();
				boolean persetStatus = ptzController.TriggerPreset(presets[selectedPreset]);
				if (persetStatus) {
					System.out.println("Preset triggered successfully.");
				}
			}
		});
		btnTrigger_Preset.setBounds(198, 52, 88, 23);
		presetsPanel.add(btnTrigger_Preset);

		JPanel patternsPanel = new JPanel();
		patternsPanel.setBorder(new TitledBorder(null, "Patterns",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		patternsPanel.setBounds(10, 189, 296, 90);
		contentPanel.add(patternsPanel);
		patternsPanel.setLayout(null);

		JComboBox<String> cmbPatterns = new JComboBox<String>(_patternValues);
		cmbPatterns.setBounds(31, 29, 255, 20);
		patternsPanel.add(cmbPatterns);

		JButton btnTrigger_Pattern = new JButton("Trigger");
		btnTrigger_Pattern.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int selectedPreset = cmbPatterns.getSelectedIndex();
				boolean patternStatus = ptzController.TriggerPattrn(patterns[selectedPreset]);
				if (patternStatus) {
					System.out.println("Pattern triggered successfully.");
				}
			}
		});
		btnTrigger_Pattern.setBounds(198, 56, 88, 23);
		patternsPanel.add(btnTrigger_Pattern);

		JButton button_zoomIn = new JButton("+");
		button_zoomIn.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(0, 0,
						ZoomDirection.kIn.getValue());
				ShowPTZStatus(_ptzStatus, button_zoomIn.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		button_zoomIn.setBounds(167, 12, 41, 23);
		contentPanel.add(button_zoomIn);

		JButton btn_zoomOut = new JButton("-");
		btn_zoomOut.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousMove(0, 0,
						ZoomDirection.kOut.getValue());
				ShowPTZStatus(_ptzStatus, btn_zoomOut.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		btn_zoomOut.setBounds(167, 71, 41, 23);
		contentPanel.add(btn_zoomOut);

		JPanel absolutePanel = new JPanel();
		absolutePanel.setBorder(new TitledBorder(null, "Absolute Move",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		absolutePanel.setBounds(10, 279, 296, 97);
		contentPanel.add(absolutePanel);
		absolutePanel.setLayout(null);

		JLabel lblX = new JLabel("X");
		lblX.setBounds(51, 22, 20, 15);
		absolutePanel.add(lblX);

		JTextField txtAbsX = new JTextField();
		txtAbsX.setBounds(71, 22, 40, 20);
		absolutePanel.add(txtAbsX);
		txtAbsX.setColumns(10);

		JLabel lblY = new JLabel("Y");
		lblY.setBounds(121, 22, 20, 15);
		absolutePanel.add(lblY);

		JTextField txtAbsY = new JTextField();
		txtAbsY.setBounds(141, 22, 40, 20);
		absolutePanel.add(txtAbsY);
		txtAbsY.setColumns(10);

		JLabel lblZ = new JLabel("Z");
		lblZ.setBounds(191, 22, 20, 15);
		absolutePanel.add(lblZ);

		JTextField txtAbsZ = new JTextField();
		txtAbsZ.setBounds(211, 22, 40, 20);
		absolutePanel.add(txtAbsZ);
		txtAbsZ.setColumns(10);

		JButton btnGetPosition = new JButton("Get Position");
		btnGetPosition.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int x = ptzController.GetX();
				int y = ptzController.GetY();
				int z = ptzController.GetZ();
				if (String.valueOf(x) != null) {
					txtAbsX.setText(String.valueOf(x));
				}
				if (String.valueOf(y) != null) {
					txtAbsY.setText(String.valueOf(y));
				}
				if (String.valueOf(z) != null) {
					txtAbsZ.setText(String.valueOf(z));
				}
			}
		});
		btnGetPosition.setBounds(51, 53, 89, 23);
		absolutePanel.add(btnGetPosition);

		JButton btnSetPosition = new JButton("Set Position");
		btnSetPosition.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String xValue = txtAbsX.getText();
				String yValue = txtAbsY.getText();
				String zValue = txtAbsZ.getText();

				if (!xValue.isEmpty() && yValue.isEmpty() && zValue.isEmpty()) {
					_ptzStatus = ptzController.AbsolutePan(Integer
							.parseInt(xValue));
					ShowPTZStatus(_ptzStatus, btnSetPosition.getText());
				} else if (xValue.isEmpty() && !yValue.isEmpty()
						&& zValue.isEmpty()) {
					_ptzStatus = ptzController.AbsoluteTilt(Integer
							.parseInt(yValue));
					ShowPTZStatus(_ptzStatus, btnSetPosition.getText());
				} else if (xValue.isEmpty() && yValue.isEmpty()
						&& !zValue.isEmpty()) {
					_ptzStatus = ptzController.AbsoluteZoom(Integer
							.parseInt(zValue));
					ShowPTZStatus(_ptzStatus, btnSetPosition.getText());
				} else if (!xValue.isEmpty() && !yValue.isEmpty()
						&& zValue.isEmpty()) {
					_ptzStatus = ptzController.AbsoluteMove(
							Integer.parseInt(xValue), Integer.parseInt(yValue));
					ShowPTZStatus(_ptzStatus, btnSetPosition.getText());
				} else if (xValue != null && yValue != null) {
					_ptzStatus = ptzController.AbsoluteMove(
							Integer.parseInt(xValue), Integer.parseInt(yValue),
							Integer.parseInt(zValue));
					ShowPTZStatus(_ptzStatus, btnSetPosition.getText());
				} else {
					System.out.println("Invalid Value");
				}
			}
		});
		btnSetPosition.setBounds(162, 53, 89, 23);
		absolutePanel.add(btnSetPosition);
		JPanel relativePanel = new JPanel();
		relativePanel.setBorder(new TitledBorder(null, "Relative Move",
				TitledBorder.LEADING, TitledBorder.TOP, null, null));
		relativePanel.setBounds(10, 378, 296, 97);
		contentPanel.add(relativePanel);
		relativePanel.setLayout(null);

		JLabel lblX_1 = new JLabel("X");
		lblX_1.setBounds(54, 23, 20, 15);
		relativePanel.add(lblX_1);

		JLabel lblY_1 = new JLabel("Y");
		lblY_1.setBounds(124, 23, 20, 15);
		relativePanel.add(lblY_1);

		JLabel lblZ_1 = new JLabel("Z");
		lblZ_1.setBounds(194, 23, 20, 15);
		relativePanel.add(lblZ_1);

		JTextField txtRelMove_x = new JTextField();
		txtRelMove_x.setBounds(74, 23, 40, 20);
		relativePanel.add(txtRelMove_x);
		txtRelMove_x.setColumns(10);

		JTextField txtRelMove_y = new JTextField();
		txtRelMove_y.setBounds(144, 23, 40, 20);
		relativePanel.add(txtRelMove_y);
		txtRelMove_y.setColumns(10);

		JTextField txtRelMove_z = new JTextField();
		txtRelMove_z.setBounds(214, 23, 40, 20);
		relativePanel.add(txtRelMove_z);
		txtRelMove_z.setColumns(10);

		JButton btnMove = new JButton("Move");
		btnMove.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

				int xValue = Integer.parseInt(txtRelMove_x.getText());
				int yValue = Integer.parseInt(txtRelMove_y.getText());
				int zValue = Integer.parseInt(txtRelMove_z.getText());
				_ptzStatus = ptzController.RelativeMove(xValue, yValue, zValue);
				ShowPTZStatus(_ptzStatus, btnMove.getText());

			}
		});
		btnMove.setBounds(105, 63, 89, 23);
		relativePanel.add(btnMove);

		JButton button_focusNear = new JButton("+");
		button_focusNear.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousFocus(FocusDirection.kNear.getValue());
				ShowPTZStatus(_ptzStatus, button_focusNear.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		button_focusNear.setBounds(214, 12, 41, 23);
		contentPanel.add(button_focusNear);

		JButton button_focusFar = new JButton("-");
		button_focusFar.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousFocus(FocusDirection.kFar.getValue());
				ShowPTZStatus(_ptzStatus, button_focusFar.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		button_focusFar.setBounds(218, 70, 41, 23);
		contentPanel.add(button_focusFar);

		JButton button_IrisOpen = new JButton("+");
		button_IrisOpen.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousIris(IrisDirection.kOpen.getValue());
				ShowPTZStatus(_ptzStatus, button_IrisOpen.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		button_IrisOpen.setBounds(265, 12, 41, 23);
		contentPanel.add(button_IrisOpen);

		JButton button_IrisClose = new JButton("-");
		button_IrisClose.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				_ptzStatus = ptzController.ContinuousIris(IrisDirection.kClose.getValue());
				ShowPTZStatus(_ptzStatus, button_IrisClose.getText());
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				ptzController.PTZStop();
			}
		});
		button_IrisClose.setBounds(269, 71, 38, 23);
		contentPanel.add(button_IrisClose);

		JLabel lblZoom = new JLabel("Zoom");
		lblZoom.setBounds(177, 45, 28, 14);
		contentPanel.add(lblZoom);

		JLabel lblFocus = new JLabel("Focus");
		lblFocus.setBounds(224, 45, 28, 14);
		contentPanel.add(lblFocus);

		JLabel lblIris = new JLabel("Iris");
		lblIris.setBounds(275, 45, 32, 14);
		contentPanel.add(lblIris);
	}

	/**
	 * Show ptz status.
	 *
	 * @param status
	 *            the PTZ movement status
	 * @param buttonText
	 *            the button text
	 */
	private void ShowPTZStatus(boolean status, String buttonText) {
		if (status) {
			System.out.println(buttonText + "  Movement successful");
		} else {
			System.out.println(buttonText + "  Movement failed");
		}
	}
}
