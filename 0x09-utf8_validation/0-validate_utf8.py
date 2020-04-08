#!/usr/bin/python3

'''UTF-8 validator'''


def validUTF8(data):
        '''Checks if UTF-8 is valid'''
        if not data:
            return False
        byte = 0
        for p in data:
            if byte > 0:
                if (p & 192) == 128:
                    byte -= 1
                else:
                    return False
            elif (p & 192) == 128:
                return False
            elif (p & 224) == 192:
                byte += 1
            elif (p & 240) == 224:
                byte += 2
            elif (p & 248) == 240:
                byte += 3
            elif (p > 248):
                return False
        return byte == 0
