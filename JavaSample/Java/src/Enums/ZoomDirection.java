package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum ZoomDirection.
 */
public enum ZoomDirection {
	
	/** The k unknown. */
	kUnknown(0),   
	
	/** The k none. */
	kNone(1),      
	
	/** The k in. */
	kIn(2),    
	
	/** The k out. */
	kOut(3);       
		
	/** The value. */
	private final int value;
    
    /**
     * Instantiates a new zoom direction.
     *
     * @param value the value
     */
    private ZoomDirection(int value) {
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
        for (ZoomDirection dir : ZoomDirection.values()) {
            if (dir.getValue() == i) {
                return dir.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }
}
