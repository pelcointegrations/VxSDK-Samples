package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum FocusDirection.
 */
public enum FocusDirection {
	
	/** The k stop. */
	kStop(0),   
	
	/** The k far. */
	kFar(1),      
	
	/** The k near. */
	kNear(2);    
		
	/** The value. */
	private final int value;
    
    /**
     * Instantiates a new focus direction.
     *
     * @param value the value
     */
    private FocusDirection(int value) {
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
        for (FocusDirection focus : FocusDirection.values()) {
            if (focus.getValue() == i) {
                return focus.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }
}

