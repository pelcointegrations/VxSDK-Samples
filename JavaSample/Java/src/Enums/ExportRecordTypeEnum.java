package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum ExportRecordTypeEnum.
 */
public enum ExportRecordTypeEnum {
	
	/** The Unknown. */
	Unknown(0),
	
	/** The Alarm. */
	Alarm(1),
	
	/** The Analytic. */
	Analytic(2),
	
	/** The Event. */
	Event(3),
	
	/** The Manual. */
	Manual(4),
	
	/** The Motion. */
	Motion(5),
	
	/** The Timed. */
	Timed(6);
   
    /** The value. */
    private final int value;
    
    /**
     * Instantiates a new export record type enum.
     *
     * @param value the value
     */
    private ExportRecordTypeEnum(int value) {
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
        for (ExportRecordTypeEnum type : ExportRecordTypeEnum.values()) {
            if (type.getValue() == i) {
                return type.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }
    
    public static int getIntValueFromString(String i) {
        for (ExportRecordTypeEnum type : ExportRecordTypeEnum.values()) {
            if (type.toString().equals(i)) {
                return type.getValue();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }

}
