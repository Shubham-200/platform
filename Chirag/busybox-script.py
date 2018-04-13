import os
import urllib
import time

print 'Make sure you have a ext4 partition called RFS in your sd card'
print 'It is assumed that you have cross compiler for arm'

r = os.popen('uname -n').read()[:-1]
sdcard = '/media/' + r + '/RFS'

if not os.path.isdir(sdcard):
	print 'error: no ext4 partition called RFS in sdcard'
	exit()

print 'Download started please wait....'
url = 'https://busybox.net/downloads/busybox-1.24.1.tar.bz2'

if url.find('/'):
	name = url.rsplit('/', 1)[1]

urllib.urlretrieve(url, name)

print 'Download complete'
print 'File name is :', name

import tarfile

tar1 = tarfile.open(name) 
tar1.extractall()

os.chdir('busybox-1.24.1')

print 'Select Busybox Settings -> Build Options -> Build Busybox as a static binary (no shared libs)'
print 'Wait for menuconfig.........'
time.sleep(5)

os.system('make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- defconfig')
os.system('make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- menuconfig')

print 'make'
com = 'make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- CONFIG_PREFIX='
com = com + '/media/' + sdcard + 'install'

os.system(com)
os.chdir(sdcard)
os.system('mkdir dev')
os.system('mknod dev/console c 5 1')
os.system('mknod dev/null c 1 3')
os.system('mknod dev/zero c 1 5')

os.system('mkdir lib usr')
os.chdir('usr')
os.system('mkdir lib')
os.chdir('../')

if os.path.isdir('/opt/gcc-arm-linux'):
	os.system('rsync -a /opt/gcc-arm-linux/arm-linux-gnueabihf/lib/ ./lib/')
	os.system('rsync -a /opt/gcc-arm-linux/arm-linux-gnueabihf/lib/ ./usr/lib/')

os.system('mkdir proc sys root')
os.system('mkdir etc')

ss = "\n".join(['echo "null::sysinit:/bin/mount -a', 'null::sysinit:/bin/hostname -F /etc/hostname', 'null::respawn:/bin/cttyhack /bin/login root', 'null::restart:/sbin/reboot" > etc/inittab'])

os.system(ss)

ss = "\n".join(['echo "proc  /proc proc  defaults  0 0', 'sysfs /sys  sysfs defaults  0 0" > etc/fstab'])
os.system(ss)

ss = 'echo "chirag-busybox-rfs" > etc/hostname'
os.system(ss)

ss = 'echo "root::0:0:root:/root:/bin/sh" > etc/passwd'
os.system(ss)
