import argparse
import math
import serial
import struct
import time

import numpy as np;
import matplotlib.pyplot as plt;

ser = serial.Serial("/dev/ttyUSB0", baudrate=115200, bytesize=8, stopbits=1, write_timeout=0.1)

def parse_arguments():
    parser = argparse.ArgumentParser(prog='fft_payload', description="push kernel image to board")
    parser.add_argument("--out", type=str, help="output file")

    args = parser.parse_args()
    return args

def wait_for_payload_signal():
    start_time = time.time()
    duration = 20
    count = 0 
    while time.time() - start_time < duration:
        byte = ser.read(1)
        if byte == b'\x03':
            count += 1
        if count == 3:
            return True

    print("Did not receive payload signal in 20 seconds.")
    return False


def main():
    args = parse_arguments();
    received = wait_for_payload_signal()
    if not received:
        ser.close()
        return

    
    size = 1024
    freq = 10
    t = np.arange(size) / size;
    f = 127.5*(np.cos(2 * np.pi * freq * t)+np.sin(np.pi * freq * t)) + 127.5;
    noise = np.random.normal(0, 50, size)
    f = f + noise
    buf = bytearray(np.clip(f, 0, 255).astype(np.uint8));

    ser.write(struct.pack("<i", size))
    print(size)

    if ser.read() != b'O':
        print("Chainloader failed to read size")
        return

    if ser.read() != b'K':
        print("Chainloader failed to read size")
        return

    print("size written.")

    chunk_size = 512
    c = 0
    for i in range(0, size, chunk_size):
        chunk = buf[i:i+chunk_size]
        written = ser.write(chunk)
        c += 1
        print(f"{c}/{math.ceil(size/chunk_size)} chunks written")
    
    print("image written.")

    received = wait_for_payload_signal()
    if not received:
        ser.close()
        return

    data_str = ""
    if args.out:
        f = open(args.out, "w")
    s = ser.readline().decode('utf-8').strip();
    data_str += s+"\n";
    cycle_meas_n = int(s);
    cycle_meas = np.zeros(cycle_meas_n);
    print(f"{cycle_meas_n} cycle measurements")
    for i in range(cycle_meas_n):
        s = ser.readline().decode('utf-8').strip();
        data_str += s+"\n";
        cycle_meas[i] = int(s);
    print(f"average cycle count: {np.average(cycle_meas)}")


    s = ser.readline().decode('utf-8').strip();
    data_str += s+"\n";
    fft_n = int(s);
    fft = np.zeros(fft_n);
    print(f"{fft_n} fft points")
    for i in range(fft_n):
        s = ser.readline().decode('utf-8').strip();
        data_str += s+"\n";
        mag2 = int(s);
        fft[i] = np.sqrt(mag2)

    if args.out:
        f.write(data_str)
        f.close()
    else:
        plt.figure()
        plt.plot((f-128)*2**24)

        plt.figure()
        #plt.plot(np.abs(np.fft.fft(f)[:fft_n//2])/fft_n)
        plt.plot(fft[:fft_n//2])

        plt.show()

main()

