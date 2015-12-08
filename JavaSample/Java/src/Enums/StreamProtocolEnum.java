package Enums;

// TODO: Auto-generated Javadoc
/**
 * The Enum StreamProtocolEnum.
 */
public enum StreamProtocolEnum {
	
	/** The k stream protocol unknown. */
	kStreamProtocolUnknown(0),
	
	/** The k stream protocol mjpeg pull. */
	kStreamProtocolMjpegPull(1),
	
	/** The k stream protocol rtsp rtp. */
	kStreamProtocolRtspRtp(2);
	
	/** The value. */
	private final int value;
    
    /**
     * Instantiates a new stream protocol enum.
     *
     * @param value the value
     */
    private StreamProtocolEnum(int value) {
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
        for (StreamProtocolEnum protocol : StreamProtocolEnum.values()) {
            if (protocol.getValue() == i) {
            	if(i == 1) return "MJpeg Pull";
            	else if (i == 2) return "RTSP";
            	
                return protocol.toString();
            }
        }
        // throw an IllegalArgumentException or return null
        throw new IllegalArgumentException("the given number doesn't match any Status.");
    }
}
