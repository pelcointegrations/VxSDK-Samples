package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum DeviceStateEnum.
 */
public enum DeviceStateEnum {
	
	/** The Unknown. */
	Unknown(0),
    
    /** The Offline. */
    Offline(1),
    
    /** The Online. */
    Online(2);
    
    /** The value. */
    private final int value;
    
    /**
     * Instantiates a new device state enum.
     *
     * @param value the value
     */
    private DeviceStateEnum(int value) {
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
        for (DeviceStateEnum status : DeviceStateEnum.values()) {
            if (status.getValue() == i) {
                return status.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }

}