package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum IrisDirection.
 */
public enum IrisDirection {
	
	/** The k stop. */
	kStop(0),   
	
	/** The k close. */
	kClose(1),      
	
	/** The k open. */
	kOpen(2);    
		
	/** The value. */
	private final int value;
    
    /**
     * Instantiates a new iris direction.
     *
     * @param value the value
     */
    private IrisDirection(int value) {
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
        for (IrisDirection iris : IrisDirection.values()) {
            if (iris.getValue() == i) {
                return iris.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }
}
