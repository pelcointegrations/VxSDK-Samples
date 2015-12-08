package Enums;



// TODO: Auto-generated Javadoc
/**
 * The Enum DeviceTypeEnum.
 */
public enum DeviceTypeEnum {
	
	/** The Unknown. */
	Unknown(0),
    
    /** The Camera. */
    Camera(1),
    
    /** The Core. */
    Core(2),
    
    /** The Core mg. */
    CoreMg(3),
    
    /** The Decoder. */
    Decoder(4),
    
    /** The Encoder. */
    Encoder(5),
    
    /** The Manager. */
    Manager(6),
    
    /** The Mg. */
    Mg(7),
    
    /** The Monitor. */
    Monitor(8),
    
    /** The Recorder. */
    Recorder(9),
    
    /** The Udi. */
    Udi(10),
    
    /** The Ui. */
    Ui(11),
    
    /** The Vcd. */
    Vcd(12);
    
    /** The value. */
    private final int value;
    
    /**
     * Instantiates a new device type enum.
     *
     * @param value the value
     */
    private DeviceTypeEnum(int value) {
        this.value = value;
    }

    /**
     * Gets the value.
     *
     * @return the value
     */
    public int getValue() {
        return value;
    }
    
    /**
     * Gets the string value from int.
     *
     * @param i the i
     * @return the string value from int
     */
    public static String getStringValueFromInt(int i) {
        for (DeviceTypeEnum status : DeviceTypeEnum.values()) {
            if (status.getValue() == i) {
                return status.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }

}
