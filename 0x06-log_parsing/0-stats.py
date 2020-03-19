#!/usr/bin/python3
import sys
"""Log Parser reads stdin an codes computer metrics"""

if __name__ == '__main__':

    def print_code(size, codes): 
        """Printer function"""
        print("File size: {:d}".format(size))
        for idx in sorted(codes.keys()):
            if codes[idx] != 0:
                print("{}: {}".format(idx, codes[idx]))

    size = 0
    codes = {"200": 0, "301": 0, "400": 0, "401": 0,
         "403": 0, "404": 0, "405": 0, "500": 0}

    count = 0
    try:
            for line in sys.stdin:
                count += 1
                arr = line.split()
                try:
                    size += int(arr[-1])
                except BaseException:
                    pass
                try:
                    st = arr[-2]
                    if st in codes:
                        codes[st] += 1
                except BaseException:
                    pass
                if count % 10 == 0:
                    print_code(size, codes)
            print_code(size, codes)
    except KeyboardInterrupt: 
        print_code(size, codes)
        raise