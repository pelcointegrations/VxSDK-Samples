package Enums;

public enum PanelLocationEnum {

	/** Left panel location. */
	Left(0),
    
    /** Right panel location. */
    Right(1);
    
    /** The value. */
    private final int value;
    
    /**
     * Instantiates a new panel location enum.
     *
     * @param value the value
     */
    private PanelLocationEnum(int value) {
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
}
