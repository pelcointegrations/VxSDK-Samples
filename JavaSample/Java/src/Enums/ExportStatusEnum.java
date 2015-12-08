package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum ExportStatusEnum.
 */
public enum ExportStatusEnum {
	 
 	/** The Unknown. */
 	Unknown(0),
     
     /** The Exporting. */
     Exporting(1),
     
     /** The Failed. */
     Failed(2),
     
     /** The Pending. */
     Pending(3),
     
     /** The Successful. */
     Successful(4);
     
     /** The value. */
     private final int value;
    
    /**
     * Instantiates a new export status enum.
     *
     * @param value the value
     */
    private ExportStatusEnum(int value) {
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
        for (ExportStatusEnum status : ExportStatusEnum.values()) {
            if (status.getValue() == i) {
                return status.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }

}
