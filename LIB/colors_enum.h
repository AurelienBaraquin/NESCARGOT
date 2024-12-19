typedef enum {
    // Grayscale
    BLACK = 0x0F,
    DARK_GRAY = 0x00,
    GRAY = 0x10,
    LIGHT_GRAY = 0x20,
    WHITE = 0x30,

    // Blues
    DARK_BLUE = 0x01,
    BLUE = 0x11,
    MEDIUM_BLUE = 0x21,
    LIGHT_BLUE = 0x31,
    CYAN = 0x22,

    // Greens
    DARK_GREEN = 0x09,
    GREEN = 0x19,
    MEDIUM_GREEN = 0x29,
    LIGHT_GREEN = 0x39,

    // Reds
    DARK_RED = 0x06,
    RED = 0x16,
    MEDIUM_RED = 0x26,
    LIGHT_RED = 0x36,

    // Oranges and Yellows
    ORANGE = 0x17,
    DARK_YELLOW = 0x08,
    YELLOW = 0x28,
    LIGHT_YELLOW = 0x38,

    // Purples and Magentas
    DARK_PURPLE = 0x05,
    PURPLE = 0x15,
    MEDIUM_PURPLE = 0x25,
    LIGHT_PURPLE = 0x35,
    MAGENTA = 0x14,
    PINK = 0x34,

    // Browns and Tans
    BROWN = 0x07,
    TAN = 0x27,
    GOLD = 0x37,

    // Cyan Shades
    DARK_CYAN = 0x02,
    MEDIUM_CYAN = 0x12,
    LIGHT_CYAN = 0x32,

    // Others
    SKY_BLUE = 0x03,
    TURQUOISE = 0x13,
    LIME = 0x0A,
    AQUA = 0x1A,

    // Reserved or unstable colors (e.g., 0x0D) are excluded for compatibility.
} Color;
