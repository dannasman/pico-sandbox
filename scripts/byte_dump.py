import serial
import sys

def is_printable(b):
    return 32 <= b <= 126

def uart_dump(port, baudrate=115200):
    try:
        ser = serial.Serial(port, baudrate, timeout=1)
        print(f"Opened {port} at {baudrate} baud.")
    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        sys.exit(1)

    offset = 0
    buffer = []

    try:
        while True:
            data = ser.read(1)
            if data:
                buffer.append(data[0])

                # Print when we have 16 bytes
                if len(buffer) == 16:
                    print_line(offset, buffer)
                    offset += 16
                    buffer.clear()
            else:
                # no data received (timeout) - flush buffer if not empty
                if buffer:
                    print_line(offset, buffer)
                    offset += len(buffer)
                    buffer.clear()
    except KeyboardInterrupt:
        # On Ctrl-C flush remaining bytes
        if buffer:
            print_line(offset, buffer)
        print("\nExiting...")
    finally:
        ser.close()

def print_line(offset, data):
    # offset as 8-digit hex
    line = f"{offset:08x} "

    # Print hex bytes in groups of 4 bytes (8 hex chars)
    for i in range(16):
        if i < len(data):
            line += f"{data[i]:02x}"
        else:
            line += "  "
        # add a space after every 4 bytes
        if (i + 1) % 4 == 0:
            line += " "

    # ASCII representation at the end
    ascii_repr = ''.join(chr(b) if is_printable(b) else '.' for b in data)
    line += f" {ascii_repr}"

    print(line)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python uart_dump.py <serial_port> [baudrate]")
        sys.exit(1)
    port = sys.argv[1]
    baudrate = int(sys.argv[2]) if len(sys.argv) > 2 else 115200
    uart_dump(port, baudrate)

