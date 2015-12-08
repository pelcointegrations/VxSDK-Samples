package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum PanTiltDirection.
 */
public enum PanTiltDirection {
	
	/** The k unknown. */
	kUnknown(0),   
	
	/** The k none. */
	kNone(1),      
	
	/** The k up left. */
	kUpLeft(2),    
	
	/** The k up. */
	kUp(3),        
	
	/** The k up right. */
	kUpRight(4),   
	
	/** The k right. */
	kRight(5),     
	
	/** The k down right. */
	kDownRight(6), 
	
	/** The k down. */
	kDown(7),      
	
	/** The k down left. */
	kDownLeft(8),  
	
	/** The k left. */
	kLeft(9);
	
	/** The value. */
	private final int value;
    
    /**
     * Instantiates a new pan tilt direction.
     *
     * @param value the value
     */
    private PanTiltDirection(int value) {
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
        for (PanTiltDirection dir : PanTiltDirection.values()) {
            if (dir.getValue() == i) {
                return dir.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }
}
