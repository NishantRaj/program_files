import os
import random
import shutil
import string
import threading
import urllib
from urllib import request
from urllib.request import urlopen
import tkinter
import sys as Sys

import time


def randomword(length):
    return ''.join(random.choice(string.ascii_lowercase) for i in range(length))


def printProgress(iteration, total, prefix='', suffix='', decimals=2, barLength=100):
    """
    Call in a loop to create terminal progress bar
    @params:
        iteration   - Required  : current iteration (Int)
        total       - Required  : total iterations (Int)
        prefix      - Optional  : prefix string (Str)
        suffix      - Optional  : suffix string (Str)
        decimals    - Optional  : number of decimals in percent complete (Int)
        barLength   - Optional  : character length of bar (Int)
    """
    filledLength = int(round(barLength * iteration / float(total)))
    percents = round(100.00 * (iteration / float(total)), decimals)
    bar = '#' * filledLength + '-' * (barLength - filledLength)
    Sys.stdout.write('%s [%s] %s%s %s\r' % (prefix, bar, percents, '%', suffix)),
    Sys.stdout.flush()
    if iteration == total:
        print("\n")


url = input("Input URL:- ")
threadsNumber = int(input("Number of Threads:- "))
u = urlopen(url)

meta = u.info()
file_size = int(u.getheader('Content-Length'))
contentType = str(u.getheader('Content-Type'))
fileType = contentType.split('/')
fileFormat = fileType[-1]
urlContent = url.split('/')
fullFileName = urlContent[-1]
print(fileType[-1])
print(meta)

# threads = []
# parts = {}
# segment_name = []
# chunk_size, rem = divmod(file_size, threadsNumber)
#
# counter = 0
# block_sz = 8192
#
#
# def download(start, randomName, chunk_size):
#     fl = open(randomName, "wb")
#     req = request.Request(url)
#     req.headers['Range'] = 'bytes=%s-%s' % (start, start + chunk_size - 1)
#     # print(req.headers)
#     down = urllib.request.urlopen(req)
#     # var = down.read()
#     # fl.write(var)
#     file_size_dl = 0
#     while True:
#         buffer = down.read(block_sz)
#         if not buffer:
#             break
#         file_size_dl += len(buffer)
#         fl.write(buffer)
#         # status = "%10d  [%3.2f%%]" % (file_size_dl, file_size_dl * 100. / chunk_size)
#         # status += chr(8) * (len(status) + 1)
#         printProgress(file_size_dl, chunk_size, prefix='Progress: ' + randomName, suffix='Complete', barLength=100)
#         # print(status)
#         # parts[start] = var
#
#
# l_chunk = chunk_size
# for i in range(0, threadsNumber):
#     r_name = "file_" + str(i) + ".nr"
#     segment_name.append(r_name)
#     if i == (threadsNumber - 1):
#         l_chunk += rem
#     t = threading.Thread(download(i * chunk_size, r_name, l_chunk))
#     # t.start()
#     threads.append(t)
# for i in threads:
#     i.start()
# for i in threads:
#     i.join()
#
# result = bytearray()
# chunk = ''
# i = 0
# while chunk is not None:
#     if (i * chunk_size) in parts:
#         chunk = parts[i * chunk_size]
#         result.extend(chunk)
#         i += 1
#     else:
#         break
#
# if len(fullFileName) > 50:
#     fullFileName = randomword(5)+"."+fileFormat
#
# if not fullFileName:
#     f = open("file1", "wb")
#     f2 = open("file", "wb")
# else:
#     f = open(fullFileName, "wb")
#     f2 = open("1_" + fullFileName, "wb")
# f2.write(result)
# print(segment_name)
# for i in segment_name:
#     with open(i, 'rb') as rd:
#         f.write(rd.read())
#     os.remove(i)
